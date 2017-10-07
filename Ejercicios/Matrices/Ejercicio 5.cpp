/*Escribir un programa que reciba dos matrices, las multiplique (Si es
posible) e imprima en pantalla el sesultado*/

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void Cambiar_Orden(vector< vector <double> > &A,unsigned int a,unsigned int b) //funcion para cambiar el orden de la matriz
{
    A.resize(a);//cambiamos el orden de filas
    for(int i=0; i<A.size();i++)
    {
        A[i].resize(b); //cambiamos el orden de cada vecto para tener las columnas deseadas
    }
}

void Recibir_Matriz(vector< vector <double> > &A)//funcion para recibir los datos de una matriz desde el teclado
{
    for(int i=0; i<A.size();i++)
        for(int j=0;j<A[i].size();j++)//usamos dos for para recorrer cada elemento de la matriz
        {
            cout<<"Ingrese el valor para fila "<<i<< " columna "<<j<<": ";
            cin>>A[i][j];//guardamos lo recibido en cada posicion
        }
    cout<<endl;
}

void Imprimir_Matriz(vector< vector <double> > A) //funcion para imprimir matrices
{
    for(int i=0; i<A.size();i++)
        {
            for(int j=0;j<A[i].size();j++)//usamos dos for para recorrer por los elementos
            {
                cout<<setw(8)<<setprecision(2)<<fixed<<A[i][j]; //imprimimos cada elemento con dos decimales
            }
            cout<<endl;//cada vez que imrpimimos una fila se imprime un salto de linea
        }
    cout<<endl;
}

bool multiplicables(vector< vector <double> > A, vector< vector <double> > B)//funcion para ver si las matrices se pueden multiplicar
{
    unsigned int a,b=B.size();//la variable b guarda el orden de las filas de la segunda matriz
    bool p;
    for(int i=0; i<A.size();i++)//se recorre por cada fila:
        {
            a=A[i].size();//guardamos en a el tvector en la posicion iamaño de cada
            if(a==b)//si son iguales se pueden multiplicar
                p=true;
            else//si no, no se puede
                p=false;
            if(p==false)//en caso de que un vector no tenga el tamaño correcto, no se puede multiplicar
                break;
        }
    return p; //se devuelve el valor de verdad obtenidos
}

vector< vector <double> > Multiplicar(vector< vector <double> > A, vector< vector <double> > B)//funcion para multiplicar
{
    vector< vector <double> > m;//vector en el que se guardara el producto de las matrices
    if(multiplicables(A,B))//si se pueden multiplicar procedemos
    {
        unsigned int a=A.size(),b=B[0].size();//variables para el orden de la nueva matriz
        Cambiar_Orden(m, a, b);//cambiamos el orden de la matriz en la que guardaresmos el producto
        for(int i=0; i<a;i++)
        {
            for(int j=0;j<b;j++)//recorreremos por cada termino de la matriz que guarda el producto
            {
                double l=0;
                for(int k=0;k<B.size();k++)//calcularesmos el producto termino a termino
                    l=l+A[i][k]*B[k][j];
                m[i][j]=l;
            }
        }
    }
    return m;//devolvemos la matriz donde tenemos el producto
}

void eliminar_matriz(vector<vector< double > > &A)//funcion para eliminar las matrices usadas
{
    for(unsigned int i=0;i<A.size();i++)
        A[i].clear();
    A.clear();
}

int main()
{
    vector< vector <double> > A;//primera matriz a multiplicar
    vector< vector <double> > B;//segunda matriz a multiplicar
    vector< vector <double> > prod;//matriz que guarda el producto
    unsigned int m,n,k,l;//varables que guardan el orden de las matrices
    cout<<"Ingrese el orden de la primera matriz: ";
    cin>>m>>n;//guardamos el orden de la primera matriz
    cout<<"Ingrese el orden de la segunda matriz: ";
    cin>>k>>l;//guardamos el orden de la segunda matriz
    Cambiar_Orden(A,m,n);//cambiamos el orden de las matrices
    Cambiar_Orden(B,k,l);
    if(multiplicables(A,B)==false)//mensaje de error en caso de no ser multiplicables
        {
            cout<<"El orden de las matrices no permite que se multipliquen.\n\n\n";
            return 0;
        }
    Recibir_Matriz(A);//recibimos las matrices que se multiplicaran
    Recibir_Matriz(B);
    cout<<"La matriz A es:\n";//imprimimos las matrices a multiplicar
    Imprimir_Matriz(A);
    cout<<"La matriz B es:\n";
    Imprimir_Matriz(B);
    prod=Multiplicar(A,B);//calculamos el producto de las magrices y se guarda en la variable prod
    cout<<"El producto de estas matrices es:\n";
    Imprimir_Matriz(prod);//imprimimos el producto de las matrices
    eliminar_matriz(A);//eliminamos las matrices usadas
    eliminar_matriz(B);
    eliminar_matriz(prod);
    return 0;
}
