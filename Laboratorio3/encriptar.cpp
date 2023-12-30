#include "encriptar.h"
int encriptar(bool metod, bool proce)
{
    ifstream f_original;
    ofstream f_codificado;
    bool band=true; //band - "no ha terminado"
    char entrada[100], salida[100];
    int n=3, base_semilla=0, size_archivo=0, cont_ceros=0, cont_unos=0;
    cout<<"Ingrese el nombre del archivo a abrir"<<endl;
    cin>>entrada;
    cout<<"Ingrese el nombre del archivo a guardar(si existe se sobre escribira)"<<endl;
    cin>>salida;
    cout<<"Ingrese la semilla"<<endl;
    cin>>n;
    if(!(n%8)==0)
        base_semilla=8*n;
    else
        base_semilla=n;
    char *packbin = new char [base_semilla];
    for(int i = 0; i<base_semilla;i++)
        *(packbin+i)=0;
    try
    {
        f_original.open(entrada,ios::in | ios::binary); // se abre el archivo de para escribirlo
        f_codificado.open(salida,ios::out | ios::trunc | ios::binary);
        if(!f_original.is_open()) //  se valida que si se haya abierto el archivo
        {
        throw '1';           //  se arroja la excepción
        }
        if(!f_codificado.is_open()) //  se valida que si se haya abierto el archivo
        {
        throw '2';           //  se arroja la excepción
        }
        while(band)
        {
            for(int i=0;i<base_semilla;i+=8)  //llenar paquete de transison
            {
                if(!f_original.good())
                {
                    band=false;
                    base_semilla=i-8;// en el caso de que p sea 0 las condiciones de los for tampoco permitiran que se ejecute
                    break;
                }
                size_archivo++;//conteo de caracteres
                chartobin(f_original.get(),packbin+i);
            }
            for(int i=0; i<base_semilla; i+=n)  //aplicar encriptacion y desencriptacion
            {
                if(metod)  //metodo 1
                {
                    if(proce)
                    {
                        if(cont_ceros==cont_unos)
                        {
                            contador(cont_ceros,cont_unos,n,packbin+i);
                            invertir(1,n,packbin+i);
                        }
                        else if(cont_ceros>cont_unos)
                        {
                            contador(cont_ceros,cont_unos,n,packbin+i);
                            invertir(2,n,packbin+i);
                        }
                        else if(cont_unos>cont_ceros)
                        {
                            contador(cont_ceros,cont_unos,n,packbin+i);
                            invertir(3,n,packbin+i);
                        }
                    }
                    else
                    {
                        if(cont_ceros==cont_unos)
                        {
                            invertir(1,n,packbin+i);
                            contador(cont_ceros,cont_unos,n,packbin+i);
                        }
                        else if(cont_ceros>cont_unos)
                        {
                            invertir(2,n,packbin+i);
                            contador(cont_ceros,cont_unos,n,packbin+i);
                        }
                        else if(cont_unos>cont_ceros)
                        {
                            invertir(3,n,packbin+i);
                            contador(cont_ceros,cont_unos,n,packbin+i);
                        }
                    }

                }
                else  //metodo 2
                {
                    if(!band && (i+n<base_semilla))
                        n=base_semilla-i;
                    if(proce)
                    {
                        mover(true,n,packbin+i);
                    }
                    else
                    {
                        mover(false,n,packbin+i);
                    }
                }
            }
            for(int i=0; i<base_semilla; i+=8)  //guardar los caracteres encriptados
                f_codificado<<bintochar(packbin+i);
        }
        f_original.close();
        f_codificado.close();
        cout<<"Ha finalizado exitosamente - El archivo contiene "<<size_archivo<<" caracteres."<<endl<<endl<<endl;
    }
    catch(char c)
    {
        cout <<"Error # "<< c<<" :  " ;
        if(c=='1')
            cout <<"Error al abrir el archivo para lectura"<< endl;
        else if (c=='2')
            cout << "Error al crear archivo de escritura"<<endl;
    }
    catch(...){
        cout <<"Error no definido"<<endl;
    }
    return 0;
}


void chartobin(int a,char *b)
{
    if(a<0)
        a+=256;
    int valores[8]={128,64,32,16,8,4,2,1};
    for(int i=0;i<8;i++)
    {
        if((a-*(valores+i))>=0)
        {
            a-=*(valores+i);
            *(b+i)='1';
        }
        else
        {
            *(b+i)='0';
        }
    }
}


char bintochar(char *b)
{
    int valores[8]={128,64,32,16,8,4,2,1}, salida=0;
    for(int i=0;i<8;i++)
    {
        if(*(b+i)=='1')
        {
            salida+=*(valores+i);
        }
    }
    if(salida-128>0)
        salida-=256;
    return salida;
}


void invertir(int salto, int size_pack,char *b)
{
    for(int h=salto-1; h<size_pack; h+=salto)
    {
        if(*(b+h)=='1')
            *(b+h)='0';
        else if(*(b+h)=='0')
            *(b+h)='1';
    }
}


void contador(int &ceros, int &unos, int size_pack, char *b)
{
    ceros=0;
    unos=0;
    for(int h=0; h<size_pack; h++)
    {
        if(*(b+h)=='1')
            unos++;
        else if(*(b+h)=='0')
            ceros++;
    }
}


void mover(bool der,int size_pack,char *b)
{
    char temp;
    if(der)
    {
        temp=*(b+size_pack-1);
        for(int i=size_pack-1;i>=1;i--)
            *(b+i)=*(b+i-1);
        *b=temp;
    }
    else
    {
        temp=*b;
        for(int i=0;i<size_pack-1;i++)
            *(b+i)=*(b+i+1);
        *(b+size_pack-1)=temp;
    }
}
