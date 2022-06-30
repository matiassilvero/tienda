#include <iostream>
#include <cstdio>
using namespace std;
#include <locale.h>
#include "rlutil.h"
using namespace rlutil;
#include "funciones.h"
#include "cliente.h"
#include "producto.h"
#include "venta.h"

int main(){
	 setlocale(LC_ALL, "spanish");
	 bool continuar = true;
     int op;
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
         cin>>op;
         switch(op){
	    	 case 1:{///SECTOR PRODUCTOS
	    	 	 cls();
	    		 bool continuarProductos = true;
	    		 int op2;
	    		 menuProductos();
	    		 cin >> op2;
                 switch(op2){
					 case 1:{//sector hombres
					 	 cls();
						 Producto regP;
						 cout << "Productos para hombres: " << endl;
						 cout << "--------------------------" << endl;
						 regP.mostrarTodosLosProductos(1);
						 bool respuesta;
						 cout << endl << "¿Desea realizar la compra de alguna de estas prendas(1- SI 0- NO)? " << endl;
						 cin >> respuesta;
						 if(respuesta==1){
						 	 int dni;
						 	 Venta regV;
						 	 int idP;
							 cout << "Ingrese su DNI, si esta registrado, procederemos a la compra, de lo contrario lo registraremos: ";
							 cin >> dni;
							 if(buscarCliente(dni)){
								 cout << "Esta registrado, continuemos :) " << endl;
								}
							 else{
								 cout << "Usted debe registrarse: " << endl;
								 regC.cargarCliente();
								 regC.grabarEnDisco();
								}
							 cout << "Ingrese el ID del producto que desea: ";
							 cin >> idP;
							 regV.cargarVenta(dni,idP);
							 regV.grabarVenta();
							}
						 break;
						}
					 case 2:{//sector mujeres
					 	 cls();
						 Producto regP;
						 cout << "Productos para mujeres: " << endl;
						 cout << "--------------------------" << endl;
						 regP.mostrarTodosLosProductos(2);
						 bool respuesta;
						 cout << endl << "¿Desea realizar la compra de alguna de estas prendas(1- SI 0- NO)? " << endl;
						 cin >> respuesta;
						 if(respuesta==1){
						 	 int dni;
						 	 Venta regV;
						 	 int idP;
							 cout << "Ingrese su DNI, si esta registrada, procederemos a la compra, de lo contrario la registraremos: ";
							 cin >> dni;
							 if(buscarCliente(dni)){
								 cout << "Esta registrada, continuemos :) " << endl;
								}
							 else{
								 cout << "Usted debe registrarse: " << endl;
								 regC.cargarCliente();
								 regC.grabarEnDisco();
								}
							 cout << "Ingrese el ID del producto que desea: ";
							 cin >> idP;
							 regV.cargarVenta(dni,idP);
							 regV.grabarVenta();
						    }
						 break;
						}
					 case 3:{//sector otros
					 	 cls();
						 Producto regP;
						 cout << "Productos para todos los sexos: " << endl;
						 cout << "--------------------------" << endl;
						 regP.mostrarTodosLosProductos(3);
						 bool respuesta;
						 cout << endl << "¿Desea realizar la compra de alguna de estas prendas(1- SI 0- NO)? " << endl;
						 cin >> respuesta;
						 if(respuesta==1){
						 	 int dni;
						 	 Venta regV;
						 	 int idP;
							 cout << "Ingrese su DNI, si esta registrade, procederemos a la compra, de lo contrario le registraremos: ";
							 cin >> dni;
							 if(buscarCliente(dni)){
								 cout << "Esta registrade, continuemos :) " << endl;
								}
							 else{
								 cout << "Usted debe registrarse: " << endl;
								 regC.cargarCliente();
								 regC.grabarEnDisco();
								}
							 cout << "Ingrese el ID del producto que desea: ";
							 cin >> idP;
							 regV.cargarVenta(dni,idP);
							 regV.grabarVenta();
						    }
						 break;
						}
					 case 0:{///vuelve al menu ppal.
						 continuarProductos = false;
						 break;
						}
					}
	    		 break;
				}
	    	 case 2:{///SECTOR PROMOCIONES
	    		 cls();
	    		 menuPromociones();
	    		 anykey();
	    		 break;
	    		}
	    	 case 3:{///SECTOR POLITICAS
	    		 cls();
	    		 menuPoliticas();
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
	    		 int op3;
	    		 cin >> op3;
                 switch(op3){
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
					 case 2:{//sector REPORTES
					 	 int op4;
					 	 cout << "1- Ver todas las ventas " << endl;
					 	 cout << "2- Ver todos los clientes " << endl;//por genero, ordenados por apellido, ordenados por edad
					 	 cout << "3- Ver todos los productos " << endl;
					 	 cout << "4- Ver recaudacion por fecha " << endl;
					 	 cin >> op4;
					 	 switch(op4){
							 case 1:{//ventas
							 	 cls();
								 Venta regV;
								 regV.mostrarTodasLasVentas();
								 anykey();
								 break;
								}
							 case 2:{//clientes
							 	 cout << "Reporte/consulta de clientes " << endl;
							 	 cout << "----------------------------" << endl;
							 	 cout << "1- Todos " << endl;
							 	 cout << "2- Ordenados por genero " << endl;
							 	 cout << "3- Ordenados por apellido " << endl;
							 	 cout << "4- Ordenados por edad " << endl;
							 	 mostrarClientesPorApellidoConMD();
							 	break;
							 }
							}
					 	 break;
						}
					 case 3:{
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
