#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "libHote.h"
#include "libValidation.h"

/*Declaracion de estructura*/
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
	char email [50];
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

/*Declaracion de Funciones*/
void ingresoDeCliente();

/*Desarollo de Funciones*/
void ingresoDeCliente()
{
	SPersona datos;
	do
	{
		printf("Ingrese el nombre: ");
		gets(datos.nombre);
		fflush(stdin);
	}while(validacionNombreYApellido(datos.nombre));
	do
	{
		printf("Ingrese el apellido: ");
		gets(datos.apellido);
		fflush(stdin);
	}while(validacionNombreYApellido(datos.apellido));
	do
	{
		printf("Ingrese su numero de cedula: ");
		gets(datos.CI);
		fflush(stdin);
	}while(validacionCedula(datos.CI));
	do
	{
		printf("Ingrese su email: ");
		gets(datos.email);
		fflush(stdin);
	}while(validacionEmail(datos.email));
	do
	{
		printf("Ingrese su celular: ");
		fflush(stdin);
		gets(datos.celular);
	}while(validacionCelular(datos.celular));
	
	do
	{
		printf("Ingrese su edad: ");
		scanf("%d",&datos.edad);
	}while(validacionEdad(datos.edad));
	
}

int main()
{
	ingresoDeCliente();
	return 0;
}
