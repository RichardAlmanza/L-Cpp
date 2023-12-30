#include "fisica.h"

fisica::fisica()
{

}

fisica::fisica(double x, double y, double v, double ang, double rad, double masa, double fricc, double rest)
    :x(x),y(-y),V(v),V_i(v),vx(v*cos(ang)),vy(v*sin(ang)),m(masa),x_i(x),y_i(-y),vx_i(vx),vy_i(vy),r(rad),e(rest),k(fricc), alfa(ang), alfa_i(ang)
{
    k=((float(rand()%1001))/100000.0);
    acc=-(k*PI*pow(r,2)/m)*0.5;
    qDebug()<<acc;
    setPos(x,-y);
}

void fisica::calc_alfa()
{
    if(x-r<=0)
    {
        if(vx<0)
            vx=-vx*e;
        x=r;
    }
    if(x+r>=1000)
    {
        if(vx>0)
            vx=-vx*e;
        x=1000-r;
    }
    if(y+r>=0)
    {
        if(vy>0)
            vy=-vy*e;
        y=-r;
    }
    if(y-r<=-500)
    {
        if(vy<0)
            vy=-vy*e;
        y=-500+r;
    }

    alfa=atan2(vy,vx);
    V=pow(vx,2)+pow(vy,2);
    ax=acc*cos(alfa)*V;
    ay=acc*sin(alfa)*V;
    qDebug()<<"==============================>>"<<ax<<"====>>"<<vx<<"====>>"<<this;
}


void fisica::actualizar()
{
    calc_alfa();
    vx+=ax*delta;
    vy+=(ay-g)*delta;
    x+=(vx+0.5*ax*delta)*delta;
    y+=(vy+0.5*ay*delta)*delta;
    setPos(x,-y);
}

QRectF fisica::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void fisica::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    switch(int(m/100)%6)
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
