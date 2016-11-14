#include "pend.h"

Pend::Pend(double ang, double r, double xx, double yy, double vel)
    :alfa(ang),dist(r),x1(xx),y1(yy)
{
    v_angular=vel;
    x=dist*qCos(alfa)+x1;
    y=dist*qSin(alfa)+y1;
    setPos(x,y);
}

void Pend::actualizar()
{
    a=g*cos(alfa);
    v_angular+=a*delta;
    alfa+=(v_angular+a*delta*0.5)*delta;
    x=dist*qCos(alfa)+x1;
    y=dist*qSin(alfa)+y1;
    setPos(x,y);
}

QPoint *Pend::get_bola(){return new QPoint(x,y);}

double Pend::get_ang(){return qRadiansToDegrees(alfa);}

double Pend::get_dist(){return dist;}

QPoint *Pend::get_origen(){return new QPoint(x1,y1);}

QRectF Pend::boundingRect() const
{
    return QRectF(-10,-10,2*10,2*10);
}

void Pend::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    switch(int((int(dist)%15))%6)
    {
        case 0:
            painter->setBrush(Qt::black);
            break;
        case 1:
            painter->setBrush(Qt::cyan);
            break;
        case 2:
            painter->setBrush(Qt::red);
            break;
        case 3:
            painter->setBrush(Qt::magenta);
            break;
        case 4:
            painter->setBrush(Qt::green);
            break;
        case 5:
            painter->setBrush(Qt::yellow);
            break;
    }
    painter->drawEllipse(boundingRect());
}
