/**
 * Ҷ����
 * QQȺ121376426
 * http://blog.yundiantech.com/
 */

#include "VideoPlayer/VideoPlayer.h"

void VideoPlayer::decodeVideoThread()
{
    fprintf(stderr, "%s start \n", __FUNCTION__);

    mIsVideoThreadFinished = false;

    int videoWidth  = 0;
    int videoHeight =  0;

    double video_pts = 0; //��ǰ��Ƶ��pts
    double audio_pts = 0; //��Ƶpts

    ///������Ƶ���
    AVFrame *pFrame = nullptr;
    AVFrame *pFrameYUV = nullptr;
    uint8_t *yuv420pBuffer = nullptr; //������yuv����
    struct SwsContext *imgConvertCtx = nullptr;  //���ڽ�������Ƶ��ʽת��

    AVCodecContext *pCodecCtx = mVideoStream->codec; //��Ƶ������

    pFrame = av_frame_alloc();

    while(1)
    {
        if (mIsQuit)
        {
            clearVideoQuene(); //��ն���
            break;
        }

        if (mIsPause == true) //�ж���ͣ
        {
            mSleep(10);
            continue;
        }

        mConditon_Video->Lock();

        if (mVideoPacktList.size() <= 0)
        {
            mConditon_Video->Unlock();
            if (mIsReadFinished)
            {
                //��������û���������Ҷ�ȡ�����
                break;
            }
            else
            {
                mSleep(1); //����ֻ����ʱû�����ݶ���
                continue;
            }
        }

        AVPacket pkt1 = mVideoPacktList.front();
        mVideoPacktList.pop_front();

        mConditon_Video->Unlock();

        AVPacket *packet = &pkt1;

        //�յ�������� ˵���ո�ִ�й���ת ������Ҫ�ѽ����������� ���һ��
        if(strcmp((char*)packet->data, FLUSH_DATA) == 0)
        {
            avcodec_flush_buffers(mVideoStream->codec);
            av_packet_unref(packet);
            continue;
        }

        if (avcodec_send_packet(pCodecCtx, packet) != 0)
        {
           qDebug("input AVPacket to decoder failed!\n");
           av_packet_unref(packet);
           continue;
        }

        while (0 == avcodec_receive_frame(pCodecCtx, pFrame))
        {
            if (packet->dts == AV_NOPTS_VALUE && pFrame->opaque&& *(uint64_t*) pFrame->opaque != AV_NOPTS_VALUE)
            {
                video_pts = *(uint64_t *) pFrame->opaque;
            }
            else if (packet->dts != AV_NOPTS_VALUE)
            {
                video_pts = packet->dts;
            }
            else
            {
                video_pts = 0;
            }

            video_pts *= av_q2d(mVideoStream->time_base);
            video_clock = video_pts;
    //OUTPUT("%s %f \n", __FUNCTION__, video_pts);
            if (seek_flag_video)
            {
                //��������ת �������ؼ�֡��Ŀ��ʱ����⼸֡
               if (video_pts < seek_time)
               {
                   av_packet_unref(packet);
                   continue;
               }
               else
               {
                   seek_flag_video = 0;
               }
            }

            ///����Ƶͬ����ʵ�ֵ�ԭ����ǣ��ж��Ƿ���ʾ��֡ͼ���ʱ���ˣ�û��������5ms��Ȼ������ж�
            while(1)
            {
                if (mIsQuit)
                {
                    break;
                }

                if (mAudioStream != NULL && !mIsAudioThreadFinished)
                {
                    if (mIsReadFinished && mAudioPacktList.size() <= 0)
                    {//��ȡ���� ����Ƶ����Ҳ�������� ��ʣ����Ƶ������  ֱ����ʾ������ ����ͬ����
                        break;
                    }

                    ///����Ƶ������£�����Ƶͬ������Ƶ
                    ///����Ƶ��pts���Աȣ�����Ƶ��������ʱ
                    audio_pts = audio_clock;
                }
                else
                {
                    ///û����Ƶ������£�ֱ��ͬ�����ⲿʱ��
                    audio_pts = (av_gettime() - mVideoStartTime) / 1000000.0;
                    audio_clock = audio_pts;
                }

    //OUTPUT("%s %f %f \n", __FUNCTION__, video_pts, audio_pts);
                //��Ҫ�� ��ת��ʱ�� ���ǰ�video_clock���ó�0��
                //���������Ҫ����video_pts
                //���򵱴Ӻ�����ת��ǰ���ʱ�� �Ῠ������
                video_pts = video_clock;

                if (video_pts <= audio_pts) break;

                int delayTime = (video_pts - audio_pts) * 1000;

                delayTime = delayTime > 5 ? 5:delayTime;

                if (!mIsNeedPause)
                {
                    mSleep(delayTime);
                }
            }

            if (pCodecCtx->width != videoWidth || pCodecCtx->height != videoHeight)
            {
                videoWidth  = pFrame->width;
                videoHeight = pFrame->height;

                if (pFrameYUV != nullptr)
                {
                    av_free(pFrameYUV);
                }

                if (yuv420pBuffer != nullptr)
                {
                    av_free(yuv420pBuffer);
                }

                if (imgConvertCtx != nullptr)
                {
                    sws_freeContext(imgConvertCtx);
                }

                pFrameYUV = av_frame_alloc();

                int yuvSize = av_image_get_buffer_size(AV_PIX_FMT_YUV420P, pCodecCtx->width, pCodecCtx->height, 1);  //��1�ֽڽ����ڴ����,�õ����ڴ��С��ӽ�ʵ�ʴ�С
            //    int yuvSize = av_image_get_buffer_size(AV_PIX_FMT_YUV420P, pCodecCtx->width, pCodecCtx->height, 0);  //��0�ֽڽ����ڴ���룬�õ����ڴ��С��0
            //    int yuvSize = av_image_get_buffer_size(AV_PIX_FMT_YUV420P, pCodecCtx->width, pCodecCtx->height, 4);   //��4�ֽڽ����ڴ���룬�õ����ڴ��С��΢��һЩ

                unsigned int numBytes = static_cast<unsigned int>(yuvSize);
                yuv420pBuffer = static_cast<uint8_t *>(av_malloc(numBytes * sizeof(uint8_t)));
                av_image_fill_arrays(pFrameYUV->data, pFrameYUV->linesize, yuv420pBuffer, AV_PIX_FMT_YUV420P, pCodecCtx->width, pCodecCtx->height, 1);

                ///���ڽ��������ݲ�һ������yuv420p�������Ҫ������������ͳһת����YUV420P
                imgConvertCtx = sws_getContext(pCodecCtx->width, pCodecCtx->height,
                        pCodecCtx->pix_fmt, pCodecCtx->width, pCodecCtx->height,
                        AV_PIX_FMT_YUV420P, SWS_BICUBIC, NULL, NULL, NULL);

            }

            sws_scale(imgConvertCtx,
                    (uint8_t const * const *) pFrame->data,
                    pFrame->linesize, 0, pCodecCtx->height, pFrameYUV->data,
                    pFrameYUV->linesize);

            doDisplayVideo(yuv420pBuffer, pCodecCtx->width, pCodecCtx->height);

            if (mIsNeedPause)
            {
                mIsPause = true;
                mIsNeedPause = false;
            }

        }
        av_packet_unref(packet);
    }

    av_free(pFrame);

    if (pFrameYUV != nullptr)
    {
        av_free(pFrameYUV);
    }

    if (yuv420pBuffer != nullptr)
    {
        av_free(yuv420pBuffer);
    }

    if (imgConvertCtx != nullptr)
    {
        sws_freeContext(imgConvertCtx);
    }

    if (!mIsQuit)
    {
        mIsQuit = true;
    }

    mIsVideoThreadFinished = true;

    fprintf(stderr, "%s finished \n", __FUNCTION__);

    return;
}
