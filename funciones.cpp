#include <iostream>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "funciones.h"
#include "producto.h"
#include "fecha.h"
#include "cliente.h"

void menuPrincipal(){

	 setColor(LIGHTRED);
	 cout << "					  #Buenos Aires, Argentina" << endl;
	 cout<<"-----------------------------------------"<< endl;
	 setColor(WHITE);
	 gotoxy(1,3);
	 cout<<"|             Tienda Trilenium          |";
	 setColor(LIGHTRED);
	 gotoxy(1,4);
	 cout<<"-----------------------------------------"<<endl;
	 setColor(WHITE);
	 gotoxy(1,5);
	 cout<<"| 1- PRODUCTOS       		 	|"<< endl;
	 setColor(RED);
	 gotoxy(1,6);
	 cout<<"| 2- PROMOCIONES  		    	|"<<endl;
	 setColor(WHITE);
	 gotoxy(1,7);
	 cout<<"| 3- POLITICA DE CAMBIOS/DEVOLUCION     |"<<endl;
	 setColor(RED);
	 gotoxy(1,8);
	 cout<<"| 4- CONTACTO 			 	|"<<endl;
	 setColor(WHITE);
	 gotoxy(1,9);
	 cout << "-----------------------------------------" << endl;
	 cout<<"| 0- FINALIZAR PROGRAMA      	 	|"<<endl;
	 setColor(WHITE);
	 cout << endl ;
	 cout<<"Ingrese una opción: ";

	}

void menuOculto(){

	 setColor(LIGHTRED);
	 gotoxy(1,2);
	 cout<<"-----------------------------------------";
	 setColor(WHITE);
	 gotoxy(1,3);
	 cout<<"|             Tienda Trilenium          |";
	 setColor(LIGHTRED);
	 gotoxy(1,4);
	 cout<<"-----------------------------------------"<<endl;
	 setColor(WHITE);
	 gotoxy(1,5);
	 cout<<"|MENU OCULTO (se selecciono la opcion 6)|"<< endl;
	 setColor(RED);
	 gotoxy(1,6);
	 cout<<"| 1- CONFIGURACION  		    	|"<<endl;
	 setColor(WHITE);
	 gotoxy(1,7);
	 cout<<"| 2- REPORTES/CONSULTAS    		|"<<endl;
	 setColor(RED);
	 gotoxy(1,8);
	 cout<<"| 3- VOLVER AL MENU PRINCIPAL 	 	|"<<endl;
	 setColor(WHITE);
	 gotoxy(1,9);
	 cout << "-----------------------------------------" << endl;
	 cout<<"| 0- VOLVER ATRAS          	        |"<<endl;
	 cout << endl ;
	 cout<<"Ingrese una opción: ";

	}

void menuProductos(){

	 setColor(LIGHTRED);
	 cout << "					  #Buenos Aires, Argentina" << endl;
	 cout<<"-----------------------------------------"<< endl;
	 setColor(WHITE);
	 gotoxy(1,3);
	 cout<<"|      Tienda Trilenium - PRODUCTOS     |";
	 setColor(LIGHTRED);
	 gotoxy(1,4);
	 cout<<"-----------------------------------------"<<endl;
	 setColor(WHITE);
	 gotoxy(1,5);
	 cout<<"| 1- HOMBRE      		 	|"<< endl;
	 gotoxy(1,6);
	 cout<<"| 2- MUJER  		 	 	|"<<endl;
	 gotoxy(1,7);
	 cout<<"| 3- OTRO    				|"<<endl;
	 gotoxy(1,8);
	 cout << "-----------------------------------------" << endl;
	 cout<<"| 0- VOLVER AL MENU ANTERIOR 		|"<<endl;
	 cout << endl ;
	 cout<<"Ingrese una opción: ";

	}

void menuPromociones(){

	 setColor(LIGHTRED);
	 cout << "					  #Buenos Aires, Argentina" << endl;
	 cout<<"-------------------------------------------------"<< endl;
	 setColor(WHITE);
	 gotoxy(1,3);
	 cout<<"|      Tienda Trilenium - PROMOCIONES           |";
	 setColor(LIGHTRED);
	 gotoxy(1,4);
	 cout<<"-------------------------------------------------"<<endl;
	 setColor(WHITE);
	 cout<<"| JUBILADOS(>65 años): 20%OFF en toda la tienda |"<< endl;
	 setColor(RED);
	 cout << "------------------------------------------------" << endl << endl;
	 setColor(WHITE);
	 cout<<"Presione cualquier tecla para volver al menu principal...";

	}

