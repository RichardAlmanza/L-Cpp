#include "fisica.h"

fisica::fisica()
{

}


fisica::fisica(double x, double y, double vx, double vy, double m)
    :x(x),y(y),vx(vx),vy(vy),m(m),x_i(x),y_i(y),vx_i(vx),vy_i(vy)
{

}


/*fisica::fisica(double x, double y, double vx, double vy, double m, double delta)
    :x(x),y(y),vx(vx),vy(vy),m(m),delta(delta)
{

}
*/


double fisica::getx()
{
    return x;
}


double fisica::getx_i()
{
    return x_i;
}


double fisica::gety()
{
    return y;
}


double fisica::gety_i()
{
    return y_i;
}


double fisica::getvx_i()
{
    return vx_i;
}


double fisica::getvy_i()
{
    return vy_i;
}


double fisica::getvx()
{
    return vx;
}


double fisica::getvy()
{
    return vy;
}


double fisica::getax()
{
    return ax;
}


double fisica::getay()
{
    return ay;
}


double fisica::getm()
{
    return m;
}


double fisica::getalfa()
{
    return alfa;
}


void fisica::calc_a(fisica *arr, int size)
{
    double ang, dist;
    fisica *obj=nullptr;
    ax=0;
    ay=0;
    for(int i=0;i<size;i++)
    {
        obj=arr+i;
        if(this==obj)
            continue;
        dist=pow(obj->gety()-this->gety(),2)+pow(obj->getx()-this->getx(),2);
        ang=atan2((obj->gety())-(this->gety()),(obj->getx())-(this->getx()));
        ax+=g*(obj->getm())*cos(ang)/dist;
        ay+=g*(obj->getm())*sin(ang)/dist;
    }
}


void fisica::actualizar()
{
    //t++;
    vx+=ax*delta;
    vy+=ay*delta;
    x+=vx*delta;
    y+=vy*delta;
    alfa=atan2(vy,vx);
}


void fisica::inicial(double xx, double yy, double vxx, double vyy, double mm)
{
    x=xx;
    y=yy;
    vx=vxx;
    vy=vyy;
    m=mm;
    x_i=x;
    y_i=y;
    vx_i=vx;
    vy_i=vy;
    //t=0;
}


fisica::~fisica()
{

}
