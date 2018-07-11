#include <iostream>
#include <iomanip>
#include <strings.h>
#include <fstream>
#include "Consola.h"



using namespace std;


/* Arit Von Vanegas Sanchez				C.I: V-26 209 304				Seccion 2			Ingenieria en Informatica */

int main(int argc, char** argv) {
	
	int resp_menu;
	
	cout << "Que desea hacer? " << endl;
	cout << "\t 1. Cargar Datos del Archivo PRUEBA.txt" << endl;
	cout << "\t 2. Ingresar un mensaje propio " << endl;
	
	cin >> resp_menu;
	fflush(stdin);
		
		
		//Cargando Datos de PRUEBA.txt
		if(resp_menu==1){
			
			string cadena;			
			ifstream archivo("PRUEBA.txt");
			
			
			if(archivo.is_open()){
				
				while(getline(archivo,cadena)){
					
					cout << " archivo abierto:  ";
					cout << cadena << endl;
				}
				
					Consola cons1(cadena);
				
					cons1.Cad_a_Ent();	
					cons1.Ent_a_Cad();	
					cons1.EscribEnt();			
				
			}
			
			else{
				cout << "archivo no abierto" << endl;
			}
			
			
						
			
		}
		
		
		// Usando Cadena introducida por el usuario
		if(resp_menu==2){
		
			string cadena;
			const char *pcadena;
				
				system("cls");
				fflush(stdin);
				cout << "Ingrese la cadena de caracteres: ";
			
				
				getline(cin,cadena);		// Crea un objeto string con la cadena de caracteres, esto es para que acepte un largo variable...
				
				
				
				Consola cons1(cadena);
				
					cons1.Cad_a_Ent();	
					cons1.Ent_a_Cad();
		}
		
			
	return 0;
}
