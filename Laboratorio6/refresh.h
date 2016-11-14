#ifndef REFRESH_H
#define REFRESH_H
#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>

class refresh : public QGraphicsItem
{
private:
    int XX=0;
    int YY=0;
    int V=0;
public:
    refresh();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    void actualizar();
};

#endif // REFRESH_H
