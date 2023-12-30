#include <iostream>

void rombo();
void euler();
void elevado();
void secuencia();
void factorprimo();
void primosuma();
void collatz();

int main()
{
    char entrada;
    while(true)
    {
        std::cout<<"*********************************************"<<std::endl<<std::endl;
        std::cout<<"1. Imprimir un patron tipo rombo"<<std::endl;
        std::cout<<"2. Valor aproximado de euler"<<std::endl;
        std::cout<<"3. Suma de los digitos elevados por si mismos"<<std::endl;
        std::cout<<"4. Imprimir el enesimo termino de los numero primos"<<std::endl;
        std::cout<<"5. Imprimir el maximo factor primo"<<std::endl;
        std::cout<<"6. Imprimir la suma de los primos menores a un numero"<<std::endl;
        std::cout<<"7. Serie Collatz"<<std::endl<<std::endl;
        std::cout<<"*********************************************"<<std::endl<<"Ingrese x para salir"<<std::endl<<std::endl;
        std::cout<<"Ingrese el numero correspondiente al programa que desee ejecutar"<<std::endl;
        std::cin>>entrada;
        std::cout<<std::endl<<std::endl;
        switch (entrada) {
        case '1':
            rombo();
            break;
        case '2':
            euler();
            break;
        case '3':
            elevado();
            break;
        case '4':
            secuencia();
            break;
        case '5':
            factorprimo();
            break;
        case '6':
            primosuma();
            break;
        case '7':
			collatz();
            break;
        case 'x':
            std::cout<<"Saliendo del programa"<<std::endl;
            break;
        case 'X':
            std::cout<<"Saliendo del programa"<<std::endl;
            break;
        default:
            std::cout<<"Esta opcion no se encuentra disponible"<<std::endl;
            break;
        }
        if(entrada=='x' || entrada=='X')
            break;
        std::cout<<std::endl<<std::endl;


    }
    return 0;
}


/**
 * @brief factorial
 * @param a
 * @return
 */
float factorial(int a)
{
    if(a<2)
        return 1.0;
    for(int i=a;i>=2;)
    {
        a*=--i;
    }
    return a;
}


///
/// \brief pote
/// \param a
/// \param b
/// \return
///
int pote(int a, int b)
{
    int c=1;
    for(int i=0;i<b;i++)
    {
        c*=a;
    }
    return c;
}


/**
 * @brief esprimo
 * @param a
 * @return
 */
bool esprimo(int a)
{
    int b=(a/2)+1;
    if(a==2)
        return true;
    for(int i=2;i<b;i++)
    {
        if(a%i==0)
            return false;
    }
    return true;
}


///
/// \brief rombo
///
void rombo()//Problema 5 - Imprimir un patron tipo rombo
{
    unsigned int linea;
    char A,B;
    unsigned short int count=0, AA,BB;
    std::cout<<"Ingrese un numero impar:"<<std::endl;
    std::cin>>linea;
    std::cout<<"Ingrese un caracter para el espaciado"<<std::endl;
    std::cin>>A;
    std::cout<<"Ingrese un caracter para el relleno"<<std::endl;
    std::cin>>B;
    if((linea%2)==0)
        linea++;
    for(unsigned int i=1;i<=(linea/2)+1;i++)
    {
        AA=linea/2-count;
        BB=i*2-1;
        for(int p=0;p<AA;p++)
            std::cout<<A;
        for(int p=0;p<BB;p++)
            std::cout<<B;
        for(int p=0;p<AA;p++)
            std::cout<<A;
        std::cout<<std::endl;
        count++;
    }
    count=1;
    for(unsigned int i=linea/2;i>=1;i--)
    {
        BB=i*2-1;
        for(int p=0;p<count;p++)
            std::cout<<A;
        for(int p=0;p<BB;p++)
            std::cout<<B;
        for(int p=0;p<count;p++)
            std::cout<<A;
        std::cout<<std::endl;
        count++;
    }
}


///
/// \brief euler
///
void euler()//Problema 6 - Valor aproximado de euler
{
    int a=1;
    float e=0.0;
    std::cout<<"Ingrese un numero entero para la precision de euler"<<std::endl;
    std::cin>>a;
    for(float i=0.0;i<a;i+=1.0)
    {
        e+=(1/factorial(i));
    }
    std::cout<<"Segun la precision que pidio el numero aproximado a euler es "<<e<<std::endl;
}


///
/// \brief elevado
///
void elevado()//Problema 9 - Suma de los digitos elevados por si mismos
{
    int num=0, valor=0, sum=0;
    std::cout<<"Ingrese un entero"<<std::endl;
    std::cin>>num;
    valor=num;
    while(valor>0)
    {
        num=valor%10;
        sum+=pote(num,num);
        valor/=10;
    }
    std::cout<<"la suma de los digitos elevador por si mismos es "<<sum<<std::endl;
}


///
/// \brief secuencia
///
void secuencia()//Problema 10 - Imprimir el enesimo termino de los numero primos
{
    int counter=1, n=0, primo=2, variante=1;
    std::cout<<"Ingrese el numero enesimo"<<std::endl;
    std::cin>>n;
    if(n>2)
    {
        primo=3;
        variante=2;
        counter=2;
    }
    while(counter < n)
    {
        primo+=variante;
        if(esprimo(primo))
            counter++;
    }
    std::cout<<"El numero primo numero "<<n<<" es "<<primo<<std::endl;
}


///
/// \brief factorprimo
///
void factorprimo()//Problema 12 - Imprimir el maximo factor primo
{
    int a;
    std::cout<<"Ingrese un valor positivo"<<std::endl;
    std::cin>>a;
    if(esprimo(a))
    {
        std::cout<<"El numero es primo y no posee factores"<<std::endl;
    }else{
        for(int i=(a/2)+1;;i--)

        {
            if(a%i==0 && esprimo(i))
            {
                std::cout<<"El maximo factor primo es "<<i<<std::endl;
                break;
            }
        }
    }
}


///
/// \brief primosuma
///
void primosuma()//Problema 13 - Imprimir la suma de los primos menores a un numero
{
    int a=0, sum=0;
    std::cout<<"Ingrese un numero positivo"<<std::endl;
    std::cin>>a;
    for(int i=a;i>1;i--)
    {
        if(esprimo(i))
            sum+=i;
    }
    std::cout<<"La suma de los numero primos menores a "<<a<<" es de "<<sum<<std::endl;
}


/**
 * @brief collatz
 */
void collatz()//Problema 16 - Imprimir serie Collatz
{
	int a=0, b=0, counter=1, mayor=0;
    std::cout<<"Ingrese un numero "<<std::endl;
    std::cin>>a;
    for(int i=a; i>0; i--)
    {
        a=i;
        while(a>1)
        {
            if(a%2==0)
                a=a/2;
            else
                a=3*a+1;
            counter++;
        }
        if(counter>mayor)
        {    
            mayor=counter;
            b=i;
        }
        counter=1;
    }
    std::cout<<"La semilla es "<<b<<" con "<<mayor<<" Terminos"<<std::endl;
    std::cout<<b<<std::endl;
    while(b>1)
    {
        if(b%2==0)
            b=b/2;
        else
            b=3*b+1;
        std::cout<<b<<std::endl;
    }
}
