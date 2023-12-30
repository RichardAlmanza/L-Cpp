#ifndef FISICA_H
#define FISICA_H
#include <math.h>
#define g 1 //0.0000000000667384
#define delta 1

class fisica
{
private:
    double x_i=0;
    double x=0;
    double y_i=0;
    double y=0;
    double vx_i=0;
    double vy_i=0;
    double vx=0;
    double vy=0;
    double alfa=0;
    double ax=0;
    double ay=0;
    //double delta=1; double t=0;
    double m=1;

public:
    fisica();
    fisica(double x, double y, double vx, double vy, double m);
    //fisica(double x, double y, double vx, double vy, double m, double delta);
    double getx();
    double getx_i();
    double gety();
    double gety_i();
    double getvx_i();
    double getvy_i();
    double getvx();
    double getvy();
    double getax();
    double getay();
    double getm();
    double getalfa();
    void calc_a(fisica *arr, int size);
    void actualizar();
    void inicial(double xx, double yy, double vxx, double vyy, double mm);
    ~fisica();

};

#endif // FISICA_H
