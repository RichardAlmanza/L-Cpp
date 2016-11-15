#include "objetos.h"


Objetos::Objetos(Pend *padre)
    :super(padre)
{
    PO=super->get_origen();
    setTransformOriginPoint((*PO));
}

QRectF Objetos::boundingRect() const
{
    return QRectF(QPoint(PO->x(),PO->y()-1),QPoint(PO->x()+super->get_dist(),PO->y()+1));
}

void Objetos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;QBrush brush;
    pen.setColor(Qt::darkBlue);pen.setWidth(0);pen.setStyle(Qt::SolidLine);
    brush.setColor(Qt::darkBlue);brush.setStyle(Qt::VerPattern);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawRoundRect(boundingRect());
    setRotation(super->get_ang());
}

void Objetos::girar()
{
    setRotation(super->get_ang());
}
