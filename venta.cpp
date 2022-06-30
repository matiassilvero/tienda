#include <iostream>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "funciones.h"
#include "cliente.h"
#include "fecha.h"
#include "venta.h"
#include "producto.h"

const char * AVENTAS = "ventas.dat";

bool Venta::cargarVenta(int dniCliente, int idProducto){

	 FILE*p = fopen("clientes.dat","rb");
	 if(p==NULL){
		 cout << "Error con el archivo clientes. " << endl;
		 anykey();
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

	 //Calculamos edad del cliente
	 Fecha fechaActual;
	 int edadCliente = fechaActual - fechaNacimientoCliente;
	 char nombreCompra[20];

	 FILE*p1 = fopen("productos.dat","rb");
	 if(p1==NULL){
		 cout << "Error con el archivo productos. " << endl;
		 anykey();
		 return false;
		}
	 Producto regP;
	 while(fread(&regP,sizeof(Producto),1,p1) == 1){
		 if(regP.getIdProducto() == idProducto){
			 setNombreProducto(regP.getNombre());
			 setMarca(regP.getMarca());
			 setGenero(regP.getGenero());
			 setTipo(regP.getTipo());
			 if(edadCliente > 65){
				 setDescuento(20);
				}
			 else{
				 setDescuento(0);
				}
			 setPrecio(regP.getPrecio() * ((100 - descuento)/100) );
			 setFechaVenta(fechaActual);
			 strcpy(nombreCompra,regP.getNombre());
			}
		}
	 fclose(p1);
	 cout << nombreCompra << " comprado con exito. " << endl;
	 anykey();

	 return true;
	}

void Venta::setDni(int ndni){
	 dni = ndni;
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

void Venta::setNombreProducto(const char * nnombre){
	 strcpy(nombreProducto,nnombre);
	}

void Venta::setPrecio(float nprecio){
	 precio = nprecio;
	}

void Venta::setMarca(int nmarca){
	 marca = nmarca;
	}

void Venta::setGenero(int ngenero){
	 genero = ngenero;
	}

void Venta::setTipo(int ntipo){
	 tipo = ntipo;
	}

void Venta::setDescuento(float ndescuento){
	 descuento = ndescuento;
	}

void Venta::setFechaVenta(Fecha nfechaventa){
	 fechaVenta = nfechaventa;
	}

void Venta::mostrarVenta(){

	 cout << "Dni del comprador: " << dni << endl;

	 cout << "Nombre: " << nombre << endl;

	 cout << "Apellido: " << apellido << endl;

	 cout << "Mail: " << mail << endl;

	 cout << "Producto: " << nombreProducto << endl;

	 cout << "Precio de compra: $" << precio << endl;

	 cout << "Marca: ";
	 if(marca == 1){
		 cout << "Adidas " << endl;
		}
	 else if(marca == 2){
		 cout << "NIKE" << endl;
		}
	 else{
		 cout << "PUMA" << endl;
		}

	 cout << "Genero: ";
	 if(genero == 1){
		 cout << "Hombre" << endl;
		}
	 else if(genero== 2){
		 cout << "Mujer" << endl;
		}
	 else{
		 cout << "Otro" << endl;
		}

	 cout << "Tipo de prenda: ";
	 if(tipo == 1){
		 cout << "Prenda superior" << endl;
		}
	 else if(tipo== 2){
		 cout << "Prenda inferior" << endl;
		}
	 else{
		 cout << "Ropa interior" << endl;
		}

	 cout << "Descuento(si es que lo tuvo de acorde a su edad): " << descuento << "%" << endl;

	 cout << "Fecha de venta: "; fechaVenta.mostrarFecha(); cout << endl;

	}

void Venta::mostrarTodasLasVentas(){

	 FILE * p = fopen(AVENTAS,"rb");
	 if(p == NULL){
		 anykey("Error al abrir el archivo ventas. ");
		 return;
		}
	 Venta regV;
	 while(fread(&regV,sizeof(Venta),1,p) == 1){
		 regV.mostrarVenta();
		 cout << "------------------"<< endl;
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

















