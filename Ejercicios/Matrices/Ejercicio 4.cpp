/*Escribir un programa que reciba dos numeros enteros positivos, de modo que
uno sean las filas y otro las columnas de una matriz.
las dos primeras filas son ingresadas por el usuario y las siguientes
se forman por la suma de las dos anteriores, es decir:

a[i][j]=a[i-2][j]+a[i-1][j]

finalmente, imprimir la matriz formada.
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

void Cambiar_Orden(vector< vector <double> > &A,unsigned int a,unsigned int b)//funcion para cambiar el orden de una matriz
{
    A.resize(a);//la matriz tiene a filas
    for(int i=0; i<A.size();i++)//la matriz tiene b columnas
    {
        A[i].resize(b);
    }
}


void imprimir_matriz(vector<vector< double > > A)//funcion que imprime una matriz
{
    for(unsigned int i=0;i<A.size();i++)//recorremos por cada fila
    {
        for(unsigned int j=0;j<A[i].size();j++)//recorremos por cada columna
        {
            cout<<setw(10)<<setprecision(2)<<fixed<<A[i][j];//imprimimos los elementos
        }
        cout<<endl;//cada vez que se imprime una fila imprimimos un salto de linea
    }
    cout<<endl;
}

void eliminar_matriz(vector<vector< double > > &A)//funcion para eliminar matrices
{
    for(unsigned int i=0;i<A.size();i++)
        A[i].clear();
    A.clear();
}

int main()
{
    int a,b;//variables que guardan el orden de la matriz
    do
    {
        cout<<"Ingrese el numero de filas de la matriz: ";
        cin>>a;
    }while(a<1);//se reciben las filas
    do
    {
        cout<<"Ingrese el numero de columnas de la matriz: ";
        cin>>b;
    }while(b<1);//se reciben las columnas
    vector< vector<double> > m;//matriz a usar
    Cambiar_Orden(m,a,b);//cambiamos el orden de la matriz
    for(unsigned int i=0;(i<2)&&(i<m.size());i++)//recibimos los vectores 0 y 1 si el numero de filas lo permite
    {
        cout<<"Ingrese los valores de la "<<i+1<<"\247 fila:"<<endl; // \247 => °
        for(unsigned int j=0;j<m[i].size();j++)//recorremos las columnas
        {
            cout<<"En la posicion "<<i<<","<<j<<" : ";
            cin>>m[i][j];//recibimos las componentes de la matriz
        }
    }
    for(unsigned int i=2;i<m.size();i++)//recorremos las filas a partir de la 2
    {
        for(unsigned int j=0;j<m[i].size();j++)//recorremos las columnas
        {
            m[i][j]=m[i-2][j]+m[i-1][j];//cada componente es la suma de las ciomponentes de las dos filas anteriores
        }
    }
    cout<<"La matriz es:"<<endl;
    imprimir_matriz(m);//imprimimos la matriz
    eliminar_matriz(m);//eliminamos la matriz
    return 0;
}