void menuPoliticas(){

	 setColor(LIGHTRED);
	 cout << "					  #Buenos Aires, Argentina" << endl;
	 cout<<"--------------------------------------------------------------------"<< endl;
	 setColor(WHITE);
	 gotoxy(1,3);
	 cout<<"|      Tienda Trilenium - POLITICAS           			   |";
	 setColor(LIGHTRED);
	 gotoxy(1,4);
	 cout<<"--------------------------------------------------------------------"<<endl;
	 setColor(WHITE);
	 cout <<"| Todos nuestros productos poseen 30 dias de prueba, 		   |" << endl;
	 cout <<"| solo se aceptan cambios por otro producto o talle manteniendo su |" << endl;
	 cout <<"| correspondiente etiqueta, no se realizan devoluciones de dinero. |"<< endl;
	 setColor(RED);
	 cout << "--------------------------------------------------------------------" << endl <<endl;
	 setColor(WHITE);
	 cout<<"Presione cualquier tecla para volver al menu principal...";

	}

void menuContacto(){

	 setColor(LIGHTRED);
	 cout << "					  #Buenos Aires, Argentina" << endl;
	 cout<<"----------------------------------------------------"<< endl;
	 setColor(WHITE);
	 gotoxy(1,3);
	 cout<<"|      Tienda Trilenium - CONTACTO                 |";
	 setColor(LIGHTRED);
	 gotoxy(1,4);
	 cout<<"----------------------------------------------------"<<endl;
	 setColor(WHITE);
	 cout <<"| Avenida Siempreviva 742 - Gral. Pacheco (Tigre)  |" << endl;
	 cout <<"| Teléfonos: (5411) 4740-5040 / (5411) 4740-0216   |" << endl;
	 cout <<"| Mail: matiassilvero3@gmail.com 		   |" << endl;
	 setColor(RED);
	 cout << "----------------------------------------------------" << endl << endl;
	 setColor(WHITE);
	 cout<<"Presione cualquier tecla para volver al menu principal...";

	}

bool buscarCliente(int dniBuscar){

	 FILE * p = fopen("clientes.dat","rb");
	 if(p==NULL){
		 cout << "Error al abrir archivo de clientes ";
		 cin.get();
		 return false;
		}
	 Cliente regC;
	 while(fread(&regC,sizeof(Cliente),1,p)==1){
		 if(regC.getDni() == dniBuscar){
			 return true;
			}
		}
	 fclose(p);

	 return false;
	}

//CUENTO CANTIDAD DE CLIENTES EN EL ARCHIVO
int cantidadDeClientes(){

     FILE * p = fopen("clientes.dat","rb");
     if(p == NULL){
         anykey("Error al abrir el archivo de clientes. ");
         return 0;
        }
     int bytes, cantClientes;
     fseek(p, 0, SEEK_END);
     bytes = ftell(p);
     cantClientes = bytes/sizeof(Cliente);
     fclose(p);

     return cantClientes;
    }

//ORDENO CLIENTES POR APELLIDO
void ordenarClientesPorApellido(Cliente * vec, int tam){//RECIBE UN VECTOR Y SU TAMAÑO

	 int i,j,pos;
	 Cliente aux;
	 for(i=0;i<tam-1;i++){
		 pos=i;
		 for(j=i+1;j<tam;j++){
			 if(strcmp(vec[j].getApellido(),vec[pos].getApellido())<0){
				 pos=j;
				}
			}
		 aux = vec[i];
		 vec[i] = vec[pos];
		 vec[pos] = aux;
		}
	}

//MUESTRO CLIENTES USANDO MD
void mostrarClientesPorApellidoConMD(){

     int cant = cantidadDeClientes();
     if(cant==0){
	    anykey("No hay clientes todavia.");
	    return;
	   }

     Cliente * vec;
     vec = (Cliente*)malloc(cant*sizeof(Cliente));

     if (vec==NULL){
	    anykey("No hay memoria para continuar.");
	    return;
	   }

     FILE *p = fopen("clientes.dat", "rb");
     if(p==NULL){
        cout<<"Error con el archivo clientes.";
	    free(vec);
	    return;
	   }
     fread(&vec[0],sizeof(Cliente),cant,p);
     fclose(p);

     ordenarClientesPorApellido(vec,cant);

     int i;
     cout<<"Listando todos tus clientes ordenados por Apellido: "<<endl<<endl;
     for(i=0;i<cant;i++){
	   // mostrarVectorClientes(vec[i]);
	    vec[i].mostrarCliente();
	    cout<<endl;
	   }
//    void mostrarVectorClientes(Cliente reg){
//    if(reg.estado==true){
//    cout<<"------------------------------------"<<endl;
//    cout<<"Id                 : "<<reg.id<<endl;
     free(vec);
     anykey();
	}
