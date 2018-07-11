#include "Consola.h"

#include <iostream>
#include <strings.h>
#include <fstream>

using namespace std;

	
	Consola::Consola(string cadena){			// Constructor
			//cout << "Cadena aceptada: " << cadena << endl;
			cadena1=cadena;
			pcadena=cadena.c_str();
			this->CalcTam();  								//inic tamanho cadena
			arreglo_ent = new unsigned int[tam_arr];		//inic el arreglo
			
			for(int i=0 ; i<tam_arr ; i++){					// llenando el arreglo de ceros para poder sobreescribirlo
				arreglo_ent[i] = 0;
				
			}
	}
	
/*----------------------------------------------------------------------------------------------------------------------------------------------*/	
	
	
	
	void Consola::CalcTam(){		// Calcula el tamanho del arreglo de enteros
			
			
			if((strlen(pcadena)%4)==0){	// Para el caso de que la cadena quepa justo en n enteros				
				tam_arr = strlen(pcadena)/4;				
			}
			
			
			if((strlen(pcadena)%4)!=0){ // Para el caso en que la cadena necesite un espacio más
				tam_arr = (strlen(pcadena)/4)+1;
			}
			
			
			
	}
/*----------------------------------------------------------------------------------------------------------------------------------------------*/	
	
	
	
	
	void Consola::Cad_a_Ent(){
		int i=0,j=0,k=0,shifter=0;
		for(i=0 ; i<tam_arr ; i++){		// Ciclo para llenar el arreglo con la información de la cadena
					
					while(j<strlen(pcadena)){						
						
						arreglo_ent[i]= arreglo_ent[i] | (pcadena[j] << shifter); // Se guarda el dato con el OR, moviendo los bits 8 posiciones como es requerido
											
						k++;
						j++;
						
						shifter=shifter+8;
						
							if(k==4){
								shifter=0;
								k=0;
								break;
							}	
					}					
					
				}
			
			cout << endl << "Imprimiendo el Arreglo de Enteros:  " << endl;
			for(i=0 ; i<tam_arr ; i++){	// Imprimiendo el arreglo de enteros			
			
				cout << " " << arreglo_ent[i] << endl;
			
			}
		
		
	}
	
/*-----------------------------------------------------------------------------------------------------------------------------------------------*/	
	
	
	
	void Consola::Ent_a_Cad(){
		int i=0,j=0,k=0,shifter=0;
		i=j=k=shifter=0;
				long aux_bitwise;
						
						for(i=0;i<tam_arr;i++){
							k=0;	
							aux_bitwise=255;	// Tiene los 8 primeros bits prendidos
							shifter=0;
								
							while(k<4){
								
								cadena_dec.push_back((arreglo_ent[i] & aux_bitwise) >> shifter);								
								//cout << cadena_dec<< endl;
								
									j++;
									k++;
									shifter = shifter+8;				// si no se mueve de vuelta a la izquierda, el dato no se puede guardar en el caracter
									aux_bitwise = aux_bitwise << 8;		// Permite extraer el dato con el AND
							}
						}
				
				
				cout << endl << "Imprimiendo la cadena decodificada:  " << endl;
				cout << cadena_dec;
		
	}
	
/*-----------------------------------------------------------------------------------------------------------------------------------------------*/	

	
	void Consola::EscribEnt(){	//Escribe el arreglo de enteros en un archivo llamado ENTEROS.txt
		
		ofstream archivo2;
		
		archivo2.open("ENTEROS.txt");
		
			if(archivo2.is_open()){
				
				cout << "\n\n archivo ENTEROS.txt creado satisfactoriamente..." << endl;
				
				for(int i=0;i<tam_arr;i++){
					archivo2 << arreglo_ent[i] <<"\n";
				}
			}
			
			else{
				cout << "No se pudo crear ENTEROS.txt" << endl;
			}
			
			archivo2.close();
		
	}
	
/*------------------------------------------------------------------------------------------------------------------------------------------------*/	
	
	void Consola::ImprimiendoEnt(){	//Imprime el mensaje original
		
		ifstream archivo3;
		string cad;
		
		archivo3.open("ENTEROS.txt");
		
			if(archivo3.is_open()){
				
				cout << "\n\n archivo ENTEROS.txt abierto  satisfactoriamente..." << endl;
				
				cout << cadena1 << endl;
				
			}
			
			else{
				cout << "No se pudo abrir ENTEROS.txt" << endl;
			}
			
			archivo3.close();
		
	}
	
	
	
	
	
	
	Consola::~Consola(){			// Destructor
			
	}
	
	
	
