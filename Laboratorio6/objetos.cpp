#include "objetos.h"


Objetos::Objetos(Pend *padre)
    :super(padre)
{
    PO=super->get_origen();
    PF=super->get_bola();
    setTransformOriginPoint((*PO));
    adap=false;
    if(PO->x()>PF->x())
    {
        adap=true;
    }
}

QRectF Objetos::boundingRect() const
{
    return QRectF((*PO),(*PF));
}

void Objetos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;
    pen.setColor(Qt::black);pen.setWidth(3);pen.setStyle(Qt::DotLine);
    painter->setPen(pen);
    if(adap)
    {
        painter->drawLine((*PO),QPoint(PO->x()-super->get_dist(),PO->y()));
    }
    else
    {
        painter->drawLine((*PO),QPoint(PO->x()+super->get_dist(),PO->y()));
    }
}

void Objetos::girar()
{
    setRotation(super->get_ang());
    if(adap)
        setRotation(super->get_ang()-180);
}
