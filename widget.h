#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include "cmythread.h"
#include <QString>
/*题目：通过点击四个按钮控制线程的开始暂停，体现在lcd数字显示上*/
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    //重绘事件：更新页面
    void paintEvent(QPaintEvent *event);
private slots:


    void on_BtnStart_clicked();

    void on_BtnEnd_clicked();

    void on_BtnPause_clicked();

    void on_BtnContin_clicked();

private:
    Ui::Widget *ui;
    CMyThread *thread;
    QString str;

public slots:
    void updateUIslot(int i);
};

#endif // WIDGET_H
