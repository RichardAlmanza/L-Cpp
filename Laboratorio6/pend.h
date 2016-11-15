#ifndef PEND_H
#define PEND_H
#include <QtMath>
#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>
#define g 9.8
#define delta 0.0002


class Pend : public QGraphicsItem
{
private:
    double x1=0;
    double y1=0;
    double x=0;
    double y=0;
    double dist=0;
    double alfa=0;
    double v_angular=0;
    double a=0;

public:
    Pend(double ang, double r, double xx, double yy, double vel);
    void actualizar();
    QPoint *get_origen();
    double get_ang();
    double get_dist();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PEND_H
