#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

class Producto{

	 private:
		int idProducto;
		int marca;//1Adidas 2NIKE 3PUMA
		float precio;
		char nombre[20];
		int stock;
		int genero;//Hombre,Mujer,Unisex
		int tipo;//Prenda superior, prenda inferior, ropa interior

	 public:
	 	bool cargarProducto();
	 	void mostrarProducto();
	 	bool grabarProductoEnDisco();
	 	bool mostrarTodosLosProductos();
	 	bool mostrarTodosLosProductos(int);

		void setIdProducto();
		void setMarca();
		void setPrecio();
		void setNombre();
		void setStock();
		void setGenero();
		void setTipo();

		int getIdProducto(){return idProducto;}
		int getMarca(){return marca;}
		float getPrecio(){return precio;}
		char * getNombre(){return nombre;}
		int getStock(){return stock;}
		int getGenero(){return genero;}
		int getTipo(){return tipo;}

	};

#endif // PRODUCTO_H_INCLUDED
