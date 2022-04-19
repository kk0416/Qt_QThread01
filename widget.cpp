#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //创建线程对象
    this->thread=CMyThread::getInstance();
    connect(this->thread,SIGNAL(sendWigt(int)),this,SLOT(updateUIslot(int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    ui->LcdNum->display(str);
}


void Widget::on_BtnStart_clicked()
{
    this->thread->threadStart();
}

void Widget::on_BtnEnd_clicked()
{
    this->thread->terminate();
    this->thread->threadStop();
}

void Widget::on_BtnPause_clicked()
{
    this->thread->threadPause();
}

void Widget::on_BtnContin_clicked()
{
    this->thread->threadContin();
}

void Widget::updateUIslot(int i)
{
    this->str=QString::number(i);//将线程里的num传过来
    this->update();//触发重绘事件，刷新界面
}
