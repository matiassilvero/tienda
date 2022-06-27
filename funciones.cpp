#include <iostream>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "funciones.h"
#include "producto.h"
#include "fecha.h"

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
	 cout<<"| 2- REPORTES    			|"<<endl;
	 setColor(RED);
	 gotoxy(1,8);
	 cout<<"| 3- VOLVER AL MENU PRINCIPAL 	 	|"<<endl;
	 setColor(WHITE);
	 gotoxy(1,9);
	 cout << "-----------------------------------------" << endl;
	 cout<<"| 0- FINALIZAR PROGRAMA      	 	|"<<endl;
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

