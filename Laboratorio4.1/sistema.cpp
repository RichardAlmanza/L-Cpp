#include "sistema.h"

void sistema::lectura(std::string fi)
{
    std::ifstream file;
    file.open(fi);
    bool band1=true, pass1=false; //band - "no ha terminado"
    char ch1;
    std::string temp1="", ingresar[5];
    int cont_words1=0;
    try
    {
        if(!file.is_open()) //  se valida que si se haya abierto el archivo
        {
        throw '1';           //  se arroja la excepción
        }
        for(int i=0; i<n;)
        {
            while(band1)
            {
                if(!file.good())
                {
                    band1=false;
                    break;
                }
                ch1=file.get();
                if(ch1!=10 && ch1!=32)
                {
                    temp1+=ch1;
                    pass1=true;
                }
                if(pass1 && (ch1==10 || ch1==32))
                {
                    *(ingresar+cont_words1)=temp1;
                    temp1="";
                    cont_words1++;
                    pass1=false;
                    break;
                }
            }
            if(cont_words1==5)
            {
                cont_words1=0;
                (cuerpo+n)->inicial(std::stod(*ingresar),std::stod(*(ingresar+1)),std::stod(*(ingresar+2)),std::stod(*(ingresar+3)),std::stod(*(ingresar+4)));
                i++;
            }
        }
    }
    catch(char c)
    {
        std::cout <<"Error # "<< c<<" :  " ;
        if(c=='1')
            std::cout <<"Error al abrir el archivo 1 para lectura"<< std::endl;
    }
    catch(...){
        std::cout <<"Error no definido"<<std::endl;
    }
    file.close();
}


sistema::sistema()
{

}


sistema::sistema(int cuerpos, std::string archivo)
    :n(cuerpos), fin_name(archivo)
{
    cuerpo=new fisica [n];
    lectura(fin_name);
}


void sistema::crear(int cuerpos, std::string archivo)
{
    n=cuerpos;
    fin_name=archivo;
    cuerpo=new fisica [n];
    lectura(fin_name);
}


void sistema::ejecutar(int veces, std::string archivo)
{
    times=veces;
    fout_name=archivo;
    fout.open(fout_name, std::ios::out | std::ios::trunc);
    for(int xp=0;xp<n;xp++)
    {
        fout<<(cuerpo+xp)->getx()<<char(9)<<(cuerpo+xp)->gety()<<char(9);
    }
    for(int i=0;i<times;i++)
    {
        fout<<std::endl;
        for(int xi=0;xi<n;xi++)
        {
            (cuerpo+xi)->calc_a(cuerpo,n);
        }
        for(int xp=0;xp<n;xp++)
        {
            (cuerpo+xp)->actualizar();
            fout<<(cuerpo+xp)->getx()<<char(9)<<(cuerpo+xp)->gety()<<char(9);
        }
    }
    fout.close();
}


sistema::~sistema()
{
    std::cout<<"El Sistema "<<fout_name<<" ha terminado."<<std::endl;
}
