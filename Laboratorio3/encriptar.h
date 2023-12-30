#ifndef ENCRIPTAR_H
#define ENCRIPTAR_H
#include <iostream>
#include <fstream>
using namespace std;
int encriptar(bool metod, bool proce);
void chartobin(int a, char*b);
char bintochar(char *b);
void invertir(int salto, int size_pack, char *b);
void contador(int &ceros, int &unos, int size_pack, char*b);
void mover(bool der, int size_pack, char *b);
#endif // ENCRIPTAR_H
