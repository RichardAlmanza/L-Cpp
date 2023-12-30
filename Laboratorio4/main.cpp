#include <iostream>
#include <fstream>
#include "fisica.h"

using namespace std;

int main()
{
    double datos[5];
    int size;
    ofstream file("Simulacion.txt", ios::out | ios::trunc);
    cout<<"Cuantos objetos desea ingresar al simulador fisico"<<endl;
    cin>>size;
    fisica *S1= new fisica[size];
    for(int i=0;i<size;i++)
    {
        cout<<"Ingrese cada uno de estos datos para el objeto "<<int(i+1)<<'.'<<endl;
        cout<<"Posicion en X"<<endl;cin>>*datos;
        cout<<"Posicion en Y"<<endl;cin>>*(datos+1);
        cout<<"Velocidad en X"<<endl;cin>>*(datos+2);
        cout<<"Velocidad en Y"<<endl;cin>>*(datos+3);
        cout<<"Masa del objeto en Kg"<<endl;cin>>*(datos+4);
        (S1+i)->inicial(*datos,*(datos+1),*(datos+2),*(datos+3),*(datos+4));
        file<<*datos<<char(9)<<*(datos+1)<<char(9);
    }
    for(int i=0;i<10000;i++)
    {
        file<<endl;
        for(int xi=0;xi<size;xi++)
        {
            (S1+xi)->calc_a(S1,size);
        }
        for(int xp=0;xp<size;xp++)
        {
            (S1+xp)->actualizar();
            file<<(S1+xp)->getx()<<char(9)<<(S1+xp)->gety()<<char(9);
        }
    }
    delete S1;
    cout<<"Ha terminado"<<endl;
    return 0;
}
