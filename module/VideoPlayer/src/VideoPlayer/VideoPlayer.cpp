﻿/**
 * 叶海辉
 * QQ群121376426
 * http://blog.yundiantech.com/
 */

#include "VideoPlayer.h"

#include "Audio/PcmVolumeControl.h"

#include <stdio.h>



VideoPlayer::VideoPlayer()
{
    mConditon_Video = new Cond;
    mConditon_Audio = new Cond;

    mPlayerState = VideoPlayer_Stop;

    mVideoPlayerCallBack = nullptr;

    mAudioID = 0;
    mIsMute = false;

    mIsNeedPause = false;

    mVolume = 1;
}

VideoPlayer::~VideoPlayer()
{

}

bool VideoPlayer::initPlayer()
{
    static int isInited = false;

    if (!isInited)
    {
        av_register_all(); //初始化FFMPEG  调用了这个才能正常使用编码器和解码器
        avformat_network_init(); //支持打开网络文件

        isInited = true;
    }

//SDL初始化需要放入子线程中，否则有些电脑会有问题。
//    if (SDL_Init(SDL_INIT_AUDIO))
//    {
//        fprintf(stderr, "Could not initialize SDL - %s. \n", SDL_GetError());
//        return false;
//    }

    return true;
}

bool VideoPlayer::startPlay(const std::string &filePath)
{
    if (mPlayerState != VideoPlayer_Stop)
    {
        return false;
    }

    mIsQuit = false;
    mIsPause = false;

    if (!filePath.empty())
        mFilePath = filePath;

    //启动新的线程实现读取视频文件
    std::thread([&](VideoPlayer *pointer)
    {
        pointer->readVideoFile();

    }, this).detach();

    return true;

}

bool VideoPlayer::replay()
{
    stop();

    startPlay(mFilePath);

    return true;
}

bool VideoPlayer::play()
{
    mIsNeedPause = false;
    mIsPause = false;

    if (mPlayerState != VideoPlayer_Pause)
    {
        return false;
    }

    uint64_t pauseTime = av_gettime() - mVideoStartTime; //暂停了多长时间
    mVideoStartTime += pauseTime; //将暂停的时间加到开始播放的时间上，保证同步不受暂停的影响

    mPlayerState = VideoPlayer_Playing;
    doPlayerStateChanged(VideoPlayer_Playing, mVideoStream != nullptr, mAudioStream != nullptr);

    return true;
}

bool VideoPlayer::pause()
{
    fprintf(stderr, "%s mIsPause=%d \n", __FUNCTION__, mIsPause);

    mIsPause = true;

    if (mPlayerState != VideoPlayer_Playing)
    {
        return false;
    }

    mPauseStartTime = av_gettime();

    mPlayerState = VideoPlayer_Pause;

    emit doPlayerStateChanged(VideoPlayer_Pause, mVideoStream != nullptr, mAudioStream != nullptr);

    return true;
}

bool VideoPlayer::stop(bool isWait)
{
    if (mPlayerState == VideoPlayer_Stop)
    {
        return false;
    }

    mPlayerState = VideoPlayer_Stop;
    mIsQuit = true;

    if (isWait)
    {
        while(!mIsReadThreadFinished)
        {
            mSleep(3);
        }
    }

    return true;
}

void VideoPlayer::seek(int64_t pos)
{
    if(!seek_req)
    {
        seek_pos = pos;
        seek_req = 1;
    }
}

void VideoPlayer::setVolume(float value)
{
    mVolume = value;
}

double VideoPlayer::getCurrentTime()
{
    return audio_clock;
}

int64_t VideoPlayer::getTotalTime()
{
    return pFormatCtx->duration;
}

