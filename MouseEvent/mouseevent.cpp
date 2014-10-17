#include "mouseevent.h"

MouseEvent::MouseEvent(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("鼠标事件"));
    buildStatusBar();
    this->setMouseTracking(true);
    resize(400,200);
}

void MouseEvent::buildStatusBar()
{
    statusLabel = new QLabel;
    statusLabel->setText(tr("当前位置："));
    statusLabel->setFixedWidth(100);

    MousePosLabel = new QLabel;
    MousePosLabel->setText(tr("Ready"));
    MousePosLabel->setFixedWidth(100);

    statusBar()->addPermanentWidget(statusLabel);
    statusBar()->addPermanentWidget(MousePosLabel);
}

MouseEvent::~MouseEvent()
{
}

void MouseEvent::mousePressEvent(QMouseEvent *e)
{
    QString str="("+QString::number(e->x())+","+QString::number(e->y())+")";

    switch (e->button()) {
    case Qt::LeftButton:
        statusBar()->showMessage(tr("左键：")+str);
        break;
    case Qt::RightButton:
        statusBar()->showMessage(tr("右键：")+str);
        break;
    case Qt::MidButton:
        statusBar()->showMessage(tr("中键：")+str);
        break;
    default:
        break;
    }
}

void MouseEvent::mouseMoveEvent(QMouseEvent *e)
{
    MousePosLabel->setText("("+QString::number(e->x())+", "+QString::number(e->y())+")");
}

void MouseEvent::mouseReleaseEvent(QMouseEvent *e)
{
    QString str="("+QString::number(e->x())+","+QString::number(e->y())+")";
    statusBar()->showMessage(tr("释放在：")+str,3000);
}

void MouseEvent::mouseDoubleClickEvent(QMouseEvent *e)
{
    MousePosLabel->setText("双击");
}
