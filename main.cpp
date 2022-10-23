#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstring>
using namespace std;
#include <locale.h>
#include "rlutil.h"
using namespace rlutil;
#include "funciones.h"
#include "cliente.h"
#include "producto.h"
#include "venta.h"

///VALIDAR DNI, Q SEA DE 1 A 99999999
///SI PONGO UN DNI Y NO ESTA REGISTRADO, Q AUTOMATICAMENTE SE PONGA ESE DNI NUEVAMENTE EN EL REGISTRO
///MEJORAR LAS PROMOCIONES, Q TENGA OPCIONES Q PUEDA EDITAR DESDE EL MENU OCULTO
///OPCION MOSTRAR TODOS LOS PRODUCTOS
///ESTETICA DEL MENU OCULTO
///MEJORAR INFORME
///Q SE COMPRE DIRECTAMENTE DESDE DONDE SE VEN LOS PRODUCTOS
///Q AVISE CUANDO EL CLIENTE RECIBIO UN DESCUENTO


int main(){

	 setlocale(LC_ALL, "spanish");
	 bool continuar = true;
     int opMenuPrincipal;
     Producto regP;
     cout << "Productos: " << endl;
     regP.mostrarTodosLosProductos();
     anykey();
     Cliente regC;
     cout << "Clientes: " << endl;
     regC.mostrarTodosLosClientes();
     anykey();
     while(continuar){
		 cls();
         menuPrincipal();
         cin>>opMenuPrincipal;
         switch(opMenuPrincipal){
	    	 case 1:{///SECTOR PRODUCTOS
	    	 	 cls();
	    		 bool continuarProductos = true;
	    		 int opProductos;
	    		 menuProductos();
	    		 cin >> opProductos;
                 switch(opProductos){
					 case 1:{//sector hombres
					 	 cls();
						 Producto regP;
						 cout << "Productos para hombres: " << endl;
						 cout << "--------------------------" << endl;
						 regP.mostrarTodosLosProductos(1);
						 anykey();
						 break;
						}
					 case 2:{//sector mujeres
					 	 cls();
						 Producto regP;
						 cout << "Productos para mujeres: " << endl;
						 cout << "--------------------------" << endl;
						 regP.mostrarTodosLosProductos(2);
						 anykey();
						 break;
						}
					 case 3:{//sector otros
					 	 cls();
						 Producto regP;
						 cout << "Productos para todos los sexos: " << endl;
						 cout << "--------------------------" << endl;
						 regP.mostrarTodosLosProductos(3);
						 anykey();
						 break;
						}
					 case 0:{///vuelve al menu ppal.
						 continuarProductos = false;
						 break;
						}
					}
	    		 break;
				}
	    	 case 2:{///SECTOR COMPRA
	    		 cls();
	    		 realizarCompra();
	    		 anykey();
	    		 break;
	    		}
	    	 case 3:{///SECTOR PROMOCIONES
	    		 cls();
	    		 menuPromociones();
	    		 anykey();
	    		 break;
	    		}
	    	 case 4:{///SECTOR CONTACTO
	    		 cls();
	    		 menuContacto();
	    		 anykey();
				 break;
	    		}
	    	 case 6:{///MENU OCULTO
	    	 	 cls();
			     menuOculto();
			     bool continuarOculto = true;
	    		 int opMenuOculto;
	    		 cin >> opMenuOculto;
                 switch(opMenuOculto){
					 case 1:{//sector configuracion
					 	 cls();
						 cout << "Cargar Productos: " << endl;
							Producto regP;
							if(regP.cargarProducto()){
								 regP.grabarProductoEnDisco();
								 cout << "Producto cargado exitosamente. " << endl;
								 anykey();
								}
						 break;
						}
					 case 2:{//sector LISTADOS
					 	 cls();
					 	 int opListados;
					 	 cout << "1- Ver todas las ventas " << endl;
					 	 cout << "2- Ver todos los clientes ordenados por apellido " << endl;
					 	 cout << "3- Ver todos los productos ordenados por stock " << endl;
					 	 cout << "0- Menu principal " << endl;
					 	 cout << "----------------------------------"<<endl;
					 	 cout << "Ingrese una opcion: ";
					 	 cin >> opListados;
					 	 switch(opListados){
							 case 1:{//ventas
							 	 cls();
								 Venta regV;
								 regV.mostrarTodasLasVentas();
								 anykey();
								 break;
								}
							 case 2:{//clientes
								 cls();
								 cout << "Clientes ordenados por apellido: " << endl << endl;
								 Cliente regC;
								 cargarVectorClientesMD();
								 anykey();
							 	break;
							 }
							 case 3:{
								 cls();
								 cout << "Productos: " << endl << endl;
								 cargarVectorProductosMD();
								 anykey();
								 break;
								}
							}
					 	 break;
						}
					 case 0:{
						 continuarOculto = false;
						 break;
						}
					}
				 break;
				}
	    	 default:{
				 anykey("Opcion incorrecta.");
				 break;
				}
	         case 0:{
	    		 cout <<endl <<endl << "Gracias por utilizar este programa." << endl;
	    		 continuar = false;
	    		 break;
                }
	    	}
		}

	 return 0;
	}
