#include <iostream>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "funciones.h"
#include "producto.h"
#include "fecha.h"
#include "venta.h"
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
	 cout<<"| 1- VER PRODUCTOS       	 	|"<< endl;
	 setColor(RED);
	 gotoxy(1,6);
	 cout<<"| 2- REALIZAR COMPRA  		    	|"<<endl;
	 setColor(WHITE);
	 gotoxy(1,7);
	 cout<<"| 3- VER PROMOCIONES    	        |"<<endl;
	 setColor(RED);
	 gotoxy(1,8);
	 cout<<"| 4- CONTACTO 			 	|"<<endl;
	 setColor(WHITE);
	 gotoxy(1,9);
	 cout << "-----------------------------------------" << endl;
	 cout<<"| 0- FINALIZAR PROGRAMA      	 	|"<<endl;
	 cout << endl ;
	 setColor(LIGHTRED);
	 gotoxy(42,11);
	 cout <<"Todos nuestros productos poseen 30 dias de prueba, 		  " << endl;
	 gotoxy(42,12);
	 cout <<"solo se aceptan cambios por otro producto o talle manteniendo su " << endl;
	 gotoxy(42,13);
	 cout <<"correspondiente etiqueta, no se realizan devoluciones de dinero. "<< endl;
	 setColor(WHITE);
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
	 cout<<"| 1- CONFIGURACION/REPORTES   		|"<<endl;
	 setColor(WHITE);
	 gotoxy(1,7);
	 cout<<"| 2- LISTADOS    			|"<<endl;
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
	 setColor(LIGHTRED);
	 gotoxy(1,6);
	 cout<<"| 2- MUJER  		 	 	|"<<endl;
	 setColor(WHITE);
	 gotoxy(1,7);
	 cout<<"| 3- OTRO    				|"<<endl;
	 setColor(LIGHTRED);
	 gotoxy(1,8);
	 cout << "-----------------------------------------" << endl;
	 cout<<"| 0- VOLVER AL MENU ANTERIOR 		|"<<endl;
	 cout << endl ;
	 setColor(WHITE);
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
	 cout<<"| JUBILADES(>=65 años): 20%OFF en toda la tienda|"<< endl;
	 setColor(RED);
	 cout << "-------------------------------------------------" << endl << endl;
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

int devolverPosicionProducto(int idABuscar){

	 FILE*p=fopen("productos.dat","rb");
	 if(p==NULL){
		 cout <<"Error con archivo productos"<<endl;
		 return -1;
		}
	 Producto regP;
	 int i= 0;
	 while(fread(&regP,sizeof(Producto),1,p)==1){
		 if(regP.getIdProducto()== idABuscar){
			 fclose(p);
			 return i;
			}
		 i++;
		}
	 fclose(p);
	 return -1;

	}

Producto devolverProductoPorPosicion(int posicion){

	 FILE*p=fopen("productos.dat","rb");
	 if(p==NULL){
		 cout <<"Error con archivo productos"<<endl;
		}

	 Producto regP;
     fseek(p, posicion*sizeof(Producto), SEEK_SET);//se posiciona de acuerdo a la posicion q le pase
     fread(&regP,sizeof(Producto), 1, p);
     fclose(p);

     return regP;


	}

bool sobreescribirStock(Producto regP, int posicion){

	 FILE*p=fopen("productos.dat","rb+");
	 if(p==NULL){
		 cout <<"Error con archivo productos"<<endl;
		}
	 bool escribio;
     fseek(p,posicion*sizeof(Producto),SEEK_SET);
     escribio=fwrite(&regP, sizeof(Producto), 1, p);

     fclose(p);
     return escribio;

	}

///edito un stock de producto por ID
void editarStockDeProducto(int idABuscar, int cantidad){//modifica stock del producto

     int posicion = devolverPosicionProducto(idABuscar);//devuelve la posicion del id que puse
     if(posicion>=0){

		 Producto regP = devolverProductoPorPosicion(posicion);//me devuelve el producto q le pase segun la posicion

		 ///convirtiendo nuevo stock
		 int nStock = regP.getStock() - cantidad;
		 regP.setStock(nStock);

		 sobreescribirStock(regP,posicion);//ACA LO MODIFICA
		 cout<<"Stock modificado, stock actual: "  << regP.getStock() << endl;

		}
	}

bool buscarClientePorDni(int dniBuscado){

	 FILE * p = fopen("clientes.dat","rb");
	 if(p==NULL){
		 anykey("Error con el archivo clientes.");
		 return false;
		}

	 Cliente regC;
	 while(fread(&regC,sizeof(Cliente),1,p) == 1 ){
		 if(regC.getDni() == dniBuscado){
			 fclose(p);
			 return true;
			}
		}
	 fclose(p);
	 return false;
	}

