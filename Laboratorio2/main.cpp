#include <iostream>
#include <string>
#include <math.h>

using namespace std;
void compare();
void stringanumero();
void sinrepe();
void separador();
void cuadromagico();
void rectangulos();
void malla();

int main()
{

    //compare();
    //stringanumero();
    //sinrepe();
    //separador();
    //cuadromagico();
    rectangulos();
    //malla();
    return 0;
}
unsigned long long int factorial(int a)
{
    unsigned long long int b=1;
    for(int i=a;i>1;i--)
        b=b*i;
    return b;
}

bool esta(char a, char *b, int size)
{
    for(int i=0; i<size; i++)
    {
        if(a==*(b+i))
            return true;
    }
    return false;
}

bool all(int *arr, int size)
{
    for(int i=0; i<size-1;i++)
    {
        if(*(arr+i)!=*(arr+i+1))
            return false;
    }
    return true;
}


void compare()
{
    char x[100]="", y[100]="";
    int counterx=0,countery=0;
    bool band=false;
    cout<<"Ingrese dos cadenas de texto"<<endl;
    cin>>x>>y;
    for(int i=0; i<100;i++)
    {
        if(*(x+i)==0)
            break;
        counterx++;
    }
    for(int i=0; i<100;i++)
    {
        if(*(y+i)==0)
            break;
        countery++;
    }
    if(counterx==countery)
    {
        for(int i=0;i<counterx;i++)
        {
            if(*(x+i)!=*(y+i))
            {
                cout<<"Son diferentes"<<endl;
                band=true;
                break;
            }
        }
        if(!band)
            cout<<"Son iguales"<<endl;
    }
    else
        cout<<"Son diferentes"<<endl;
}


void stringanumero()
{
    char x[100]="";
    int y=0, z=0;
    cout<<"Ingrese un numero"<<endl;
    cin>>x;
    for(int i=0;i<100;i++)
    {
        if(*(x+i)==0)
        {
            y=i;
            break;
        }
    }
    for(int i=0;i<y;i++)
    {
        z+=(*(x+i)-48)*(pow(10,y)/pow(10,i+1));
    }
    cout<<z/1<<endl;
}


void sinrepe()
{
    char x[100]="",letras[50]="";
    int counter=0, sizee;
    for(int i=0;i<100;i++)
    {
        if(*(x+i)==0)
        {
            sizee=i;
            break;
        }
    }
    cout<<"Ingrese una palabra"<<endl;
    cin>>x;
    cout<<"Original: "<<x<<endl;
    cout<<"Sin copias: ";
    for(int i=0;i<sizee;i++)
    {
        if(!esta(*(x+i),letras,50))
        {
            cout<<*(x+i);
            *(letras+counter)=*(x+i);
            counter++;
        }
    }
    cout<<endl;

}



void separador()
{
    string x,y,z;
    cout<<"Ingrese algo"<<endl;
    cin>>x;
    for(int i=0; i<x.size();i++)
    {
        if(x.at(i)<=57 && x.at(i)>=48)
            z+=x.at(i);
        else
            y+=x.at(i);
    }
    cout<<"Original: "<<x<<endl;
    cout<<"Texto: "<<y<<". Numeros: "<<z<<endl;
}



