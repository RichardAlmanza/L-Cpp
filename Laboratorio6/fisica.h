#ifndef FISICA_H
#define FISICA_H
#include <math.h>
#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>
#include <list>
#define g 1
#define delta 0.1


class fisica: public QGraphicsItem
{
private:
    double x=0;
    double y=0;
    double vx=0;
    double vy=0;
    double ax=0;
    double ay=0;
    double m=1;
    double r=0;  //Radio de la esfera

public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    fisica();
    fisica(double xx, double yy, double masa,double rad, double vvx, double vvy);
    double getx();
    double gety();
    double getm();
    void save(QTextStream *out);
    void calc_a(std::list <fisica*> *arr);
    void actualizar();
    ~fisica();
};

#endif // FISICA_H
