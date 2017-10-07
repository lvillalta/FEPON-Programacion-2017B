/*Escribir una funcion recursiva para calcular en n'esimo termino
de la sucesion de fibonacci, sabiendo que:
f0=0,f1=1, fn=f(n-1)+f(n-2)*/
#include <iostream>

using namespace std;

long fibonacci(long n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    else
        return fibonacci(n-1)+fibonacci(n-2);
}

int main()
{
    for(int i=0;i<20;i++)
    cout<<fibonacci(i)<<endl;
    return 0;
}
