#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

class Venta{

	 private:
	  int dni;					//archivo Clientes
	  char nombre[20];          //archivo Clientes
	  char apellido[20];        //archivo Clientes
	  char mail[30];            //archivo Clientes
	  char nombreProducto[20];	//archivo Productos
	  float precio;             //archivo Productos
	  int marca;                //archivo Productos
	  int genero;               //archivo Productos
	  int tipo;                 //archivo Productos
	  float descuento;
	  Fecha fechaVenta;

	 public:
	  bool cargarVenta();//si es true va guardar la venta
	  bool cargarVenta(int,int);
	  void mostrarVenta();
	  void mostrarTodasLasVentas();
	  bool grabarVenta();

	  void setDni(int);
	  void setNombre(const char*);
	  void setNombreProducto(const char*);
	  void setApellido(const char*);
	  void setMail(const char*);
	  void setPrecio(float);
	  void setMarca(int);
	  void setGenero(int);
	  void setTipo(int);
	  void setDescuento(float);
	  void setFechaVenta(Fecha);

	  int getDni(){return dni;}
	  char * getNombre(){return nombre;}
	  char * getNombreProducto(){return nombreProducto;}
	  char * getApellido(){return apellido;}
	  char * getMail(){return mail;}
	  float getPrecio(){return precio;}
	  int getMarca(){return marca;}
	  int getGenero(){return genero;}
	  int getTipo(){return tipo;}
	  float getDescuento(){return descuento;}
	  Fecha getFechaVenta();

	};

#endif // VENTA_H_INCLUDED
