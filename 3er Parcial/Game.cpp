/*						^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
						^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
						^^  *******************************************************************   ^^
						^^  **                                                               **   ^^
						^^  **          *******      ******       *******       *******      **   ^^
						^^  **         **           **           **     **     **            **   ^^
						^^  **         **           **           **     **     **            **   ^^
						^^  **         *******       *****       ********      ********      **   ^^
						^^  **         **                **      **            **            **   ^^
						^^  **         **                **      **            **            **   ^^
						^^  **          *******     ******       **             *******      **   ^^
						^^  **                                                               **   ^^
						^^  *******************************************************************   ^^
						^^                                                                        ^^
						^^              DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION                ^^
						^^              ------------------------------------------                ^^
						^^                                                                        ^^
						^^              INGENIERIA  EN  SISTEMAS  E  INFORMATICA                  ^^
						^^              ----------------------------------------                  ^^
						^^                                                                        ^^
						^^                           ESTRUCTURA DE DATOS                          ^^
						^^                          ---------------------                         ^^
						^^                                                                        ^^
						^^                       PROYECTO DE INVESTIGACION                        ^^
						^^                      -------------------------                         ^^
						^^     Integrantes:                                                       ^^
						^^     ------------                                                       ^^
						^^     => BORJA DIEGO		                                              ^^
						^^     => LASSO DANNY		                                              ^^
						^^     => RODRIGUEZ BRYAN                                                 ^^
						^^             						                  					  ^^
						^^	DOCENTE: ING. FERNANDO SOLIS	                                      ^^
						^^	FECHA DE PRESENTACION: 2018/02/16		                              ^^
						^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
						^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
								
#include "PersonalLibrary.h"
#include "ListaDoble.h"
/**
* Explica como funciona el programa y como se
* se juega
*/
void introGame(){
	system("cls");
	color(10);
	printf("\n\t\t\t\t--------------------------------------------------");
	printf("\n\t\t\t\t||EN ESTE JUEGO USTED MANEJA EL NUMERO SUPERIOR  ||");
	printf("\n\t\t\t\t||DEBE DIRIGIR A UN IGUAL NUMERO QUE SE ENCUENTRE||");
	printf("\n\t\t\t\t||EN LA PARTE INFERIOR...                        ||");
	printf("\n\t\t\t\t||                                               ||");
	printf("\n\t\t\t\t||EN CASO DE CAER EN UNO   DIFERENTE SE AGREGARA ||");
	printf("\n\t\t\t\t||A LA LISTA                                     ||");
	printf("\n\t\t\t\t||SI EL NUMERO CAE EN UNO IGUAL SE BORRA EL      ||");
	printf("\n\t\t\t\t||EL NUMERO, SI EL SIGUIENTE NUMERO DE  LA LISTA ||");
	printf("\n\t\t\t\t||ES SU IMEDIATO SUPERIOR, TAMBIEN SE BORRA...   ||");
	printf("\n\t\t\t\t||                                               ||");
	color(11);
	printf("\n\t\t\t\t||PARA SALIR DEL JUEGO PRESIONA <enter>          ||");
	printf("\n\t\t\t\t||PARA GUARDAR TU PARTIDA PRESIONA <s>           ||");
	printf("\n\t\t\t\t||                                               ||");
	printf("\n\t\t\t\t||PARA MOVER EL NUMERO UTILZA LAS TECLAS         ||");
	printf("\n\t\t\t\t||DE DIRECCION                                   ||");
	printf("\n\t\t\t\t||                                               ||");
	color(10);
	printf("\n\t\t\t\t|| BUENA SUERTE!!!                               ||");
	printf("\n\t\t\t\t--------------------------------------------------");
	printf("\n\n\t\t\t\tCARGANDO...\n\n\t\t\t\t");
	
	for(int i=0;i<50;i++){
		Sleep(125);
		printf("%c",175);
	}
}


