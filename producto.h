#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

class Producto{

	 private:
		int idProducto;
		char nombre[20];
		float precio;
		int marca;//1Adidas 2NIKE 3PUMA
		int stock;
		int genero;//Hombre,Mujer,Unisex
		int tipo;//Prenda superior, prenda inferior, ropa interior

	 public:
	 	bool cargarProducto();
	 	void mostrarProducto(Producto);
	 	void mostrarProducto();
	 	bool mostrarTodosLosProductos();
	 	void mostrarEncabezadoProducto();
	 	bool grabarProductoEnDisco();
	 	bool mostrarTodosLosProductos(int);

		void setIdProducto(int);
		void setMarca(int);
		void setPrecio(float);
		void setNombre(const char*);
		void setStock(int);
		void setGenero(int);
		void setTipo(int);

		int getIdProducto(){return idProducto;}
		int getMarca(){return marca;}
		float getPrecio(){return precio;}
		char * getNombre(){return nombre;}
		int getStock(){return stock;}
		int getGenero(){return genero;}
		int getTipo(){return tipo;}

	};

void cargarVectorProductosMD();

#endif // PRODUCTO_H_INCLUDED
