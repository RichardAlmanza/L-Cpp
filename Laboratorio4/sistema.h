#ifndef SISTEMA_H
#define SISTEMA_H
#include <iostream>
#include <fstream>
#include <string>
#include "fisica.h"

class sistema
{
private:
    int n=0;
    int times=0;
    fisica *cuerpo=nullptr;
    std::string fin;
    std::string fout;

public:
    sistema();
    sistema(int cuerpos, std::string archivo);
    void crear(int cuerpos, std::string archivo);
    void ejecutar(int veces, std::string archivo);
    ~sistema();
};

#endif // SISTEMA_H
