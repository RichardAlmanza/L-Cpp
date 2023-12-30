#include <iostream>
#include <fstream>
#include "sistema.h"

using namespace std;

int main()
{
    int size, objetos;
    string nombre;
    sistema *conjunto=nullptr;
    cout<<"Orden del contenido de los archivos"<<endl;
    cout<<"PosX   PosY   VelX   VelY   Masa"<<endl;
    cout<<"Cuantos Sistemas desea simular?"<<endl;
    cin>>size;
    conjunto= new sistema[size];
    for(int i=0;i<size;i++)
    {
        cout<<"Ingrese cada uno de estos datos para el sistema "<<int(i+1)<<'.'<<endl;
        cout<<"Nombre del archivo"<<endl;cin>>nombre;
        cout<<"Cantidad e cuerpos"<<endl;cin>>objetos;
        (conjunto+i)->crear(objetos,nombre);
    }
    for(int i=0;i<size;i++)
    {
        cout<<"Ingrese cada uno de los siguientes datos para el sistema"<<int(i+1)<<'.'<<endl;
        cout<<"Nombre del archivo de salida"<<endl;cin>>nombre;
        cout<<"Cantidad de ejecuciones"<<endl;cin>>objetos;
        (conjunto+i)->ejecutar(objetos,nombre);
        delete (conjunto+i);
    }
    return 0;
}
