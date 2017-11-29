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
int menu(const char *titulo, const char *opciones[],int n){
	int selec=1;
	int tecla;
	bool repite=true;
	system("color A");
	do{
		system("cls");
		system("color A");
		color(10);
		//imprime titulo
		gotoxy(15,1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),158);
		printf("================================================");
		gotoxy(25,2); 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		printf("%s",titulo);
		//imprime opciones
		for(int i=0;i<n;i++){
				gotoxy(20,4+i); printf("%d . %s",i+1,opciones[i]);	
		}
		//imprime flecha de seleccion
		gotoxy(20,3+selec); 
		//printf("==>");
		//gotoxy(10,20); 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),249);
		printf("%d . %s",selec,opciones[selec-1]);	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),158);
		gotoxy(15,14);
		printf("================================================");
		do{
			tecla=getch();
		}while(tecla!=72 && tecla!=80 && tecla!=13&& tecla !=00);
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
			case 0:
				ShellExecute(NULL, TEXT("open"),TEXT("Extras\\Ayuda-hotel.chm"),NULL, NULL,SW_SHOWNORMAL);
				break;
		}
	}while(repite);
	return selec;
	//referencias
	//https://www.youtube.com/watch?v=-jpN6LHy2Bk
	//https://www.youtube.com/watch?v=nPpG36OHZP4
}
int menuP(const char *titulo, const char *opciones[],int n){
	int select=1;
	int key;
	bool repit=true;
	do{
		system("cls");
		system("color A");
		//imprime titulo
		gotoxy(15,1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),158);
		printf("================================================");
		gotoxy(25,2); 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		printf("%s",titulo);
		//imprime opciones
		for(int i=0;i<n;i++){
				gotoxy(20,4+i); printf("%d . %s",i+1,opciones[i]);	
		}
		//imprime flecha de seleccion
		gotoxy(20,3+select); 
		//printf("==>");
		//gotoxy(10,20); 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),249);
		printf("%d . %s",select,opciones[select-1]);	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),158);
		gotoxy(15,12);
		printf("================================================");
		do{
			key=getch();
		}while(key!=72 && key!=80 && key!=13);
		switch(key){
			case 72:
				key--;
				if(select<1){
					select=n;
				}
				break;
			case 80:
				select++;
				if(select>n){
					select=1;
				}
				break;
			case 13:
				repit=false;
				break;
		}
	}while(repit);
	return select;
	//referencias
	//https://www.youtube.com/watch?v=-jpN6LHy2Bk
	//https://www.youtube.com/watch?v=nPpG36OHZP4
}
//fechas
//fechas
void mes(int ref){
	switch(ref){
		case 1: 
		printf("\n\ENEROn");
		break;
		case 2:
			printf("\nFEBRERO\n");
		break;
		case 3: 
			printf("\nMARZO\n");
		break;
		case 4: 
			printf("\nABRIL\n");
		break;	
		case 5: 
			printf("\nMAYO\n");
		break;
		case 6: 
			printf("\nJUNIO\n");
		break;
		case 7: 
			printf("\nJULIO\n");
		break;
		case 8: 
			printf("\nAGOSTO\n");
		break;	
		case 9: 
			printf("\nSEPTIEMBRE\n");
		break;
		case 10: 
			printf("\nOCTUBRE\n");
		break;	
		case 11:
			printf("\nNOVIEMBRE\n");
		break;	
		case 12: 
			printf("\nDICIEMBRE\n");
		break;
	}
}
int dias_del_mes(int ref){
	switch(ref){
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			return 31;
		break;
		case 4: case 6: case 9: case 11:
			return 30;
		break;	
		case 2:
			return 28;
		break;
	}
}
#define diaA 1
#define mesA 2 
int actual(int ref){
	time_t tiempo= time(0);
	struct tm *tlocal=localtime(&tiempo);
	char actual[128];
	//dia=1,mes=2,anio=3
	switch(ref){
		case 1:
			strftime(actual,238,"%d",tlocal);
			return atoi(actual);
		break;
		case 2:
			strftime(actual,238,"%m",tlocal);
			return atoi(actual);
		break;
	}
}
//
