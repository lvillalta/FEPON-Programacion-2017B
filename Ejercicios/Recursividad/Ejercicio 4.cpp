/*Sea X la sucesion definida de la siguiente forma:
x0=991,x1=111, xn=( (3x(n-1)+x(n-2)) mod 1000)/1000
Escribir una funcion que calcule el n-esimo termino de esta sucesion.

Ahora, sea S la serie definida por sn=suma_(i=0)^n xi. Escribir una
funcion que calcule el n-esimo termino de esta serie.

Finalmente, sea n=min{i: si>=p}, es decir,  n es igual a la
menor cantidad de numeros que deben sumarse para exceder al numero p.
Escriba un funcion que reciba p y calcule el valor de n.
*/
#include <iostream>
#include <cmath>

using namespace std;

double sucesion(int n)
{
    if(n==0)
        return 991;
    else if(n==1)
        return 111;
    else
        return fmod((3*sucesion(n-1))+sucesion(n-2),1000)/1000;
}

double serie(int n)
{
    if(n==0)
        return sucesion(0);
    else
        return sucesion(n)+serie(n-1);
}

int calcular_n(double p)
{
    int m=0;
    while(serie(m)<p)
        m++;
    return m;
}

int main()
{
    cout<<"Los primeros terminos de la serie son: "<<endl;
    for(int i=0;i<25;i++)
        cout<<"S"<<i<<"="<<serie(i)<<endl;
    cout<<"\nIngrese el valor de p: ";
    double p;
    cin>>p;
    cout<<"Se tiene que n es: "<<calcular_n(p)<<endl<<endl;
    return 0;
}
