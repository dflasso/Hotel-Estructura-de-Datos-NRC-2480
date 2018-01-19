#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>
#include <fstream>
#include <string>
#include <time.h>
#include <pthread.h>

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define TECLA_DERECHA 77
#define TECLA_IZQUIERDA 75
#define TECLA_ENTER 13

void gotoxy(int x, int y) //referencia: https://www.youtube.com/watch?v=evmIH4nyTgE
{ 
	HANDLE hCon;
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hCon,dwPos);	
}

void color(int x)
{
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),x);
}

int menu(char *titulo, char *opciones[], int numero)
{

	bool repite=true;
	int seleccionar=1,tecla;
	int i;
	system("cls");
	do
	{

		gotoxy(10,2);
		color(158);
		printf("================================================");
		color(11);
		printf("\n\t\t\t%s\t\t\t\n\n",titulo);
		 //letras en amarillo
		color(15); //letras en blanco
		for(i=0;i<numero;i++)
			printf("\t\t%s\n",opciones[i]);		
		gotoxy(16,4+seleccionar); //17
		color(249);
		//printf("%c %s",175,opciones[seleccionar-1]); //impresion con asterisco
		printf("%s",opciones[seleccionar-1]);
		color(158);
		gotoxy(10,15);
		printf("================================================");
		color(15);
		do
		{
			tecla=getch();

		}while(tecla!=TECLA_ARRIBA && tecla!=TECLA_ABAJO && tecla!= TECLA_ENTER && tecla !=00);
		switch(tecla)
		{
			case TECLA_ARRIBA:
			{
				seleccionar--;
				if(seleccionar==0)
					seleccionar=numero;			
			}
			break;
			case TECLA_ABAJO:
			{
				seleccionar++;
				if(seleccionar==numero+1)
					seleccionar=1;
			}
			break;
			case TECLA_ENTER:
				repite=false;
			break;
			case 0:
				ShellExecute(NULL, TEXT("open"),TEXT("Extras\\Ayuda-hotel.chm"),NULL, NULL,SW_SHOWNORMAL);
			break;
		}
	}while(repite);
	color(15); 
	return seleccionar;
}

void AltEnter()
{
    keybd_event(VK_MENU,
                0x38,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                KEYEVENTF_KEYUP,
                0);
    keybd_event(VK_MENU,
                0x38,
                KEYEVENTF_KEYUP,
                0);
}

bool validacionCaracter(char cadena[]){
	int i;
	for(i=0;cadena[i]!='\0';i++)
	{
		if((cadena[i]<65||cadena[i]>90)&&(cadena[i]<97||cadena[i]>122)&&cadena[i]!=32&&cadena[i]!=-92&&cadena[i]!=-91)
		{
			printf("______________________________________________________\nDato Incorrecto !!\nNo puede contener caracteres especiales, ni numeros\nVuelva a ingresar por favor\n______________________________________________________\n\n");
			return true;
			break;
		}	
	}	
	return false;
}

void imprimirTXT(char txt[])
{
	int x=0,y=0;
    char caracter[200];
    system("color 0E");
    FILE *INICIO;
    INICIO=fopen(txt,"r");

    while (!feof(INICIO))
    {
        fgets(caracter,130,INICIO);
        gotoxy(x,y);
		puts(caracter);
        y++;
    }
}
