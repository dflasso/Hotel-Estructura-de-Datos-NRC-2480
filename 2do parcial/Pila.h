#include "Nodo.h"

class Pila{
	private:
		Nodo* palabras;
		int contadorNodo;
	public:
		Pila()
		{
			palabras=NULL;
			contadorNodo=0;
		}
		void setPalabras(Nodo*);
		Nodo* getPalabras();
		void generarPila();
		void generarPila(int i);
		void push(char []);
		void pushNew(char [],char []);
		void pushNew(char [],char[],int );
		void popPalabra(char []);
		void buscar(char []);
		void buscar(char palabra[],Pila *&palabrasBuscadas);
		void imprimir();
		void nombreBakcup(char[],int );
		void crearBackup(char[],int );
};

void Pila::setPalabras(Nodo* palabras_)
{
	palabras=palabras_;
}

Nodo* Pila::getPalabras()
{
	return palabras;
}

void Pila::push(char linea[])
{
	Nodo *nuevo=new Nodo();
	char *palabraAux;
	palabraAux=strtok(linea,";");
	nuevo->setIngles(palabraAux);
	while(palabraAux != NULL)
    {
      nuevo->setEspaniol(palabraAux);
      palabraAux = strtok(NULL, " ");
    }
	if(contadorNodo==0)
	{
		nuevo->setSiguienteDireccion(NULL);
		palabras=nuevo;
	}
	else
	{
		nuevo->setSiguienteDireccion(palabras);
		palabras=nuevo;
	}
	contadorNodo++;	
}

void Pila::generarPila(){
	FILE *archivoPalabras=fopen("D:\\Traductor\\palabrasDiccionario.txt","r");
	char linea[50];
	while(!feof(archivoPalabras)){
		fscanf(archivoPalabras,"%s",linea);
		push(linea);
	}
	fclose(archivoPalabras);
}
void Pila::generarPila(int i){
	FILE *archivoPalabras=fopen("D:\\Traductor\\Backup.txt","r");
	char linea[50];
	while(!feof(archivoPalabras)){
		fscanf(archivoPalabras,"%s",linea);
		push(linea);
	}
	fclose(archivoPalabras);
}

void Pila::imprimir()
{
	Nodo *nuevo=palabras;
	printf("\tEspañol\t\t\tIngles\n\n");
	while(nuevo!=NULL)
	{
		printf(" =>\t%s\t\t\t%s\n",nuevo->getEspaniol(),nuevo->getIngles());
		nuevo=nuevo->getSiguienteDireccion();
	}
}

void Pila::buscar(char palabra[])
{
	Nodo *aux=palabras;
	int contador=0;
	FILE *archivoQR, *archivoAG,*archivoBD;
	archivoQR=fopen("D:\\Traductor\\SoloPalabraQR.txt","w");
	archivoAG=fopen("D:\\Traductor\\Agente.txt","w");
	archivoBD=fopen("D:\\Traductor\\BD.txt","w");
	while(aux!=NULL)
	{
		if(strcmp(palabra,aux->getEspaniol())==0)
		{
			printf("\n\tEspa%col\t\t\tIngles\n\n",164);
			printf(" =>\t%s\t\t\t%s\n\n",aux->getEspaniol(),aux->getIngles());
			fprintf(archivoQR,"---------------------------------------------------\nPalabra Traducida:\nEspañol: %s - Ingles: %s\n---------------------------------------------------\n",aux->getEspaniol(),aux->getIngles());
			fprintf(archivoAG,"Espaniol: %s.\nIngles: %s",aux->getEspaniol(),aux->getIngles());
			fprintf(archivoBD,"%s;%s",aux->getEspaniol(),aux->getIngles());
			fclose(archivoAG);
			fclose(archivoQR);
			fclose(archivoBD);
			ShellExecute(NULL, TEXT("open"),TEXT("Extras\\WinAppMSAgentsManagementPalabra.exe"),NULL, NULL,SW_SHOWNORMAL);
			contador++;
		}
		aux=aux->getSiguienteDireccion();
	}
	if(contador==0)
		printf("\nPalabra inexistente, por favor ingrese nuevemente la palabra a buscar.\n\n");
	
	system("start Extras\\CreateCodigoQR.jar");
	system("start Extras\\BDMongo.jar");
}
void Pila::buscar(char palabra[],Pila *&palabrasBuscadas)
{
	Nodo *aux=palabras;
	int contador=0;
	char ingles[20];
	strcpy(ingles,"\0");
	while(aux!=NULL)
	{
		if(strcmp(palabra,aux->getEspaniol())==0)
		{
			strcpy(ingles,aux->getIngles());
			palabrasBuscadas->pushNew(palabra,ingles,0);
		}
		aux=aux->getSiguienteDireccion();
	}
}

