#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>


typedef struct SNodo{
	char espaniol[20];
	char ingles[20];
	struct Pila *siguiente;
	struct Pila *anterior;
}*Nodo;
#ifndef LISTA_H
#define LISTA_H
class Pila{
	private:
		Nodo palabras;
	public:
		Pila();
		void generarPila();
		void insertar(char []);
		void buscar();
};
#endif

Pila::Pila(){
	palabras=NULL;
}
/*void Pila::insertar(char refEspaniol[],char refIngles[]){
	
}*/
void Pila::insertar(char linea[])
{
	Pila *aux=new Pila();
	char *palabraAux;
	palabraAux=strtok(linea,";");
	strcpy(aux->espaniol,palabraAux);
	palabraAux=strtok(linea,";");
	strcpy(aux->ingles,palabraAux);
	if(palabras!=NULL){
		aux->siguiente=NULL;
		aux->anterior=NULL;
		palabras=aux;
	}else{
		palabras->siguiente=aux;
		aux->anterior=palabras;
		aux->siguiente=NULL;
	}
	printf("%s  ",aux->espaniol);
	printf("%s  \n",aux->ingles);
}
void Pila::generarPila(){
	FILE *arcPalabras=fopen("palabrasDiccionario.txt","r");
	char linea[50];
	while(!feof(arcPalabras)){
		fscanf(arcPalabras,"%s",linea);
		insertar(linea);
	}
	fclose(arcPalabras);
}