int VideoPlayer::openSDL()
{



	 int wanted_nb_channels = 2;
    ///打开SDL，并设置播放的格式为:AUDIO_S16LSB 双声道，44100hz
    ///后期使用ffmpeg解码完音频后，需要重采样成和这个一样的格式，否则播放会有杂音
    SDL_AudioSpec wanted_spec, spec;
    //int wanted_nb_channels = 2;
   // int samplerate = 44100;
    #define SDL_AUDIO_MIN_BUFFER_SIZE 512
    #define SDL_AUDIO_MAX_CALLBACKS_PER_SEC 60

    //wanted_spec.freq = samplerate;
    //wanted_spec.freq = aCodecCtx->sample_rate;
    //wanted_spec.freq = 46050;
    wanted_spec.freq = 46050;

    wanted_spec.samples = FFMAX(SDL_AUDIO_MIN_BUFFER_SIZE, 2 << av_log2_16bit(wanted_spec.freq / SDL_AUDIO_MAX_CALLBACKS_PER_SEC));
    //wanted_spec.samples = SDL_AUDIO_BUFFER_SIZE;  // 自定义SDL缓冲区大小
    wanted_spec.format = AUDIO_S16SYS; // 具体含义请查看“SDL宏定义”部分
    wanted_spec.silence = 0;            // 0指示静音
    wanted_spec.callback = sdlAudioCallBackFunc;  // 回调函数
    wanted_spec.userdata = this;                  // 传给上面回调函数的外带数据

 
    int num = SDL_GetNumAudioDevices(0);
    for (int i=0;i<num;i++)
    {
        mAudioID = SDL_OpenAudioDevice(SDL_GetAudioDeviceName(i,0), false, &wanted_spec, &spec,0);
        if (mAudioID > 0)
        {
            break;
        }
    }

    /* 检查实际使用的配置（保存在spec,由SDL_OpenAudio()填充） */
//    if (spec.format != AUDIO_S16SYS)
    if (mAudioID <= 0)
    {
        mIsAudioThreadFinished = true;
        return -1;
    }
fprintf(stderr, "mAudioID=%d\n\n\n\n\n\n", mAudioID);
    return 0;
}

void VideoPlayer::closeSDL()
{
    if (mAudioID > 0)
    {
        SDL_LockAudioDevice(mAudioID);
        SDL_PauseAudioDevice(mAudioID, 1);
        SDL_UnlockAudioDevice(mAudioID);

        SDL_CloseAudioDevice(mAudioID);
    }

    mAudioID = 0;
}

