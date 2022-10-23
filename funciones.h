#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void menuPrincipal();
void menuOculto();
void menuPoliticas();
void menuContacto();
int generarIdProducto();
void menuProductos();
void menuPromociones();
bool buscarClientePorDni(int);
void mostrarClientesPorApellidoConMD();
void ordenarClientesPorApellido();
int cantidadDeClientes();
int cantidadDeProductos();
bool buscarIdProducto(int);
bool realizarCompra();
void cargarVectorClientesMD();
bool validarFecha(int,int,int);

#endif // FUNCIONES_H_INCLUDED
