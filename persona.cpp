#include <iostream>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "fecha.h"
#include "persona.h"

bool Persona::cargarPersona(){

	 cout << "Ingrese el dni: ";
	 cin >> dni;
	 cin.ignore();

	 cout << "Ingrese el nombre: " << endl;
	 cin.getline(nombre,20);

	 cout << "Ingrese el apellido: " << endl;
	 cin.getline(apellido,20);

	 cout << "Ingrese el genero(1- Hombre 2- Mujer 3-Otro): ";
	 cin >> genero;

	 cout << "Ingrese la fecha de nacimiento(DDMMAA): " << endl;
	 fechaNacimiento.cargarFecha();
	 cin.ignore();

	}

void Persona::mostrarPersona(){

	 cout << "Dni: " << dni << endl;

	 cout << "Nombre: " << nombre << endl;

	 cout << "Apellido: " << apellido << endl;

	 cout << "Genero: ";
	 if(genero == 1){
		 cout << "Hombre " << endl;
		}
	 else if(genero == 2){
		 cout << "Mujer " << endl;
		}
	 else{
	 	 cout << "Otro " << endl;
		}

	 cout << "Fecha de nacimiento: "; fechaNacimiento.mostrarFecha();

	}