Producto devolverProductoPorId(int idProducto){

	 FILE * p = fopen("productos.dat","rb");
	 if(p==NULL){
		 anykey("Error con el archivo productos.");
		}

	 Producto regP;
	 while(fread(&regP,sizeof(Producto),1,p) == 1 ){
		 if(regP.getIdProducto() == idProducto){
			 return regP;
			}
		}
	 cout << "No se encontro ese Id. " << endl;
	 regP.setTipo(-1);

	 anykey();
	 fclose(p);

	}

float importeConDescuento(int dni, float importeTotal){

	 FILE * p = fopen("clientes.dat","rb");
	 if(p==NULL){
		 anykey("Error con el archivo clientes.");
		 return -1;
		}

	 Cliente regC;
	 Fecha fechaActual;
	 int edad;

	 while(fread(&regC,sizeof(Cliente),1,p) == 1 ){
		 if(regC.getDni() == dni){
			 edad = fechaActual - regC.getFechaNacimiento();
			}
		}

	 if(edad>=65){
		 importeTotal = importeTotal * 0.8;
		}

	 return importeTotal;

	 fclose(p);

	}

Cliente devolverClientePorDni(int dniBuscado){

	FILE * p = fopen("clientes.dat","rb");
	 if(p==NULL){
		 anykey("Error con el archivo clientes.");
		}

	 Cliente regC;
	 while(fread(&regC,sizeof(Cliente),1,p) == 1 ){
		 if(regC.getDni() == dniBuscado){
			 fclose(p);
			 return regC;
			}
		}
	 fclose(p);

	}

