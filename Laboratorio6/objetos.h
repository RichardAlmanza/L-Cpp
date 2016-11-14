#ifndef OBJETOS_H
#define OBJETOS_H
#include <QGraphicsItem>
#include <QPainter>
#include "pend.h"
#include <QDebug>

class Objetos: public QGraphicsItem
{
private:
    Pend *super;
    QPoint *PO,*PF;
    bool adap;
public:
    Objetos(Pend *padre=Q_NULLPTR);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void girar();
};

#endif // OBJETOS_H
