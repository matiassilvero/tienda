#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "funciones.h"
#include "fecha.h"
#include "persona.h"

class Cliente:public Persona{

	 private:
	    char mail[20];
		long celular;
	 public:
//	    void setDni();
//	    void setNombre();
//	    void setApellido();
//	    void setEdad();
//	    void setGenero();
//
//	    int getDni(){return dni;}
//		char * getNombre(){return nombre;}
//		char * getApellido(){return apellido;}
//		Fecha getFechaNacimiento(){return fechaNacimiento;}
//		int getGenero(){return genero;}
///TODO ESO CREO Q YA ESTA EN LA CLASE PERSONA

        bool cargarCliente();
        bool grabarEnDisco();
        void mostrarCliente();
        bool leerDeDisco(int);
        void mostrarTodosLosClientes();

	};


#endif // CLIENTE_H_INCLUDED
