#include <iostream>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "fecha.h"

Fecha::Fecha(){

	 time_t timestamp;
     timestamp = time(NULL);
     tm *f;
     f = localtime(&timestamp);
     dia = f->tm_mday;
     mes = f->tm_mon + 1;
     anio = f->tm_year + 1900;

	}

bool Fecha::cargarFecha(){

	 cout << "Dia: ";
	 cin >> dia;

	 cout << "Mes: ";
	 cin >> mes;

	 cout << "Anio: ";
	 cin >> anio;

	 return true;

	}

void Fecha::mostrarFecha(){

	 cout << getDia() << "/" << getMes() << "/" << getAnio() << endl;

	}



bool Fecha::operator>(Fecha obj){

     if (anio > obj.getAnio()){
         return true;
		}
     if (anio == obj.getAnio() && mes > obj.getMes()){
		 return true;
	    }
     if (anio == obj.getAnio() && mes == obj.getMes() && dia > obj.getDia()){
         return true;
		}

     return false;

	}

bool Fecha::operator<(Fecha obj){

     if (anio < obj.getAnio()){
         return true;
		}
     if (anio == obj.getAnio() && mes < obj.getMes()){
         return true;
		}
     if (anio == obj.getAnio() && mes == obj.getMes() && dia < obj.getDia()){
         return true;
		}

     return false;

	}

bool Fecha::operator==(Fecha obj){

	 if(anio == obj.getAnio() && mes == obj.getMes() && dia == obj.getDia()){
		 return true;
		}

	 return false;

	}

bool Fecha::operator>=(Fecha obj){

     if (anio > obj.getAnio()){
         return true;
		}
     if (anio == obj.getAnio() && mes > obj.getMes()){
         return true;
        }
     if (anio == obj.getAnio() && mes == obj.getMes() && dia >= obj.getDia()){
         return true;
		}

     return false;
	}

bool Fecha::operator<=(Fecha obj){

     if (anio < obj.getAnio()){
         return true;
		}
     if (anio == obj.getAnio() && mes < obj.getMes()){
         return true;
		}
     if (anio == obj.getAnio() && mes == obj.getMes() && dia <= obj.getDia()){
		 return true;
		}

     return false;
	}

int Fecha::operator-(Fecha obj){///DEVUELVE LA EDAD RESTANDO 2 FECHAS

     int total = anio - obj.getAnio();//anio de la primer fecha MENOS la segunda

     if(mes < obj.getMes()){
         total -=1;
		}
     else if(mes == obj.getMes() && dia < obj.getDia()){
         total -=1;
		}

     return total;

	}
