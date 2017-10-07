/*Escribir una funcion que reciba una matriz cuadrada A y un numero real L y
calcule B = A-L*I, donde I es la matriz identidad.*/

#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

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

void DatosAleatorios( vector < vector < double > > &A)//funcion para llenar una matriz con datos aleatorios
{
    for(int i=0;i<A.size();i++)//recorremos por llas filas de la matriz
    {
        for(int j=0;j<A[i].size();j++)//recorremos por las columnas de la matriz
        {
            A[i][j]=100*(rand()/(RAND_MAX+1.0));//llenamos la matriz con numeros aleatorios 0-100
        }
    }
}

void Cambiar_Orden(vector< vector <double> > &A,unsigned int a,unsigned int b)//funcion para cambiar el orden de una matriz
{
    A.resize(a);//la matriz tiene a filas
    for(int i=0; i<A.size();i++)//la matriz tiene b columnas
    {
        A[i].resize(b);
    }
}

vector<vector< double > > matriz_B(vector<vector<double> > A,double lambda)//funcion que hará lo que pide el eercicio
{
    for(unsigned int i=0;i<A.size();i++)//recorremos por las filas de la matriz
    {
        for(unsigned int j=0;j<A[i].size();j++)//recorremos por las columnas de la matriz
        {
            if(i==j)
                A[i][j]=A[i][j]-lambda;//A-L*I solo cambia la matriz en la diagonal, es decir cuando
                //a=j, por tanto cambiamos los elementos en esas coordenadas
        }
    }
    return A;//devolvemos la matriz modificada
}

int main()
{
    srand(time(0));//semilla para los numeros aleatorios
    unsigned int n=1+rand()%10;//la matriz tendra un rango aleatorio 1-10
    double lambda=100*(rand()/(RAND_MAX+1.0));//lambda es un numero aleatorio 0-100
    vector < vector <double> > A,B;//matrices a usar
    Cambiar_Orden(A,n,n);//A es una matriz cuadrada de orden n
    DatosAleatorios(A);//llenamos A con numeros aleatorios
    cout<<"La matriz A es:\n";
    imprimir_matriz(A);//imprimimos la matriz creada
    cout<<"El valor de L es: "<<lambda<<endl;//imprimimos el valor de lambda
    cout<<"La matriz B=A-L*I es:\n";
    B=matriz_B(A,lambda);//calculamos A-L*I y guardamos en B
    imprimir_matriz(B);//imptimimos la matriz
    eliminar_matriz(A);//eliminamos las matrices
    eliminar_matriz(B);
    return 0;
}
