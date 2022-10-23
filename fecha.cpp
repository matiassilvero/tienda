#include <iostream>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "fecha.h"
#include "funciones.h"
#include "persona.h"

Fecha::Fecha(){

	 time_t timestamp;
     timestamp = time(NULL);
     tm *f;
     f = localtime(&timestamp);
     dia = f->tm_mday;
     mes = f->tm_mon + 1;
     anio = f->tm_year + 1900;

	}

Fecha::Fecha(int d,int m, int a){

	 dia = d;
	 mes = m;
	 anio = a;

	}

bool Fecha::cargarFecha(){

	 cout << "Dia: ";
	 cin >> dia;

	 cout << "Mes: ";
	 cin >> mes;

	 cout << "Anio: ";
	 cin >> anio;

	 bool fechaValida = validarFecha(dia,mes,anio);

	 return fechaValida;

	}

void Fecha::mostrarFecha(){

	 if(dia<10){
         cout << "0" << dia << "/";
        }
     else{
         cout << dia << "/";
        }
     if(mes<10){
         cout << "0" << mes << "/";
        }
     else{
         cout << mes << "/";
        }

	 cout << anio;

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

