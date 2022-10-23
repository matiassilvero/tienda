#include <iostream>
#include <iomanip>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "cliente.h"
#include "funciones.h"

const char * ACLIENTES = "clientes.dat";

bool Cliente::cargarCliente(){

	 if(Persona::cargarPersona()){
		 cout << "Ingrese mail: ";
		 cin.getline(mail,30);///validar con el @

		 cout << "Ingrese celular: ";
		 cin >> celular;
		 if(celular<1100000000 || celular > 1199999999){
			 cout << "Debe ingresar un celular valido";
			 return false;
			}

		 return true;

		}

	 return false;

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

void Cliente::mostrarCliente(){

	 Persona::mostrarPersona();
	 cout << endl;

	 cout << "                                             Mail: " << mail << endl;
	 cout << "                                             Celular: " << celular << endl;
	 cout << "-----------------------------------------------------------------------------" << endl;

	}

void Cliente::mostrarEncabezadoCliente(){

     cout << left;
     cout << setw(10) << "   DNI ";
     cout << setw(11) << "Nombre ";
     cout << setw(11) << "Apellido ";
     cout << setw(13) << "Fecha Nac.";
     cout << setw(8) << "Genero"<<endl;
     cout << "-----------------------------------------------------------------------------" << endl;

    }

void Cliente::mostrarTodosLosClientes(){

	 FILE * p = fopen(ACLIENTES,"rb");
	 if(p==NULL){
		 cout << "Error al abrir archivo de clientes ";
		 cin.get();
		 return;
		}
	 Cliente regC;
	 mostrarEncabezadoCliente();
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

bool Cliente::leerDeDisco(int nroRegistro) {

	 FILE* p = fopen("Choferes.dat", "rb");
     if (p == NULL) {
		 return false;
		}
     fseek(p, nroRegistro * sizeof(Cliente), SEEK_SET);
     bool ok = fread(this, sizeof(Cliente), 1, p);
     fclose(p);

     return ok;

	}

Cliente devolverClientePorPosicion2(int posicion){

	FILE * p = fopen("clientes.dat","rb");
	 if(p==NULL){
		 anykey("Error con el archivo clientes.");
		}

	 Cliente regC;
	 int i=0;
	 while(fread(&regC,sizeof(Cliente),1,p) == 1 ){
		 if(i == posicion){
			 fclose(p);
			 return regC;
			}
		 i++;
		}
	 fclose(p);

	}

void ordenarClientes(Cliente * vec, int cantidad){

     for(int i = 0; i<cantidad-1; i++){
         int posMenor = i;

         for(int j = i+1; j < cantidad; j++){
             if(strcasecmp(vec[j].getApellido(), vec[posMenor].getApellido()) < 0){
				 posMenor = j;
				}
			}
		 Cliente iAux;
		 iAux = vec[i];
		 vec[i] = vec[posMenor];
		 vec[posMenor] = iAux;
		}

    }

///MEMORIA DINAMICA
void cargarVectorClientesMD(){

     Cliente * vectorDinamico;
     int tamanio;
     tamanio = cantidadDeClientes();
     vectorDinamico = new Cliente[tamanio];
     if(vectorDinamico==NULL){
	  	 return;
	  	}
     //cout<<"Carga tu vector: "<<endl;
      Cliente regC;
      int i=0;
      for(i=0;i<tamanio;i++){
          vectorDinamico[i] = devolverClientePorPosicion2(i);
	  	}

     //Para mostrar el vector
     ordenarClientes(vectorDinamico,tamanio);
     regC.mostrarEncabezadoCliente();
     for(int i=0;i<tamanio;i++){
	  	 vectorDinamico[i].mostrarCliente();
	  	 cout << endl;
     }
	  delete vectorDinamico;

	}
