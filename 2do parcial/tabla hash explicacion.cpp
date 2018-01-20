#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <string.h>
#define MAXC 10 //MAXIMO TAMAÑO DE UNA CADENA
#define MAXA 10 //TAMAÑO DE LA TABLA

typedef struct nodo
{
    int clave;
	char cadena[MAXC];
    struct nodo *siguiente;
    struct nodo *anterior;
}*tabla;
 
int clave (char cadenaAux[MAXC])//OBTIENE LA SUMA DE LOS VALORES ASCII DE CADA CARACTER DE LA CADENA
{
    int clave=0, ascii, i=0;
    
    while((ascii=cadenaAux[i++])!='\0')
        clave+=ascii;
    return clave;
}
 
void insertar(tabla &hash, char cadena[MAXC])//INSERTAR NUEVO ELEMENTO EN UNA LISTA
{
    tabla nuevo=new nodo();
    strcpy(nuevo->cadena,cadena);
    nuevo->clave=clave(cadena);
	if(hash==NULL){
    	hash=nuevo;
		hash->anterior=NULL;
    	hash->siguiente=NULL;
	}else{
		hash->siguiente=nuevo;
		nuevo->anterior=hash;
		nuevo->siguiente=NULL;
	}
}
 
void mostrar(tabla &hash)//IMPRIMIR LA TABLA
{
    tabla aux=hash;
    
    while (aux!=NULL)//MIENTRAS NO SEA EL FINAL DE LA LISTA
    {
        printf("\t[ %d ]-> %s\n",aux->clave,aux->cadena);//IMPRIME EL DATO DEL NODO CORRESPONDIENTE
        aux = aux->siguiente;//AVANZAMOS AL SIGUIENTE NODO
    }
}

void borrar(tabla &hash, char cadena[MAXC])//IMPRIMIR LA TABLA
{
    tabla aux=hash,anterior;
    int claveb=-1,ref;
    while (aux!=NULL)//MIENTRAS NO SEA EL FINAL DE LA LISTA
    {
    	ref=clave(cadena);
        if((aux->clave-ref)==0){
        	claveb=aux->clave;
        	printf("\n\nELEMENTO Borrado\n");
        	anterior=aux->anterior;
        	anterior->siguiente=aux->siguiente;
        	aux=NULL;
		}else{
			aux = aux->siguiente;//AVANZAMOS AL SIGUIENTE NODO	
		}
        
    }
    if(claveb==-1){
    	printf("\n\nNo se encontro el elemento\n");
	}
} 

void buscar(tabla &hash, char cadena[MAXC])
{
    tabla aux=hash;
    int claveb=-1,ref;
    while (aux!=NULL)//MIENTRAS NO SEA EL FINAL DE LA LISTA
    {
    	ref=clave(cadena);
        if((aux->clave-ref)==0){
        	claveb=aux->clave;
        	printf("\n\nELEMENTO ENCONTRADO\n");
		}
        aux = aux->siguiente;//AVANZAMOS AL SIGUIENTE NODO
    }
    if(claveb==-1){
    	printf("\n\nNo se encontro el elemento\n");
	}
} 
int main()
{
    struct nodo *ptabla[MAXA];//ARREGLO DE PUNTEROS PARA NODOS
    tabla hash=NULL; //tabla hash
    char cadenaux[MAXC];//ARREGLO AUXILIAR PARA GUARDAR CADENA INTRODUCIDA
    int op, clavecadena, pos;//VARIABLES USADAS PARA MENU Y POSICION EN EL ARREGLO
    
    
    do
    {
        printf("\n*********************************\n");
        printf("\n\nTABLA HASH\n\t1.- Guardar una cadenan\n\t2. Mostrar \n\t3.- Buscar una candenan\n\t4.- Borrar una cadenan\n\t0.- Salir.\t\t");
        scanf("%i", &op);
        printf("\n*********************************\n");
        
        switch(op)
        {
            case 1:
                printf("\nIntroduce cadena  ");
                fflush(stdin);
                gets(cadenaux);
                //clavecadena=clave(cadenaux);
                insertar(hash,cadenaux);
                break;
        	case 2:
        		mostrar(hash);
        	break;
        	case 3:
        		printf("nIntroduce cadena a buscar  ");
                fflush(stdin);
                gets(cadenaux);
                buscar(hash,cadenaux);
        		break;
        	case 4:
        		printf("nIntroduce cadena que desea borrar borrar  ");
                fflush(stdin);
                gets(cadenaux);
                borrar(hash,cadenaux);
        		break;
        }
    }while(op!=0);
    return 0;
}
