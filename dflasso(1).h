/*UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
   			ESTRUCTURA DE DATOS
		ING. FERNANDO SOLIS
		TEMA: LIBRERIA PERSONAL
ESTUDIANTE: DANNY LASSO
	SEMESTRE OCT 2017 - FEB 2018*/

//lectura y escritura de datos
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
//funciones de consola
#include <windows.h>
#include  <ctype.h>
//funciones para cadenas
#include  <string.h>
//archivo
#include <fstream>
#include <string>
//funciones con el reloj y calendario de la computadora
#include <time.h>
//
void etiqueta(const char *prog){
	system("color F2");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),160);
	printf("\n\n*******************************************************************\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),249);
	printf("|||\t\tUNIVERISDAD DE LAS FUERZAS ARMADAS-ESPE\t\t|||\n");
	printf("|||\t\t\tESTRUCTURA DE DATOS\n");
	printf("|||PROGRAMA:\t%s\n",prog);
	printf("|||ALUMNO:\tDANY LASSO\t\t\t\t\t|||\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),160);
	printf("*******************************************************************\n");
	system("pause");
}
void gotoxy(int x, int y){
	HANDLE hCon;
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hCon,dwPos);
	//referencia
	//https://www.youtube.com/watch?v=evmIH4nyTgE
}
int selecionar1(const char *titulo, const char *opciones[],int n){
	int selec=1;
	int tecla;
	bool repite=true;
	system("color F9");
	do{
		system("cls");
		//imprime flecha de seleccion
		gotoxy(5,3+selec); 
		//imprime titulo
		gotoxy(15,2); printf("%s",titulo);
		//imprime opciones
		for(int i=0;i<n;i++){
			if(3+selec!=4+i){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),249);
				gotoxy(10,4+i); printf("%d . %s",i+1,opciones[i]);	
			}else{
				//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),249);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),31);
				gotoxy(10,4+i); printf("%d . %s",i+1,opciones[i]);
			}
			//gotoxy(10,15); printf("\t\t%d == %d\t",3+selec,4+i);+
			//system("pause");
		}
		do{
			tecla=getch();
		}while(tecla!=72 && tecla!=80 && tecla!=13);
		switch(tecla){
			case 72:
				selec--;
				if(selec<1){
					selec=n;
				}
				break;
			case 80:
				selec++;
				if(selec>n){
					selec=1;
				}
				break;
			case 13:
				repite=false;
				break;
		}
	}while(repite);
	return selec;
	//referencias
	//https://www.youtube.com/watch?v=-jpN6LHy2Bk
	//https://www.youtube.com/watch?v=nPpG36OHZP4
}
int numero(const char msg[]){
	int n=0;
	char cadena[10], d;
	printf("\n%s\t",msg);
	while((d=getch())!=13){
		if((d>='0')&&(d<='9')){
			printf("%c",d);
			cadena[n]=d;
			n++;
		}
	}
	cadena[d]='\0';
	return atoi(cadena);
}
void color(int X){
SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),X);
}
int menu(){
	char fr1[100][100]={"Crear Lista.","Imprimir Lista.","Ingreso al inicio de la Lista.","Ingreso al final de la Lista.","Ingreso en una posicion especifica de la Lista.","Salir."};
	char c;
	system("cls");
	int y=2,n,opcion;
	gotoxy(10,0);
	system("color E");
	printf(":::::::::::MENU PRINCIPAL::::::::::::");
	gotoxy(1,1);
	for(int i=1;i<7;i++){
		if(i==1){
			color(07);
			gotoxy(1,y+i);
			printf("%s",fr1[i-1]);
			color(07);
		}
		else{
			color(07);
			gotoxy(1,y+i);
			printf("%s",fr1[i-1]);
		}
	}
	do{
		c=getch();
		gotoxy(1,y+1);
		color(07);
		for(int i=y; i<8 ;i++){
			gotoxy(1,i+1);
			printf("%s",fr1[i-2]);
		}
		if (c==-32){
			c=getch();
			if (c==72){
				if (y==2){
					y=8;
				}
				else{
					y--;
				}
				gotoxy(1,y+1);
				color(249);
				printf("%s",fr1[y-2]);
			}
			if (c==80){
				if (y==9){
					y=2;
				}
				else{
					y++;
				}
				gotoxy(1,y+1);
				color(249);
				printf("%s",fr1[y-2]);
			}
		}
		if (c==13){
			n=y-1;
			break;
		}
		else{
			gotoxy(1,y+1);
			color(249);
			printf("%s",fr1[y-2]);
		}
	}while(1);
	opcion=n;
    system("cls");
    return n;
}
//
