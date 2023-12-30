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
    std::string fin_name;
    std::string fout_name;
    std::ifstream fin;
    std::ofstream fout;
    void lectura(std::string fi);

public:
    sistema();
    sistema(int cuerpos, std::string archivo);
    void crear(int cuerpos, std::string archivo);
    void ejecutar(int veces, std::string archivo);
    ~sistema();
};

#endif // SISTEMA_H
