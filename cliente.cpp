#include <iostream>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "funciones.h"
#include "cliente.h"

const char * ACLIENTES = "clientes.dat";

bool Cliente::cargarCliente(){

	 Persona::cargarPersona();

	 cout << "Ingrese mail: ";
	 cin.getline(mail,30);

	 cout << "Ingrese celular: ";
	 cin >> celular;

	 return true;

	}

void Cliente::mostrarCliente(){

	 Persona::mostrarPersona();

	 cout << "Mail: " << mail << endl;

	 cout << "Celular: " << celular << endl;

	}

bool Cliente::grabarEnDisco(){

	 FILE * p = fopen(ACLIENTES,"ab");
	 if(p==NULL){
		 cout << "Error con el archivo de clientes. " << endl;
		 cin.get();
		 return false;
		}
	 bool escribio = fwrite(this, sizeof * this, 1, p);
     fclose(p);

     return escribio;

	}

void Cliente::mostrarTodosLosClientes(){

	 FILE * p = fopen(ACLIENTES,"rb");
	 if(p==NULL){
		 cout << "Error al abrir archivo de clientes ";
		 cin.get();
		 return;
		}
	 Cliente regC;
	 while(fread(&regC,sizeof(Cliente),1,p)==1){
		 regC.mostrarCliente();
		}
	 fclose(p);

	 return;

	}

void Cliente::setMail(const char * nmail){
	 strcpy(mail,nmail);
	}

void Cliente::setCelular(long ncelular){
	 celular = ncelular;
	}