void Pila::pushNew(char palabraEspaniol[],char palabrasIngles[],int i)
{
	Nodo *nuevo=new Nodo();
	nuevo->setEspaniol(palabraEspaniol);
	nuevo->setIngles(palabrasIngles);
	if(contadorNodo==0)
	{
		nuevo->setSiguienteDireccion(NULL);
	}
	else
	{
		nuevo->setSiguienteDireccion(palabras);
	}
	palabras=nuevo;
	contadorNodo++;	
}


void Pila::pushNew(char palabraEspaniol[],char palabrasIngles[])
{
	Nodo *nuevo=new Nodo();
	FILE *archivoPalabras=fopen("D:\\Traductor\\palabrasDiccionario.txt","a+");
	nuevo->setEspaniol(palabraEspaniol);
	nuevo->setIngles(palabrasIngles);
	if(contadorNodo==0)
	{
		nuevo->setSiguienteDireccion(NULL);
	}
	else
	{
		nuevo->setSiguienteDireccion(palabras);
	}
	palabras=nuevo;
	contadorNodo++;
	printf("\n\t   Nueva palabra ingresada.\n\n\tEspa%col\t\t\tIngles\n\n",164);
	printf(" =>\t%s\t\t\t%s\n\n",palabras->getEspaniol(),palabras->getIngles());
	fprintf(archivoPalabras,"\n%s;%s",palabras->getEspaniol(),palabras->getIngles());
	fclose(archivoPalabras);	
}

void Pila::popPalabra(char palabra[])
{
	Nodo *aux=palabras;
	int contador=0;

	while(aux!=NULL)
	{
		if(strcmp(palabra,aux->getEspaniol())==0)
		{
			aux=NULL;
			contadorNodo--;
			contador++;
		}
		aux=aux->getSiguienteDireccion();
	}
	if(contador==0)
		printf("\nPalabra inexistente, por favor ingrese nuevemente la palabra a buscar.\n\n");
}

void Pila::nombreBakcup(char nombre[],int i)
{
	time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[128];
    char direcion[2000];
    strftime(output,128,"fecha_%d_%m_%y_hora_%H_%M_%S",tlocal);
    strcpy(nombre,"Backup(");
    strcat(nombre,output);
	strcat(nombre,").txt");
    printf("%s\n",nombre);
    strcat(direcion,nombre);
    strcpy(nombre,direcion);
}

void Pila::crearBackup(char nombre[],int i){
	Nodo *nuevo=palabras;
	FILE *arcBackup=NULL;
	if(i==1){
		arcBackup=fopen("D:\\Traductor\\Backup.txt","w");	
	}else if(i==2){
		arcBackup=fopen("Backup.txt","w");
	}
	//INGRESO DE DATOS DE LA PILAS
	while(nuevo!=NULL)
	{
		fprintf(arcBackup,"%s;%s\n",nuevo->getEspaniol(),nuevo->getIngles());
		nuevo=nuevo->getSiguienteDireccion();
	}
	fclose(arcBackup);
	if(i==2){
		rename("Backup.txt",nombre);
	}
	system("pause");
}