int main(int argc, char** argv) {
	bool flag=true,flagGame=true;// variables boleanas para volvel al menu
	int opcion,opcionJuego; // las opciones escogidas por el usuario
	//arreglo de opciones menu principal
	const char *opciones[]={"1) Juego.","2) Imagen.","3) Consulta PDF.","4) Codigo QR.","5) Ayuda o PULSE \"F1\".","6) Backup.","7) Base de Datos (Mongo).","8) Salir / Exit."};
	//arreglo de opciones del juego 
	const char *opcionesJuego[]={"1) Comenzar juego.","2) Comenzar con el juego guardado.","3) Ver su ultimo puntaje.","4) Volver al Menu Principal."}; //poner lista de puntajes
	//Clase que contiene los metodo del juego
	ListaDoble *ObjJuego=new ListaDoble;
	
	AltEnter(); // funcion que agranda la pantalla 
	CreateDirectory ("C:\\JuegoSnake", NULL); // crea la carpeta JuegoSnake
	
	ShellExecute(NULL, TEXT("open"),TEXT("C:\\data\\DB\\mongod.exe"),NULL, NULL,SW_SHOWNORMAL); //ejecuta la base de datos mongo
	
	do
	{
		flag=true;
		opcion=menu("Menu Principal",opciones,8); //despliega el menu principal
		system("cls"); // borra la pantalla 
		switch(opcion)
		{
			case 1:
				//ejecuta el agente
				ShellExecute(NULL, TEXT("open"),TEXT("Extras\\WinAppMSAgentsManagementBienvenida.exe"),NULL, NULL,SW_SHOWNORMAL);
				do
				{
					flagGame=true;
					opcionJuego=menu("Juego",opcionesJuego,4); // imprime menu del juego, retorna la opcion escogida
					system("cls");
					switch(opcionJuego)
					{
						case 1:
							introGame(); // imprime reglas y funcionalidad del juego
							color(15); 
							printf("\n\n\t\t\t\t");
							ObjJuego->juegoTetris(0); // metodo que comienza el juego
							ShellExecute(NULL, TEXT("open"),TEXT("Extras\\WinAppMSAgentsManagementQR.exe"),NULL, NULL,SW_SHOWNORMAL); //ejecuta el agente
							system("start Extras\\CreateCodigoQR.jar"); // crea el codigo QR del juego terminado (puntaje)
							system("start Extras\\DBMongoInsert.jar"); // inserta el puntaje en la base de datos mongo
							break;
							
						case 2:
							introGame();
							color(15);
							printf("\n\n\t\t\t\t");
							// al enviar como parametro (1) se recupera el ultimo juego
							ObjJuego->juegoTetris(1); // utilizando el backup recupera la informacion del ultimo juego
							break;
							
						case 3:
							ObjJuego->impresion(); // imprime puntaje y numeros no eliminados
							break;
							
						case 4:
							flagGame=false; // bandera para salir al menu principal
							break;
					}
					if(opcionJuego!=4)
					{
 						printf("Presione cualquier tecla para volver al menu . . .");
 						getch();
					}
				}while(flagGame);
				break;
			case 2:
				//ejecuta una imagen 
				ShellExecute(NULL, TEXT("open"),TEXT("Extras\\WinAppMSAgentsManagementImage.exe"),NULL, NULL,SW_SHOWNORMAL);
				ShellExecute(NULL, TEXT("open"),TEXT("Extras\\image.exe"),NULL, NULL,SW_SHOWNORMAL);
				break;
			case 3:
				ShellExecute(NULL, TEXT("open"),TEXT("Extras\\WinAppMSAgentsManagementPDF.exe"),NULL, NULL,SW_SHOWNORMAL);
				system("start Extras\\CreatePDF.jar");
				break;
			case 4:
				ShellExecute(NULL, TEXT("open"),TEXT("Extras\\WinAppMSAgentsManagementQR.exe"),NULL, NULL,SW_SHOWNORMAL);
				system("start Extras\\CreateCodigoQR.jar");
				break;
			case 5:
				ShellExecute(NULL, TEXT("open"),TEXT("Extras\\Ayuda.chm"),NULL, NULL,SW_SHOWNORMAL);		
				break;
			case 6:
				ShellExecute(NULL, TEXT("open"),TEXT("Extras\\WinAppMSAgentsManagementBackup.exe"),NULL, NULL,SW_SHOWNORMAL);
				//ObjJuego->(nombre,2);
				//ObjJuego->crearBackup(nombre,1);
				printf("Presione cualquier tecla para volver al menu principal. . .");
				break;
			case 7:
				ShellExecute(NULL, TEXT("open"),TEXT("Extras\\WinAppMSAgentsManagementDBMongo.exe"),NULL, NULL,SW_SHOWNORMAL);
				system("start Extras\\MongoTXT.Tabla.jar");
				printf("\t\t\tBase de Datos \"Puntajes Snake\"\n\n");
				imprimirTXT("C:\\JuegoSnake\\DBConsole.txt");
				printf("Presione cualquier tecla para volver al menu principal. . .");
				getch();
				break;
			case 8:
				ShellExecute(NULL, TEXT("open"),TEXT("Extras\\WinAppMSAgentsManagementExit.exe"),NULL, NULL,SW_SHOWNORMAL);
				color(13);
				printf("\t\t%c%c Gracias por utilizar el Programa %c%c\n\n",245,245,245,245);
				color(15);
				flag=false;
				break;
		}
	}while(flag);
	delete(ObjJuego);
}
