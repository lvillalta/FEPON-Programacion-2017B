/*Escribir una funcion recursiva que resiva el inicio, fin y salto
e imprima una tabla de valores de una cierta funcion.*/

#include <iostream>
#include <iomanip>

using namespace std;

double f(double x)
{
    return x*x;
}

void tabla(double inicio, double fin, double salto)
{
    if((inicio==fin)||fin<inicio)
        cout<<setw(6)<<fin<<" |"<<setw(6)<<f(fin)<<endl;
    else
    {
        cout<<setw(6)<<inicio<<" |"<<setw(6)<<f(inicio)<<endl;
        tabla(inicio+salto,fin,salto);
    }
}

int main()
{
    cout<<setw(6)<<"x"<<" |"<<setw(6)<<"y"<<endl;
    tabla(-3,3,1.3);
    return 0;
}
