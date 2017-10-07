/*El mayor comun divisor de los enteros x y y es el entero más grande
que se puede dividir entre x y y de manera uniforme. Escriba una
función recursiva llamada mcd, que devuelva el mayor común divisor
de x y y, definida mediante la recursividad*/
#include <iostream>

using namespace std;

int mcd(int mayor, int menor)
{
    if (menor==0)
        return mayor;
    else
        return mcd(menor,mayor%menor);
}

int main()
{
    int x,y;
    cout<<"Ingrese el valor de x: ";
    cin>>x;
    do
    {
        cout<<"Ingrese el valor de y(y<=x): ";
        cin>>y;
    }while(y>x);
    cout<<"El maximo comun divisor entre "<<x<<" y "<<y<<" es: "<<mcd(x,y);
    return 0;
}
