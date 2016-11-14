#include "fisica.h"

fisica::fisica()
{

}

fisica::fisica(double xx, double yy, double masa, double rad, double vvx, double vvy)
    :x(xx),y(-yy),vx(vvx),vy(-vvy),m(masa),r(rad)
{
    qDebug()<<x<<"  "<<y<<"  "<<m<<"  "<<r<<"  "<<vx<<"  "<<vy;
    setPos(x,y);
}
double fisica::getx(){return x;}
double fisica::gety(){return y;}
double fisica::getm(){return m;}

void fisica::save(QTextStream *out)
{
    *out<<x<<','<<-y<<','<<m<<','<<r<<','<<vx<<','<<-vy<<','<<'\n';
}

void fisica::calc_a(std::list<fisica *> *arr)
{
    double ang, dist;
    ax=0;
    ay=0;
    for(std::list<fisica*>::iterator it=arr->begin(); it!=arr->end();++it)
    {
        if((*it)==this)
            continue;
        dist=pow((*it)->gety()-this->gety(),2)+pow((*it)->getx()-this->getx(),2);
        ang=atan2(((*it)->gety())-(this->gety()),((*it)->getx())-(this->getx()));
        ax+=g*((*it)->getm())*cos(ang)/dist;
        ay+=g*((*it)->getm())*sin(ang)/dist;
    }
}


void fisica::actualizar()
{
    vx+=ax*delta;
    vy+=ay*delta;
    x+=(vx+0.5*ax*delta)*delta;
    y+=(vy+0.5*ay*delta)*delta;
    setPos(x,y);
}

QRectF fisica::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void fisica::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    switch(int(m)%6)
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

fisica::~fisica()
{

}
