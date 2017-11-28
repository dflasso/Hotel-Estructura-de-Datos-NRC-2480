#include "libHotel.h"
#include "libGraphicalInterface.h"
#include "libValidation.h"

/*Declaracion de estructura*/
typedef struct SCuarto{ ///inf. cuartos
	bool disponible;
	float precio;
	int id;
	char tipo[20];
	char descripcion[100];
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
//
void printC(Cliente &cl){
	Cliente aux=cl;
	while(aux!=NULL){
		printf("%s\n%s\n",aux->cliente.nombre,aux->cliente.CI);
		aux=aux->siguiente;
	}
}
/*Declaracion de Funciones*/
void inicio(Mes *);
void calendarioMes(Dia *,int );
//funcion que se desarrolla el programa
void hotel(Mes *,Cliente *,FILE *);
void menuPrincipal();
//ingreso de clientes
void nuevoHuesped(Cliente *);
void reservarHotel(Cliente *,Mes *,FILE *);
int selecDia(int refMes);//imprimer los dias dias del mes provicionalmente
void menuMes(Cliente *,Mes *,FILE *);
//funciones de visualizacion
void menuVisualizar(Cliente *,Mes *);
void disponibles(Dia *);
void printCuartos(Mes *,char []);
void printH(Mes *);
void printC(Cliente *);
//registro de clientes
void ingresoDeCliente(Cliente *,char cedula[],FILE *);
bool apruebaReserva(Mes *,int ,int ,Cliente *,FILE *);
void informacionClienteTotal(Cliente *);
void informacionClienteEspecifico(Cliente *,int);
//modificacion
void modificar(Cliente *);
//busqueda
void buscarCI(Cliente *,Mes *);
//eliminar
void eliminar(FILE *,Cliente *,Mes *);
void habilitaCuarto(Mes *);
//archivos
void generaFILE(FILE *);
void RecrearFILE(FILE *,Cliente *,Mes *);

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
void inicio(Mes &mes,int refMes){
	Mes nuevo=new SMes();
	Mes recorre=mes;
	if(mes==NULL){
		nuevo->numeroMes=actual(mesA);
		for(int i=actual(diaA);i<=dias_del_mes(nuevo->numeroMes);i++){
			if(i==actual(diaA)){
				nuevo->dia=NULL;
				calendarioMes(nuevo->dia,i);	
			}else{
				calendarioMes(nuevo->dia,i);
			}
		}
		mes=nuevo;
	}else{
		nuevo->numeroMes=refMes;
		for(int i=1;i<=dias_del_mes(nuevo->numeroMes);i++){
			if(i==1){
				nuevo->dia=NULL;
				calendarioMes(nuevo->dia,i);	
			}else{
				calendarioMes(nuevo->dia,i);
			}
		}
		
		while(recorre->siguiente!=NULL){
			recorre=recorre->siguiente;
		}
		nuevo->siguiente=NULL;
		recorre->siguiente=nuevo;
		nuevo->anterior=recorre;
	}
}
//eliminar
void habilitaCuarto(Dia &dia){
	Dia auxDia=dia;
	char refDia[20],cedu[20];
	const char *opciones[]={"Cuarto Simple","Habitacion Fmiliar","Habitacion Matrimonial","REGRESAR"};
	int opc=0;
	int i=2;
	do{
		printf("\nIngresar el dia de la reserva que desea eliminar:\t");
		fflush(stdin);
		gets(refDia);
	}while(validacionNumero(refDia));
	while(auxDia!=NULL){
		if((atoi(refDia))==auxDia->dia){
			do{
				i=3;
				opc=menu("TIPOS DE CUARTOS",opciones,4);
				color(10);
				switch(opc){
					case 1:
						do{
							do{
								printf("\nIngrese el Numero de Cedula que reservaron la habitacion\t");
								color(10);
								fflush(stdin);
								gets(cedu);
							}while(validacionCedula(cedu));
							if((strcmp(cedu,auxDia->habitacion.cuarto1.CI))!=0){
								color(12);
								printf("\nrecuerde solo tiene %d intento(s)\n",i);
								i--;	
							}
							color(10);
						}while(i>0&&(strcmp(cedu,auxDia->habitacion.cuarto1.CI))!=0);
						if(i>0){
							auxDia->habitacion.cuarto1.disponible=true;
							strcpy(auxDia->habitacion.cuarto1.CI,"");
							printf("\nReserva eliminada...\n");
							system("pause");
						}else{
							printf("\nLo sentrimos... Sus intentos han fallado\n");
							system("pause");
						}
					break;
					case 2:
						do{
							do{
								printf("\nIngrese el Numero de Cedula que reservaron la habitacion\t");
								color(10);
								fflush(stdin);
								gets(cedu);
							}while(validacionCedula(cedu));
							if((strcmp(cedu,auxDia->habitacion.cuarto2.CI))!=0){
								color(12);
								printf("\nrecuerde solo tiene %d intento(s)\n",i);
								i--;	
							}
							color(10);
						}while(i>0&&(strcmp(cedu,auxDia->habitacion.cuarto2.CI))!=0);
						if(i>0){
							auxDia->habitacion.cuarto2.disponible=true;
							strcpy(auxDia->habitacion.cuarto2.CI,"");
							printf("\nReserva eliminada...\n");
							system("pause");
						}else{
							printf("\nLo sentrimos... Sus intentos han fallado\n");
							system("pause");
						}
					break;
					case 3:
						do{
							do{
								printf("\nIngrese el Numero de Cedula que reservaron la habitacion\t");
								color(10);
								fflush(stdin);
								gets(cedu);
							}while(validacionCedula(cedu));
							if(strcmp(cedu,auxDia->habitacion.cuarto3.CI)!=0){
								color(12);
								printf("\nrecuerde solo tiene %d intento(s)\n",i);
								i--;	
							}
							color(10);
						}while(i>0&&(strcmp(cedu,auxDia->habitacion.cuarto3.CI))!=0);
						if(i>0){
							auxDia->habitacion.cuarto3.disponible=true;
							strcpy(auxDia->habitacion.cuarto3.CI,"");
							printf("\nReserva eliminada...\n");
							system("pause");
						}else{
							printf("\nLo sentrimos... Sus intentos han fallado\n");
							system("pause");
						}
					break;
				}
			}while(opc!=4);
		}
		auxDia=auxDia->siguiente;
	}
}
void RecrearFILE(FILE *archivoHotel,Cliente &clientes,Mes &mes){
	generaFILE(archivoHotel);
	Cliente auxCliente=clientes;
	Mes auxMes=mes;
	Dia auxDia=NULL;
	archivoHotel=fopen("Hotel-clientes.txt","a+");
	while(auxCliente!=NULL){
		fprintf(archivoHotel,"\n---------------------------------------------------\nNueva reservacion:\nCliente: %s  %s\n",auxCliente->cliente.nombre,auxCliente->cliente.apellido);
		fprintf(archivoHotel,"Cedula:  %s\n",auxCliente->cliente.CI);
		fprintf(archivoHotel,"Email:  %s\n",auxCliente->cliente.email);
		fprintf(archivoHotel,"Celular:  %s\nEdad:  %d\n",auxCliente->cliente.celular,auxCliente->cliente.edad);
		auxMes=mes;
		while(auxMes!=NULL){
			auxDia=auxMes->dia;
			while(auxDia!=NULL){
				if(strcmp(auxDia->habitacion.cuarto1.CI,auxCliente->cliente.CI)==0){
					fprintf(archivoHotel,"La Habitacion:  %s\n",auxDia->habitacion.cuarto1.tipo);
					fprintf(archivoHotel,"Fecha: dia: %d / mes:  %d  /  2017\n",auxDia->dia,auxMes->numeroMes);
				}
				if(strcmp(auxDia->habitacion.cuarto2.CI,auxCliente->cliente.CI)==0){
					fprintf(archivoHotel,"La Habitacion:  %s\n",auxDia->habitacion.cuarto2.tipo);
					fprintf(archivoHotel,"Fecha: dia: %d / mes:  %d  /  2017\n",auxDia->dia,auxMes->numeroMes);
				}
				if(strcmp(auxDia->habitacion.cuarto3.CI,auxCliente->cliente.CI)==0){
					fprintf(archivoHotel,"La Habitacion:  %s\n",auxDia->habitacion.cuarto3.tipo);
					fprintf(archivoHotel,"Fecha: dia: %d / mes:  %d  /  2017\n",auxDia->dia,auxMes->numeroMes);
				}
				auxDia=auxDia->siguiente;
			}
			auxMes=auxMes->siguiente;
		}
		auxCliente=auxCliente->siguiente;
	}
	fclose(archivoHotel);
}

void eliminar(FILE *archivoHotel,Cliente &clientes,Mes &mes){
	int opc=0;
	const char *opciones[]={"ELIMINAR LA RESERVA DE UN DIA ESPECIFICO","ELIMMINAR TODAS LAS RESERVAS DE UN CLIENTE","SALIR"};
	bool noHayMes=true;
	Mes auxMes;
	char refMes[20], refDia[20];
	color(10);
	Cliente auxCl=NULL,ant=NULL,pos=NULL;
	do{
		auxMes=mes;
		opc=menu("MENU DE ELIMANCIONES",opciones,3);
		color(10);
		auxCl=clientes;
		switch(opc){
			case 1: //un dia
				do{
					do{
						printf("\nIngrese el mes de la reserva\t");
						fflush(stdin);
						gets(refMes);
					}while(validacionNumero(refMes));
					auxMes=mes;
					while(auxMes!=NULL){
						if(auxMes->numeroMes==atoi(refMes)){
							habilitaCuarto(auxMes->dia);
							noHayMes=false;
						}
						auxMes=auxMes->siguiente;
					}
					if(noHayMes){
						printf("\nERROR!!!\nNo existen reservas en el mes seleccionado\n,tal vez, el mes seleccionado ya paso \nO el mes no esta dentro del rango\n");
						system("pause");
					}
				}while(noHayMes);
			break;
			case 2: //cliente
				do{
					printf("\nIngrese el Numero de Cedula del cliente que sera eliminado del sistema...\t");
					color(10);
					fflush(stdin);
					gets(refMes);
				}while(validacionCedula(refMes));				
				while(auxCl!=NULL){
					if(strcmp(auxCl->cliente.CI,refMes)==0){
						ant=auxCl->anterior;
						pos=auxCl->siguiente;
						ant->siguiente=pos;
						pos->anterior=ant;
					}
					auxCl=auxCl->siguiente;
				}
			break;
		}
	}while(opc!=3);
	RecrearFILE(archivoHotel,clientes,mes);
}
//imprime habitaciones del cliente
void printCuartos(Mes &mes,char cedula[]){
	Mes auxMes=mes;
	Dia auxDia=NULL;
	printf("\n---------------------------------------\n\tRESERVAS DEL CLIENTE ");
	while(auxMes!=NULL){
		auxDia=auxMes->dia;
		while(auxDia!=NULL){
			if(strcmp(auxDia->habitacion.cuarto1.CI,cedula)==0){
				printf("\n\nLa Habitacion:  %s\n",auxDia->habitacion.cuarto1.tipo);
				printf("Fecha: dia: %d / mes:  %d  /  2017\n",auxDia->dia,auxMes->numeroMes);
				printf("Costo:  %.2f",auxDia->habitacion.cuarto1.precio);
			}
			if(strcmp(auxDia->habitacion.cuarto2.CI,cedula)==0){
				printf("\n\nLa Habitacion:  %s\n",auxDia->habitacion.cuarto2.tipo);
				printf("Fecha: dia: %d / mes:  %d  /  2017\n",auxDia->dia,auxMes->numeroMes);
				printf("Costo:  %.2f",auxDia->habitacion.cuarto2.precio);
			}
			if(strcmp(auxDia->habitacion.cuarto3.CI,cedula)==0){
				printf("\n\nLa Habitacion:  %s\n",auxDia->habitacion.cuarto3.tipo);
				printf("Fecha: dia: %d / mes:  %d  /  2017\n",auxDia->dia,auxMes->numeroMes);
				printf("Costo:  %.2f",auxDia->habitacion.cuarto3.precio);
			}
			auxDia=auxDia->siguiente;
		}
		auxMes=auxMes->siguiente;
	}
}
//imprime cierto cliente especifico
void informacionClienteEspecifico(Cliente &Lista, int ubicacion){
	Cliente Aux=new SCliente();
	Aux=Lista;
	int cont=0;
	if(Aux == NULL)
    	printf("No existe elementos en la lista.\n\n");
    else
    {
    	while(Aux!=NULL)
		{
			if(ubicacion==cont)
			{
				printf("\n");
				printf("Nombre: %s\n",Aux->cliente.nombre);
	        	printf("Apellido: %s\n",Aux->cliente.apellido);
	        	printf("Cedula de Identidad: %s\n",Aux->cliente.CI);
	        	printf("Email: %s\n",Aux->cliente.email);
	        	printf("Numero de Celular: %s\n",Aux->cliente.celular);
	        	printf("Edad: %d\n",Aux->cliente.edad);
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
void informacionClienteTotal(Cliente &Lista){
	Cliente Aux=new SCliente();
	Aux=Lista;
	system("cls");
	int i=1;
	if(Aux == NULL)
    	printf("No existe elementos en la lista.\n\n");
    else
    {
	    printf("\t\t_______ Informacion Personal _______\n\n");
		while(Aux != NULL)
		{
			printf("\n");
	        printf("%d) Nombre: %s\n",i,Aux->cliente.nombre);
	        printf("   Apellido: %s\n",Aux->cliente.apellido);
	        printf("   Cedula de Identidad: %s\n",Aux->cliente.CI);
	        printf("   Email: %s\n",Aux->cliente.email);
	        printf("   Numero de Celular: %s\n",Aux->cliente.celular);
	        printf("   Edad: %d\n",Aux->cliente.edad);
	        Aux=Aux->siguiente;
	        i++;
	    }
	}
	system("pause");
}

void ingresoDeCliente(Cliente &Lista,char cedula[],FILE *archivoHotel){
	system("color A");
	color(10);
	int cont=0;
	char edad[100],opcion;
	Cliente Nuevo=new SCliente();
	Cliente Guia=new SCliente();
	Cliente Aux;
	Guia=Aux=Lista;
	char cedulaAux[20];
	archivoHotel=fopen("Hotel-clientes.txt","a+");
	do
	{
		color(14);
		printf("\n\t\t-------------------------------------------------------");
		printf("\n\t\t||Ingrese su numero de cedula:  ");
		fflush(stdin);
		color(10);
		gets(Nuevo->cliente.CI);
		fflush(stdin);
		color(14);
		printf("\t\t-------------------------------------------------------\n");
	}while(validacionCedula(Nuevo->cliente.CI));
	while(Guia!=NULL)
	{
		if(strcmp(Nuevo->cliente.CI,Guia->cliente.CI)==0)
		{
			printf("\nNumero de cedula encontrado ! ( %s )",Nuevo->cliente.CI);
			printf("\n\nA continuacion se le va a desplegar sus datos para verificar su ingreso.\nPresione cualquier tecla para continuar. . .\n");
			getch();
			informacionClienteEspecifico(Guia,cont);
			cont++;
			break;
		}
		Guia=Guia->siguiente;
	}
	if(cont==0){
			do
			{
				color(14);
				printf("\n\t\t-------------------------------------------------------");
				printf("\n\t\t||  Ingrese el nombre:  ");
				color(10);
				fflush(stdin);
				gets(Nuevo->cliente.nombre);
				fflush(stdin);
				color(14);
				printf("\t\t-------------------------------------------------------\n");
			}while(validacionNombreYApellido(Nuevo->cliente.nombre));
			do
			{
				color(14);
				printf("\n\t\t-------------------------------------------------------");
				printf("\n\t\t||  Ingrese el apellido:  ");
				color(10);
				gets(Nuevo->cliente.apellido);
				fflush(stdin);
				color(14);
				printf("\t\t-------------------------------------------------------\n");
			}while(validacionNombreYApellido(Nuevo->cliente.apellido));
			fprintf(archivoHotel,"\n---------------------------------------------------\nNueva reservacion:\nCliente: %s  %s\n",Nuevo->cliente.nombre,Nuevo->cliente.apellido);
			fprintf(archivoHotel,"Cedula:  %s\n",Nuevo->cliente.CI);
			do
			{
				color(14);
				printf("\n\t\t-------------------------------------------------------");
				printf("\n\t\t||  Ingrese su email: ");
				color(10);
				gets(Nuevo->cliente.email);
				fflush(stdin);
				color(14);
				printf("\t\t-------------------------------------------------------\n");
			}while(validacionEmail(Nuevo->cliente.email));
			fprintf(archivoHotel,"Email:  %s\n",Nuevo->cliente.email);
			do
			{
				color(14);
				printf("\n\t\t-------------------------------------------------------");
				printf("\n\t\t||  Ingrese su celular:  ");
				color(10);
				fflush(stdin);
				gets(Nuevo->cliente.celular);
				color(14);
				printf("\t\t-------------------------------------------------------\n");
			}while(validacionCelular(Nuevo->cliente.celular));
			
			do
			{
				color(14);
				printf("\n\t\t-------------------------------------------------------");
				printf("\n\t\t||  Ingrese su edad:  ");
				color(10);
				gets(edad);
				fflush(stdin);
				color(14);
				printf("\t\t-------------------------------------------------------\n");
			}while(validacionEdad(edad));
			Nuevo->cliente.edad=atoi(edad);			
			fprintf(archivoHotel,"Celular:  %s\nEdad:  %d\n",Nuevo->cliente.celular,Nuevo->cliente.edad);
		}else{
		printf("\ndesea actualizar algun dato, Yes o No (Y/N)?");
	    opcion=getch();
	    while(((opcion!='Y')&&(opcion!='y'))&&((opcion!='N')&&(opcion!='n')))
	    {
	         printf("\nOpcion incorrecta !!\n");
	         fflush(stdin);
	         printf("Ingrese correctamente la opcion Yes o No (Y/N) ");
	         opcion=getch();
	    }
	    if((opcion=='Y')||(opcion=='y'))
	    {
	    	printf("\n\n");
	    	do
			{
				color(14);
				printf("\n\t\t-------------------------------------------------------");
				printf("\n\t\t||  Ingrese el nombre:  ");
				color(10);
				fflush(stdin);
				gets(Nuevo->cliente.nombre);
				fflush(stdin);
				color(14);
				printf("\t\t-------------------------------------------------------\n");
			}while(validacionNombreYApellido(Nuevo->cliente.nombre));
			do
			{
				color(14);
				printf("\n\t\t-------------------------------------------------------");
				printf("\n\t\t||  Ingrese el apellido:  ");
				color(10);
				gets(Nuevo->cliente.apellido);
				fflush(stdin);
				color(14);
				printf("\t\t-------------------------------------------------------\n");
			}while(validacionNombreYApellido(Nuevo->cliente.apellido));
			fprintf(archivoHotel,"\n---------------------------------------------------\nNueva reservacion:\nCliente: %s  %s\n",Nuevo->cliente.nombre,Nuevo->cliente.apellido);
			fprintf(archivoHotel,"Cedula:  %s\n",Nuevo->cliente.CI);
			do
			{
				color(14);
				printf("\n\t\t-------------------------------------------------------");
				printf("\n\t\t||  Ingrese su email: ");
				color(10);
				gets(Nuevo->cliente.email);
				fflush(stdin);
				color(14);
				printf("\t\t-------------------------------------------------------\n");
			}while(validacionEmail(Nuevo->cliente.email));
			fprintf(archivoHotel,"Email:  %s\n",Nuevo->cliente.email);
			do
			{
				color(14);
				printf("\n\t\t-------------------------------------------------------");
				printf("\n\t\t||  Ingrese su celular:  ");
				color(10);
				fflush(stdin);
				gets(Nuevo->cliente.celular);
				color(14);
				printf("\t\t-------------------------------------------------------\n");
			}while(validacionCelular(Nuevo->cliente.celular));
			
			do
			{
				color(14);
				printf("\n\t\t-------------------------------------------------------");
				printf("\n\t\t||  Ingrese su edad:  ");
				color(10);
				gets(edad);
				fflush(stdin);
				color(14);
				printf("\t\t-------------------------------------------------------\n");
			}while(validacionEdad(edad));
			Nuevo->cliente.edad=atoi(edad);			
			fprintf(archivoHotel,"Celular:  %s\nEdad:  %d\n",Nuevo->cliente.celular,Nuevo->cliente.edad);
		}else{
			strcpy(Nuevo->cliente.nombre,Guia->cliente.nombre);
			strcpy(Nuevo->cliente.apellido,Guia->cliente.apellido);
			strcpy(Nuevo->cliente.email,Guia->cliente.email);
			strcpy(Nuevo->cliente.celular,Guia->cliente.celular);
			Nuevo->cliente.edad=Guia->cliente.edad;
			printf("\n");
		}
	}
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
		system("pause");
		strcpy(cedula,Nuevo->cliente.CI);
	fclose(archivoHotel);
}

//Ingreso de lista cliente
///ingresos
int selecDia(int refMes){
	for(int i=1;i<=dias_del_mes(refMes);i++){
		printf("\t %d\n",i);
	}
	printf("ingrese el dia que desea reservar...\n\t ");
	scanf("%d",&refMes);
	return refMes;
}
bool apruebaReserva(Dia &dia,int diaR,int idCuarto,Cliente &clientes,FILE *archivoHotel){
	bool ok=false;
	Dia aux=dia;
	system("cls");
	color(1);
	while(aux!=NULL){
		if(aux->dia==diaR){
			switch(idCuarto){
				case 1:
					if(aux->habitacion.cuarto1.disponible){
						aux->habitacion.cuarto1.disponible=false;
						printf("RESERVACION EXITOSA!!!...\n\nA continuacion debe ingresar sus datos:\n");
						ingresoDeCliente(clientes,aux->habitacion.cuarto1.CI,archivoHotel);
						archivoHotel=fopen("Hotel-clientes.txt","a+");
						fprintf(archivoHotel,"\nLas habitacion:   %s\nEL dia: %d",aux->habitacion.cuarto1.tipo,aux->dia);
						fclose(archivoHotel);
						ok=true;
					}else{
						color(12);
						printf("\nLo sentimos...\n\nLa habitacion ya se encuentra reservada.\n\n");
						system("pause");
					}
				break;
				case 2:
					if(aux->habitacion.cuarto2.disponible){
						aux->habitacion.cuarto2.disponible=false;
						printf("RESERVACION EXITOSA!!!...\n\nA continuacion debe ingresar sus datos\n");
						ingresoDeCliente(clientes,aux->habitacion.cuarto2.CI,archivoHotel);
						archivoHotel=fopen("Hotel-clientes.txt","a+");
						fprintf(archivoHotel,"\nLas habitacion:   %s\nEL dia: %d",aux->habitacion.cuarto2.tipo,aux->dia);
						fclose(archivoHotel);
						ok=true;
					}else{
						color(12);
						printf("\nLo sentimos...\n\nLa habitacion ya se encuentra reservada.\n\n");
						system("pause");
					}
				break;
				case 3:
					if(aux->habitacion.cuarto3.disponible){
						aux->habitacion.cuarto3.disponible=false;
						printf("RESERVACION EXITOSA!!!...\nA continuacion debe ingresar sus datos\n");
						ingresoDeCliente(clientes,aux->habitacion.cuarto3.CI,archivoHotel);
						archivoHotel=fopen("Hotel-clientes.txt","a+");
						fprintf(archivoHotel,"\nLas habitacion:   %s\nEL dia: %d",aux->habitacion.cuarto3.tipo,aux->dia);
						fclose(archivoHotel);
						ok=true;
					}else{
						color(12);
						printf("\nLo sentimos...\n\nLa habitacion ya se encuentra reservada.\n\n");
						system("pause");
					}
				break;
			}
		}
		aux=aux->siguiente;
	}
	return ok;
}

//VISUALIZAR
void disponibles(Dia &ref){
	Dia aux=ref;
	color(10);
	while(aux!=NULL){
		printf("\nEl dia %d: \n\n",aux->dia);
		if(aux->habitacion.cuarto1.disponible){
			color(10);
			printf("%c La habitacion  %s %cESTA DISPONIBLE!\n",175,aux->habitacion.cuarto1.tipo,33);
			printf("  Tiene  %s\n",aux->habitacion.cuarto1.descripcion);
			printf("  El precio de la habitacion es: $%.2f \n\n",aux->habitacion.cuarto1.precio);
		}else{
			color(12);
			printf("%c La habitacion  %s %cESTA OCUPADA!\n\n",175,aux->habitacion.cuarto1.tipo,33);
		}
		if(aux->habitacion.cuarto2.disponible){
			color(10);
			printf("%c La habitacion  %s %cESTA DISPONIBLE!\n",175,aux->habitacion.cuarto2.tipo,33);
			printf("  Tiene  %s\n",aux->habitacion.cuarto2.descripcion);
			printf("  El precio de la habitacion es: $%.2f \n\n",aux->habitacion.cuarto2.precio);
		}
		else{
			color(12);
			printf("%c La habitacion  %s %cESTA OCUPADA!\n\n",175,aux->habitacion.cuarto2.tipo,33);
		}
		if(aux->habitacion.cuarto3.disponible){
			color(10);
			printf("%c La habitacion  %s %cESTA DISPONIBLE!\n",175,aux->habitacion.cuarto3.tipo,33);
			printf("  Tiene  %s\n",aux->habitacion.cuarto3.descripcion);
			printf("  El precio de la habitacion es: $%.2f \n\n",aux->habitacion.cuarto3.precio);
		}
		else{
			color(12);
			printf("%c La habitacion  %s %cESTA OCUPADA!\n\n",175,aux->habitacion.cuarto3.tipo,33);
		}
		printf("\n------------------------------------------------------\n\n");
		aux=aux->siguiente;
	}
	color(10);
}
void reservarHotel(Cliente &clientes,Mes &mes,FILE *archivoHotel){
	int opc=1;
	int diaR=0; //guarda el dia de la posible reserva
	int tipoCuarto=0;
	const char *opcCuartos[]={"Habitacion simple","Habitacion Familiar","Habitacion Matrimonial"};
	system("cls");
	disponibles(mes->dia);
	system("pause");
	system("cls");
	system("color A");
	color(10);
	printf("A continuacion se presentara un formato de calendario para que pueda escoger el dia: \n\n");
	system("pause");
	if(mes->numeroMes==11){
		diaR=mes30(mes->numeroMes);
	}else if(mes->numeroMes==12){
		diaR=mes31(mes->numeroMes);
	}
	tipoCuarto=menu("Eliga el cuarto que desea",opcCuartos,3);
	if(apruebaReserva(mes->dia,diaR,tipoCuarto,clientes,archivoHotel)){
		archivoHotel=fopen("Hotel-clientes.txt","a+");
		fprintf(archivoHotel,"/ mes: %d  /  2017\n",mes->numeroMes);
		fclose(archivoHotel);
	}
	printf("\n\n");
}
void menuMes(Cliente &clientes,Mes &mes,FILE *archivoHotel){
	int opc=0;
	int refMes=0;
	char numAux[10];
	bool valido=true,noHayMes=true;
	Mes auxMes=NULL;
	const char *opciones[]={"Reservar en el mes actual","Reservar en otro mes","Regresar al menu de reservas"};
	do{
		opc=menu("Menu de Reservaciones",opciones,3);
		color(10);
		switch(opc){
			case 1:
				reservarHotel(clientes,mes,archivoHotel);
			break;
			case 2:
				do{
					valido=false;
					printf("\nIngrese el mes que desea reservar:\t");
					gets(numAux);
					valido=validacionNumero(numAux);
					refMes=atoi(numAux);
					if(!valido&&refMes<actual(mesA)){
						printf("\nError!!!...\nEl numero de mes que ingreso ya paso en el presente a%co\n",164);
						valido=true;
					}else if(!valido&&refMes>12){
						printf("\nError!!!...\nEl numero de mes que ingreso no existe...\nPor favor ingrese un numero entre 1(Enero)-12(Febrero)\n\n");
						valido=true;
					}
				}while(valido);
				busquedaMes:
					auxMes=mes;
					while(auxMes!=NULL){
						if(auxMes->numeroMes==refMes){
							reservarHotel(clientes,auxMes,archivoHotel);
							noHayMes=false;
						}
						auxMes=auxMes->siguiente;
					}
				if(noHayMes){
					inicio(mes,refMes);
					goto busquedaMes;	
				}
				
			break;
		}
	}while(opc!=3);
}


//Busca en toda la lista cliente mediante la cedula
void buscarCI(Cliente &Lista,Mes &mes){
	char buscar[11],editar[11];
	int cont=0,ubicacion=0;
	Cliente Aux=new SCliente();
	Aux=Lista;
	system("cls");
	system("color A");
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
				printf("\n\nA continuacion se le va a desplegar sus datos para verificar su busqueda.\nPresione cualquier tecla para continuar. . .\n");
    			getch();
    			informacionClienteEspecifico(Lista,ubicacion);
    			printCuartos(mes,Aux->cliente.CI);
    			cont++;
    			break;
			}
			ubicacion++;
			Aux=Aux->siguiente;
		}
		if(cont==0)
			printf("\nNo se ha encontrado al cliente.\n\n");
	}
}



//Modifica en toda la lista cliente mediante la cedula
void modificar(Cliente &Lista){
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
		printf("Modificar.\n\n");
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
				printf("\nNumero de cedula encontrado ! ( %s )\n\n",buscar);
				cont++;
				system("pause");
				system("cls");
				int opc=0;
				const char *opciones[]={"Todo","Nombre","Apellido","Cedula de Identidad","Email","Celular","Edad","Salir al menu principal"};
				do{
					opc=menu("Modificar",opciones,8);
					system("color A");
					color(10);
					switch(opc)
					{
						char edad[100];
						case 1:
						{
							do
							{
								color(14);
								printf("\n\t\t-------------------------------------------------------");
								printf("\n\t\t||  Ingrese el nombre:  ");
								color(10);
								fflush(stdin);
								gets(Lista->cliente.nombre);
								fflush(stdin);
								color(14);
								printf("\t\t-------------------------------------------------------\n");
							}while(validacionNombreYApellido(Lista->cliente.nombre));
							do
							{
								color(14);
								printf("\n\t\t-------------------------------------------------------");
								printf("\n\t\t||  Ingrese el apellido:  ");
								color(10);
								gets(Lista->cliente.apellido);
								fflush(stdin);
								color(14);
								printf("\t\t-------------------------------------------------------\n");
							}while(validacionNombreYApellido(Lista->cliente.apellido));
							do
							{
								color(14);
								printf("\n\t\t-------------------------------------------------------");
								printf("\n\t\t||  Ingrese su email: ");
								color(10);
								gets(Lista->cliente.email);
								fflush(stdin);
								color(14);
								printf("\t\t-------------------------------------------------------\n");
							}while(validacionEmail(Lista->cliente.email));
							do
							{
								color(14);
								printf("\n\t\t-------------------------------------------------------");
								printf("\n\t\t||  Ingrese su celular:  ");
								color(10);
								fflush(stdin);
								gets(Lista->cliente.celular);
								color(14);
								printf("\t\t-------------------------------------------------------\n");
							}while(validacionCelular(Lista->cliente.celular));							
							do
							{
								color(14);
								printf("\n\t\t-------------------------------------------------------");
								printf("\n\t\t||  Ingrese su edad:  ");
								color(10);
								gets(edad);
								fflush(stdin);
								color(14);
								printf("\t\t-------------------------------------------------------\n");
							}while(validacionEdad(edad));
							Lista->cliente.edad=atoi(edad);	
						}
						break;
						case 2:
						{
							do
							{
								color(14);
								printf("\n\t\t-------------------------------------------------------");
								printf("\n\t\t||  Ingrese el nombre:  ");
								color(10);
								fflush(stdin);
								gets(Aux->cliente.nombre);
								fflush(stdin);
								color(14);
								printf("\t\t-------------------------------------------------------\n");
							}while(validacionNombreYApellido(Lista->cliente.nombre));
						}
						break;
						case 3:
						{
							do
							{
								color(14);
								printf("\n\t\t-------------------------------------------------------");
								printf("\n\t\t||  Ingrese el apellido:  ");
								color(10);
								gets(Lista->cliente.apellido);
								fflush(stdin);
								color(14);
								printf("\t\t-------------------------------------------------------\n");
							}while(validacionNombreYApellido(Lista->cliente.apellido));
						}	
						break;
						case 4:
						{
							do
							{
								color(14);
								printf("\n\t\t-------------------------------------------------------");
								printf("\n\t\t||Ingrese su numero de cedula:  ");
								fflush(stdin);
								color(10);
								gets(Lista->cliente.CI);
								fflush(stdin);
								color(14);
								printf("\t\t-------------------------------------------------------\n");
							}while(validacionCedula(Lista->cliente.CI));	
						}	
						break;
						case 5:
						{
							do
							{
								color(14);
								printf("\n\t\t-------------------------------------------------------");
								printf("\n\t\t||  Ingrese su email: ");
								color(10);
								gets(Lista->cliente.email);
								fflush(stdin);
								color(14);
								printf("\t\t-------------------------------------------------------\n");
							}while(validacionEmail(Lista->cliente.email));
						}
						break;
						case 6:
						{
							do
							{
								color(14);
								printf("\n\t\t-------------------------------------------------------");
								printf("\n\t\t||  Ingrese su celular:  ");
								color(10);
								fflush(stdin);
								gets(Lista->cliente.celular);
								color(14);
								printf("\t\t-------------------------------------------------------\n");
							}while(validacionCelular(Lista->cliente.celular));
						}
						break;
						case 7:
						{
							do
							{
								color(14);
								printf("\n\t\t-------------------------------------------------------");
								printf("\n\t\t||  Ingrese su edad:  ");
								color(10);
								gets(edad);
								fflush(stdin);
								color(14);
								printf("\t\t-------------------------------------------------------\n");
							}while(validacionEdad(edad));
							Lista->cliente.edad=atoi(edad);		
						}	
						break;
					}
					if(opc!=8)
					{
						printf("\nCambio Exitoso");
						printf("\n\nA continuacion se le va a desplegar sus datos para verificar su modificacion.\nPresione cualquier tecla para continuar. . .\n");
		    			getch();
		    			informacionClienteEspecifico(Lista,ubicacion);
						printf("\n\nPresione cualquier tecla para volver al Menu Modificar . . .");
						getch();
					}
				}while(opc!=8);					
    		break;
			}
			ubicacion++;
			Aux=Aux->siguiente;
		}
		if(cont==0)
			printf("\nNo se ha encontrado al cliente.");

	}
	
}

