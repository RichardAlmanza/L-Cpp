#include "comparar.h"
void comparar()
{
    ifstream f_1, f_2;
    bool band1=true, band2=true, pass1=false, pass2=false; //band - "no ha terminado"
    char entrada[100], salida[100], ch1, ch2;
    string temp1="", temp2="";
    int size_archivo1=0, size_archivo2=0, cont_words1=0, cont_words2=0;
    cout<<"Ingrese el nombre del primer archivo a abrir"<<endl;
    cin>>entrada;
    cout<<"Ingrese el nombre del segundo archivo a abrir"<<endl;
    cin>>salida;
    try
    {
        f_1.open(entrada,ios::in | ios::binary); // se abre el archivo de para escribirlo
        f_2.open(salida,ios::in | ios::binary);
        if(!f_1.is_open()) //  se valida que si se haya abierto el archivo
        {
        throw '1';           //  se arroja la excepción
        }
        if(!f_2.is_open()) //  se valida que si se haya abierto el archivo
        {
        throw '2';           //  se arroja la excepción
        }
        while(band1 && band2)
        {
            while(true)
            {
                if(!f_1.good())
                {
                    band1=false;
                    break;
                }
                else
                    size_archivo1++;
                ch1=f_1.get();
                if(ch1!=10 && ch1!=32)
                {
                    temp1+=ch1;
                    pass1=true;
                }
                if(pass1 && (ch1==10 || ch1==32))
                {
                    pass1=false;
                    cont_words1++;
                    break;
                }
            }
            while(true)
            {
                if(!f_2.good())
                {
                    band2=false;
                    break;
                }
                else
                    size_archivo2++;
                ch2=f_2.get();
                if(ch2!=10 && ch2!=32)
                {
                    temp2+=ch2;
                    pass2=true;
                }
                if(pass2 && (ch2==10 || ch2==32))
                {
                    pass2=false;
                    cont_words2++;
                    break;
                }
            }
            if(temp1==temp2 && temp1!="")
            {
                cout<<'\"'<<temp1<<"\" Y \""<<temp2<<"\" Son iguales"<<endl;
                temp1=""; temp2="";

            }
            else if(temp1!=temp2)
            {
                cout<<'\"'<<temp1<<"\" Y \""<<temp2<<"\" Son diferentes  <-------||"<<endl;
                temp1=""; temp2="";
            }
        }
        cout<<"Se leyo"<<cont_words1<<" palabras en el archivo 1"<<endl;
        cout<<"Se leyo"<<cont_words2<<" palabras en el archivo 2"<<endl;
    }
    catch(char c)
    {
        cout <<"Error # "<< c<<" :  " ;
        if(c=='1')
            cout <<"Error al abrir el archivo 1 para lectura"<< endl;
        else if (c=='2')
            cout << "Error al abrir el archivo 2 para lectura"<<endl;
    }
    catch(...){
        cout <<"Error no definido"<<endl;
    }
}