void VideoPlayer::readVideoFile()
{
    ///SDL初始化需要放入子线程中，否则有些电脑会有问题。
    if (SDL_Init(SDL_INIT_AUDIO))
    {
        doOpenSdlFailed(-100);
        fprintf(stderr, "Could not initialize SDL - %s. \n", SDL_GetError());
        return;
    }

    mIsReadThreadFinished = false;
    mIsReadFinished = false;

    const char * file_path = mFilePath.c_str();

    pFormatCtx = nullptr;
    pCodecCtx = nullptr;
    pCodec = nullptr;

    aCodecCtx = nullptr;
    aCodec = nullptr;
    aFrame = nullptr;

    mAudioStream = nullptr;
    mVideoStream = nullptr;

    audio_clock = 0;
    video_clock = 0;

    int audioStream ,videoStream;

    //Allocate an AVFormatContext.
    pFormatCtx = avformat_alloc_context();

    AVDictionary* opts = NULL;
    av_dict_set(&opts, "rtsp_transport", "tcp", 0); //设置tcp or udp，默认一般优先tcp再尝试udp
    av_dict_set(&opts, "stimeout", "60000000", 0);//设置超时3秒

    if (avformat_open_input(&pFormatCtx, file_path, nullptr, &opts) != 0)
    {
        fprintf(stderr, "can't open the file. \n");
        doOpenVideoFileFailed();
        goto end;
    }

    if (avformat_find_stream_info(pFormatCtx, nullptr) < 0)
    {
        fprintf(stderr, "Could't find stream infomation.\n");
        doOpenVideoFileFailed();
        goto end;
    }

    videoStream = -1;
    audioStream = -1;

    ///循环查找视频中包含的流信息，
    for (int i = 0; i < pFormatCtx->nb_streams; i++)
    {
        if (pFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO)
        {
            videoStream = i;
        }
        if (pFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_AUDIO  && audioStream < 0)
        {
            audioStream = i;
        }
    }

    doTotalTimeChanged(getTotalTime());

    ///打开视频解码器，并启动视频线程
    if (videoStream >= 0)
    {
        ///查找视频解码器
        pCodecCtx = pFormatCtx->streams[videoStream]->codec;
        pCodec = avcodec_find_decoder(pCodecCtx->codec_id);

        if (pCodec == nullptr)
        {
            fprintf(stderr, "PCodec not found.\n");
            doOpenVideoFileFailed();
            goto end;
        }

        ///打开视频解码器
        if (avcodec_open2(pCodecCtx, pCodec, NULL) < 0)
        {
            fprintf(stderr, "Could not open video codec.\n");
            doOpenVideoFileFailed();
            goto end;
        }

        mVideoStream = pFormatCtx->streams[videoStream];

        ///创建一个线程专门用来解码视频
        std::thread([&](VideoPlayer *pointer)
        {
            pointer->decodeVideoThread();

        }, this).detach();

    }

    if (audioStream >= 0)
    {
        ///查找音频解码器
        aCodecCtx = pFormatCtx->streams[audioStream]->codec;
        aCodec = avcodec_find_decoder(aCodecCtx->codec_id);

        if (aCodec == NULL)
        {
            fprintf(stderr, "ACodec not found.\n");
            audioStream = -1;
        }
        else
        {
            ///打开音频解码器
            if (avcodec_open2(aCodecCtx, aCodec, nullptr) < 0)
            {
                fprintf(stderr, "Could not open audio codec.\n");
                doOpenVideoFileFailed();
                goto end;
            }

            ///解码音频相关
            aFrame = av_frame_alloc();


            //重采样设置选项-----------------------------------------------------------start
            aFrame_ReSample = nullptr;

            //frame->16bit 44100 PCM 统一音频采样格式与采样率
            swrCtx = nullptr;

            //输入的声道布局
            int in_ch_layout;

            //输出的声道布局
            out_ch_layout = av_get_default_channel_layout(audio_tgt_channels); ///AV_CH_LAYOUT_STEREO

            out_ch_layout &= ~AV_CH_LAYOUT_STEREO_DOWNMIX;

            /// 这里音频播放使用了固定的参数
            /// 强制将音频重采样成44100 双声道  AV_SAMPLE_FMT_S16
            /// SDL播放中也是用了同样的播放参数
            //重采样设置选项----------------
            //输入的采样格式
            in_sample_fmt = aCodecCtx->sample_fmt;
            //输出的采样格式 16bit PCM
            out_sample_fmt = AV_SAMPLE_FMT_S16;
            //输入的采样率
            in_sample_rate = aCodecCtx->sample_rate;
            
             
            //输入的声道布局
            in_ch_layout = aCodecCtx->channel_layout;

            //输出的采样率
            //out_sample_rate = 44100;
            out_sample_rate = aCodecCtx->sample_rate;
            
            //输出的声道布局

            audio_tgt_channels = 2; ///av_get_channel_layout_nb_channels(out_ch_layout);
            out_ch_layout = av_get_default_channel_layout(audio_tgt_channels); ///AV_CH_LAYOUT_STEREO

            out_ch_layout &= ~AV_CH_LAYOUT_STEREO_DOWNMIX;

            /// 2019-5-13添加
            /// wav/wmv 文件获取到的aCodecCtx->channel_layout为0会导致后面的初始化失败，因此这里需要加个判断。
            if (in_ch_layout <= 0)
            {
                in_ch_layout = av_get_default_channel_layout(aCodecCtx->channels);
            }

            swrCtx = swr_alloc_set_opts(nullptr, out_ch_layout, out_sample_fmt, out_sample_rate,
                                                 in_ch_layout, in_sample_fmt, in_sample_rate, 0, nullptr);

            /** Open the resampler with the specified parameters. */
            int ret = swr_init(swrCtx);
            if (ret < 0)
            {
                char buff[128]={0};
                av_strerror(ret, buff, 128);

                fprintf(stderr, "Could not open resample context %s\n", buff);
                swr_free(&swrCtx);
                swrCtx = nullptr;
                doOpenVideoFileFailed();
                goto end;
            }

            //存储pcm数据
            int out_linesize = out_sample_rate * audio_tgt_channels;

          //  out_linesize = av_samples_get_buffer_size(NULL, audio_tgt_channels, av_get_bytes_per_sample(out_sample_fmt), out_sample_fmt, 1);
       
            out_linesize = AVCODEC_MAX_AUDIO_FRAME_SIZE;


            mAudioStream = pFormatCtx->streams[audioStream];

            ///打开SDL播放声音
            int code = openSDL();

            if (code == 0)
            {
                SDL_LockAudioDevice(mAudioID);
                SDL_PauseAudioDevice(mAudioID,0);
                SDL_UnlockAudioDevice(mAudioID);

                mIsAudioThreadFinished = false;
            }
            else
            {
                doOpenSdlFailed(code);
            }
        }

    }

//    av_dump_format(pFormatCtx, 0, file_path, 0); //输出视频信息

    mPlayerState = VideoPlayer_Playing;
    doPlayerStateChanged(VideoPlayer_Playing, mVideoStream != nullptr, mAudioStream != nullptr);

    mVideoStartTime = av_gettime();
fprintf(stderr, "%s mIsQuit=%d mIsPause=%d \n", __FUNCTION__, mIsQuit, mIsPause);
    while (1)
    {
        if (mIsQuit)
        {
            //停止播放了
            break;
        }

        if (seek_req)
        {
            int stream_index = -1;
            int64_t seek_target = seek_pos;

            if (videoStream >= 0)
                stream_index = videoStream;
            else if (audioStream >= 0)
                stream_index = audioStream;

            AVRational aVRational = {1, AV_TIME_BASE};
            if (stream_index >= 0)
            {
                seek_target = av_rescale_q(seek_target, aVRational, pFormatCtx->streams[stream_index]->time_base);
            }

            if (av_seek_frame(pFormatCtx, stream_index, seek_target, AVSEEK_FLAG_BACKWARD) < 0)
            {
                fprintf(stderr, "%s: error while seeking\n",pFormatCtx->filename);
            }
            else
            {
                if (audioStream >= 0)
                {
                    AVPacket packet;
                    av_new_packet(&packet, 10);
                    strcpy((char*)packet.data,FLUSH_DATA);
                    clearAudioQuene(); //清除队列
                    inputAudioQuene(packet); //往队列中存入用来清除的包
                }

                if (videoStream >= 0)
                {
                    AVPacket packet;
                    av_new_packet(&packet, 10);
                    strcpy((char*)packet.data,FLUSH_DATA);
                    clearVideoQuene(); //清除队列
                    inputVideoQuene(packet); //往队列中存入用来清除的包
                    video_clock = 0;
                }

                mVideoStartTime = av_gettime() - seek_pos;
                mPauseStartTime = av_gettime();
            }
            seek_req = 0;
            seek_time = seek_pos / 1000000.0;
            seek_flag_audio = 1;
            seek_flag_video = 1;

            if (mIsPause)
            {
                mIsNeedPause = true;
                mIsPause = false;
            }

        }

        //这里做了个限制  当队列里面的数据超过某个大小的时候 就暂停读取  防止一下子就把视频读完了，导致的空间分配不足
        //这个值可以稍微写大一些
        if (mAudioPacktList.size() > MAX_AUDIO_SIZE || mVideoPacktList.size() > MAX_VIDEO_SIZE)
        {
            mSleep(10);
            continue;
        }

        if (mIsPause == true)
        {
            mSleep(10);
            continue;
        }

        AVPacket packet;
        if (av_read_frame(pFormatCtx, &packet) < 0)
        {
            mIsReadFinished = true;

            if (mIsQuit)
            {
                break; //解码线程也执行完了 可以退出了
            }

            mSleep(10);
            continue;
        }

        if (packet.stream_index == videoStream)
        {
            inputVideoQuene(packet);
            //这里我们将数据存入队列 因此不调用 av_free_packet 释放
        }
        else if( packet.stream_index == audioStream )
        {
            if (mIsAudioThreadFinished)
            { ///SDL没有打开，则音频数据直接释放
                av_packet_unref(&packet);
            }
            else
            {
                inputAudioQuene(packet);
                //这里我们将数据存入队列 因此不调用 av_free_packet 释放
            }

        }
        else
        {
            // Free the packet that was allocated by av_read_frame
            av_packet_unref(&packet);
        }
    }

    ///文件读取结束 跳出循环的情况
    ///等待播放完毕
    while (!mIsQuit)
    {
        mSleep(100);
    }

end:

    clearAudioQuene();
    clearVideoQuene();

    if (mPlayerState != VideoPlayer_Stop) //不是外部调用的stop 是正常播放结束
    {
        stop();
    }

    while((mVideoStream != nullptr && !mIsVideoThreadFinished) || (mAudioStream != nullptr && !mIsAudioThreadFinished))
    {
        mSleep(10);
    } //确保视频线程结束后 再销毁队列

    closeSDL();

    if (swrCtx != nullptr)
    {
        swr_free(&swrCtx);
        swrCtx = nullptr;
    }

    if (aFrame != nullptr)
    {
        av_frame_free(&aFrame);
        aFrame = nullptr;
    }

    if (aFrame_ReSample != nullptr)
    {
        av_frame_free(&aFrame_ReSample);
        aFrame_ReSample = nullptr;
    }

    if (aCodecCtx != nullptr)
    {
        avcodec_close(aCodecCtx);
        aCodecCtx = nullptr;
    }

    if (pCodecCtx != nullptr)
    {
        avcodec_close(pCodecCtx);
        pCodecCtx = nullptr;
    }

    avformat_close_input(&pFormatCtx);
    avformat_free_context(pFormatCtx);

    SDL_Quit();

    doPlayerStateChanged(VideoPlayer_Stop, mVideoStream != nullptr, mAudioStream != nullptr);

    mIsReadThreadFinished = true;

fprintf(stderr, "%s finished \n", __FUNCTION__);
}

