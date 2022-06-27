#include <iostream>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "funciones.h"
#include "producto.h"

const char * APRODUCTOS = "productos.dat";

bool Producto::cargarProducto(){

	 idProducto = generarIdProducto();

	 cout << "Ingrese la marca(1-Adidas, 2-NIKE, 3-PUMA): ";
	 cin >> marca;

	 cout << "Ingrese el nombre del producto: ";
	 cin.ignore();
	 cin.getline(nombre,20);

	 cout << "Ingrese el stock del producto: ";
	 cin >> stock;

	 cout << "Ingrese el genero del producto(1-Hombre, 2-Mujer, 3-Unisex): ";
	 cin >> genero;

	 cout << "Ingrese el tipo de producto(1-Prenda superior, 2-Prenda inferior, 3-Ropa interior): ";
	 cin >> tipo;

	 cout << "Ingrese precio: ";
	 cin >> precio;

	 return true;

	}

void Producto::mostrarProducto(){

	 cout << "Id: " << idProducto << endl;

	 cout << "Marca: ";
	 if(marca == 1){
		 cout << "Adidas" << endl;
		}
	 else if(marca==2){
		 cout << "NIKE" << endl;
		}
	 else{
		 cout << "PUMA" << endl;
		}

	 cout << "Stock: " << stock << " unidades " << endl;

	 cout << "Genero: ";
	 if(genero == 1){
		 cout << "Hombre" << endl;
		}
	 else if(genero==2){
		 cout << "Mujer" << endl;
		}
	 else{
		 cout << "Unisex" << endl;
		}

	 cout << "Tipo: ";
	 if(tipo == 1){
		 cout << "Prenda superior" << endl;
		}
	 else if(tipo==2){
		 cout << "Prenda inferior" << endl;
		}
	 else{
		 cout << "Ropa interior" << endl;
		}

	 cout << "Precio: ";
	 cout << "$" << precio;

	}

bool Producto::mostrarTodosLosProductos(){

	 FILE * p =fopen(APRODUCTOS,"rb");
	 if(p==NULL){
		 cout << "Error con el archivo de productos. ";
		 cin.get();
		 return false;
		}
	 Producto regP;
	 while(fread(&regP,sizeof(Producto),1,p) == 1){
		 regP.mostrarProducto();
		}
	 fclose(p);

	 return true;

	}

bool Producto::grabarProductoEnDisco(){

	 FILE*p=fopen(APRODUCTOS,"ab");
	 if(p==NULL){
		 cout<< "Error con el archivo productos. ";
		 cin.get();
		 return false;
		}
	 bool escribio = fwrite(this, sizeof * this, 1, p);
     fclose(p);

     return escribio;

	}

int generarIdProducto(){

     FILE* p = fopen(APRODUCTOS,"ab");
     if(p==NULL){
		 cout << "Error con el archivo clientes. ";
		 cin.get();
		 return -1;
        }
     fseek(p,SEEK_SET,SEEK_END);
     int id=((ftell(p)/sizeof(Producto))+1);
     fclose(p);

     return id;

	}
