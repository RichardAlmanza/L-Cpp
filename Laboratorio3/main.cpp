#include "encriptar.h"
#include "comparar.h"
main()
{
    bool band=true, metodo=true, proceso=true;
    char entrada;
    while(band)
    {
        cout<<"****************************************"<<endl;
        cout<<"1. Encriptar / Desencriptar"<<endl;
        cout<<"2. Comparar"<<endl;
        cout<<"****************************************"<<endl;
        cin>>entrada;
        cout<<endl<<endl;
        switch(entrada)
        {
            case '1':
                cout<<"*****************"<<endl;
                cout<<"1. Metodo 1"<<endl;
                cout<<"2. Metodo 2"<<endl;
                cout<<"*****************"<<endl;
                cin>>entrada;
                cout<<endl<<endl;
                if(entrada=='1')
                    metodo=true;
                else if(entrada=='2')
                    metodo=false;
                else
                    break;
                cout<<"*****************"<<endl;
                cout<<"1. Encriptar"<<endl;
                cout<<"2. Desencriptar"<<endl;
                cout<<"*****************"<<endl;
                cin>>entrada;
                cout<<endl<<endl;
                if(entrada=='1')
                    proceso=true;
                else if(entrada=='2')
                    proceso=false;
                else
                    break;
                encriptar(metodo, proceso);
                break;

            case '2':
                comparar();
                break;

            default:
                cout<<"Saliendo del programa"<<endl;
                band=false;
                break;
        }

    }
    return 0;
}
