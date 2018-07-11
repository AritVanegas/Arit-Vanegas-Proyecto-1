#ifndef CONSOLA_H
#define CONSOLA_H

#include <iostream>
#include <strings.h>

using namespace std;


class Consola
{
	
	string cadena1;
	int tam_arr;
	const char *pcadena;
	unsigned int *arreglo_ent;
	//int i=0,j=0,k=0,shifter=0;
	
	string cadena_dec; //cadena decodificada
	
	public:
		
		Consola(string cadena); // Constructor
		
		void EscribEnt();
		
		void ImprimiendoEnt();
		
		void CalcTam();		// Calcula el tamaño del arreglo de enteros
		
		void Cad_a_Ent();		
		
		void Ent_a_Cad();
		
		~Consola();
	
};

#endif
