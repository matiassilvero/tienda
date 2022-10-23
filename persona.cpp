#include <iostream>
#include <iomanip>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "fecha.h"
#include "persona.h"
#include "cliente.h"

bool Persona::cargarPersona(){

	 cout << "Ingrese el dni: ";
	 cin >> dni;
	 if(dni<1000000 || dni>99999999){
		 cout << "Debe ser un DNI valido, entre 1000000 y 99999999 ";
		 return false;
		}
	 cin.ignore();

	 cout << "Ingrese el nombre: ";
	 cin.getline(nombre,20);

	 cout << "Ingrese el apellido: ";
	 cin.getline(apellido,20);

	 cout << "Ingrese el genero(1- Hombre 2- Mujer 3-Otro): ";
	 cin >> genero;
	 if(genero < 1 || genero > 3){
		 cout << "Debe ser un genero valido, entre 1 y 3";
		 return false;
		}

	 cout << "Ingrese la fecha de nacimiento(DDMMAA): " << endl;
	 if(!fechaNacimiento.cargarFecha()){
		 cout << "No es una fecha valida. ";
		 return false;
		}
	 cin.ignore();

	 return true;

	}

void Persona::mostrarPersona(){

     cout << left;
	 cout << setw(10) << dni;
	 cout << setw(11) << nombre;
	 cout << setw(11) << apellido;
	 cout << setw(1); fechaNacimiento.mostrarFecha();
	 cout << "   " << setw(8);
	 if(genero == 1){
		 cout << "Hombre ";
		}
	 else if(genero == 2){
		 cout << "Mujer ";
		}
	 else{
	 	 cout << "Otro ";
		}
	}

void Persona::setNombre(const char * nnombre){
	 strcpy(nombre,nnombre);
	}

void Persona::setApellido(const char * napellido){
	 strcpy(apellido,napellido);
	}

void Persona::setDni(int ndni){
	 dni = ndni;
	}

void Persona::setGenero(int ngenero){
	 genero = ngenero;
	}

void Persona::setFechaNacimiento(Fecha fechaNac){
	 fechaNacimiento = fechaNac;
	}

