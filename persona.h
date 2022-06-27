#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

class Persona{

	 protected:
	  int dni;
	  char nombre[20];
	  char apellido[20];
	  Fecha fechaNacimiento;
	  int genero;

	 public:
	  void setDni();
	  void setNombre();
	  void setApellido();
	  void setEdad();
	  void setGenero();

	  int getDni(){return dni;}
	  char * getNombre(){return nombre;}
	  char * getApellido(){return apellido;}
	  Fecha getFechaNacimiento(){return fechaNacimiento;}
	  int getGenero(){return genero;}

	  bool cargarPersona();
	  void mostrarPersona();
//	  bool grabarEnDisco();
//	  bool leerDeDisco(int);

	};

#endif // PERSONA_H_INCLUDED
