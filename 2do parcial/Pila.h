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
		void buscar();
		void imprimir();
};

void Pila::push(char linea[])
{
	Nodo *nuevo=new Nodo();
	char *palabraAux;
	palabraAux=strtok(linea,";");
	nuevo->setEspaniol(palabraAux);
	palabraAux=strtok(linea,";");
	nuevo->setIngles(palabraAux);
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