void menuVisualizar(Cliente &clientes,Mes &mes){
	int opc=0;
	const char *opciones[]={"Habitaciones disponibles","Habitaciones reservadas por un cliente","Regresar al menu de reservas"};
	do{
		opc=menu("Menu de Visualizaciones",opciones,3);
		switch(opc){
			case 1:
				disponibles(mes->dia);
			break;
			case 2:
				buscarCI(clientes,mes);
			break;
		}
		if(opc!=3)
		{
			printf("\n\nPresione cualquier tecla para volver al Menu Visualizaciones . . .");
			getch();
		}
	}while(opc!=3);
}
//Funcion principal del programa.
//Archivos
void generaFILE(FILE *archi){
	archi=fopen("Hotel-clientes.txt","w+");
	fprintf(archi,"\tClientes reservados en el presente fiscal \n\n");
	fprintf(archi,"En este archivo se encuentra los datos de clientes Hospedados en el presente \n**Nombre y apellido\n**celular\n**mail");
	fprintf(archi,"\n**Cedula de Identidad (CI)\n**Cuartos reservados con sus precios y fechas");
	fclose(archi);
}

//
void printH(Mes &mes){
	Mes aux=mes;
	Dia auxD=NULL;
	while(aux!=NULL){
		printf("mes  %d ",aux->numeroMes);
		auxD=aux->dia;
		while(auxD!=NULL){
			printf("%d\n%s\n%s",auxD->dia,auxD->habitacion.cuarto1.tipo,auxD->habitacion.cuarto1.CI);
			auxD=auxD->siguiente;
		}
		aux=aux->siguiente;
	}
}

