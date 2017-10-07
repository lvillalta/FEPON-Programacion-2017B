/*Escribir una funcion que reciba dos enteros positivos m, n y dos reales a,b
y retorne una matriz de orden mxn, donde
A[i][i]=Raizcuadrada[(i-a)^2 + (j-b)2]*/

#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

vector < vector < double > > matriz(unsigned int m,unsigned int n, double a, double b)//funcion que realizara lo que pide el ejercicio
{
    vector < vector < double > > A;//matriz que devolvera la funcion
    A.resize(m);//la matriz tendra m filas
    for(unsigned int i=0;i<A.size();i++)//la matriz tendra n columnas
        A[i].resize(n);
    for(unsigned int i=0;i<A.size();i++)//recorremos por las filas de la matriz
    {
        for(unsigned int j=0;j<A[i].size();j++)//recorremos por las columnas de la matriz
        {
            A[i][j]=sqrt(pow(i-a,2)+pow(j-b,2));//calculamos cada componente de la matriz como pide el ejercicio
        }
    }
    return A;//la funcion devuelve la matriz A
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

}

void eliminar_matriz(vector<vector< double > > &A)//funcion para eliminar matrices
{
    for(unsigned int i=0;i<A.size();i++)
        A[i].clear();
    A.clear();
}
int main()
{
    int m,n;//variables que guardaran el orden de las matrices
    double x,y;//variables que guardaran los valores de a y b que indica el ejercicio
    do{
        cout<<"Ingrese dos n\243meros enteros positivos: ";
        cin>>m>>n;//leemos el orden de la matriz
    }while(m<=0||n<=0);
    cout<<"Ingrese dos n\243meros reales: ";
    cin>>x>>y;//leemos los reales
    vector<vector< double > > A;//declaramos la matriz que usaremos
    A=matriz(m,n,x,y);//guardamos en A la matriz con el formato pedido
    cout<<"La matriz generada es: "<<endl;
    imprimir_matriz(A);//imprimimos la matriz
    eliminar_matriz(A);//eliminamos la matriz
    return 0;
}
