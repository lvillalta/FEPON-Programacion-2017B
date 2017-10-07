/*Escribir una funcion que reciba el valor de un prestamo, el numero de cuotas en
las que se pagara y el interes anual y genere una matriz donde la primera columna
es el periodo, la segunda la cuota, la tercera el interes, la cuarta la amortizacion
y la quinta el saldo*/

#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

void imprimir_matriz(vector<vector< double > > A)//funcion para imprimir la tabla
{
    cout<<setw(7)<<"Periodo"<<setw(13)<<"Cuota"<<setw(13)<<"Interes";//imrpimimos el encabezado
    cout<<setw(13)<<"Amorticacion"<<setw(13)<<"Saldo"<<endl;
    for(unsigned int i=0;i<A.size();i++)//recorremos las filas
    {
        for(unsigned int j=0;j<A[i].size();j++)//recorremos las columnas
        {
            if(j==0)//imprimimos el valor de la columna cero en la fila i sin decimales
                cout<<setw(7)<<setprecision(0)<<fixed<<A[i][j];
            else//imprimimos las otras columnas con tres decimales(usual para moneda)
                cout<<setw(13)<<setprecision(3)<<fixed<<A[i][j];
        }
        cout<<endl;//cada vez que se imprime una fila se da un salto de linea
    }
    cout<<endl;

}

void eliminar_matriz(vector<vector< double > > &A)//funcion para eliminar matrices
{
    for(unsigned int i=0;i<A.size();i++)
        A[i].clear();
    A.clear();
}

void Cambiar_Orden(vector< vector <double> > &A,unsigned int a,unsigned int b)//funcion para cambiar el orden de una matriz
{
    A.resize(a);//la matriz tiene a filas
    for(int i=0; i<A.size();i++)//la matriz tiene b columnas
    {
        A[i].resize(b);
    }
}

vector< vector <double> > TablaAmortizacion(double capital, double interes, unsigned int numero_cuotas)//funcion para hacer la tabla de amortizacion
{
    unsigned int c=5;//la matriz tiene 5 columnas
    vector< vector <double> > ta;//matriz en la que guardaremos la tabla
    Cambiar_Orden(ta,numero_cuotas+1,c);//cambiamos el orden de la matriz
    //tiene espacio para cuando no se han pagado cuotas y para cada cuota pagada
    double cuota;//variable que guardara el valor de las cuotas
    /*Calculamos las cuotas:*/
    cuota=1-pow(1+interes,-static_cast<int>(numero_cuotas));
    cuota=capital*interes/cuota;
    ta[0][4]=capital;//el saldo inicial es el del prestamo
    for(unsigned int i=1;i<(ta.size());i++)//recorremos las filas de la tabla
    {
        ta[i][0]=i;//numero de cuota
        ta[i][1]=cuota;//valor de la cuota
        ta[i][2]=ta[i-1][4]*(interes);//el interes se calcula del saldo anterior
        ta[i][3]=cuota-ta[i][2];//la amortizacion es la cuota menos el interes
        ta[i][4]=ta[i-1][4]-ta[i][3];//el saldo es el saldo anterior menos la amortizacion
    }
    return ta;//la funcion devuelve la tabla
}

int main()
{

    vector< vector <double> > A;//matriz para guardar la tabla
    double prestamo,interes;//variables a usar...
    unsigned int cuotas;
    do//leemos el valor del prestamo desde el teclado, aseguarandonos de que sea positivo
    {
        cout<<"Ingrese el valor del prestamo: ";
        cin>>prestamo;
    }while(prestamo<=0);
    do//leemos el interes asegurandonos de que este en (0,1)
    {
        cout<<"Ingrese el interes (en escala 1): ";
        cin>>interes;
    }while(interes<=0 || interes>=1);
    do//recibimos las cuotas, asegurandonos de que sean mayor o igual a 1
    {
        cout<<"Ingrese el numero de cuotas: ";
        cin>>cuotas;
    }while(cuotas<1);
    A=TablaAmortizacion(prestamo,interes,cuotas);//calculamos la tabla y guardamos en A
    imprimir_matriz(A);//imprimimos la tabla
    return 0;
}