bool VideoPlayer::inputVideoQuene(const AVPacket &pkt)
{
    if (av_dup_packet((AVPacket*)&pkt) < 0)
    {
        return false;
    }

    mConditon_Video->Lock();
    mVideoPacktList.push_back(pkt);
    mConditon_Video->Signal();
    mConditon_Video->Unlock();

    return true;
}

void VideoPlayer::clearVideoQuene()
{
    mConditon_Video->Lock();
    for (AVPacket pkt : mVideoPacktList)
    {
//        av_free_packet(&pkt);
        av_packet_unref(&pkt);
    }
    mVideoPacktList.clear();
    mConditon_Video->Unlock();
}

bool VideoPlayer::inputAudioQuene(const AVPacket &pkt)
{
    if (av_dup_packet((AVPacket*)&pkt) < 0)
    {
        return false;
    }

    mConditon_Audio->Lock();
    mAudioPacktList.push_back(pkt);
    mConditon_Audio->Signal();
    mConditon_Audio->Unlock();

    return true;
}

void VideoPlayer::clearAudioQuene()
{
    mConditon_Audio->Lock();
    for (AVPacket pkt : mAudioPacktList)
    {
//        av_free_packet(&pkt);
        av_packet_unref(&pkt);
    }
    mAudioPacktList.clear();
    mConditon_Audio->Unlock();
}

