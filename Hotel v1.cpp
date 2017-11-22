#include "libHote.h"
//estructuras
typedef struct SCuarto{ ///inf. cuartos
	bool disponible;
	float precio;
	char tipo[20];
	char descripcion[20];
	char CI[11];
}Cuarto;
typedef struct SPersona{ ///contiene los datos personales
	char nombre[20];
	char apellido[20];
	char celular[11];
	char CI[11];
	int edad;
	Cuarto cuarto;
}Persona;
typedef struct SCliente{ ///Lista de clientes
	Persona cliente;
	struct SCliente *siguiente;
	struct SCliente *anterior;
}*Cliente;
typedef struct SHabitacion{ //habitaciones del hotel
	Cuarto cuarto1;
	Cuarto cuarto2;
	Cuarto cuarto3;
}Habitacion;
typedef struct SDia{ //lista que simula un calendario de los dias del mes
	Habitacion habitacion;
	struct SDia *siguiente;
	struct SDia *anterior;
}*Dia;
typedef struct SMes{ //lista de meses del año
	Dia dia;
	struct SMes *siguiente;
	struct SMes *anterior;
}*Mes;
//declaracion
//desarrollo
int main(){
	return 0;
}
