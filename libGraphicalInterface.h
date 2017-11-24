/*UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
   			ESTRUCTURA DE DATOS
		ING. FERNANDO SOLIS
		TEMA: LIBRERIA PERSONAL
ESTUDIANTE: BRYAN RODRIGUEZ
	SEMESTRE OCT 2017 - FEB 2018*/

//librerias
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <time.h>

using namespace std;


void color(int a,int b){
    int color= (a*16)+b;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),color);
}

void portada (){
	
    int tesp=5,x=3,y=4;
    char caracter[130];
    system("color 0E");
    FILE *INICIO;
    INICIO=fopen("Datos.txt","r");


         for (int i=1;i<167;i++) 
        {
            gotoxy(i,1);printf("%c",223);
        }
        for (int i=1;i<47;i++)
        {
            gotoxy(1,i);printf("%c",219);
        }

          for (int i=1;i<47;i++) 
        {
            gotoxy(167,i);printf("%c",219);
        }
        for (int i=1;i<=167;i++) 
        {
            gotoxy(i,47);printf("%c",223);
        }

        while (!feof(INICIO))
        {
            fgets(caracter,130,INICIO);
            gotoxy(x,y);cout<<caracter;
            Sleep(125);
            y++;
        }
        printf("\n\n\n");
     
        Sleep(3000);
        Beep(330,200);
        system("cls");
		system("color 0E");


     
        gotoxy(10,1);printf("%c",219);Sleep(tesp);
        gotoxy(10,2);printf("%c",219);Sleep(tesp);
        gotoxy(10,3);printf("%c",219);Sleep(tesp);
        gotoxy(10,4);printf("%c",219);Sleep(tesp);
        gotoxy(10,5);printf("%c",219);Sleep(tesp);
        gotoxy(10,6);printf("%c",219);Sleep(tesp);
        gotoxy(10,7);printf("%c",219);Sleep(tesp);
        
        gotoxy(11,7);printf("%c",219);Sleep(tesp);
        gotoxy(12,7);printf("%c",219);Sleep(tesp);
        gotoxy(13,7);printf("%c",219);Sleep(tesp);
        gotoxy(14,7);printf("%c",219);Sleep(tesp);
        gotoxy(15,7);printf("%c",219);Sleep(tesp);

        gotoxy(16,1);printf("%c",219);Sleep(tesp);
        gotoxy(16,2);printf("%c",219);Sleep(tesp);
        gotoxy(16,3);printf("%c",219);Sleep(tesp);
        gotoxy(16,4);printf("%c",219);Sleep(tesp);
        gotoxy(16,5);printf("%c",219);Sleep(tesp);
        gotoxy(16,6);printf("%c",219);Sleep(tesp);
   		gotoxy(16,7);printf("%c",219);Sleep(tesp);
    
    	Beep(800,300);
    	
    	//N
    	
        gotoxy(18,1);printf("%c",219);Sleep(tesp);
        gotoxy(18,2);printf("%c",219);Sleep(tesp);
        gotoxy(18,3);printf("%c",219);Sleep(tesp);
        gotoxy(18,4);printf("%c",219);Sleep(tesp);
        gotoxy(18,5);printf("%c",219);Sleep(tesp);
        gotoxy(18,6);printf("%c",219);Sleep(tesp);
        gotoxy(18,7);printf("%c",219);Sleep(tesp);
        
        gotoxy(19,1);printf("%c",219);Sleep(tesp);
        gotoxy(20,2);printf("%c",219);Sleep(tesp);
    	gotoxy(21,3);printf("%c",219);Sleep(tesp);
        gotoxy(22,4);printf("%c",219);Sleep(tesp);
        gotoxy(23,5);printf("%c",219);Sleep(tesp);
        gotoxy(24,6);printf("%c",219);Sleep(tesp);
        gotoxy(25,7);printf("%c",219);Sleep(tesp);
        
        gotoxy(25,1);printf("%c",219);Sleep(tesp);
        gotoxy(25,2);printf("%c",219);Sleep(tesp);
        gotoxy(25,3);printf("%c",219);Sleep(tesp);
        gotoxy(25,4);printf("%c",219);Sleep(tesp);
        gotoxy(25,5);printf("%c",219);Sleep(tesp);
        gotoxy(25,6);printf("%c",219);Sleep(tesp);
        gotoxy(25,7);printf("%c",219);Sleep(tesp);
        Beep(800,300);
    //I
    
    	gotoxy(27,1);printf("%c",219);Sleep(tesp);
        gotoxy(27,2);printf("%c",219);Sleep(tesp);
        gotoxy(27,3);printf("%c",219);Sleep(tesp);
        gotoxy(27,4);printf("%c",219);Sleep(tesp);
        gotoxy(27,5);printf("%c",219);Sleep(tesp);
        gotoxy(27,6);printf("%c",219);Sleep(tesp);
        gotoxy(27,7);printf("%c",219);Sleep(tesp);
        Beep(800,300);
    //V
    
    	gotoxy(29,1);printf("%c",219);Sleep(tesp);
        gotoxy(30,2);printf("%c",219);Sleep(tesp);
    	gotoxy(31,3);printf("%c",219);Sleep(tesp);
        gotoxy(32,4);printf("%c",219);Sleep(tesp);
        gotoxy(33,5);printf("%c",219);Sleep(tesp);
        gotoxy(34,6);printf("%c",219);Sleep(tesp);
        gotoxy(35,7);printf("%c",219);Sleep(tesp);
        
        
        gotoxy(36,7);printf("%c",219);Sleep(tesp);
        gotoxy(37,6);printf("%c",219);Sleep(tesp);
    	gotoxy(38,5);printf("%c",219);Sleep(tesp);
        gotoxy(39,4);printf("%c",219);Sleep(tesp);
        gotoxy(40,3);printf("%c",219);Sleep(tesp);
        gotoxy(41,2);printf("%c",219);Sleep(tesp);
        gotoxy(42,1);printf("%c",219);Sleep(tesp);
    	Beep(800,300);
    //E
    
     	gotoxy(44,1);printf("%c",219);Sleep(tesp);
        gotoxy(44,2);printf("%c",219);Sleep(tesp);
        gotoxy(44,3);printf("%c",219);Sleep(tesp);
        gotoxy(44,4);printf("%c",219);Sleep(tesp);
        gotoxy(44,5);printf("%c",219);Sleep(tesp);
        gotoxy(44,6);printf("%c",219);Sleep(tesp);
        gotoxy(44,7);printf("%c",219);Sleep(tesp);
        
        gotoxy(45,1);printf("%c",223);Sleep(tesp);
        gotoxy(46,1);printf("%c",223);Sleep(tesp);
        gotoxy(47,1);printf("%c",223);Sleep(tesp);
        gotoxy(48,1);printf("%c",223);Sleep(tesp);
        gotoxy(49,1);printf("%c",223);Sleep(tesp);
        gotoxy(50,1);printf("%c",223);Sleep(tesp);
        
        gotoxy(45,4);printf("%c",223);Sleep(tesp);
        gotoxy(46,4);printf("%c",223);Sleep(tesp);
        gotoxy(47,4);printf("%c",223);Sleep(tesp);
        gotoxy(48,4);printf("%c",223);Sleep(tesp);
        gotoxy(49,4);printf("%c",223);Sleep(tesp);
        gotoxy(50,4);printf("%c",223);Sleep(tesp);
    
        gotoxy(45,7);printf("%c",219);Sleep(tesp);
        gotoxy(46,7);printf("%c",219);Sleep(tesp);
        gotoxy(47,7);printf("%c",219);Sleep(tesp);
        gotoxy(48,7);printf("%c",219);Sleep(tesp);
        gotoxy(49,7);printf("%c",219);Sleep(tesp);
        gotoxy(50,7);printf("%c",219);Sleep(tesp);
        Beep(800,300);
    //R
    	gotoxy(52,1);printf("%c",219);Sleep(tesp);
        gotoxy(52,2);printf("%c",219);Sleep(tesp);
        gotoxy(52,3);printf("%c",219);Sleep(tesp);
        gotoxy(52,4);printf("%c",219);Sleep(tesp);
        gotoxy(52,5);printf("%c",219);Sleep(tesp);
        gotoxy(52,6);printf("%c",219);Sleep(tesp);
        gotoxy(52,7);printf("%c",219);Sleep(tesp);
        
        gotoxy(53,1);printf("%c",223);Sleep(tesp);
        gotoxy(54,1);printf("%c",223);Sleep(tesp);
        gotoxy(55,1);printf("%c",223);Sleep(tesp);
        gotoxy(56,1);printf("%c",223);Sleep(tesp);
        gotoxy(57,1);printf("%c",223);Sleep(tesp);
       	gotoxy(58,1);printf("%c",223);Sleep(tesp);
       
       
	    gotoxy(59,1);printf("%c",219);Sleep(tesp);
        gotoxy(59,2);printf("%c",219);Sleep(tesp);
        gotoxy(59,3);printf("%c",219);Sleep(tesp);
      //  gotoxy(59,4);printf("%c",219);Sleep(tesp);
        
        gotoxy(53,4);printf("%c",223);Sleep(tesp);
        gotoxy(54,4);printf("%c",223);Sleep(tesp);
        gotoxy(55,4);printf("%c",223);Sleep(tesp);
        gotoxy(56,4);printf("%c",223);Sleep(tesp);
        gotoxy(57,4);printf("%c",223);Sleep(tesp);
       	gotoxy(58,4);printf("%c",223);Sleep(tesp);
        
		gotoxy(53,4);printf("%c",219);Sleep(tesp);
        gotoxy(54,5);printf("%c",219);Sleep(tesp);
    	gotoxy(55,6);printf("%c",219);Sleep(tesp);
        gotoxy(56,7);printf("%c",219);Sleep(tesp);
     	Beep(800,300);
	//S
		

        gotoxy(61,1);printf("%c",223);Sleep(tesp);
        gotoxy(62,1);printf("%c",223);Sleep(tesp);
        gotoxy(63,1);printf("%c",223);Sleep(tesp);
        gotoxy(64,1);printf("%c",223);Sleep(tesp);
       	gotoxy(65,1);printf("%c",223);Sleep(tesp);
       	gotoxy(66,1);printf("%c",223);Sleep(tesp);
       	gotoxy(67,1);printf("%c",223);Sleep(tesp);
       	gotoxy(68,1);printf("%c",223);Sleep(tesp);
	
		gotoxy(61,1);printf("%c",219);Sleep(tesp);
        gotoxy(61,2);printf("%c",219);Sleep(tesp);
        gotoxy(61,3);printf("%c",219);Sleep(tesp);
        
        gotoxy(61,4);printf("%c",223);Sleep(tesp);
        gotoxy(62,4);printf("%c",223);Sleep(tesp);
        gotoxy(63,4);printf("%c",223);Sleep(tesp);
        gotoxy(64,4);printf("%c",223);Sleep(tesp);
       	gotoxy(65,4);printf("%c",223);Sleep(tesp);
       	gotoxy(66,4);printf("%c",223);Sleep(tesp);
       	gotoxy(67,4);printf("%c",223);Sleep(tesp);
       	gotoxy(68,4);printf("%c",223);Sleep(tesp);
        
        gotoxy(68,4);printf("%c",219);Sleep(tesp);
        gotoxy(68,5);printf("%c",219);Sleep(tesp);
        gotoxy(68,6);printf("%c",219);Sleep(tesp);
        gotoxy(68,7);printf("%c",219);Sleep(tesp);
        
		gotoxy(61,7);printf("%c",219);Sleep(tesp);
        gotoxy(62,7);printf("%c",219);Sleep(tesp);
        gotoxy(63,7);printf("%c",219);Sleep(tesp);
        gotoxy(64,7);printf("%c",219);Sleep(tesp);
       	gotoxy(65,7);printf("%c",219);Sleep(tesp);
       	gotoxy(66,7);printf("%c",219);Sleep(tesp);
       	gotoxy(67,7);printf("%c",219);Sleep(tesp);
       	gotoxy(68,7);printf("%c",219);Sleep(tesp);
	 	Beep(800,300);
  //I
    
    	gotoxy(70,1);printf("%c",219);Sleep(tesp);
        gotoxy(70,2);printf("%c",219);Sleep(tesp);
        gotoxy(70,3);printf("%c",219);Sleep(tesp);
        gotoxy(70,4);printf("%c",219);Sleep(tesp);
        gotoxy(70,5);printf("%c",219);Sleep(tesp);
        gotoxy(70,6);printf("%c",219);Sleep(tesp);
        gotoxy(70,7);printf("%c",219);Sleep(tesp);
	 	Beep(800,300);
  //D
  		gotoxy(72,1);printf("%c",219);Sleep(tesp);
        gotoxy(72,2);printf("%c",219);Sleep(tesp);
        gotoxy(72,3);printf("%c",219);Sleep(tesp);
        gotoxy(72,4);printf("%c",219);Sleep(tesp);
        gotoxy(72,5);printf("%c",219);Sleep(tesp);
        gotoxy(72,6);printf("%c",219);Sleep(tesp);
        gotoxy(72,7);printf("%c",219);Sleep(tesp);
  			 
  		gotoxy(73,1);printf("%c",223);Sleep(tesp);
        gotoxy(74,1);printf("%c",223);Sleep(tesp);
        gotoxy(75,1);printf("%c",223);Sleep(tesp);
        gotoxy(76,1);printf("%c",223);Sleep(tesp);
       	gotoxy(77,1);printf("%c",219);Sleep(tesp);
       	
		gotoxy(78,2);printf("%c",219);Sleep(tesp);
       	gotoxy(79,3);printf("%c",219);Sleep(tesp);
       	gotoxy(79,4);printf("%c",219);Sleep(tesp);
       	gotoxy(79,5);printf("%c",219);Sleep(tesp);

       	gotoxy(78,6);printf("%c",219);Sleep(tesp);
  		gotoxy(77,7);printf("%c",219);Sleep(tesp);
		

		gotoxy(73,7);printf("%c",219);Sleep(tesp);
		gotoxy(74,7);printf("%c",219);Sleep(tesp);
        gotoxy(75,7);printf("%c",219);Sleep(tesp);
        gotoxy(76,7);printf("%c",219);Sleep(tesp);
       	Beep(800,300);
    //A
    
    	 
        gotoxy(80,7);printf("%c",219);Sleep(tesp);
        gotoxy(81,6);printf("%c",219);Sleep(tesp);
    	gotoxy(82,5);printf("%c",219);Sleep(tesp);
        gotoxy(83,4);printf("%c",219);Sleep(tesp);
        gotoxy(84,3);printf("%c",219);Sleep(tesp);
        gotoxy(85,2);printf("%c",219);Sleep(tesp);
        gotoxy(86,1);printf("%c",219);Sleep(tesp);
        
        gotoxy(84,4);printf("%c",223);Sleep(tesp);
       	gotoxy(85,4);printf("%c",223);Sleep(tesp);
       	gotoxy(86,4);printf("%c",223);Sleep(tesp);
       	gotoxy(87,4);printf("%c",223);Sleep(tesp);
       	gotoxy(88,4);printf("%c",223);Sleep(tesp);
       	gotoxy(89,4);printf("%c",223);Sleep(tesp);

    	gotoxy(87,1);printf("%c",219);Sleep(tesp);
        gotoxy(88,2);printf("%c",219);Sleep(tesp);
    	gotoxy(89,3);printf("%c",219);Sleep(tesp);
        gotoxy(90,4);printf("%c",219);Sleep(tesp);
        gotoxy(91,5);printf("%c",219);Sleep(tesp);
        gotoxy(92,6);printf("%c",219);Sleep(tesp);
        gotoxy(93,7);printf("%c",219);Sleep(tesp);        
       	Beep(800,300);
    //D
    	
    	gotoxy(95,1);printf("%c",219);Sleep(tesp);
        gotoxy(95,2);printf("%c",219);Sleep(tesp);
        gotoxy(95,3);printf("%c",219);Sleep(tesp);
        gotoxy(95,4);printf("%c",219);Sleep(tesp);
        gotoxy(95,5);printf("%c",219);Sleep(tesp);
        gotoxy(95,6);printf("%c",219);Sleep(tesp);
        gotoxy(95,7);printf("%c",219);Sleep(tesp);
  			 
  		gotoxy(96,1);printf("%c",223);Sleep(tesp);
        gotoxy(97,1);printf("%c",223);Sleep(tesp);
        gotoxy(98,1);printf("%c",223);Sleep(tesp);
        gotoxy(99,1);printf("%c",223);Sleep(tesp);
       	gotoxy(100,1);printf("%c",219);Sleep(tesp);
       	
		gotoxy(101,2);printf("%c",219);Sleep(tesp);
      	gotoxy(102,3);printf("%c",219);Sleep(tesp);
       	gotoxy(102,4);printf("%c",219);Sleep(tesp);
       	gotoxy(102,5);printf("%c",219);Sleep(tesp);

       	gotoxy(101,6);printf("%c",219);Sleep(tesp);
  		gotoxy(100,7);printf("%c",219);Sleep(tesp);
		

		gotoxy(96,7);printf("%c",219);Sleep(tesp);
		gotoxy(97,7);printf("%c",219);Sleep(tesp);
        gotoxy(98,7);printf("%c",219);Sleep(tesp);
        gotoxy(99,7);printf("%c",219);Sleep(tesp);
    	Beep(800,300);
    //D
    	
    	gotoxy(110,1);printf("%c",219);Sleep(tesp);
        gotoxy(110,2);printf("%c",219);Sleep(tesp);
        gotoxy(110,3);printf("%c",219);Sleep(tesp);
        gotoxy(110,4);printf("%c",219);Sleep(tesp);
        gotoxy(110,5);printf("%c",219);Sleep(tesp);
        gotoxy(110,6);printf("%c",219);Sleep(tesp);
        gotoxy(110,7);printf("%c",219);Sleep(tesp);
  			 
  		gotoxy(111,1);printf("%c",223);Sleep(tesp);
        gotoxy(112,1);printf("%c",223);Sleep(tesp);
        gotoxy(113,1);printf("%c",223);Sleep(tesp);
        gotoxy(114,1);printf("%c",223);Sleep(tesp);
       	gotoxy(115,1);printf("%c",219);Sleep(tesp);
       	
		gotoxy(116,2);printf("%c",219);Sleep(tesp);
      	gotoxy(117,3);printf("%c",219);Sleep(tesp);
       	gotoxy(117,4);printf("%c",219);Sleep(tesp);
       	gotoxy(117,5);printf("%c",219);Sleep(tesp);

       	gotoxy(116,6);printf("%c",219);Sleep(tesp);
  		gotoxy(115,7);printf("%c",219);Sleep(tesp);
		

		gotoxy(111,7);printf("%c",219);Sleep(tesp);
		gotoxy(112,7);printf("%c",219);Sleep(tesp);
        gotoxy(113,7);printf("%c",219);Sleep(tesp);
        gotoxy(114,7);printf("%c",219);Sleep(tesp);
    	Beep(800,300);
   
     //E	
        gotoxy(119,1);printf("%c",219);Sleep(tesp);
        gotoxy(119,2);printf("%c",219);Sleep(tesp);
        gotoxy(119,3);printf("%c",219);Sleep(tesp);
        gotoxy(119,4);printf("%c",219);Sleep(tesp);
        gotoxy(119,5);printf("%c",219);Sleep(tesp);
        gotoxy(119,5);printf("%c",219);Sleep(tesp);
		gotoxy(119,6);printf("%c",219);Sleep(tesp);
		gotoxy(119,7);printf("%c",219);Sleep(tesp);


        gotoxy(120,1);printf("%c",223);Sleep(tesp);
        gotoxy(121,1);printf("%c",223);Sleep(tesp);
        gotoxy(122,1);printf("%c",223);Sleep(tesp);
        gotoxy(123,1);printf("%c",223);Sleep(tesp);


        gotoxy(120,4);printf("%c",223);Sleep(tesp);
        gotoxy(121,4);printf("%c",223);Sleep(tesp);
	    gotoxy(122,4);printf("%c",223);Sleep(tesp);
        gotoxy(123,4);printf("%c",223);Sleep(tesp);


        gotoxy(119,7);printf("%c",219);Sleep(tesp);
        gotoxy(120,7);printf("%c",219);Sleep(tesp);
        gotoxy(121,7);printf("%c",219);Sleep(tesp);
        gotoxy(122,7);printf("%c",219);Sleep(tesp);
        gotoxy(123,7);printf("%c",219);Sleep(tesp);
    	Beep(800,300);
    	
    	
    	//L
    	
    	gotoxy(128,1);printf("%c",219);Sleep(tesp);
        gotoxy(128,2);printf("%c",219);Sleep(tesp);
        gotoxy(128,3);printf("%c",219);Sleep(tesp);
        gotoxy(128,4);printf("%c",219);Sleep(tesp);
        gotoxy(128,5);printf("%c",219);Sleep(tesp);
        gotoxy(128,5);printf("%c",219);Sleep(tesp);
		gotoxy(128,6);printf("%c",219);Sleep(tesp);
		gotoxy(128,7);printf("%c",219);Sleep(tesp);

        gotoxy(128,7);printf("%c",219);Sleep(tesp);
        gotoxy(129,7);printf("%c",219);Sleep(tesp);
        gotoxy(130,7);printf("%c",219);Sleep(tesp);
        gotoxy(131,7);printf("%c",219);Sleep(tesp);
        gotoxy(132,7);printf("%c",219);Sleep(tesp);
    	Beep(800,300);
    	
    	//A
    	gotoxy(134,7);printf("%c",219);Sleep(tesp);
        gotoxy(135,6);printf("%c",219);Sleep(tesp);
    	gotoxy(136,5);printf("%c",219);Sleep(tesp);
        gotoxy(137,4);printf("%c",219);Sleep(tesp);
        gotoxy(138,3);printf("%c",219);Sleep(tesp);
        gotoxy(139,2);printf("%c",219);Sleep(tesp);
        gotoxy(140,1);printf("%c",219);Sleep(tesp);
        
        gotoxy(138,4);printf("%c",223);Sleep(tesp);
       	gotoxy(139,4);printf("%c",223);Sleep(tesp);
       	gotoxy(140,4);printf("%c",223);Sleep(tesp);
       	gotoxy(141,4);printf("%c",223);Sleep(tesp);
       	gotoxy(142,4);printf("%c",223);Sleep(tesp);
       	gotoxy(143,4);printf("%c",223);Sleep(tesp);

    	gotoxy(141,1);printf("%c",219);Sleep(tesp);
        gotoxy(142,2);printf("%c",219);Sleep(tesp);
    	gotoxy(143,3);printf("%c",219);Sleep(tesp);
        gotoxy(144,4);printf("%c",219);Sleep(tesp);
        gotoxy(145,5);printf("%c",219);Sleep(tesp);
        gotoxy(145,6);printf("%c",219);Sleep(tesp);
        gotoxy(146,7);printf("%c",219);Sleep(tesp); 
    	Beep(800,300);
    	
    	//S
        gotoxy(148,1);printf("%c",223);Sleep(tesp);
        gotoxy(149,1);printf("%c",223);Sleep(tesp);
        gotoxy(150,1);printf("%c",223);Sleep(tesp);
        gotoxy(151,1);printf("%c",223);Sleep(tesp);
       	gotoxy(152,1);printf("%c",223);Sleep(tesp);
       	gotoxy(153,1);printf("%c",223);Sleep(tesp);
       	gotoxy(154,1);printf("%c",223);Sleep(tesp);
       	gotoxy(155,1);printf("%c",223);Sleep(tesp);
	
		gotoxy(148,1);printf("%c",219);Sleep(tesp);
        gotoxy(148,2);printf("%c",219);Sleep(tesp);
        gotoxy(148,3);printf("%c",219);Sleep(tesp);
        
        gotoxy(148,4);printf("%c",223);Sleep(tesp);
        gotoxy(149,4);printf("%c",223);Sleep(tesp);
        gotoxy(150,4);printf("%c",223);Sleep(tesp);
        gotoxy(151,4);printf("%c",223);Sleep(tesp);
       	gotoxy(152,4);printf("%c",223);Sleep(tesp);
       	gotoxy(153,4);printf("%c",223);Sleep(tesp);
       	gotoxy(154,4);printf("%c",223);Sleep(tesp);
       	gotoxy(155,4);printf("%c",223);Sleep(tesp);
        
        gotoxy(155,4);printf("%c",219);Sleep(tesp);
        gotoxy(155,5);printf("%c",219);Sleep(tesp);
        gotoxy(155,6);printf("%c",219);Sleep(tesp);
        gotoxy(155,7);printf("%c",219);Sleep(tesp);
        
		gotoxy(148,7);printf("%c",219);Sleep(tesp);
        gotoxy(149,7);printf("%c",219);Sleep(tesp);
        gotoxy(150,7);printf("%c",219);Sleep(tesp);
        gotoxy(151,7);printf("%c",219);Sleep(tesp);
       	gotoxy(152,7);printf("%c",219);Sleep(tesp);
       	gotoxy(153,7);printf("%c",219);Sleep(tesp);
       	gotoxy(154,7);printf("%c",219);Sleep(tesp);
       	gotoxy(155,7);printf("%c",219);Sleep(tesp);
    	Beep(800,300);
    	//letras fuerzas
    	//F
    	gotoxy(10,11);printf("%c",219);Sleep(tesp);
        gotoxy(10,12);printf("%c",219);Sleep(tesp);
        gotoxy(10,13);printf("%c",219);Sleep(tesp);
        gotoxy(10,14);printf("%c",219);Sleep(tesp);
        gotoxy(10,15);printf("%c",219);Sleep(tesp);
        gotoxy(10,15);printf("%c",219);Sleep(tesp);
		gotoxy(10,16);printf("%c",219);Sleep(tesp);
		gotoxy(10,17);printf("%c",219);Sleep(tesp);

        gotoxy(11,11);printf("%c",223);Sleep(tesp);
        gotoxy(12,11);printf("%c",223);Sleep(tesp);
        gotoxy(13,11);printf("%c",223);Sleep(tesp);
        gotoxy(14,11);printf("%c",223);Sleep(tesp);
        gotoxy(15,11);printf("%c",223);Sleep(tesp);
        gotoxy(16,11);printf("%c",223);Sleep(tesp);
        gotoxy(17,11);printf("%c",223);Sleep(tesp);

        gotoxy(11,14);printf("%c",223);Sleep(tesp);
        gotoxy(12,14);printf("%c",223);Sleep(tesp);
	    gotoxy(13,14);printf("%c",223);Sleep(tesp);
        gotoxy(14,14);printf("%c",223);Sleep(tesp);
        gotoxy(15,14);printf("%c",223);Sleep(tesp);
        gotoxy(16,14);printf("%c",223);Sleep(tesp);
        gotoxy(17,14);printf("%c",223);Sleep(tesp);
        
    	Beep(800,300);
    	
    	//U
     
        gotoxy(19,11);printf("%c",219);Sleep(tesp);
        gotoxy(19,12);printf("%c",219);Sleep(tesp);
        gotoxy(19,13);printf("%c",219);Sleep(tesp);
        gotoxy(19,14);printf("%c",219);Sleep(tesp);
        gotoxy(19,15);printf("%c",219);Sleep(tesp);
        gotoxy(19,16);printf("%c",219);Sleep(tesp);
        gotoxy(19,17);printf("%c",219);Sleep(tesp);
        
        gotoxy(20,17);printf("%c",219);Sleep(tesp);
        gotoxy(21,17);printf("%c",219);Sleep(tesp);
        gotoxy(22,17);printf("%c",219);Sleep(tesp);
        gotoxy(23,17);printf("%c",219);Sleep(tesp);
        gotoxy(24,17);printf("%c",219);Sleep(tesp);


        gotoxy(24,11);printf("%c",219);Sleep(tesp);
        gotoxy(24,12);printf("%c",219);Sleep(tesp);
        gotoxy(24,13);printf("%c",219);Sleep(tesp);
        gotoxy(24,14);printf("%c",219);Sleep(tesp);
        gotoxy(24,15);printf("%c",219);Sleep(tesp);
        gotoxy(24,16);printf("%c",219);Sleep(tesp);
        gotoxy(24,17);printf("%c",219);Sleep(tesp);
    
    	Beep(800,300);
    	
    //E
        gotoxy(26,11);printf("%c",219);Sleep(tesp);
        gotoxy(26,12);printf("%c",219);Sleep(tesp);
        gotoxy(26,13);printf("%c",219);Sleep(tesp);
        gotoxy(26,14);printf("%c",219);Sleep(tesp);
        gotoxy(26,15);printf("%c",219);Sleep(tesp);
        gotoxy(26,16);printf("%c",219);Sleep(tesp);
        gotoxy(26,17);printf("%c",219);Sleep(tesp);
        
        gotoxy(27,11);printf("%c",223);Sleep(tesp);
        gotoxy(28,11);printf("%c",223);Sleep(tesp);
        gotoxy(29,11);printf("%c",223);Sleep(tesp);
        gotoxy(30,11);printf("%c",223);Sleep(tesp);
        gotoxy(31,11);printf("%c",223);Sleep(tesp);
        
        gotoxy(27,14);printf("%c",223);Sleep(tesp);
        gotoxy(28,14);printf("%c",223);Sleep(tesp);
        gotoxy(29,14);printf("%c",223);Sleep(tesp);
        gotoxy(30,14);printf("%c",223);Sleep(tesp);
        gotoxy(31,14);printf("%c",223);Sleep(tesp);
    
        gotoxy(27,17);printf("%c",219);Sleep(tesp);
        gotoxy(28,17);printf("%c",219);Sleep(tesp);
        gotoxy(29,17);printf("%c",219);Sleep(tesp);
        gotoxy(30,17);printf("%c",219);Sleep(tesp);
        gotoxy(31,17);printf("%c",219);Sleep(tesp);
        Beep(800,300);
       
	   //R
    	gotoxy(33,11);printf("%c",219);Sleep(tesp);
        gotoxy(33,12);printf("%c",219);Sleep(tesp);
        gotoxy(33,13);printf("%c",219);Sleep(tesp);
        gotoxy(33,14);printf("%c",219);Sleep(tesp);
        gotoxy(33,15);printf("%c",219);Sleep(tesp);
        gotoxy(33,16);printf("%c",219);Sleep(tesp);
        gotoxy(33,17);printf("%c",219);Sleep(tesp);
        
        gotoxy(34,11);printf("%c",223);Sleep(tesp);
        gotoxy(35,11);printf("%c",223);Sleep(tesp);
        gotoxy(36,11);printf("%c",223);Sleep(tesp);
        gotoxy(37,11);printf("%c",223);Sleep(tesp);
        gotoxy(38,11);printf("%c",223);Sleep(tesp);
       	gotoxy(39,11);printf("%c",223);Sleep(tesp);
       
       
	    gotoxy(40,11);printf("%c",219);Sleep(tesp);
        gotoxy(40,12);printf("%c",219);Sleep(tesp);
        gotoxy(40,13);printf("%c",219);Sleep(tesp);
        
        gotoxy(34,14);printf("%c",223);Sleep(tesp);
        gotoxy(35,14);printf("%c",223);Sleep(tesp);
        gotoxy(36,14);printf("%c",223);Sleep(tesp);
        gotoxy(37,14);printf("%c",223);Sleep(tesp);
        gotoxy(38,14);printf("%c",223);Sleep(tesp);
       	gotoxy(39,14);printf("%c",223);Sleep(tesp);
        
		gotoxy(34,14);printf("%c",219);Sleep(tesp);
        gotoxy(35,15);printf("%c",219);Sleep(tesp);
    	gotoxy(36,16);printf("%c",219);Sleep(tesp);
        gotoxy(37,17);printf("%c",219);Sleep(tesp);
     	Beep(800,300);
	   
	//Z
		gotoxy(43,11);printf("%c",223);Sleep(tesp);
        gotoxy(44,11);printf("%c",223);Sleep(tesp);
        gotoxy(45,11);printf("%c",223);Sleep(tesp);
        gotoxy(46,11);printf("%c",223);Sleep(tesp);
        gotoxy(47,11);printf("%c",223);Sleep(tesp);
        gotoxy(48,11);printf("%c",223);Sleep(tesp);
        gotoxy(49,11);printf("%c",223);Sleep(tesp);
        
        gotoxy(44,17);printf("%c",219);Sleep(tesp);
        gotoxy(45,16);printf("%c",219);Sleep(tesp);
    	gotoxy(46,15);printf("%c",219);Sleep(tesp);
        gotoxy(47,14);printf("%c",219);Sleep(tesp);
        gotoxy(48,13);printf("%c",219);Sleep(tesp);
        gotoxy(49,12);printf("%c",219);Sleep(tesp);
        gotoxy(50,11);printf("%c",219);Sleep(tesp);
        
      
        gotoxy(44,17);printf("%c",219);Sleep(tesp);
        gotoxy(45,17);printf("%c",219);Sleep(tesp);
        gotoxy(46,17);printf("%c",219);Sleep(tesp);
        gotoxy(47,17);printf("%c",219);Sleep(tesp);
        gotoxy(48,17);printf("%c",219);Sleep(tesp);
        gotoxy(49,17);printf("%c",219);Sleep(tesp);
        gotoxy(50,17);printf("%c",219);Sleep(tesp);
	
	//A
	
		gotoxy(52,17);printf("%c",219);Sleep(tesp);
        gotoxy(53,16);printf("%c",219);Sleep(tesp);
    	gotoxy(54,15);printf("%c",219);Sleep(tesp);
        gotoxy(55,14);printf("%c",219);Sleep(tesp);
        gotoxy(56,13);printf("%c",219);Sleep(tesp);
        gotoxy(57,12);printf("%c",219);Sleep(tesp);
        gotoxy(58,11);printf("%c",219);Sleep(tesp);
        

       	gotoxy(56,14);printf("%c",223);Sleep(tesp);
       	gotoxy(57,14);printf("%c",223);Sleep(tesp);
       	gotoxy(58,14);printf("%c",223);Sleep(tesp);
       	gotoxy(59,14);printf("%c",223);Sleep(tesp);
       	gotoxy(60,14);printf("%c",223);Sleep(tesp);

    	gotoxy(58,11);printf("%c",219);Sleep(tesp);
        gotoxy(59,12);printf("%c",219);Sleep(tesp);
    	gotoxy(60,13);printf("%c",219);Sleep(tesp);
        gotoxy(61,14);printf("%c",219);Sleep(tesp);
        gotoxy(62,15);printf("%c",219);Sleep(tesp);
        gotoxy(63,16);printf("%c",219);Sleep(tesp);
        gotoxy(64,17);printf("%c",219);Sleep(tesp);    
       	Beep(800,300);
		   
		//S
		
        gotoxy(66,11);printf("%c",223);Sleep(tesp);
        gotoxy(67,11);printf("%c",223);Sleep(tesp);
        gotoxy(68,11);printf("%c",223);Sleep(tesp);
        gotoxy(69,11);printf("%c",223);Sleep(tesp);
       	gotoxy(70,11);printf("%c",223);Sleep(tesp);
       	gotoxy(71,11);printf("%c",223);Sleep(tesp);
       	gotoxy(72,11);printf("%c",223);Sleep(tesp);
       	gotoxy(73,11);printf("%c",223);Sleep(tesp);
	
		gotoxy(66,11);printf("%c",219);Sleep(tesp);
        gotoxy(66,12);printf("%c",219);Sleep(tesp);
        gotoxy(66,13);printf("%c",219);Sleep(tesp);
        
        gotoxy(66,14);printf("%c",223);Sleep(tesp);
        gotoxy(67,14);printf("%c",223);Sleep(tesp);
        gotoxy(68,14);printf("%c",223);Sleep(tesp);
        gotoxy(69,14);printf("%c",223);Sleep(tesp);
       	gotoxy(70,14);printf("%c",223);Sleep(tesp);
       	gotoxy(71,14);printf("%c",223);Sleep(tesp);
       	gotoxy(72,14);printf("%c",223);Sleep(tesp);
       	gotoxy(73,14);printf("%c",223);Sleep(tesp);
        
        gotoxy(73,14);printf("%c",219);Sleep(tesp);
        gotoxy(73,15);printf("%c",219);Sleep(tesp);
        gotoxy(73,16);printf("%c",219);Sleep(tesp);
        gotoxy(73,17);printf("%c",219);Sleep(tesp);
        
		gotoxy(66,17);printf("%c",219);Sleep(tesp);
        gotoxy(67,17);printf("%c",219);Sleep(tesp);
        gotoxy(68,17);printf("%c",219);Sleep(tesp);
        gotoxy(69,17);printf("%c",219);Sleep(tesp);
       	gotoxy(70,17);printf("%c",219);Sleep(tesp);
       	gotoxy(71,17);printf("%c",219);Sleep(tesp);
       	gotoxy(72,17);printf("%c",219);Sleep(tesp);
       	gotoxy(73,17);printf("%c",219);Sleep(tesp);
	 	Beep(800,300);
	 	
	 	
	 	//A
	
		gotoxy(80,17);printf("%c",219);Sleep(tesp);
        gotoxy(81,16);printf("%c",219);Sleep(tesp);
    	gotoxy(82,15);printf("%c",219);Sleep(tesp);
        gotoxy(83,14);printf("%c",219);Sleep(tesp);
        gotoxy(84,13);printf("%c",219);Sleep(tesp);
        gotoxy(85,12);printf("%c",219);Sleep(tesp);
        gotoxy(86,11);printf("%c",219);Sleep(tesp);
    

       	gotoxy(84,14);printf("%c",223);Sleep(tesp);
       	gotoxy(85,14);printf("%c",223);Sleep(tesp);
       	gotoxy(86,14);printf("%c",223);Sleep(tesp);
       	gotoxy(87,14);printf("%c",223);Sleep(tesp);
       	gotoxy(88,14);printf("%c",223);Sleep(tesp);

    	gotoxy(86,11);printf("%c",219);Sleep(tesp);
        gotoxy(87,12);printf("%c",219);Sleep(tesp);
    	gotoxy(88,13);printf("%c",219);Sleep(tesp);
        gotoxy(89,14);printf("%c",219);Sleep(tesp);
        gotoxy(90,15);printf("%c",219);Sleep(tesp);
        gotoxy(91,16);printf("%c",219);Sleep(tesp);
        gotoxy(92,17);printf("%c",219);Sleep(tesp);    
       	Beep(800,300);
       	
       	 //R
    	gotoxy(94,11);printf("%c",219);Sleep(tesp);
        gotoxy(94,12);printf("%c",219);Sleep(tesp);
        gotoxy(94,13);printf("%c",219);Sleep(tesp);
        gotoxy(94,14);printf("%c",219);Sleep(tesp);
        gotoxy(94,15);printf("%c",219);Sleep(tesp);
        gotoxy(94,16);printf("%c",219);Sleep(tesp);
        gotoxy(94,17);printf("%c",219);Sleep(tesp);
        
        gotoxy(95,11);printf("%c",223);Sleep(tesp);
        gotoxy(96,11);printf("%c",223);Sleep(tesp);
        gotoxy(97,11);printf("%c",223);Sleep(tesp);
        gotoxy(98,11);printf("%c",223);Sleep(tesp);
        gotoxy(99,11);printf("%c",223);Sleep(tesp);
       	gotoxy(100,11);printf("%c",223);Sleep(tesp);
       
       
	    gotoxy(101,11);printf("%c",219);Sleep(tesp);
        gotoxy(101,12);printf("%c",219);Sleep(tesp);
        gotoxy(101,13);printf("%c",219);Sleep(tesp);
        
        gotoxy(95,14);printf("%c",223);Sleep(tesp);
        gotoxy(96,14);printf("%c",223);Sleep(tesp);
        gotoxy(97,14);printf("%c",223);Sleep(tesp);
        gotoxy(98,14);printf("%c",223);Sleep(tesp);
        gotoxy(99,14);printf("%c",223);Sleep(tesp);
       	gotoxy(100,14);printf("%c",223);Sleep(tesp);
        
		gotoxy(95,14);printf("%c",219);Sleep(tesp);
        gotoxy(96,15);printf("%c",219);Sleep(tesp);
    	gotoxy(97,16);printf("%c",219);Sleep(tesp);
        gotoxy(98,17);printf("%c",219);Sleep(tesp);
     	Beep(800,300);
     	
     	//M
     	gotoxy(103,11);printf("%c",219);Sleep(tesp);
        gotoxy(103,12);printf("%c",219);Sleep(tesp);
        gotoxy(103,13);printf("%c",219);Sleep(tesp);
        gotoxy(103,14);printf("%c",219);Sleep(tesp);
        gotoxy(103,15);printf("%c",219);Sleep(tesp);
        gotoxy(103,16);printf("%c",219);Sleep(tesp);
        gotoxy(103,17);printf("%c",219);Sleep(tesp);
    
        
        gotoxy(104,11);printf("%c",219);Sleep(tesp);
        gotoxy(105,12);printf("%c",219);Sleep(tesp);
    	gotoxy(106,13);printf("%c",219);Sleep(tesp);
        gotoxy(107,14);printf("%c",219);Sleep(tesp);
        gotoxy(108,15);printf("%c",219);Sleep(tesp);
        gotoxy(109,16);printf("%c",219);Sleep(tesp);
        gotoxy(110,17);printf("%c",219);Sleep(tesp);
        
        gotoxy(111,17);printf("%c",219);Sleep(tesp);
        gotoxy(112,16);printf("%c",219);Sleep(tesp);
    	gotoxy(113,15);printf("%c",219);Sleep(tesp);
        gotoxy(114,14);printf("%c",219);Sleep(tesp);
        gotoxy(115,13);printf("%c",219);Sleep(tesp);
        gotoxy(116,12);printf("%c",219);Sleep(tesp);
        gotoxy(117,11);printf("%c",219);Sleep(tesp);
		
		gotoxy(118,11);printf("%c",219);Sleep(tesp);
        gotoxy(118,12);printf("%c",219);Sleep(tesp);
        gotoxy(118,13);printf("%c",219);Sleep(tesp);
        gotoxy(118,14);printf("%c",219);Sleep(tesp);
        gotoxy(118,15);printf("%c",219);Sleep(tesp);
        gotoxy(118,16);printf("%c",219);Sleep(tesp);
        gotoxy(118,17);printf("%c",219);Sleep(tesp);
       
    	    
       	Beep(800,300);
		
       		//A
	
		gotoxy(119,17);printf("%c",219);Sleep(tesp);
        gotoxy(120,16);printf("%c",219);Sleep(tesp);
    	gotoxy(121,15);printf("%c",219);Sleep(tesp);
        gotoxy(122,14);printf("%c",219);Sleep(tesp);
        gotoxy(123,13);printf("%c",219);Sleep(tesp);
        gotoxy(124,12);printf("%c",219);Sleep(tesp);
        gotoxy(125,11);printf("%c",219);Sleep(tesp);
    

       	gotoxy(123,14);printf("%c",223);Sleep(tesp);
       	gotoxy(124,14);printf("%c",223);Sleep(tesp);
       	gotoxy(125,14);printf("%c",223);Sleep(tesp);
       	gotoxy(126,14);printf("%c",223);Sleep(tesp);
       	gotoxy(127,14);printf("%c",223);Sleep(tesp);

    	gotoxy(125,11);printf("%c",219);Sleep(tesp);
        gotoxy(126,12);printf("%c",219);Sleep(tesp);
    	gotoxy(127,13);printf("%c",219);Sleep(tesp);
        gotoxy(128,14);printf("%c",219);Sleep(tesp);
        gotoxy(129,15);printf("%c",219);Sleep(tesp);
        gotoxy(130,16);printf("%c",219);Sleep(tesp);
        gotoxy(131,17);printf("%c",219);Sleep(tesp);    
       	Beep(800,300);
       	
		 //D
    	
    	gotoxy(133,11);printf("%c",219);Sleep(tesp);
        gotoxy(133,12);printf("%c",219);Sleep(tesp);
        gotoxy(133,13);printf("%c",219);Sleep(tesp);
        gotoxy(133,14);printf("%c",219);Sleep(tesp);
        gotoxy(133,15);printf("%c",219);Sleep(tesp);
        gotoxy(133,16);printf("%c",219);Sleep(tesp);
        gotoxy(133,17);printf("%c",219);Sleep(tesp);
  			 
  		gotoxy(134,11);printf("%c",223);Sleep(tesp);
        gotoxy(135,11);printf("%c",223);Sleep(tesp);
        gotoxy(136,11);printf("%c",223);Sleep(tesp);
        gotoxy(137,11);printf("%c",223);Sleep(tesp);
       	gotoxy(138,11);printf("%c",219);Sleep(tesp);
       	
		gotoxy(139,12);printf("%c",219);Sleep(tesp);
      	gotoxy(139,13);printf("%c",219);Sleep(tesp);
       	gotoxy(139,14);printf("%c",219);Sleep(tesp);
       	gotoxy(139,15);printf("%c",219);Sleep(tesp);

      	gotoxy(139,16);printf("%c",219);Sleep(tesp);
  		gotoxy(138,17);printf("%c",219);Sleep(tesp);
		
		
		gotoxy(134,17);printf("%c",219);Sleep(tesp);
        gotoxy(135,17);printf("%c",219);Sleep(tesp);
        gotoxy(136,17);printf("%c",219);Sleep(tesp);
        gotoxy(137,17);printf("%c",219);Sleep(tesp);
    	Beep(800,300);
	   
	    //A
	
		gotoxy(141,17);printf("%c",219);Sleep(tesp);
        gotoxy(142,16);printf("%c",219);Sleep(tesp);
    	gotoxy(143,15);printf("%c",219);Sleep(tesp);
        gotoxy(144,14);printf("%c",219);Sleep(tesp);
        gotoxy(145,13);printf("%c",219);Sleep(tesp);
        gotoxy(146,12);printf("%c",219);Sleep(tesp);
        gotoxy(147,11);printf("%c",219);Sleep(tesp);
    

       	gotoxy(145,14);printf("%c",223);Sleep(tesp);
       	gotoxy(146,14);printf("%c",223);Sleep(tesp);
       	gotoxy(147,14);printf("%c",223);Sleep(tesp);
       	gotoxy(148,14);printf("%c",223);Sleep(tesp);
       	gotoxy(149,14);printf("%c",223);Sleep(tesp);

    	gotoxy(147,11);printf("%c",219);Sleep(tesp);
        gotoxy(148,12);printf("%c",219);Sleep(tesp);
    	gotoxy(149,13);printf("%c",219);Sleep(tesp);
        gotoxy(150,14);printf("%c",219);Sleep(tesp);
        gotoxy(151,15);printf("%c",219);Sleep(tesp);
        gotoxy(152,16);printf("%c",219);Sleep(tesp);
        gotoxy(153,17);printf("%c",219);Sleep(tesp);    
       	Beep(800,300);
	   
		//S
        gotoxy(155,11);printf("%c",223);Sleep(tesp);
        gotoxy(156,11);printf("%c",223);Sleep(tesp);
        gotoxy(157,11);printf("%c",223);Sleep(tesp);
        gotoxy(158,11);printf("%c",223);Sleep(tesp);
       	gotoxy(159,11);printf("%c",223);Sleep(tesp);
       	gotoxy(160,11);printf("%c",223);Sleep(tesp);
       	gotoxy(161,11);printf("%c",223);Sleep(tesp);
       	gotoxy(155,11);printf("%c",223);Sleep(tesp);
	
		gotoxy(155,11);printf("%c",219);Sleep(tesp);
        gotoxy(155,12);printf("%c",219);Sleep(tesp);
        gotoxy(155,13);printf("%c",219);Sleep(tesp);
        
        gotoxy(155,14);printf("%c",223);Sleep(tesp);
        gotoxy(156,14);printf("%c",223);Sleep(tesp);
        gotoxy(157,14);printf("%c",223);Sleep(tesp);
        gotoxy(158,14);printf("%c",223);Sleep(tesp);
       	gotoxy(159,14);printf("%c",223);Sleep(tesp);
       	gotoxy(160,14);printf("%c",223);Sleep(tesp);
       	gotoxy(161,14);printf("%c",223);Sleep(tesp);
       	gotoxy(162,14);printf("%c",223);Sleep(tesp);
        
        gotoxy(162,14);printf("%c",219);Sleep(tesp);
        gotoxy(162,15);printf("%c",219);Sleep(tesp);
        gotoxy(162,16);printf("%c",219);Sleep(tesp);
        gotoxy(162,17);printf("%c",219);Sleep(tesp);
        
		gotoxy(155,17);printf("%c",219);Sleep(tesp);
        gotoxy(156,17);printf("%c",219);Sleep(tesp);
        gotoxy(157,17);printf("%c",219);Sleep(tesp);
        gotoxy(158,17);printf("%c",219);Sleep(tesp);
       	gotoxy(159,17);printf("%c",219);Sleep(tesp);
       	gotoxy(160,17);printf("%c",219);Sleep(tesp);
       	gotoxy(161,17);printf("%c",219);Sleep(tesp);
       	gotoxy(162,17);printf("%c",219);Sleep(tesp);
    	Beep(800,300);
    	
    	system("color 0A");
	   
	   	  //E
        gotoxy(65,21);printf("%c",219);Sleep(tesp);
        gotoxy(65,22);printf("%c",219);Sleep(tesp);
        gotoxy(65,23);printf("%c",219);Sleep(tesp);
        gotoxy(65,24);printf("%c",219);Sleep(tesp);
        gotoxy(65,25);printf("%c",219);Sleep(tesp);
        gotoxy(65,26);printf("%c",219);Sleep(tesp);
        gotoxy(65,27);printf("%c",219);Sleep(tesp);
        
        gotoxy(66,21);printf("%c",223);Sleep(tesp);
        gotoxy(67,21);printf("%c",223);Sleep(tesp);
        gotoxy(68,21);printf("%c",223);Sleep(tesp);
        gotoxy(69,21);printf("%c",223);Sleep(tesp);
        gotoxy(70,21);printf("%c",223);Sleep(tesp);
        
        gotoxy(66,24);printf("%c",223);Sleep(tesp);
        gotoxy(67,24);printf("%c",223);Sleep(tesp);
        gotoxy(68,24);printf("%c",223);Sleep(tesp);
        gotoxy(69,24);printf("%c",223);Sleep(tesp);
        gotoxy(70,24);printf("%c",223);Sleep(tesp);
    
        gotoxy(66,27);printf("%c",219);Sleep(tesp);
        gotoxy(67,27);printf("%c",219);Sleep(tesp);
        gotoxy(68,27);printf("%c",219);Sleep(tesp);
        gotoxy(69,27);printf("%c",219);Sleep(tesp);
        gotoxy(70,27);printf("%c",219);Sleep(tesp);
        Beep(800,300);
	   
	   	//S
	   	gotoxy(75,21);printf("%c",223);Sleep(tesp);
        gotoxy(76,21);printf("%c",223);Sleep(tesp);
        gotoxy(77,21);printf("%c",223);Sleep(tesp);
        gotoxy(78,21);printf("%c",223);Sleep(tesp);
       	gotoxy(79,21);printf("%c",223);Sleep(tesp);
       	gotoxy(80,21);printf("%c",223);Sleep(tesp);
       	gotoxy(81,21);printf("%c",223);Sleep(tesp);
       	
	
		gotoxy(75,21);printf("%c",219);Sleep(tesp);
        gotoxy(75,22);printf("%c",219);Sleep(tesp);
        gotoxy(75,23);printf("%c",219);Sleep(tesp);
        
        gotoxy(75,24);printf("%c",223);Sleep(tesp);
        gotoxy(76,24);printf("%c",223);Sleep(tesp);
        gotoxy(77,24);printf("%c",223);Sleep(tesp);
        gotoxy(78,24);printf("%c",223);Sleep(tesp);
       	gotoxy(79,24);printf("%c",223);Sleep(tesp);
       	gotoxy(80,24);printf("%c",223);Sleep(tesp);
       	gotoxy(81,24);printf("%c",223);Sleep(tesp);
       	gotoxy(82,24);printf("%c",223);Sleep(tesp);
        
        gotoxy(82,24);printf("%c",219);Sleep(tesp);
        gotoxy(82,25);printf("%c",219);Sleep(tesp);
        gotoxy(82,26);printf("%c",219);Sleep(tesp);
        gotoxy(82,27);printf("%c",219);Sleep(tesp);
        
		gotoxy(75,27);printf("%c",219);Sleep(tesp);
        gotoxy(76,27);printf("%c",219);Sleep(tesp);
        gotoxy(77,27);printf("%c",219);Sleep(tesp);
        gotoxy(78,27);printf("%c",219);Sleep(tesp);
       	gotoxy(79,27);printf("%c",219);Sleep(tesp);
       	gotoxy(80,27);printf("%c",219);Sleep(tesp);
       	gotoxy(81,27);printf("%c",219);Sleep(tesp);
       	gotoxy(82,27);printf("%c",219);Sleep(tesp);
    	Beep(800,300);
    	
        //P
       
        gotoxy(84,21);printf("%c",219);Sleep(tesp);
        gotoxy(84,22);printf("%c",219);Sleep(tesp);
        gotoxy(84,23);printf("%c",219);Sleep(tesp);
        gotoxy(84,24);printf("%c",219);Sleep(tesp);
        gotoxy(84,25);printf("%c",219);Sleep(tesp);
        gotoxy(84,26);printf("%c",219);Sleep(tesp);
        gotoxy(84,27);printf("%c",219);Sleep(tesp);
 

        gotoxy(85,21);printf("%c",223);Sleep(tesp);
        gotoxy(86,21);printf("%c",223);Sleep(tesp);
        gotoxy(87,21);printf("%c",223);Sleep(tesp);
        gotoxy(88,21);printf("%c",223);Sleep(tesp);
        gotoxy(89,21);printf("%c",223);Sleep(tesp);
        gotoxy(90,21);printf("%c",223);Sleep(tesp);
        

        gotoxy(90,21);printf("%c",219);Sleep(tesp);
        gotoxy(90,22);printf("%c",219);Sleep(tesp);
        gotoxy(90,23);printf("%c",219);Sleep(tesp);
        gotoxy(90,24);printf("%c",219);Sleep(tesp);

		gotoxy(90,25);printf("%c",223);Sleep(tesp);
		gotoxy(89,25);printf("%c",223);Sleep(tesp);
        gotoxy(88,25);printf("%c",223);Sleep(tesp);
        gotoxy(87,25);printf("%c",223);Sleep(tesp);
        gotoxy(86,25);printf("%c",223);Sleep(tesp);
        gotoxy(85,25);printf("%c",223);Sleep(tesp);
        
    Beep(800,300);
		
		
		  	  //E
        gotoxy(95,21);printf("%c",219);Sleep(tesp);
        gotoxy(95,22);printf("%c",219);Sleep(tesp);
        gotoxy(95,23);printf("%c",219);Sleep(tesp);
        gotoxy(95,24);printf("%c",219);Sleep(tesp);
        gotoxy(95,25);printf("%c",219);Sleep(tesp);
        gotoxy(95,26);printf("%c",219);Sleep(tesp);
        gotoxy(95,27);printf("%c",219);Sleep(tesp);
    
        gotoxy(96,21);printf("%c",223);Sleep(tesp);
        gotoxy(97,21);printf("%c",223);Sleep(tesp);
        gotoxy(98,21);printf("%c",223);Sleep(tesp);
        gotoxy(99,21);printf("%c",223);Sleep(tesp);
        gotoxy(100,21);printf("%c",223);Sleep(tesp);
        
        gotoxy(96,24);printf("%c",223);Sleep(tesp);
        gotoxy(97,24);printf("%c",223);Sleep(tesp);
        gotoxy(98,24);printf("%c",223);Sleep(tesp);
        gotoxy(99,24);printf("%c",223);Sleep(tesp);
        gotoxy(100,24);printf("%c",223);Sleep(tesp);
    
        gotoxy(96,27);printf("%c",219);Sleep(tesp);
        gotoxy(97,27);printf("%c",219);Sleep(tesp);
        gotoxy(98,27);printf("%c",219);Sleep(tesp);
        gotoxy(99,27);printf("%c",219);Sleep(tesp);
        gotoxy(100,27);printf("%c",219);Sleep(tesp);
        Beep(800,300);



    gotoxy(70,32);

    printf("\t\tLOADING PLEASE WAIT...\n");
    for(int i=0;i<150;i++)
    {
        gotoxy(i,30);
        printf("%c",219);
        for(int x=50;x<90;x++)
        {
            for(int y=1;y<20;y++)
            {
                gotoxy(y+180,34);
            }
        }
    }
    Beep(262,150);
    Beep(262,150);
    Beep(262,150);
    
    printf("\n\n");
    Sleep(700);
    //system("pause");
    system("cls");
    Beep(330,200);
}

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


/*Declaracion de Funciones*/
/*
//Menu Principal del Sistema
void menuPrincipal(){
//	Mes mes=NULL;
//	Cliente clientes=NULL;
	int opc=0;
	const char *opciones[]={"Reservacion","Backups","Consulta","Ayuda","Codigo QR","Logo Espe","Salir del programa"};
	do{
		opc=menu("Menu Principal",opciones,7);
		color(16);
		switch(opc){
			case 1:
			Hotel();
			fflush(stdin);
				
			break;
			case 2:
			
				
			break;
			case 3:
			
			break;
			case 4:
			
			break;
			case 6:
				
			
			break;
	
			case 7:
			gotoxy(7,15);
			printf("		Gracias por Confiar en nosotros Vuelva Pronto!!!		Que Tenga un Excelente dia! ");
		
			break;
	}
	}while(opc!=7);
}*/
