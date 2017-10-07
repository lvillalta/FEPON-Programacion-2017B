/*Escribir una función que reciba una matriz donde cada fila es
un vector y los ortogonalice por Gram Schmit. Dos vectores se dicen ortogonales
si el producto escalar entre ambos da 0.
Si M={v1,v2,...,vn}, este conjunto se puede ortogonalizar a OG={w1,w2,...wn}
donde w1=v1, wi=vi-Suma_(j=1)^(i-1) (<wj,vi>/<wj,wj>) wj
donde <a,b> es el producto punto entre a y b

Los vectores de la matriz son L.I.*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

void cambiar_orden(vector< vector <double> > &A,unsigned int a,unsigned int b)//funcion para cambiar el orden de una matriz
{
    A.resize(a);//la matriz tiene a filas
    for(int i=0; i<A.size();i++)//la matriz tiene b columnas
    {
        A[i].resize(b);
    }
}

void recibir_vectores(vector < vector <double > > &A)//funcion para recibir los vectores...
{
    unsigned int a,b;//variables para guardar el orden de la matriz
    cout<<"Cuantos vectores desea ingresar? ";
    cin>>a;//guarda las filas
    cout<<"De que orden son los vectores? ";
    cin>>b;//guarda las columnas
    cambiar_orden(A,a,b);//cambiamos el orden de la matriz
    for(unsigned int i=0;i<A.size();i++)//recorremos por las filas
    {
        for(unsigned int j=0;j<A[i].size();j++)//recorremos por los espacios de cada vector
        {
            cout<<"Ingrese la componente "<<j<<" del vector "<<i<<": ";
            cin>>A[i][j];//recibimos el valor de cada elemento del vector i
        }
        cout<<endl;
    }
    cout<<endl;
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

double punto(vector < double > a, vector <double> b)//funcion para calcular el producto punto entre vectores
{
    double n=0;//variable que guarda el valor del producto
    if(a.size()==b.size())//solo se puede hacer si tienen la misma dimension
    {
        for(unsigned int i=0;i<a.size();i++)//recorremos por cada elemento del los vectores
        {
            n+=a[i]*b[i];//el producto punto usual es la suma del producto de las componenetes
        }
    }
    else
        n=-INFINITY;//si tienen dimensiones distintas devuelve menos inf como error
    return n;//devuelve n
}

vector < double > suma(vector < double > a, vector < double > b)//funcion para sumar vectores
{
    vector < double > s;//vector que guarda la suma
    if(a.size()==b.size())//solo se puede hacer entre vectores de la misma dimension
    {
        s.resize(a.size());//el vector resultante tiene la misma dimension que los sumados
        for(unsigned int i=0;i<a.size();i++)//recorremos por los elementos de los vectores
        {
            s[i]=a[i]+b[i];//sumamos componente a componente
        }
    }
    return s;//devuelve el vector s
}

vector < double > por_escalar(double escalar, vector < double > vect)//funcion para calcular el producto entre un escalar y un vector
{
    vector < double > s(vect.size());//el tamaño del vector producto es el mismo que el del que se multiplica por escalar
    for(unsigned int i=0;i<s.size();i++)//recorremos por cada componente de los vectores
    {
        s[i]=escalar*vect[i];//el producto por escalar se hacer multiplicado el numero por cada componente del vector
    }
    return s;//devuelve el vector
}

void Ortogonalizar(vector < vector <double > > &A)//funcion para ortogonalizar
{
    for(unsigned int i=1;i<A.size();i++)//dejamos el primer vector como está, los otros se ortogonalizan en funcion de ese...
    {
        double numero;//guardara el valor de (<wj,vi>/<wj,wj>)
        vector < double > a(A[i].size());//guarda el valor de Suma_(j=1)^(i-1) (<wj,vi>/<wj,wj>) wj
        for(unsigned int j=0;j<i;j++)//se hace la suma para los vectores ya ortogonalizados
        {
            numero=punto(A[i],A[j])/punto(A[j],A[j]);//calculamos (<wj,vi>/<wj,wj>)
            a=suma(a,por_escalar(numero,A[j]));//claculamos Suma_(j=1)^(i-1) (<wj,vi>/<wj,wj>) wj
        }
        A[i]=suma(A[i],por_escalar(-1,a));//calculamos vi-Suma_(j=1)^(i-1) (<wj,vi>/<wj,wj>) wj
    }
}

int main()
{
    vector < vector <double > > A;//matriz que se usara
    recibir_vectores(A);//recibimos los vectores
    Ortogonalizar(A);//ortogonalizamos los vectores
    imprimir_matriz(A);//imprimirmos la matriz de vectores ortogonalizados
    eliminar_matriz(A);//eliminamos la matriz
    return 0;
}
