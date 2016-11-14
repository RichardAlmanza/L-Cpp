#include "refresh.h"

refresh::refresh()
{
    XX=0;
    YY=0;
    V=1;
    setOpacity(0.001);
    setPos(XX,YY);
}

void refresh::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;
    pen.setColor(Qt::white);pen.setWidth(1);pen.setBrush(Qt::white);
    painter->setPen(pen);
    painter->drawLine(QPoint(0,0),QPoint(1000,0));
}

QRectF refresh::boundingRect() const
{
    return QRectF(QPoint(0,0),QPoint(1000,0));
}

void refresh::actualizar()
{
    if(YY>=500 && V>0)
    {
        YY=0;
    }
    YY+=V;
    setPos(XX,YY);
}
