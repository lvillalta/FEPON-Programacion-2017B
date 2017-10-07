/*Escribir una funcion recursiva que sume cada digito de un numero entero*/
#include <iostream>
#include <cmath>

using namespace std;

long suma_digitos(long numero)
{
    if(abs(numero)==0)
        return 0;
    else
        return abs(numero%10)+suma_digitos(numero/10);
}

int main()
{
    int n;
    cout<<"Ingrese un numero entero: ";
    cin>>n;
    cout<<"La suma de sus digitos es: "<<suma_digitos(n)<<endl;
    return 0;
}
