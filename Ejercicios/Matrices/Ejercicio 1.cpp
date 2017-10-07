/*Escribir una funcion que reciba una matriz cuadrada de numeros reales y retorne
un vector con el numero elementos no nulos de cada fila*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

vector <int > NoNulos (vector < vector < double > > A)//funcion para contar los elementos no nulos cada fila de una matriz
{
    vector <int > N;//vector en el que se guardaran los elementos no nulos de cada fila
    int contador;//variable que contara los elementos no nulos
    for(int i=0;i<A.size();i++)//recorremos cada fila de la matriz
    {
        contador=0;//al inicio no tenemos elementos no nulos contados
        for(int j=0;j<A[i].size();j++)//recorremos cada elemento de la fila
        {
            if(A[i][j]!=0)//si se encuentra un elemento no nulo
                contador++;//contamos
        }
        N.push_back(contador);//añadimos el numero de elementos no nulos al vector
    }
    return N;//la funcion devuelve el vector que conto los elementos no nulos
}

void DatosAleatorios( vector < vector < double > > &A)//funcion que llena una matriz con numeros aleatorios
{
    for(int i=0;i<A.size();i++)//recorremos las filas de la matriz
    {
        for(int j=0;j<A[i].size();j++)//recorremos las columnas de la matriz
        {
            A[i][j]=rand()%100;//a cada elemento de la matriz le asignamos un numero aleatorio entre 0 y 99
        }
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
    srand(time(0));//semilla para los numeros aleatorios
    unsigned int n=1+rand()%10;//orden de la matriz entre 1 y 10
    vector < vector < double > > m;//declaramos la matriz
    vector <int> nn;//declaramos el vector que guardara los elementos no nulos
    m.resize(n);//la matriz tiene n filas
    for(int i=0;i<m.size();i++)//la matriz tiene n columnas
        m[i].resize(n);
    DatosAleatorios(m);//llenamos la matriz con datos aleatorios
    nn = NoNulos(m);//guardamos en el vector nn el vector que se obtiene de contar los elementos no nulos de m
    cout<<"El vector de elementos no nulos es:\n";
    for(int i=0;i<m.size();i++)//imprimimos el vector de elementos no nulos
        cout<<setw(5)<<nn[i];
    cout<<endl;
    eliminar_matriz(m);//eliminamos la matriz
    nn.clear();//eliminamos el vector


    return 0;
}
