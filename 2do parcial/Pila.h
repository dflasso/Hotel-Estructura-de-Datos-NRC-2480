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
		void generarPila();
		void push(char []);
		void buscar(char []);
		void imprimir();
};

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
	FILE *archivoPalabras=fopen("palabrasDiccionario.txt","r");
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
	
	
	while(aux!=NULL)
	{
		if(strcmp(palabra,aux->getEspaniol())==0)
		{
			printf("\n\tEspa%col\t\t\tIngles\n\n",164);
			printf(" =>\t%s\t\t\t%s\n\n",aux->getEspaniol(),aux->getIngles());
			contador++;
		}
		aux=aux->getSiguienteDireccion();
	}
	if(contador==0)
		printf("\nPalabra inexistente, por favor ingrese nuevemente la palabra a buscar.\n\n");
}
