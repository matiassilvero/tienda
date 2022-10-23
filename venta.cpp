#include <iostream>
#include <iomanip>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "funciones.h"
#include "cliente.h"
#include "fecha.h"
#include "venta.h"
#include "producto.h"

const char * AVENTAS = "ventas.dat";

bool Venta::cargarVenta(int dniCliente, float importe,int idProducto){

	 FILE*p = fopen("clientes.dat","rb");
	 if(p==NULL){
		 anykey("Error con el archivo clientes. ");
		 return false;
		}

	 Cliente regC;
	 Fecha fechaNacimientoCliente;

	 while(fread(&regC,sizeof(Cliente),1,p) == 1){
		 if(regC.getDni() == dniCliente){
			 setDni(dniCliente);
			 setNombre(regC.getNombre());
			 setApellido(regC.getApellido());
			 setMail(regC.getMail());
			 fechaNacimientoCliente = regC.getFechaNacimiento();
			}
		}

	 fclose(p);


	 FILE*p1 = fopen("productos.dat","rb");
	 if(p1==NULL){
		 anykey("Error con el archivo productos. ");
		 return false;
		}

	 Producto regP;

	 while(fread(&regP,sizeof(Producto),1,p) == 1){
		 if(regP.getIdProducto() == idProducto){
			 setIdProducto(idProducto);
			}
		}

	 fclose(p1);

	 Fecha fechaActual;
	 if(int edad = fechaActual-fechaNacimientoCliente >= 65){
		 setDescuento(20);
		}
	 else{
		 setDescuento(0);
		}
	 setPrecio(importe);
	 setFechaVenta(fechaActual);
	 cout << endl;

	 return true;

	}

void Venta::setDni(int ndni){
	 dni = ndni;
	}

void Venta::setIdProducto(int nIdProducto){
	 idProducto= nIdProducto;
	}

void Venta::setNombre(const char * nnombre){
	 strcpy(nombre,nnombre);
	}

void Venta::setApellido(const char * napellido){
	 strcpy(apellido,napellido);
	}

void Venta::setMail(const char * nmail){
	 strcpy(mail,nmail);
	}

void Venta::setPrecio(float nprecio){
	 precio = nprecio;
	}

void Venta::setDescuento(float ndescuento){
	 descuento = ndescuento;
	}

void Venta::setFechaVenta(Fecha nfechaventa){
	 fechaVenta = nfechaventa;
	}

void Venta::mostrarEncabezadoVenta(){

     cout << left;
     cout << setw(3) << " ID";
     cout << setw(12) << "   DNI ";
     cout << setw(12) << "Nombre ";
     cout << setw(12) << "Apellido ";
     cout << setw(17) << "    Mail";
     cout << setw(8) << "Precio";
     cout << setw(12) << "Descuento";
     cout << setw(13) << "Fecha Venta" << endl;
     cout << "----------------------------------------------------------------------------------------" << endl;

    }

void Venta::mostrarVenta(){

	 cout << left;
	 cout << " " << setw(4) << idProducto;
	 cout << setw(10) << dni;
	 cout << setw(11) << nombre;
	 cout << setw(11) << apellido;
	 cout << setw(18) << mail;
	 cout << "$" << fixed << setprecision(2) << setw(12) << precio;
	 cout << "%" << setw(8) << descuento;
	 cout << setw(1); fechaVenta.mostrarFecha();

	}

void Venta::mostrarTodasLasVentas(){

	 FILE * p = fopen(AVENTAS,"rb");
	 if(p == NULL){
		 anykey("Error al abrir el archivo ventas. ");
		 return;
		}
	 Venta regV;
	 mostrarEncabezadoVenta();
	 while(fread(&regV,sizeof(Venta),1,p) == 1){
		 regV.mostrarVenta();
		 cout << endl;
		}
	 fclose(p);

	}

bool Venta::grabarVenta(){

	 FILE * p = fopen(AVENTAS,"ab");
	 if(p == NULL){
		 cout << "Error con el archivo de ventas. " << endl;
		 anykey();
		 return false;
		}
	 bool escribio = fwrite(this, sizeof * this, 1, p);
     fclose(p);

     return escribio;

	}

















