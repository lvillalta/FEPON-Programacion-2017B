/*Realice un programa que pida el ingreso de los datos 
personales del usuario (nombre, cedula y teléfono) 
y los muestre por pantalla.
*/
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

int main(){
	system("color 4C");
	string nom;
	int CI;
	int telf;
	
	cout<<"Ingrese su nombre:\n";
	cin>>nom;
	cout<<"Ingrese su numero de cedula:\n";
	cin>>CI;
	cout<<"Ingrese su telefono:\n";
	cin>>telf;
	
	cout<<"\n\n* * * * * * * * * * * * * * * * * * * *\n";
	cout<<"*                                     *\n";
	cout<<"*    Su nombre es: "<<nom<<"             *\n";     
	cout<<"*    Su cedula es: "<<CI<<"         *\n";
	cout<<"*    Su telefono es: "<<telf<<"        *\n";
	cout<<"*                                     *\n";
	cout<<"* * * * * * * * * * * * * * * * * * * *\n";
system("PAUSE");
return 0;	
} 