///当使用界面类继承了本类之后，以下函数不会执行

///打开文件失败
void VideoPlayer::doOpenVideoFileFailed(const int &code)
{
    fprintf(stderr, "%s \n", __FUNCTION__);

    if (mVideoPlayerCallBack != nullptr)
    {
        mVideoPlayerCallBack->onOpenVideoFileFailed(code);
    }

}

///打开sdl失败的时候回调此函数
void VideoPlayer::doOpenSdlFailed(const int &code)
{
    fprintf(stderr, "%s \n", __FUNCTION__);

    if (mVideoPlayerCallBack != nullptr)
    {
        mVideoPlayerCallBack->onOpenSdlFailed(code);
    }
}

///获取到视频时长的时候调用此函数
void VideoPlayer::doTotalTimeChanged(const int64_t &uSec)
{
    fprintf(stderr, "%s \n", __FUNCTION__);

    if (mVideoPlayerCallBack != nullptr)
    {
        mVideoPlayerCallBack->onTotalTimeChanged(uSec);
    }
}

///播放器状态改变的时候回调此函数
void VideoPlayer::doPlayerStateChanged(const VideoPlayerState &state, const bool &hasVideo, const bool &hasAudio)
{
    fprintf(stderr, "%s \n", __FUNCTION__);

    if (mVideoPlayerCallBack != nullptr)
    {
        mVideoPlayerCallBack->onPlayerStateChanged(state, hasVideo, hasAudio);
    }

}

///显示视频数据，此函数不宜做耗时操作，否则会影响播放的流畅性。
void VideoPlayer::doDisplayVideo(const uint8_t *yuv420Buffer, const int &width, const int &height)
{
//    fprintf(stderr, "%s \n", __FUNCTION__);
    if (mVideoPlayerCallBack != nullptr)
    {
        VideoFramePtr videoFrame = std::make_shared<VideoFrame>();

        VideoFrame * ptr = videoFrame.get();

        ptr->initBuffer(width, height);
        ptr->setYUVbuf(yuv420Buffer);

        mVideoPlayerCallBack->onDisplayVideo(videoFrame);
    }
}
