#include "libHote.h"
#include "libValidation.h"

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
	char email[100];
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
struct SDia{ //lista que simula un calendario de los dias del mes
	Habitacion habitacion;
	int dia;
	struct SDia *siguiente;
	struct SDia *anterior;
};
typedef struct SDia *Dia;
struct SMes{ //lista de meses del año
	Dia dia;
	int numeroMes;
	struct SMes *siguiente;
	struct SMes *anterior;
};
typedef struct SMes *Mes;
//declaracion
void inicio(Mes *);
void calendarioMes(Dia *,int );
void hotel();
void menuVisualizar(Cliente *,Mes *);
void disponibles(Dia *);
void ingresoDeCliente();
//desarrollo
//INCIALIZACION
void calendarioMes(Dia &diaActual,int refDia){
	Dia recorre=diaActual;
	Dia nuevo=new SDia();
	if(diaActual==NULL){
		nuevo->dia=refDia;
		nuevo->habitacion.cuarto1.disponible=true;
		strcpy(nuevo->habitacion.cuarto1.tipo,"Cuarto simple");
		nuevo->habitacion.cuarto1.precio=15,00;
		strcpy(nuevo->habitacion.cuarto1.descripcion,"Cama de una plaza y baño");
		strcpy(nuevo->habitacion.cuarto1.CI,"");
		nuevo->habitacion.cuarto2.disponible=true;
		strcpy(nuevo->habitacion.cuarto2.tipo,"Familiar");
		strcpy(nuevo->habitacion.cuarto2.descripcion,"Cama matrimonial, 2 literas con baño");
		nuevo->habitacion.cuarto2.precio=25,00;
		strcpy(nuevo->habitacion.cuarto2.CI,"");
		nuevo->habitacion.cuarto3.disponible=true;
		strcpy(nuevo->habitacion.cuarto3.tipo,"Matrimonial");
		strcpy(nuevo->habitacion.cuarto3.descripcion,"Cama matrimonial y yacusi");
		nuevo->habitacion.cuarto3.precio=30,00;
		strcpy(nuevo->habitacion.cuarto3.CI,"");
		diaActual=nuevo;
		diaActual->siguiente=NULL;
		diaActual->anterior=NULL;
	}else{
		nuevo->dia=refDia;
		nuevo->habitacion.cuarto1.disponible=true;
		strcpy(nuevo->habitacion.cuarto1.tipo,"Cuarto simple");
		nuevo->habitacion.cuarto1.precio=15,00;
		strcpy(nuevo->habitacion.cuarto1.descripcion,"Cama de una plaza y baño");
		strcpy(nuevo->habitacion.cuarto1.CI,"");
		nuevo->habitacion.cuarto2.disponible=true;
		strcpy(nuevo->habitacion.cuarto2.tipo,"Familiar");
		strcpy(nuevo->habitacion.cuarto2.descripcion,"Cama matrimonial, 2 literas con baño");
		nuevo->habitacion.cuarto2.precio=25,00;
		strcpy(nuevo->habitacion.cuarto2.CI,"");
		nuevo->habitacion.cuarto3.disponible=true;
		strcpy(nuevo->habitacion.cuarto3.tipo,"Matrimonial");
		strcpy(nuevo->habitacion.cuarto3.descripcion,"Cama matrimonial y yacusi");
		nuevo->habitacion.cuarto3.precio=30,00;
		strcpy(nuevo->habitacion.cuarto3.CI,"");
		while(recorre->siguiente!=NULL){
			recorre=recorre->siguiente;
		}
		recorre->siguiente=nuevo;
		nuevo->anterior=recorre;
		nuevo->siguiente=NULL;
	}
	
}
void inicio(Mes &mes){
	Mes nuevo=new SMes();
	Mes recorre=mes;
	if(mes==NULL){
		nuevo->numeroMes=dias_del_mes(actual(mesA));
		for(int i=actual(diaA);i<=nuevo->numeroMes;i++){
			if(i==actual(diaA)){
				nuevo->dia=NULL;
				calendarioMes(nuevo->dia,i);	
			}else{
				calendarioMes(nuevo->dia,i);
			}
		}
		mes=nuevo;
	}else{
		nuevo->numeroMes=dias_del_mes(actual(mesA));
		for(int i=actual(diaA);i<=nuevo->numeroMes;i++){
			calendarioMes(nuevo->dia,i);
		}
		
		while(recorre->siguiente!=NULL){
			recorre=recorre->siguiente;
		}
		nuevo->siguiente=NULL;
		recorre->siguiente=nuevo;
		nuevo->anterior=recorre;
	}
}
//ingresos
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

//VISUALIZAR
void disponibles(Dia &ref){
	Dia aux=ref;
	color(10);
	while(aux!=NULL){
		printf("\nEl dia %d: \n",aux->dia);
		if(aux->habitacion.cuarto1.disponible){
			printf("La habitacion  %s ¡ESTA DISPONIBLE!\n",aux->habitacion.cuarto1.tipo);
			printf("Tiene  %s\n",aux->habitacion.cuarto1.descripcion);
			printf("El precio de la habitacion es:%.2f \n",aux->habitacion.cuarto1.precio);
		}
		if(aux->habitacion.cuarto2.disponible){
			printf("La habitacion  %s ¡ESTA DISPONIBLE!\n",aux->habitacion.cuarto2.tipo);
			printf("Tiene  %s\n",aux->habitacion.cuarto2.descripcion);
			printf("El precio de la habitacion es:%.2f \n",aux->habitacion.cuarto2.precio);
		}
		if(aux->habitacion.cuarto3.disponible){
			printf("La habitacion  %s ¡ESTA DISPONIBLE!\n",aux->habitacion.cuarto3.tipo);
			printf("Tiene  %s\n",aux->habitacion.cuarto3.descripcion);
			printf("El precio de la habitacion es:%.2f \n",aux->habitacion.cuarto3.precio);
		}
		aux=aux->siguiente;
	}
	system("pause");
}
void menuVisualizar(Cliente &clientes,Mes &mes){
	int opc=0;
	const char *opciones[]={"Habitaciones disponibles","Habitaciones ocupadas","Habitaciones reservadas por un cliente","Regresar al menu de reservas"};
	do{
		opc=menu("Menu de Visualizaciones",opciones,4);
		switch(opc){
			case 1:
				disponibles(mes->dia);
			break;
			case 2:
			break;
			case 3:
			break;
		}
	}while(opc!=4);
}
//FUNCION PRINCIPAL DEL PROGRAMA
void hotel(){
	Mes mes=NULL;
	Cliente clientes;
	int opc=0;
	const char *opciones[]={"Reservas Nueva","Buscar Reserva","Eliminar Reserva","Modificar Reserva","Visualizar reservas","Salir al menu principal"};
	inicio(mes);
	do{
		opc=menu("Menu de Reservas",opciones,6);
		color(10);
		switch(opc){
			case 1:
				ingresoDeCliente();
			break;
			case 2:
			break;
			case 3:
			break;
			case 4:
			break;
			case 5:
				menuVisualizar(clientes,mes);
			break;
		}
	}while(opc!=6);
}
int main(){
	hotel();
	return 0;
}