void hotel(Mes &mes,Cliente &clientes,FILE *FHotel){
	bool ceroReservas=true;
	int opc=0;
	const char *opciones[]={"Reserva Nueva","Buscar Reserva","Eliminar Reserva","Modificar Reserva","Visualizar reservas","Salir al menu principal"};
	do{
		opc=menu("Menu de Reservas",opciones,6);
		system("color A");
		color(10);
		switch(opc){
			case 1:
				menuMes(clientes,mes,FHotel);
				ceroReservas=false;
			break;
			case 2: //Buscar reserva
				if(ceroReservas){
					printf("\nError!!!\nAun no se ha hecho ninguna reserva\n");
				}else{
					buscarCI(clientes,mes);
				}
			break;
			case 3: //eliminar
				if(ceroReservas){
					printf("\nError!!!\nAun no se ha hecho ninguna reserva\n");
				}else{
					eliminar(FHotel,clientes,mes);
				}
			break;
			case 4: //modificar
				if(ceroReservas){
					printf("\nError!!!\nAun no se ha hecho ninguna reserva\n");
				}else{			
					//informacionClienteTotal(clientes);
					modificar(clientes);
				}
			break;
			case 5:
				menuVisualizar(clientes,mes);
			break;
		}
		if(opc!=6)
		{
			printf("\n\nPresione cualquier tecla para volver al Menu Reservas . . .");
			getch();
		}
	}while(opc!=6);
}
void menuPrincipal(){
	Mes mes=NULL;
	FILE *FHotel=NULL;//ARCHIVO DEL HOTEL
	Cliente clientes=NULL;
	system("color A");
	int opc;
	//inicializacion con el calendario del mes actual
	inicio(mes,0);
	//crea el archivo
	generaFILE(FHotel);
	system("color A");
	const char *opciones[]={"Reservacion","Imagen","Consulta PDF.","Codigo QR","Ayuda. o PULSE F1","Salir"};
	do{
		opc=menu("Menu Principal",opciones,6);
		system("color A");
		color(10);
		switch(opc){
			case 1:
				hotel(mes,clientes,FHotel);
			break;
			case 2:
				ShellExecute(NULL, TEXT("open"),TEXT("Extras\\image.exe"),NULL, NULL,SW_SHOWNORMAL);		
			break;
			case 3:
				system("start Extras\\CreatePDF.jar");
			break;
			case 4:
				system("start Extras\\CodigoQR.jar");				
			break;
			case 5:
				ShellExecute(NULL, TEXT("open"),TEXT("Extras\\Ayuda-hotel.chm"),NULL, NULL,SW_SHOWNORMAL);				
			break;
		}
	}while(opc!=6);
	free(FHotel);
	free(mes);
	free(clientes);

}
int main(){
	AltEnter();
	//portada();
	menuPrincipal();
	return 0;
}