Cliente devolverClientePorPosicion(int posicion){

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


int devolverDescuentoPorEdad(int dni){

	 FILE*p = fopen("clientes.dat","rb");
	 if(p==NULL){
		 anykey("Error con el archivo clientes. ");
		 return false;
		}

	 Cliente regC;
	 Fecha fechaNacimientoCliente;

	 while(fread(&regC,sizeof(Cliente),1,p) == 1){
		 if(regC.getDni() == dni){
			 fechaNacimientoCliente = regC.getFechaNacimiento();
			}
		}
	 fclose(p);

	 Fecha fechaActual;
	 int edadCliente = fechaActual - fechaNacimientoCliente;
	 if(edadCliente>=65){
		 return 20;
		}
	 else{
		 return 0;
		}

	}

bool comprar(int dniRecibido){

	 bool continuarCompra=true;
	 float importeFinal=0;
	 int cantidadPrendasTotales=0;

	 while(continuarCompra){
		 int idProducto,cantidad;
	     float importeDeEstaVenta =0;

	     cout << ">Ingrese el ID de la prenda que desea comprar, recuerde nuestras promociones en el menu principal: ";
	     cin >> idProducto;

	     Producto aux = devolverProductoPorId(idProducto);//en idProducto ya tengo todo el producto que eligio
		 if(aux.getTipo() == -1){
			 cout << "Error con el id"<< endl;
			 return false;
			}

	     cout << "Producto a comprar: " << aux.getNombre() << " $" << aux.getPrecio() << "c/u" <<endl;

	     cout << ">Ingrese la cantidad que desea, ese producto dispone de " << aux.getStock() << " unidades: ";
	     cin >> cantidad;

	     int respuesta;
	     if(cantidad>aux.getStock()){
	     	 cout << "No puede seleccionar mas de lo que haya en stock, desea comprar " << aux.getStock() << "? 1-Si 2-No:";
	     	 cin >> respuesta;///LE DA LA CHANCE AL COMPRADOR Q ELIJA EL MAXIMO STOCK
	     	 if(respuesta==1){
	    		 cantidad = aux.getStock();
	    		}
	     	 else{
	     		 cout << "Se cancela la compra , intente cuando dispongamos de stock "<< endl;
	     		 continuarCompra = false;
	    		}
	    	}
		 if(cantidad == 0){
			 cout << "Se cancela la compra , no puede seleccionar 0 prendas "<< endl;
			 continuarCompra = false;
			}

		 if(cantidad<=aux.getStock() && cantidad != 0){

			 importeDeEstaVenta = cantidad * importeConDescuento(dniRecibido,aux.getPrecio());

			 //cout << "Compra hecha, valor: $" << importeDeEstaVenta<< endl;

			 float pago;
			 cout << ">Total de compra: $"<< importeDeEstaVenta << ". Ingrese con cuanto dinero abona: $";///sumar todos los importes del vector
			 cin >> pago;
			 cout << endl;

			 if(pago>=importeDeEstaVenta){

				 editarStockDeProducto(idProducto,cantidad);
				 importeFinal+= importeDeEstaVenta;
				 cantidadPrendasTotales+=cantidad;

				 cout << "Recibe un vuelto de $" << pago - importeDeEstaVenta << endl;
				 cout << "Muchas gracias por su compra! La factura fue enviada a " << devolverClientePorDni(dniRecibido).getMail();

				 Venta regV;
				 regV.cargarVenta(dniRecibido,importeDeEstaVenta,idProducto);
				 regV.grabarVenta();

				 int respuesta2;
				 cout << endl << ">Desea comprar otro producto? 1- Si 2- No: " ;
				 cin >> respuesta2;

				 if(respuesta2==2){
					 cout << "Gracias por su tiempo " << endl;
					 continuarCompra=false;
					}
				}
			 else{
				 cout << "No le alcanza para realizar el pago, intente mas tarde. " << endl;
				 continuarCompra=false;
				}
			}
		}

		cout << endl << "Importe total de compra: $" << importeFinal << ", cantidad de prendas: " << cantidadPrendasTotales << endl;

	}

bool realizarCompra(){///ver si puedo hacerlo con while, pero no podria ir guardando cada prenda en mi vector dinamico

	 int dni;
	 float importeFinal=0;

	 cout << "Ingrese su dni: ";
	 cin >> dni;
	 if(buscarClientePorDni(dni)){
		 cout << "Esta registrado, continuemos :) " << endl;;
		 Fecha fechaActual;
		 cout << "Nombre: " << devolverClientePorDni(dni).getNombre() << ". Edad: " << fechaActual - devolverClientePorDni(dni).getFechaNacimiento() << endl <<endl;
		}
	 else{
		 cout << "Debe registrarse para realizar la compra " << endl;
		 Cliente regC;
		 if(regC.cargarCliente()){
			 regC.grabarEnDisco();
			}
		 else{
			 return false;
			}
		 cout << endl;
		}

	 comprar(dni);
	 return true;

	}

///VALIDAR FECHA
bool validarFecha(int dia, int mes, int anio){

	 Fecha fechaEnviada(dia,mes,anio);
	 Fecha actual;
     bool fechaValida = false;
     if(mes > 0 && mes < 13){
         switch(mes){
             case 1:/// Enero, marzo, mayo, julio, agosto, octubre y diciembre (meses de 31 dias)
             case 3:
             case 5:
             case 7:
             case 8:
             case 10:
             case 12:{
                 if(dia > 0 && dia < 32 && anio > 1895 && anio <= actual.getAnio() && fechaEnviada < actual){
					 fechaValida = true;
					}
				}
             break;

             case 4:///Abril, junio, septiembre y noviembre (meses de 30 días)
             case 6:
		     case 9:
		     case 11:{
		  	     if(dia>0 && dia<31 && anio>1895 && anio <= actual.getAnio() && fechaEnviada < actual){
					 fechaValida = true;
					}
				}
		     break;

		     case 2:{///Febrero, si es bisiesto, tendrá 29 días
				 if((anio%4 == 0) && (anio%100 != 0) || (anio%400 == 0)){
					 if(dia>0 && dia<30 && anio>1895 && anio <= actual.getAnio()&& fechaEnviada < actual){
						 fechaValida = true;
						 }
					}
				 else{///Si no es bisiesto, tendrá 28
					 if(dia>0 && dia<29 && anio>1895 && anio <= actual.getAnio() && fechaEnviada < actual){
						 fechaValida = true;
						}
					}
				}
		  	  break;
			}
		}
	 return fechaValida;
	}

int cantidadDeClientes(){
     int cantidadClientes;
     FILE *p = fopen("clientes.dat","rb");
      if(p == NULL){
        cout << "Error en la apertura del archivo.";
        cin.get();
        return -1;
      }
      fseek(p, SEEK_SET, SEEK_END);
      cantidadClientes = ftell(p)/sizeof (Cliente);
      return cantidadClientes;
    }

int cantidadDeProductos(){
     int cantidadProductos;
     FILE *p = fopen("productos.dat","rb");
      if(p == NULL){
        cout << "Error en la apertura del archivo.";
        cin.get();
        return -1;
      }
      fseek(p, SEEK_SET, SEEK_END);
      cantidadProductos = ftell(p)/sizeof (Producto);
      return cantidadProductos;
    }

/*	///VALIDAR ENTERO
int validarIngresoEntero(){

     int op;
     while(!(cin>>op)){
		 setColor(LIGHTRED);
         cout << " No ingreso un valor numerico: ";
         cin.clear();
         cin.ignore(123,'\n');

		}
     return op;
	}



*/

//bool realizarCompra(){///ver si puedo hacerlo con while, pero no podria ir guardando cada prenda en mi vector dinamico
//
//	 int dni;
//	 Venta * vectorPrendas;
//	 int cantidadCompras;
//	 int cantidadTotalPrendas=0;
//
//	 cout << "Ingrese su dni: ";
//	 cin >> dni;
//	 if(buscarClientePorDni(dni)){
//		 cout << "Esta registrado, continuemos :) " << endl << endl;
//		}
//	 else{
//		 cout << "Debe registrarse para realizar la compra " << endl;
//		 Cliente regC;
//		 regC.cargarCliente();
//		 regC.grabarEnDisco();
//		 cout << endl;
//		}

//	 cout << ">Ingrese la cantidad de compras que va a realizar: " << endl << endl;//el usuario ya sabe cuantas prendas distintas va comprar, ver si se puede cambiar
//	 cin >> cantidadCompras;
//	 vectorPrendas = new Venta[cantidadCompras];
//	 if(vectorPrendas == NULL){
//		 anykey("Error al crear el vector para las prendas. ");
//		 return false;
//		}
//
//	 for (int i=0; i<cantidadCompras; i++){
//
//		 int idProducto,cantidad;
//		 float importeTotal, importeFinal=0;
//
//         cout << ">Ingrese el ID de la prenda que desea comprar, recuerde nuestras promociones en el menu principal: ";
//         cin >> idProducto;
//
//         Producto aux = devolverProductoPorId(idProducto);//en idProducto ya tengo todo el producto que eligio
//
//         cout << "Producto a comprar: " << aux.getNombre() << endl;
//
//         cout << ">Ingrese la cantidad que desea, ese producto dispone de " << aux.getStock() << " unidades: ";
//         cin >> cantidad;
//
//         int respuesta;
//         if(cantidad>aux.getStock()){
//         	 cout << "No puede seleccionar mas de lo que haya en stock, desea comprar " << aux.getStock() << "? 1-Si 2-No"<<endl;
//         	 cin >> respuesta;
//         	 if(respuesta==1){
//         		 cantidad = aux.getStock();
//         		}
//         	 else{
//         		 anykey("Se cancela toda la compra de este producto, intente cuando dispongamos de stock");
//         		 return false;
//         		}
//         	}
//
//		 importeTotal = cantidad * aux.getPrecio();
//		 cantidadTotalPrendas+=cantidad;
//
//		 vectorPrendas[i].setDni(dni);
//		 vectorPrendas[i].setNombre(devolverClientePorDni(dni).getNombre());
//		 vectorPrendas[i].setApellido(devolverClientePorDni(dni).getApellido());
//		 vectorPrendas[i].setMail(devolverClientePorDni(dni).getMail());
//		 vectorPrendas[i].setDescuento(devolverDescuentoPorEdad(dni));
//		 if(devolverDescuentoPorEdad(dni) > 0){
//			 vectorPrendas[i].setPrecio(importeTotal * (100 - devolverDescuentoPorEdad(dni)/100)) ;
//			}
//		 else{
//			 vectorPrendas[i].setPrecio(importeTotal);
//			}
//		 Fecha fechaActual;
//		 vectorPrendas[i].setFechaVenta(fechaActual);///aca ya tengo el vector en I cargado
//
//		 vectorPrendas[i].cargarVenta(dni,importeTotal);
//		 vectorPrendas[i].grabarVenta();
//
//		 cout << endl;
//
//		}
//
//	 delete vectorPrendas;
//
//	 		    cout<<"Mostrando tu vector: "<<endl;
//		    for(int i=0;i<cantidadCompras;i++){
//		        vectorPrendas[i].mostrarVenta();
//		    }
//		    cout<<endl;
//
//	 float pago;
//	 float importeFinal = 0;
//
//	 for(int i=0; i<cantidadCompras; i++){
//		 importeFinal = vectorPrendas[i].getPrecio();
//		}
//
//	 cout << ">Precio total: $" << importeFinal << ". Ingrese con cuanto dinero abona: $";///sumar todos los importes del vector
//	 cin >> pago;
//
//	 //float importeFinal = importeConDescuento(dni,importeTotal); no es necesario xq ya voy haciendo los descuentos cuando cargo vector
//
//	 cout << "Ha comprado en total: " << cantidadTotalPrendas << " prendas por $" << importeFinal <<endl;//sumar todas las cantidad del vec
//	 cout << "Recibe un vuelto de $" << pago - importeFinal << endl;
//
//	}
