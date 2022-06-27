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
						 //muestro todos los productos de hombres
						 break;
						}
					 case 2:{//sector mujeres
					 	 //muestro todos los productos de mujeres
						 break;
						}
					 case 3:{//sector otros
					 	 //muestro todos los productos de otros
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
			     menuOculto();
			     anykey();
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
