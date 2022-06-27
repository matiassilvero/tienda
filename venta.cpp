#include <iostream>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "funciones.h"
#include "cliente.h"
#include "fecha.h"
#include "venta.h"

const char * AVENTAS = "ventas.dat";

bool Venta::cargarVenta(){

	 int d;
	 cout << "dni: ";
	 cin >> d;
	 setDni(d);

	 char n[20];
	 cout << "nombre: ";
	 cin.getline(n,20);
	 setNombre(n);

	 char a[20];
	 char np[20];
	 cout << "apellido: ";
	 cin.getline(a,20);
	 setApellido(a);

	 char mail[20];
	 cout << "mail: " ;
	 cin.getline(mail,20);
	 setMail(mail);

	 float p;
	 cout << "precio: ";
	 cin >>p;
	 setPrecio(p);

	 int m,g,t;
	 float des;
	 cout << "marca: ";
	 cin >>m;
	 setMarca(m);

	 cout << "genero: ";
	 cin >> g;
	 setGenero(g);

	 cout << "tipo:";
	 cin >>t;
	 setTipo(t);

	 cout << "descuento: ";
	 cin >> des;
	 setDescuento(des);

	 Fecha fechaVe;
	 cout << "fecha venta: ";
	 setFechaVenta(fechaVe);

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

	 cout << "Precio de compra: " << precio << endl;

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

	 //cout << "Fecha de venta: " << fechaVenta << endl;

	}


















