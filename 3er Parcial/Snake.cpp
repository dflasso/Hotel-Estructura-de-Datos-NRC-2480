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

int main(int argc, char** argv) {
	bool flag=true,flagGame=true;
	int opcion,opcionJuego;
	char *opciones[]={"1) Juego Snake.","2) Imagen.","3) Consulta PDF.","4) Codigo QR.","5) Ayuda o PULSE \"F1\".","6) Backup.","7) Base de Datos (Mongo).","8) Salir / Exit."};
	char *opcionesJuego[]={"1) Comenzar juego.","2) Ver su ultimo puntaje.","3) Volver al Menu Principal."}; //poner lista de puntajes
	ListaDoble *ObjJuego=new ListaDoble;
	
	AltEnter();
	CreateDirectory ("C:\\JuegoSnake", NULL);
	ShellExecute(NULL, TEXT("open"),TEXT("C:\\data\\DB\\mongod.exe"),NULL, NULL,SW_SHOWNORMAL);
	
	do
	{
		flag=true;
		opcion=menu("Menu Principal",opciones,8);
		system("cls");
		switch(opcion)
		{
			case 1:
				ShellExecute(NULL, TEXT("open"),TEXT("Extras\\WinAppMSAgentsManagementBienvenida.exe"),NULL, NULL,SW_SHOWNORMAL);
				do
				{
					flagGame=true;
					opcionJuego=menu("Juego del Snake",opcionesJuego,3);
					system("cls");
					switch(opcionJuego)
					{
						case 1:
							ObjJuego->juego();
							ShellExecute(NULL, TEXT("open"),TEXT("Extras\\WinAppMSAgentsManagementQR.exe"),NULL, NULL,SW_SHOWNORMAL);
							system("start Extras\\CreateCodigoQR.jar");
							system("start Extras\\DBMongoInsert.jar");
							break;
						case 2:
							ObjJuego->impresion();
							break;
						case 3:
							flagGame=false;
							break;
					}
					if(opcionJuego!=3)
 					{
 						printf("Presione cualquier tecla para volver al menu . . .");
 						getch();
 					}
				}while(flagGame);
				break;
			case 2:
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
				//backup
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

}
