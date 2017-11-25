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
//funcion que se desarrolla el programa
void hotel();
void menuPrincipal();
//ingreso de clientes
void nuevoHuesped(Cliente *);
void reservarHotel(Cliente *,Mes *);
int selecDia(int refMes);//imprimer los dias dias del mes provicionalmente
void menuMes(Cliente *,Mes *);
//funciones de visualizacion
void menuVisualizar(Cliente *,Mes *);
void disponibles(Dia *);
//registro de clientes
void ingresoDeCliente(Cliente *,char cedula[]);
void apruebaReserva(Mes *,int ,int ,Cliente *);
void informacionClienteTotal(Cliente *);
void informacionClienteEspecifico(Cliente *,int);
//modificacion
void modificarCI(Cliente *);
//busqueda
void buscarCI(Cliente *);
//archivos
void generaFILE(FILE *);


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
		nuevo->numeroMes=dias_del_mes(actual(mesA));
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

void ingresoDeCliente(Cliente &Lista,char cedula[]){
	int cont=0;
	char edad[100],opcion;
	Cliente Nuevo=new SCliente();
	Cliente Guia=new SCliente();
	Cliente Aux;
	Guia=Aux=Lista;
	system("cls");
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
			ingresoDatos:
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
				//scanf("%d",&Nuevo->cliente.edad);
				fflush(stdin);
				color(14);
				printf("\t\t-------------------------------------------------------\n");
			}while(validacionEdad(edad));
			Nuevo->cliente.edad=atoi(edad);			
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
	    	goto ingresoDatos;
		}else{
			strcpy(Nuevo->cliente.nombre,Guia->cliente.nombre);
			strcpy(Nuevo->cliente.apellido,Guia->cliente.apellido);
			strcpy(Nuevo->cliente.email,Guia->cliente.email);
			strcpy(Nuevo->cliente.celular,Guia->cliente.celular);
			Nuevo->cliente.edad=Guia->cliente.edad;
			printf("\n");
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
}
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
void apruebaReserva(Dia &dia,int diaR,int idCuarto,Cliente &clientes){
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
						printf("\nRESERVACION EXITOSA!!!...\n\nAcontinuacion debe ingresar sus datos\n");
						ingresoDeCliente(clientes,aux->habitacion.cuarto1.CI);
						ok=true;
					}else{
						printf("\nLo sentimos...\n\nLa habitacion ya se encuentra reservada\n\n");
					}
				break;
				case 2:
					if(aux->habitacion.cuarto2.disponible){
						aux->habitacion.cuarto2.disponible=false;
						printf("\nRESERVACION EXITOSA!!!...\n\nAcontinuacion debe ingresar sus datos\n");
						ingresoDeCliente(clientes,aux->habitacion.cuarto2.CI);
						ok=true;
					}else{
						printf("\nLo sentimos...\nLa habitacion ya se encuentra reservada\n\n");
					}
				break;
				case 3:
					if(aux->habitacion.cuarto3.disponible){
						aux->habitacion.cuarto3.disponible=false;
						printf("\nRESERVACION EXITOSA!!!...\nAcontinuacion debe ingresar sus datos\n");
						ingresoDeCliente(clientes,aux->habitacion.cuarto3.CI);
						ok=true;
					}else{
						printf("\nLo sentimos...\nLa habitacion ya se encuentra reservada\n\n");
					}
				break;
			}
		}
		aux=aux->siguiente;
	}
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
	color(10);
	system("pause");
}
void reservarHotel(Cliente &clientes,Mes &mes){
	int opc=1;
	int diaR=0; //guarda el dia de la posible reserva
	int tipoCuarto=0;
	const char *opcCuartos[]={"Habitacion simple","Habitacion Familiar","Habitacion Matrimonial"};
	disponibles(mes->dia);
	system("cls");
	printf("\nAcontinuacion se presentara un menu con los dias del mes\n\n");
	system("pause");
	diaR=selecDia(mes->numeroMes);
	tipoCuarto=menu("Eliga el cuarto que desea",opcCuartos,3);
	apruebaReserva(mes->dia,diaR,tipoCuarto,clientes);
	printf("\n\n");
}
void menuMes(Cliente &clientes,Mes &mes){
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
				reservarHotel(clientes,mes);
			break;
			case 2:
				do{
					printf("\nIngrese el mes que desea reservar:\t");
					gets(numAux);
					valido=validacionNumero(numAux);
					refMes=atoi(numAux);
					if(!valido&&refMes<actual(mesA)){
						printf("\nError!!!...\nEl numero de mes que ingreso ya paso en el presente a%co\n",164);
						valido=false;
					}else if(!valido&&refMes>12){
						printf("\nError!!!...\nEl numero de mes que ingreso no existe...\nPor favor ingrese un numero entre 1(Enero)-12(Febrero)\n\n");
						valido=false;
					}
				}while(valido);
				busquedaMes:
					auxMes=mes;
					while(auxMes!=NULL){
						if(auxMes->numeroMes==refMes){
							reservarHotel(clientes,auxMes);
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
	printf("\n");
}
//Busca en toda la lista cliente mediante la cedula
void buscarCI(Cliente &Lista){
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
				printf("\n\nA continuacion se le va a desplegar sus datos para verificar su busqueda.\nPresione cualquier tecla para continuar. . .\n");
    			getch();
    			informacionClienteEspecifico(Lista,ubicacion);
    			cont++;
    			break;
			}
			ubicacion++;
			Aux=Aux->siguiente;
		}
		if(cont==0)
			printf("\nNo se ha encontrado al cliente.\n\n");
	}
	system("pause");
}
//Modifica en toda la lista cliente mediante la cedula
void modificarCI(Cliente &Lista){
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
void elimianrClienteCI(Cliente &clientes, Mes &mes){
	
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
//Archivos
void generaFILE(FILE *archi){
	archi=fopen("Hotel-clientes.txt","w+");
	fprintf(archi,"\tClientes reservados en el presente fiscal \n\n");
	fprintf(archi,"En este archivo se encuentra los datos de clientes Hospedados en el presente \n**Nombre y apellido\n**celular\n**mail");
	fprintf(archi,"\n**Cedula de Identidad (CI)\n**Cuartos reservados con sus precios y fechas");
	fclose(archi);
}
//
void hotel(){
	Mes mes=NULL;
	FILE *FHotel=NULL;//ARCHIVO DEL HOTEL
	Cliente clientes=NULL;
	bool ceroReservas=true;
	int opc=0;
	const char *opciones[]={"Reserva Nueva","Buscar Reserva","Eliminar Reserva","Modificar Reserva","Visualizar reservas","Salir al menu principal"};
	//inicializacion con el calendario del mes actual
	inicio(mes,0);
	//crea el archivo
	generaFILE(FHotel);
	do{
		opc=menu("Menu de Reservas",opciones,6);
		color(10);
		switch(opc){
			case 1:
				menuMes(clientes,mes);
				ceroReservas=false;
			break;
			case 2:
				if(ceroReservas){
					printf("\nError!!!\nAun no se ha hecho ninguna reserva\n");
					system("pause");
				}else{
					buscarCI(clientes);
				}
			break;
			case 3:
				if(ceroReservas){
					printf("\nError!!!\nAun no se ha hecho ninguna reserva\n");
					system("pause");
				}else{
					
				}
			break;
			case 4:
				if(ceroReservas){
					printf("\nError!!!\nAun no se ha hecho ninguna reserva\n");
					system("pause");
				}else{
					printf("\n%d\n",clientes);
					
					informacionClienteTotal(clientes);
				}
			break;
			case 5:
				menuVisualizar(clientes,mes);
			break;
		}
	}while(opc!=6);
	free(FHotel);
	free(mes);
	free(clientes);
}
void menuPrincipal(){
	Mes mes=NULL;
	Cliente clientes=NULL;
	int opc=0;
	const char *opciones[]={"Reservacion","Backups","Consulta","Ayuda","Codigo QR","Salir"};
	inicio(mes,0);
	do{
		opc=menuP("Menu Principal",opciones,6);
		color(10);
		switch(opc){
			case 1:
				hotel();
				
			break;
			case 2:
				
			break;
			case 3:
				
			break;
			case 4:
				
			break;
			case 5:
				
			break;
		}
	}while(opc!=6);
}
int main(){
	//AltEnter();
	//portada();
	menuPrincipal();
	return 0;
}

