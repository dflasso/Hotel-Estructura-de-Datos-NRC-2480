/*UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
   			ESTRUCTURA DE DATOS
		ING. FERNANDO SOLIS
		TEMA: LIBRERIA PERSONAL
ESTUDIANTE: BRYAN RODRIGUEZ
	SEMESTRE OCT 2017 - FEB 2018*/

//lectura y escritura de datos
//declaracion de librerias
#include <stdio.h>
#include <iostream>//sirve para operaciones de entrada y de salida
#include <stdlib.h>
#include <conio.h>//provee un sistema de E/S por consola
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
#include <cstring>//manejo de cadenas de caracteres
#include <cstdlib>//sirve para llamar un comando del sistema sobre el cual se está ejecutando el programa.
#include <ctime>//funciones para conseguir y manipular la informacion de la fecha y el tiempo.
#include <stdio.h> // para usar texbox
#include <windows.h> // Libreria que me permite utilizar el "Sleep(tiempo)"---> sirve para hacer una pausa de x tiempo
using namespace std;
#include <fstream> // para activar las funciones de manejo de texto

/*Declaracion de Funciones*/


void caratula(){
	system("cls");
	system("color 0E");
	printf("\t\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^  *******************************************************************   ^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^  **                                                               **   ^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^  **          *******      ******       *******       *******      **   ^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^  **         **           **           **     **     **            **   ^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^  **         **           **           **     **     **            **   ^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^  **         *******       *****       ********      ********      **   ^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^  **         **                **      **            **            **   ^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^  **         **                **      **            **            **   ^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^  **          *******     ******       **             *******      **   ^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^  **                                                               **   ^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^  *******************************************************************   ^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^                                                                        ^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^              DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION                ^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^              ------------------------------------------                ^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^                                                                        ^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^              INGENIERIA  EN  SISTEMAS  E  INFORMATICA                  ^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^              ----------------------------------------                  ^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^                                                                        ^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^                           PROGRAMACION I                               ^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^                       ---------------------                            ^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^                                                                        ^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^                     	PROYECTO DE INVESTIGACION                         ^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^                      -------------------------                         ^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^     Integrantes:                                                       ^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^     ------------                                                       ^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^     => BORJA DIEGO		                                          ^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^     => LASSO DANNY		                                          ^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^     => RODRIGUEZ BRYAN                                                 ^^\n");Sleep(100);
    printf("\t\t\t\t\t\t^^                                                                        ^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");Sleep(100);
	printf("\t\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");Sleep(100);
	printf("\n\nPresione cualquier tecla para continuar.....");
	//funcion Sleep(); me permite imprimir en pantalla con un tiempo especificado a manera de pausa
	getch();
}

//esta funcion sirve para que cuando compile el programa la consola se ponga en toda la pantalla
void AltEnter(){
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
    return;

}



