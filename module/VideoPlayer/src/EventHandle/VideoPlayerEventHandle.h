#ifndef VIDEOPLAYEREVENTHANDLE_H
#define VIDEOPLAYEREVENTHANDLE_H

#include "types.h"
#include "VideoPlayer/Video/VideoFrame.h"

class VideoPlayerCallBack
{
public:
    ~VideoPlayerCallBack();

    ///���ļ�ʧ��
    virtual void onOpenVideoFileFailed(const int &code = 0) = 0;

    ///��sdlʧ�ܵ�ʱ��ص��˺���
    virtual void onOpenSdlFailed(const int &code) = 0;

    ///��ȡ����Ƶʱ����ʱ����ô˺���
    virtual void onTotalTimeChanged(const int64_t &uSec) = 0;

    ///������״̬�ı��ʱ��ص��˺���
    virtual void onPlayerStateChanged(const VideoPlayerState &state, const bool &hasVideo, const bool &hasAudio) = 0;

    ///������Ƶ���˺�����������ʱ�����������Ӱ�첥�ŵ������ԡ�
    virtual void onDisplayVideo(VideoFramePtr videoFrame) = 0;

};

#endif // VIDEOPLAERYEVENTHANDLE_H
