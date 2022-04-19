#ifndef CMYTHREAD_H
#define CMYTHREAD_H


#include <QThread>
#include <QMutex>
#include <QDebug>
//线程单例类
class CMyThread :public QThread
{
    Q_OBJECT
public:
    virtual ~CMyThread();
    static CMyThread* getInstance();

    void run();//重写run函数，线程执行函数
public slots:
    void threadStart();//线程启动函数
    void threadPause();//线程暂停
    void threadContin();//线程继续
    void threadStop();//线程结束
private:
    CMyThread();
    static CMyThread *pthread;
    int m_i;//++显示到界面的数
    QMutex m_mutex;//互斥量 暂停继续使用
    bool m_BtnpauseState;//点击暂停 状态1
signals:
    void sendWigt(int i);
};

#endif // CMYTHREAD_H
