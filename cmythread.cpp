#include "cmythread.h"
CMyThread* CMyThread::pthread=nullptr;
CMyThread::CMyThread()
{
    this->m_i=0;
    this->m_BtnpauseState=false;
}

CMyThread::~CMyThread()
{
    delete CMyThread::pthread;
}

CMyThread* CMyThread::getInstance()
{
    if(CMyThread::pthread==nullptr)
    {
        CMyThread::pthread=new CMyThread();
    }
    return CMyThread::pthread;
}

void CMyThread::run()
{
    this->m_BtnpauseState=true;
    qDebug()<<QString("run :%1").arg(this->m_BtnpauseState);
    while(1)
    {
        this->m_mutex.lock();//锁
        this->m_i++;
        qDebug()<<"run m_i="<<this->m_i;
        this->m_mutex.unlock();//解锁
        emit sendWigt(this->m_i);//发送信号
        this->sleep(1);
    }

}

void CMyThread::threadStart()
{
    this->start();
}

void CMyThread::threadPause()
{
    if(this->m_BtnpauseState==true)//防止运行中直接按继续按钮误解锁
    {
        qDebug()<<QString("pause :%1").arg(this->m_BtnpauseState);
        this->m_mutex.lock();
        this->m_BtnpauseState=false;
        qDebug()<<QString("BtnPause");
    }
    else
    {
         qDebug()<<"不要重复按暂停";
    }
}

void CMyThread::threadContin()
{
    if(this->m_BtnpauseState==false)//防止运行中直接按继续按钮误解锁
    {
        qDebug()<<QString("Continue :%1").arg(this->m_BtnpauseState);
        this->m_mutex.unlock();
        this->m_BtnpauseState=true;
        qDebug()<<QString("Continue");
    }
    else{
        qDebug()<<"先按继续再暂停";
    }

}

void CMyThread::threadStop()
{
    this->m_i=0;//结束后再开始从0开始
    this->exit();
}

