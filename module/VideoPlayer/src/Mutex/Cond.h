#ifndef COND_H
#define COND_H

/// ע��Mingw�Ļ�ʹ�õ���linux�µ�api pthread
/// û��_MSC_VER����� ���Ǿ���Ϊ���õ���mingw������

#ifndef _MSC_VER
#define MINGW
#endif

#if defined(WIN32) && !defined(MINGW)
    #include <WinSock2.h>
    #include <Windows.h>
#else
    #include <pthread.h>
    #include <time.h>
#endif

class Cond
{
public:
    Cond();
    ~Cond();

    //����
    int Lock();

    //����
    int Unlock();

    //
    int Wait();

    //�̶�ʱ��ȴ�
    int TimedWait(int second);

    //
    int Signal();

    //��������˯���߳�
    int Broadcast();

private:

#if defined(WIN32) && !defined(MINGW)
    CRITICAL_SECTION m_mutex;
    RTL_CONDITION_VARIABLE m_cond;
#else
    pthread_mutex_t m_mutex;
    pthread_cond_t m_cond;
#endif

};

#endif // MUTEX_H
