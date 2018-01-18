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
		void push(char []);
		void pop(char []);
		void buscar(char []);
		void imprimir();
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
	FILE *archivoPalabras=fopen("D:\\palabrasDiccionario.txt","r");
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
	FILE *archivoQR, *archivoAG;
	archivoQR=fopen("D:\\SoloPalabraQR.txt","w");
	archivoAG=fopen("D:\\Agente.txt","w");
	while(aux!=NULL)
	{
		if(strcmp(palabra,aux->getEspaniol())==0)
		{
			printf("\n\tEspa%col\t\t\tIngles\n\n",164);
			printf(" =>\t%s\t\t\t%s\n\n",aux->getEspaniol(),aux->getIngles());
			fprintf(archivoQR,"---------------------------------------------------\nPalabra Traducida:\nEspañol: %s - Ingles: %s\n---------------------------------------------------\n",aux->getEspaniol(),aux->getIngles());
			fprintf(archivoAG,"Español: %s. Ingles: %s",aux->getEspaniol(),aux->getIngles());
			fclose(archivoAG);
			fclose(archivoQR);
			system("start Extras\\CreateCodigoQR.jar");
			contador++;
		}
		aux=aux->getSiguienteDireccion();
	}
	if(contador==0)
		printf("\nPalabra inexistente, por favor ingrese nuevemente la palabra a buscar.\n\n");
}
