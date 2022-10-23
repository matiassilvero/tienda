#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "funciones.h"
#include "fecha.h"
#include "persona.h"

class Cliente:public Persona{

	 private:
	    char mail[15];
		long celular;

	 public:
        bool cargarCliente();
        bool grabarEnDisco();
        void mostrarCliente();
        void mostrarEncabezadoCliente();
        bool leerDeDisco(int);
        void mostrarTodosLosClientes();

		void setMail(const char*);
	    void setCelular(long);

		char * getMail(){return mail;}
		long getCelular(){return celular;}

	};


#endif // CLIENTE_H_INCLUDED
