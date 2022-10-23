#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

class Venta{

	 private:
	  int dni;
	  char nombre[10];
	  char apellido[10];
	  char mail[15];

	  int idProducto;
	  float precio;
	  float descuento;
	  Fecha fechaVenta;

	 public:
	  bool cargarVenta(int,float,int);//si es true va guardar la venta
	  void mostrarVenta();
	  void mostrarTodasLasVentas();
	  bool grabarVenta();
	  void mostrarEncabezadoVenta();

	  void setDni(int);
	  void setNombre(const char*);
	  void setApellido(const char*);
	  void setMail(const char*);

	  void setIdProducto(int);
	  void setPrecio(float);
	  void setDescuento(float);
	  void setFechaVenta(Fecha);

	  int getDni(){return dni;}
	  char * getNombre(){return nombre;}
	  char * getApellido(){return apellido;}
	  char * getMail(){return mail;}
	  float getPrecio(){return precio;}
	  float getDescuento(){return descuento;}
	  Fecha getFechaVenta();

	};

#endif // VENTA_H_INCLUDED
