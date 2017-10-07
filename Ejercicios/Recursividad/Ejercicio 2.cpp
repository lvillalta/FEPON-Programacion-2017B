/*Escribir una funcon que calcule el n-esimo termino de una sucesion
definida como:
s0=a,s1=b,s2=c, sn=s(n-1)+s(n-2)*s(n-3);
donde a,b,c son parte de los argumentos ingresados en la funcion*/
#include <iostream>

using namespace std;

double sucesion(double n,double a, double b, double c)
{
    if(n==0)
        return a;
    else if (n==1)
        return b;
    else if (n==2)
        return c;
    else
        return sucesion(n-1,a,b,c)+sucesion(n-2,a,b,c)*sucesion(n-3,a,b,c);
}

int main()
{
    for(int i=0;i<15;i++)
        cout<<sucesion(i,1,0,1)<<endl;
    return 0;
}