void cuadromagico()
{
    int n=0;
    cout<<"Ingrese el valor n de Rn para la matriz cuadrada"<<endl;
    cin>>n;
    int cuadrado[n][n], verificacion[2*n+2], counter=0;
    for(int i=2*n+2;i>0;i--)//Limpieza
        *(verificacion+i-1)=0;
    for(int xi=0; xi<n;xi++)//Procedimiento para llenar la matriz  xi-filas
    {
        cout<<"Fila "<<xi+1<<endl;
        for(int xp=0; xp<n; xp++)//xp-columnas
        {
            cout<<"Ingrese el termino "<<xp+1<<" de la fila "<<xi+1<<endl;
            cin>>*(*(cuadrado+xi)+xp);
            *(verificacion+counter)+=*(*(cuadrado+xi)+xp);//ingresa la suma de las filas
        }
        counter++;
    }
    for(int xi=0; xi<n;xi++)//Imprimir la matriz, xi-filas
    {
        cout<<'|';
        for(int xp=0; xp<n;xp++)//xp-columnas
        {
            cout<<*(*(cuadrado+xi)+xp)<<'|';
            *(verificacion+counter)+=*(*(cuadrado+xp)+xi);//xp-filas y xi-columnas  ingresa la suma de las columnas
        }
        counter++;
        cout<<endl;
    }
    for(int i=0; i<n;i++)
        *(verificacion+counter)+=*(*(cuadrado+i)+i);//suma de diagonal 1
    counter++;
    for(int xi=0; xi<n;xi++)
    {
        *(verificacion+counter)+=*(*(cuadrado+xi)+(n-xi-1));//suma diagonal 2
    }
    counter++;
    /*
    for(int i=0;i<counter;i++)
        cout<<*(verificacion+i)<<endl;
    */
    if(all(verificacion,2*n+2))
        cout<<"Si es un cuadrado magico"<<endl;
    else
        cout<<"No es un cuadrado magico"<<endl;
}


void rectangulos()
{
    int rec[4],rec2[4],rec3[4]={0,0,0,0},may,max;//[x1,y1,x2,y2]
    bool rr[4]={false,false,false,false};
    cout<<"Ingrese las coordenadas del rectangulo 1"<<endl;
    for(int i=0; i<4; i++)
        cin>>*(rec+i);
    cout<<"Ingrese las coordenadas del rectangulo 1"<<endl;
    for(int i=0; i<4; i++)
        cin>>*(rec2+i);
    if(*(rec+3)>*(rec2+3))
        may=*(rec+3);
    else
        may=*(rec2+3);
    if(*(rec+2)>*(rec2+2))
        max=*(rec+2);
    else
        max=*(rec2+2);
    char plano[may+1][max+1];
    for(int xi=0;xi<=may;xi++)//fila (y)
    {
        for(int xp=0;xp<=max;xp++)//columna (x)
        {
            *(*(plano+xi)+xp)='.';
        }
    }
    for(int xi=*(rec+1);xi<=*(rec+3);xi++)//fila (y)
    {
        for(int xp=*rec;xp<=*(rec+2);xp++)//columna (x)
        {
            *(*(plano+xi)+xp)='+';
        }
    }
    for(int xi=*(rec2+1);xi<=*(rec2+3);xi++)//fila (y)
    {
        for(int xp=*rec2;xp<=*(rec2+2);xp++)//columna (x)
        {
            if(*(*(plano+xi)+xp)=='+')
                *(*(plano+xi)+xp)='0';
            else
                *(*(plano+xi)+xp)='-';
        }
    }
    for(int xi=0;xi<=may;xi++)//fila (y)
    {
        for(int xp=0;xp<=max;xp++)//columna (x)
        {
            cout<<*(*(plano+xi)+xp);
        }
        cout<<endl;
    }
    int counter=0, counter2=1;
    for(int xi=0;xi<=may;xi++)//fila (y)
    {
        for(int xp=0;xp<=max;xp++)//columna (x)
        {
            if(*(*(plano+xi)+xp)=='0')
            {
                *(rec3+counter)=xp;
                *(rec3+counter2)=xi;
                *(rr+counter)=true;
                *(rr+counter2)=true;
                if(counter==0)
                {
                    counter=2;
                    counter2=3;
                }
            }
        }
    }
    if(*rec3==0&&*(rec3+1)==0&&*(rec3+2)==0&&*(rec3+3)==0)
        cout<<"No hay interseccion"<<endl;
    else
    {
        cout<<"Las coordenadas son "<<endl<<'[';
        for(int i=0;i<4;i++)
            cout<<*(rec3+i)<<',';
        cout<<']'<<endl;
        
    }
}


void malla()
{
    unsigned long long int ultra, low;
    unsigned long int mid;
    int n;
    cout<<"Ingrese el valor de n hasta el 10"<<endl;
    cin>>n;
    ultra=pow(factorial(n),2);
    low=factorial(2*n);
    low = low/ultra;
    cout<<"La malla es de "<<n<<'x'<<n<<" Y posee "<<low<<" caminos"<<endl;
    //(2n)!/(n!*n!)
}
