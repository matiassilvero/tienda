#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include "ctime"

class Fecha{

	 private:
		 int dia, mes, anio;
	 public:
		 Fecha();
		 Fecha(int,int,int);
	     bool cargarFecha();
	     void mostrarFecha();

		 bool operator<(Fecha);
		 bool operator>(Fecha);
		 bool operator==(Fecha);
		 bool operator<=(Fecha);
		 bool operator>=(Fecha);
		 int operator-(Fecha obj);///DEVUELVE LA EDAD ACTUAL

	     void setDia();
	     void setMes();
		 void setAnio();

		 int getDia(){return dia;}
		 int getMes(){return mes;}
		 int getAnio(){return anio;}

	};

#endif // FECHA_H_INCLUDED
