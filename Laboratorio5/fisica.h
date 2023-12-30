#ifndef FISICA_H
#define FISICA_H
#include <math.h>
#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>
#define g 10 //0.0000000000667384
#define delta 0.01


class fisica: public QGraphicsItem
{
private:
    double acc=0;
    double x_i=0;
    double x=0;
    double y_i=0;
    double y=0;
    double vx_i=0;
    double vy_i=0;
    double vx=0;
    double vy=0;
    double V_i=0;
    double V=0;
    double alfa=0;
    double alfa_i=0;
    double ax=0;
    double ay=0;
    double m=1;
    double r=0;  //Radio de la esfera
    double k=0;  //Coeficiente de friccion
    double e=0;  //Coeficiente de Restitucion
    double PI=3.141598;

public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    fisica();
    fisica(double x, double y, double v, double ang, double rad, double masa, double fricc, double rest);
    void calc_alfa();
    void actualizar();
    ~fisica();
};

#endif // FISICA_H
