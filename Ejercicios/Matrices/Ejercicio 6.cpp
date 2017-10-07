/*Escribir una funcion que calcule la norma de una matriz, definida como
la maxima suma absoluta de las columnas de la matriz:
||A||=Max_(1<=n<=j) {Suma_(i=1)^m [|a_(ij)|]}*/

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
    for(int i=0;i<A.size();i++)//recorremos las filas de la matriz
    {
        for(int j=0;j<A[i].size();j++)//recorremos las columnas de la matriz
        {
            A[i][j]=-100+200*(rand()/(RAND_MAX+1.0));//llenamos cada componente de la matriz con un numero aleatorio -100,100
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

double Norma(vector < vector < double > > A)//funcion para calcular la nomra
{
    double norma=0,suma_columna;//norma guardara la norma, suma_columna la suma de cada columna
    unsigned int filas=A.size(),columnas=A[0].size();//variables que guardan el numero de filas y columnas de la matriz
    for(unsigned int j=0;j<columnas;j++)//recorremos por cada columna
    {
        suma_columna=0;//al inicio no hemos sumado ningun valor de la columna
        for(unsigned int i=0;i<A.size();i++)//recorremos por los elementos de la columna
            suma_columna=abs(A[i][j])+suma_columna;//sumamos los valores absolutos de los elementos de la columna
        norma=max(norma,suma_columna);//esta norma nos indica que es el mayor de las sumas de las columnas
        //asi guardamos en norma el mayor numero entre la suma anterior y la actual.
    }
    return norma;//la funckion de vuelve el valor de la norma calculada
}

int main()
{
    srand(time(0));//semilla para los numeros aleatorios
    unsigned int a=2+rand()%9,b=2+rand()%9;//la matriz tendra un orden aleatorio
    double n;//variable para guardar el valor de la norma
    vector < vector <double> > A;//matriz de la que se calculara la norma
    Cambiar_Orden(A,a,b);//le cambiamos el orden a la matriz
    DatosAleatorios(A);//llenamos la matriz con numeros a leatorios
    cout<<"La matriz A es:\n";
    imprimir_matriz(A);//imprimos la matriz creada
    n=Norma(A);//calculamos la norma y guardamos en n
    cout<<"La norma de A es: "<<n<<endl;//imprimimos la norma
    return 0;
}
