#ifndef BUTTERFLY_H
#define BUTTERFLY_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>

class Butterfly : public QObject,public QGraphicsItem
{
    Q_OBJECT

public:
    Butterfly(QObject *parent = 0);

protected:
    QRectF boundingRect() const;
    void timerEvent(QTimerEvent *);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    bool up;
    QPixmap pix_up;            //用于表示两幅蝴蝶的图片
    QPixmap pix_down;
    qreal angle;
};

#endif // BUTTERFLY_H
