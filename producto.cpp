#include <iostream>
#include <iomanip>
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

	 cout << "Ingrese el genero del producto(1-Hombre, 2-Mujer, 3-Otros): ";
	 cin >> genero;

	 cout << "Ingrese el tipo de producto(1-Prenda superior, 2-Prenda inferior, 3-Ropa interior): ";
	 cin >> tipo;

	 cout << "Ingrese precio: $";
	 cin >> precio;

	 return true;

	}

bool Producto::mostrarTodosLosProductos(){

	 FILE * p =fopen(APRODUCTOS,"rb");
	 if(p==NULL){
		 cout << "Error con el archivo de productos. ";
		 cin.get();
		 return false;
		}
	 Producto regP;
     mostrarEncabezadoProducto();

	 while(fread(&regP,sizeof(Producto),1,p) == 1){
		 mostrarProducto(regP);
		 cout << endl;
		}
	 fclose(p);

	 return true;

	}

void Producto::mostrarEncabezadoProducto(){

    cout << left;
    cout << setw(3) << " ID";
    cout << setw(19) << "  Nombre del producto";
    cout << setw(9) << "  Precio";
    cout << setw(9) << "   Marca";
    cout << setw(8) << " Stock";
    cout << setw(8) << "Genero";
    cout << setw(20) << "Tipo de prenda" << endl;
    cout << "-------------------------------------------------------------------------" << endl;

}

void Producto::mostrarProducto(){

     cout << left;
     cout << " " << setw(4) << idProducto;
     cout << setw(20) << nombre;
     cout << "$" << fixed << setprecision(2) << setw(10) << precio;
     cout << setw(8);
         if(marca== 1){
             cout << "Adidas";
            }
         else if(marca==2){
             cout << "NIKE";
            }
         else{
             cout << "PUMA";
            }
     cout << setw(4) << stock;
     cout << "  " << setw(8);
         if(genero==1){
             cout << "Hombre";
            }
         else if(genero == 2){
             cout << "Mujer";
            }
         else{
             cout << "Unisex";
            }
     cout << setw(20);
         if(tipo == 1){
             cout << "Prenda superior";
            }
         else if(tipo==2){
             cout << "Prenda inferior";
            }
         else{
             cout << "Ropa interior";
            }

    }

void Producto::mostrarProducto(Producto regP){

     cout << left;
     cout << " " << setw(4) << regP.getIdProducto();
     cout << setw(20) << regP.getNombre();
     cout << "$" << fixed << setprecision(2) << setw(10) << regP.getPrecio();
     cout << setw(8);
         if(regP.getMarca() == 1){
             cout << "Adidas";
            }
         else if(regP.getMarca()==2){
             cout << "NIKE";
            }
         else{
             cout << "PUMA";
            }
     cout << setw(4) << regP.getStock();
     cout << "  " << setw(8);
         if(regP.getGenero()==1){
             cout << "Hombre";
            }
         else if(regP.getGenero() == 2){
             cout << "Mujer";
            }
         else{
             cout << "Unisex";
            }
     cout << setw(20);
         if(regP.getTipo() == 1){
             cout << "Prenda superior";
            }
         else if(regP.getTipo()==2){
             cout << "Prenda inferior";
            }
         else{
             cout << "Ropa interior";
            }

    }

bool Producto::mostrarTodosLosProductos(int gen){

	 FILE * p =fopen(APRODUCTOS,"rb");
	 if(p==NULL){
		 cout << "Error con el archivo de productos. ";
		 cin.get();
		 return false;
		}
	 Producto regP;
	 mostrarEncabezadoProducto();

	 while(fread(&regP,sizeof(Producto),1,p) == 1){
		 if(regP.getGenero()==gen){
			 mostrarProducto(regP);
			 cout << endl;
			}
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
     int id = ((ftell(p)/sizeof(Producto))+1);
     fclose(p);

     return id;

	}

void Producto::setIdProducto(int nIdProducto){
	 idProducto = nIdProducto;
	}

void Producto::setMarca(int nMarca){
	 marca = nMarca;
	}

void Producto::setPrecio(float nPrecio){
	 precio = nPrecio;
	}

void Producto::setNombre(const char * nNombre){
	 strcpy(nombre,nNombre);
	}

void Producto::setStock(int nStock){
	 stock = nStock;
	}

void Producto::setGenero(int nGenero){
	 genero = nGenero;
	}

void Producto::setTipo(int nTipo){
	 tipo = nTipo;
	}

Producto devolverProductoPorPosicion2(int posicion){

	FILE * p = fopen("productos.dat","rb");
	 if(p==NULL){
		 anykey("Error con el archivo productos.");
		}

	 Producto regP;
	 int i=0;
	 while(fread(&regP,sizeof(Producto),1,p) == 1 ){
		 if(i == posicion){
			 fclose(p);
			 return regP;
			}
		 i++;
		}
	 fclose(p);

	}

void ordenarProductos(Producto* vec, int cantidad){

     for(int i = 0; i<cantidad-1; i++){
         int posMenor = i;

         for(int j = i+1; j < cantidad; j++){
             if(vec[j].getStock()<vec[posMenor].getStock()){
				 posMenor = j;
				}
			}
		 Producto iAux;
		 iAux = vec[i];
		 vec[i] = vec[posMenor];
		 vec[posMenor] = iAux;
		}

    }

///MEMORIA DINAMICA
void cargarVectorProductosMD(){

     Producto * vectorDinamico;
     int tamanio;
     tamanio = cantidadDeProductos();
     vectorDinamico = new Producto[tamanio];
     if(vectorDinamico==NULL){
	  	 return;
	  	}
     //cout<<"Carga tu vector: "<<endl;
      Producto regP;
      int i=0;
      for(i=0;i<tamanio;i++){
          vectorDinamico[i] = devolverProductoPorPosicion2(i);
	  	}

     //Para mostrar el vector
     ordenarProductos(vectorDinamico,tamanio);
     regP.mostrarEncabezadoProducto();
     for(int i=0;i<tamanio;i++){
	  	 vectorDinamico[i].mostrarProducto();
	  	 cout << endl;
     }
	  delete vectorDinamico;

	}
