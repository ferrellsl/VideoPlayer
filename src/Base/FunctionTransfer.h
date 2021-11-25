#ifndef FUNCTIONTRANSFER_H
#define FUNCTIONTRANSFER_H

#include  <functional>

#include <QThread>
#include <QObject>

//#ifdef QT_NO_KEYWORDS
//#define signals Q_SIGNALS
//#define slots Q_SLOTS
//#define emit Q_EMIT
//#endif

class FunctionTransfer : public QObject
{
    Q_OBJECT
public:

    ///@brief ���캯��
    explicit FunctionTransfer(QObject *parent = 0);
    ~FunctionTransfer();

    static void init(Qt::HANDLE id);
    static bool isMainThread();

public:
    ///@brief �ƶ�����f��main��ִ��
    static void runInMainThread(std::function<void()> f, bool isBlock = false);

private:
    static Qt::HANDLE gMainThreadId;

    //��ȫ��������ʵ����һ��FunctionTransfer��ʵ������ʵ�����ڵ��߳̾������̡߳�
    static FunctionTransfer *main_thread_forward;

Q_SIGNALS:
    ///@brief �ڱ���߳��к���������
    void comming(std::function<void()> f);
    void comming_noBlock(std::function<void()> f);

private Q_SLOTS:
    ///@brief ִ�к�������
    void slotExec(std::function<void()> f);

};

#endif // FUNCTIONTRANSFER_H
