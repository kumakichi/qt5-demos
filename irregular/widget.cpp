#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPixmap pix;
    pix.load(":/clock_200.png");//,0,Qt::AvoidDither|Qt::ThresholdAlphaDither|Qt::ThresholdDither);
    resize(pix.size());
    setMask(QBitmap(pix.mask()));
}

Widget::~Widget()
{

}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(Qt::LeftButton == event->button()) {
        dragPosition = event->globalPos()-frameGeometry().topLeft();
        event->accept();
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(Qt::LeftButton & event->buttons()) {
        move(event->globalPos()-dragPosition);
        event->accept();
    }
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    paint.drawPixmap(0,0,QPixmap(":/clock_200.png"));
}
