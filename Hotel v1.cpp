#include "libHotel.h"
#include "libGraphicalInterface.h"
#include "libValidation.h"

/*Declaracion de estructura*/
typedef struct SCuarto{ ///inf. cuartos
	bool disponible;
	float precio;
	int id;
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
int contadorNodoCliente=0;

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

/*Declaracion de Funciones*/
void inicio(Mes *);
void calendarioMes(Dia *,int );
void hotel();
void nuevoHuesped(Cliente *);
void reservarHotel(Cliente *,Mes *);
int selecDia(int refMes);//imprimer los dias dias del mes provicionalmente
void menuMes(Cliente *,Mes *);
void menuVisualizar(Cliente *,Mes *);
void disponibles(Dia *);
void ingresoDeCliente(Cliente *);
void apruebaReserva(Mes *,int ,int idCuarto);
void informacionClienteTotal(Cliente *);
void informacionClienteEspecifico(Cliente *,int);
void buscarCI(Cliente *);

/*Desarollo de Funciones*/
//Inicializacion
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
		nuevo->habitacion.cuarto1.id=1;
		//cuarto 2
		nuevo->habitacion.cuarto2.disponible=true;
		strcpy(nuevo->habitacion.cuarto2.tipo,"Familiar");
		strcpy(nuevo->habitacion.cuarto2.descripcion,"Cama matrimonial, 2 literas con baño");
		nuevo->habitacion.cuarto2.precio=25,00;
		strcpy(nuevo->habitacion.cuarto2.CI,"");
		nuevo->habitacion.cuarto2.id=2;
		//cuarto 3
		nuevo->habitacion.cuarto3.disponible=true;
		strcpy(nuevo->habitacion.cuarto3.tipo,"Matrimonial");
		strcpy(nuevo->habitacion.cuarto3.descripcion,"Cama matrimonial y yacusi");
		nuevo->habitacion.cuarto3.precio=30,00;
		strcpy(nuevo->habitacion.cuarto3.CI,"");
		nuevo->habitacion.cuarto3.id=3;
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
//Ingreso de lista cliente
void ingresoDeCliente(Cliente &Lista){
	int cont=1;
	char edad[100];
	Cliente Nuevo=new SCliente();
	Cliente Aux;
	Aux=Lista;
	system("cls");
	do
	{
		printf("Ingrese el nombre: ");
		gets(Nuevo->cliente.nombre);
		fflush(stdin);
	}while(validacionNombreYApellido(Nuevo->cliente.nombre));
	do
	{
		printf("Ingrese el apellido: ");
		gets(Nuevo->cliente.apellido);
		fflush(stdin);
	}while(validacionNombreYApellido(Nuevo->cliente.apellido));
	do
	{
		printf("Ingrese su numero de cedula: ");
		gets(Nuevo->cliente.CI);
		fflush(stdin);
	}while(validacionCedula(Nuevo->cliente.CI));
	do
	{
		printf("Ingrese su email: ");
		gets(Nuevo->cliente.email);
		fflush(stdin);
	}while(validacionEmail(Nuevo->cliente.email));
	do
	{
		printf("Ingrese su celular: ");
		fflush(stdin);
		gets(Nuevo->cliente.celular);
	}while(validacionCelular(Nuevo->cliente.celular));
	
	do
	{
		printf("Ingrese su edad: ");
		scanf("%d",&Nuevo->cliente.edad);
		fflush(stdin);
		itoa(Nuevo->cliente.edad,edad,10);
	}while(validacionEdad(edad));
	if(Aux!=NULL)
	{
		while(Aux->siguiente!=NULL)
		{
			Aux=Aux->siguiente;
		}
        Nuevo->siguiente=NULL;
        Aux->siguiente=Nuevo;
        Nuevo->anterior=Aux;
	}
	else
	{
		Nuevo->anterior=NULL;
		Nuevo->siguiente=NULL;
		Lista=Nuevo;
	}
	contadorNodoCliente++;
	printf("\n");
}
///ingresos
int selecDia(int refMes){
	for(int i=1;i<=dias_del_mes(refMes);i++){
		printf("\t %d\n",i);
	}
	printf("ingrese el dia que desea reservar...\n\t ");
	scanf("%d",&refMes);
	return refMes;
}
void apruebaReserva(Dia &dia,int diaR,int idCuarto){
	bool ok=false;
	Dia aux=dia;
	system("cls");
	system("color F0");
	while(aux!=NULL){
		if(aux->dia==diaR){
			switch(idCuarto){
				case 1:
					if(aux->habitacion.cuarto1.disponible){
						aux->habitacion.cuarto1.disponible=false;
						printf("\nRESERVACION EXITOSA!!!...\n\nAcontinuacion debe ingresar sus datos\n");
						do
						{
							printf("Ingrese su numero de cedula: ");
							fflush(stdin);
							gets(aux->habitacion.cuarto1.CI);
							fflush(stdin);
						}while(validacionCedula(aux->habitacion.cuarto1.CI));
						ok=true;
					}else{
						printf("\nLo sentimos...\n\nLa habitacion ya se encuentra reservada\n\n");
					}
				break;
				case 2:
					if(aux->habitacion.cuarto2.disponible){
						aux->habitacion.cuarto2.disponible=false;
						printf("\nRESERVACION EXITOSA!!!...\n\nAcontinuacion debe ingresar sus datos\n");
						do
						{
							printf("Ingrese su numero de cedula: ");
							fflush(stdin);
							gets(aux->habitacion.cuarto2.CI);
							fflush(stdin);
						}while(validacionCedula(aux->habitacion.cuarto2.CI));
						ok=true;
					}else{
						printf("\nLo sentimos...\nLa habitacion ya se encuentra reservada\n\n");
					}
				break;
				case 3:
					if(aux->habitacion.cuarto3.disponible){
						aux->habitacion.cuarto2.disponible=false;
						printf("\nRESERVACION EXITOSA!!!...\nAcontinuacion debe ingresar sus datos\n");
						do
						{
							printf("Ingrese su numero de cedula: ");
							fflush(stdin);
							gets(aux->habitacion.cuarto3.CI);
							fflush(stdin);
						}while(validacionCedula(aux->habitacion.cuarto3.CI));
						ok=true;
					}else{
						printf("\nLo sentimos...\nLa habitacion ya se encuentra reservada\n\n");
					}
				break;
			}
		}
		aux=aux->siguiente;
	}
	system("pause");
	/*if(ok){
		return aux->habitacion.cuarto1.CI;
	}else{
		
	}*/
}
//VISUALIZAR
void disponibles(Dia &ref){
	Dia aux=ref;
	color(10);
	while(aux!=NULL){
		printf("\nEl dia %d: \n",aux->dia);
		if(aux->habitacion.cuarto1.disponible){
			color(10);
			printf("La habitacion  %s ¡ESTA DISPONIBLE!\n",aux->habitacion.cuarto1.tipo);
			printf("Tiene  %s\n",aux->habitacion.cuarto1.descripcion);
			printf("El precio de la habitacion es:%.2f \n",aux->habitacion.cuarto1.precio);
		}else{
			color(12);
			printf("La habitacion  %s ¡ESTA OCUPADA!\n",aux->habitacion.cuarto1.tipo);
		}
		printf("\n------------------------------------------------------\n");
		if(aux->habitacion.cuarto2.disponible){
			color(10);
			printf("La habitacion  %s ¡ESTA DISPONIBLE!\n",aux->habitacion.cuarto2.tipo);
			printf("Tiene  %s\n",aux->habitacion.cuarto2.descripcion);
			printf("El precio de la habitacion es:%.2f \n",aux->habitacion.cuarto2.precio);
		}
		else{
			color(12);
			printf("La habitacion  %s ¡ESTA OCUPADA!\n",aux->habitacion.cuarto2.tipo);
		}
		printf("\n------------------------------------------------------\n");
		if(aux->habitacion.cuarto3.disponible){
			color(10);
			printf("La habitacion  %s ¡ESTA DISPONIBLE!\n",aux->habitacion.cuarto3.tipo);
			printf("Tiene  %s\n",aux->habitacion.cuarto3.descripcion);
			printf("El precio de la habitacion es:%.2f \n",aux->habitacion.cuarto3.precio);
		}
		else{
			color(12);
			printf("La habitacion  %s ¡ESTA OCUPADA!\n",aux->habitacion.cuarto3.tipo);
		}
		printf("\n------------------------------------------------------\n\n");
		aux=aux->siguiente;
	}
	system("pause");
}
void reservarHotel(Cliente &clientes,Mes &mes){
	int opc=1;
	int diaR=0; //guarda el dia de la posible reserva
	int tipoCuarto=0;
	const char *opciones[]={"Reservar otro dia en este mes","Reservar en otro mes"};
	const char *opcCuartos[]={"Habitacion simple","Habitacion Familiar","Habitacion Matrimonial"};
	do{
		if(opc==1){
			disponibles(mes->dia);
			system("cls");
			printf("\nAcontinuacion se presentara un menu con los dias del mes\n\n");
			system("pause");
			diaR=selecDia(mes->numeroMes);
			tipoCuarto=menu("Eliga el cuarto que desea",opcCuartos,3);
			apruebaReserva(mes->dia,diaR,tipoCuarto);
			
		}
		opc=menu("Menu de Reservaciones en el mes seleccionado",opciones,2);
	}while(opc!=2);
}
void menuMes(Cliente &clientes,Mes &mes){
	int opc=0;
	const char *opciones[]={"Reservar en el mes actual","Reservar en otro mes","Regresar al menu de reservas"};
	do{
		opc=menu("Menu de Reservaciones",opciones,3);
		switch(opc){
			case 1:
				reservarHotel(clientes,mes);
			break;
			case 2:
			break;
			case 3:
			break;
		}
	}while(opc!=3);
	printf("\n");
}

//imprime cierto cliente especifico
informacionClienteEspecifico(Cliente &Lista, int ubicacion)
{
	Cliente Aux=new SCliente();
	Aux=Lista;
	int i=1,cont=0;
	if(Aux == NULL)
    	printf("No existe elementos en la lista.\n\n");
    else
    {
    	while(Aux!=NULL)
		{
			if(ubicacion==cont)
			{
				printf("%d) %s\n",ubicacion+1,Aux->cliente.nombre);
	        	printf("   %s\n",Aux->cliente.apellido);
	        	printf("   %s\n",Aux->cliente.CI);
	        	printf("   %s\n",Aux->cliente.email);
	        	printf("   %s\n",Aux->cliente.celular);
				break;
			}
			else
			{
				cont++;
			}
			Aux=Aux->siguiente;		
		}
	}
	if(cont==0&&ubicacion!=0)
		printf("\nNo se ha encontrado al cliente.\n\n");
}

//imprime toda la lista CLiente
void informacionClienteTotal(Cliente &Lista)
{
	Cliente Aux=new SCliente();
	Aux=Lista;
	system("cls");
	int i=1;
	if(Aux == NULL)
    	printf("No existe elementos en la lista.\n\n");
    else
    {
	    printf("\t\t_______Informacion personal_______\n\n");
		while(Aux != NULL)
		{
			
	        printf("%d) %s\n",i,Aux->cliente.nombre);
	        printf("   %s\n",Aux->cliente.apellido);
	        printf("   %s\n",Aux->cliente.CI);
	        printf("   %s\n",Aux->cliente.email);
	        printf("   %s\n",Aux->cliente.celular);
	        Aux=Aux->siguiente;
	        i++;
	    }
	    printf("\n");
	}
}

//Busca en toda la lista cliente mediante la cedula
void buscarCI(Cliente &Lista)
{
	char buscar[11],editar[11];
	int cont=0,ubicacion=0;
	Cliente Aux=new SCliente();
	Aux=Lista;
	system("cls");
	if(Aux == NULL)
    	printf("No existe elementos en la lista.\n\n");
    else
    {
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("Buscar.\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		do
		{
			printf("Ingrese el numero de cedula a buscar: ");
			gets(buscar);
			fflush(stdin);
		}while(validacionCedula(buscar));
		while(Aux!=NULL)
		{
			if(strcmp(buscar,Aux->cliente.CI)==0)
			{
				printf("\nNumero de cedula encontrado ! ( %s )\n",buscar);
				do
				{
					printf("Ingrese el nuevo numero de cedula: ");
					gets(editar);
					fflush(stdin);
				}while(validacionCedula(editar));
				strcpy(Aux->cliente.CI,editar);
				printf("\nCambio Exitoso");
				cont++;
				printf("\n\nA continuacion se le va a desplegar sus datos para verificar su modificacion.\nPresione cualquier tecla para continuar. . .\n");
    			getch();
    			informacionClienteEspecifico(Lista,ubicacion);
    			break;
			}
			ubicacion++;
			Aux=Aux->siguiente;
		}
		if(cont==0)
			printf("\nNo se ha encontrado al cliente.\n\n");

	}
	
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
	printf("\n");
}
//Funcion principal del programa.
void hotel(){
	Mes mes=NULL;
	Cliente clientes=NULL;
	int opc=0;
	const char *opciones[]={"Reservas Nueva","Buscar Reserva","Eliminar Reserva","Modificar Reserva","Visualizar reservas","Salir al menu principal"};
	inicio(mes);
	do{
		opc=menu("Menu de Reservas",opciones,6);
		color(10);
		switch(opc){
			case 1:
				menuMes(clientes,mes);
				
			break;
			case 2:
				ingresoDeCliente(clientes);
			break;
			case 3:
				buscarCI(clientes);
			break;
			case 4:
				informacionClienteTotal(clientes);
			break;
			case 5:
				menuVisualizar(clientes,mes);
			break;
		}
	if(opc!=6)
	{
		printf("Presione cualquier tecla para volver al menu reservas . . .");
		getch();
	}
	}while(opc!=6);
}
int main()
{
	AltEnter();
	portada();
	hotel();
	return 0;
}

