/*Escribir una funcion recursiva que calcule el numero de combinaciones sin
repeticion de p elementos elegidos de un conjunto de n elementos,
sabiendo que c_n^p=n!/(p!*(n-p)!).

Nota: Recordar la relacion de la "combinatoria" y el triangulo de pascal
para observar la relacion de recurrencia.*/

#include <iostream>
#include <iomanip>

using namespace std;

long Combinatoria(long n, long p)
{
    if (n==p || p==0)
        return 1;
    else
        return Combinatoria(n-1,p-1)+Combinatoria(n-1,p);
}

int main()
{
    int espacio=12*2;
    for(int i=0;i<=12;i++)
    {
        for(int j=0;j<=i;j++)
            {
                if(j==0)
                    cout<<setw(espacio)<<Combinatoria(i,j);
                else
                    cout<<setw(4)<<Combinatoria(i,j);
            }
        cout<<endl;
        espacio=espacio-2;
    }
    return 0;
}
