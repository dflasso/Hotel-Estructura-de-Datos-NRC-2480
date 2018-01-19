#include "PersonalLibrary.h"
#include "Pila.h"

void menuMouse(){
	int opcion,opcionTraductor,opcBack;
	bool flag=true,flagTraslate=true;
	char palabra[25],palabraSpa[25],palabraEng[25];
	char *opciones[]={"1) Traductor / Traslater.","2) Imagen.","3) Consulta PDF.","4) Codigo QR.","5) Ayuda o PULSE \"F1\".","6) Backup.","7) Base de Datos (Mongo).","8) Salir / Exit."};
	char *opcionesTraductor[]={"1) Traducir.","2) Insertar palabra al diccionario.","3) Imprimir palabras buscadas.","4) Volver al Menu Principal."};
	char *opcionesBackup[]={"1) Crear Backup.","2) Recuperar informacion.","3) Volver al Menu Principal."};
	Pila *objPalabra=new Pila();
	Pila *palabrasBuscadas=new Pila();
	char nombre[2000];

	AltEnter();
	CreateDirectory ("D:\\Traductor", NULL);
	system("copy palabrasDiccionario.txt D:\\Traductor\\palabrasDiccionario.txt");
	system("cls");
	ShellExecute(NULL, TEXT("open"),TEXT("C:\\data\\DB\\mongod.exe"),NULL, NULL,SW_SHOWNORMAL);
	ShellExecute(NULL, TEXT("open"),TEXT("Extras\\WinAppMSAgentsManagementBienvenida.exe"),NULL, NULL,SW_SHOWNORMAL);
	objPalabra->generarPila();
	
	gotoxy(10,2);
		color(158);
		printf("================================================");
		color(11);
		printf("\n\t\t\tMenu Principal\t\t\t\n\n");
		//letras en amarillo
		color(15); //letras en blanco
		printf("\t\t1)Traductor / Translater.\n");
		printf("\t\t2)Imagen.\n");
		printf("\t\t3)Consulta PDF.\n");
		printf("\t\t4)Codigo QR.\n");
		printf("\t\t5)Ayuda o PULSE 'F1'\n");
		printf("\t\t6)Backup.\n");
		printf("\t\t7)Base de Datos (Mongo).\n");
		printf("\t\t8)Salir / Exit.\n");
		color(158);
		gotoxy(10,15);
		printf("================================================");
		color(15);
	
	HANDLE paraEntrada = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD regEntrada;
	DWORD evento;
	COORD coordenadas;
	SetConsoleMode(paraEntrada, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
	while (1) {
		ReadConsoleInput(paraEntrada, &regEntrada, 1, &evento);
		if (regEntrada.EventType == MOUSE_EVENT)
		{
			if (regEntrada.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				coordenadas.X = regEntrada.Event.MouseEvent.dwMousePosition.X;
				coordenadas.Y = regEntrada.Event.MouseEvent.dwMousePosition.Y;
				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 5)
				{
					system("cls");
					do
				{
					opcionTraductor=menu("Traductor / Traslater.",opcionesTraductor,4);
	//				system("cls");
					switch(opcionTraductor)
					{
						case 1:
							do
							{
								printf("Ingrese la palabra que desea traducir: ");
								fflush(stdin);
								gets(palabra);
								objPalabra->buscar(palabra);
							}while(validacionCaracter(palabra));
								
							break;
						case 4:
							flagTraslate=false;
							break;
					}
					if(opcionTraductor!=4)
					{
						printf("Presione cualquier tecla para volver al menu . . .");
						getch();
					}
				}while(flagTraslate);
					system("pause");
					system("cls");
					menuMouse();
					
				}

				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 6)
				{
				    system("cls");
					ShellExecute(NULL, TEXT("open"),TEXT("Extras\\image.exe"),NULL, NULL,SW_SHOWNORMAL);
					system("pause");
					system("cls");
					menuMouse();

				}
				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 7)//(coordenadas.X >0 && coordenadas.X <= 9 && coordenadas.Y == 3)
				{
					system("cls");
					ShellExecute(NULL, TEXT("open"),TEXT("Extras\\WinAppMSAgentsManagementPDF.exe"),NULL, NULL,SW_SHOWNORMAL);
					system("start Extras\\CreatePDF.jar");
					system("pause");
					system("cls");
					menuMouse();
				}

				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 8)
				{
					system("cls");
					ShellExecute(NULL, TEXT("open"),TEXT("Extras\\WinAppMSAgentsManagementQR.exe"),NULL, NULL,SW_SHOWNORMAL);
					system("start Extras\\CreateCodigoQR.jar");	 //cada que ingrese una palabra generar el qr
					system("pause");
					system("cls");
					menuMouse();
				}

				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 9)
				{
					system("cls");
					ShellExecute(NULL, TEXT("open"),TEXT("Extras\\Ayuda-Hotel.chm"),NULL, NULL,SW_SHOWNORMAL);	
					system("pause");
					system("cls");
				    menuMouse();
					
				}
				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 10)
				{
				     system("cls");
					int opcBack=1;
				do{
					opcBack=menu("RESPALDO DE INFORMACION",opcionesBackup,3);
					switch(opcBack){
						case 1:
							palabrasBuscadas->crearBackup(nombre,1);
							palabrasBuscadas->crearBackup(nombre,2);
							ShellExecute(NULL, TEXT("open"),TEXT("Extras\\WinAppMSAgentsManagementBackup.exe"),NULL, NULL,SW_SHOWNORMAL);
							break;
						case 2:
							palabrasBuscadas->generarPila(0);
							break;
					}
				}while(opcBack!=3);
				
					system("pause");
					system("cls");
					menuMouse();
				}
				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 11)
				{
				     system("cls");
					ShellExecute(NULL, TEXT("open"),TEXT("Extras\\WinAppMSAgentsManagementBDMongo.exe"),NULL, NULL,SW_SHOWNORMAL);
					system("start Extras\\MongoTXT.Tabla.jar");
					imprimirTXT("D:\\Traductor\\BDConsole.txt");
					//system("start C:\\Users\\RAMIRO BORJA F\\AppData\\Local\\MongoDBCompass.exe");
					//ShellExecute(NULL, TEXT("open"),TEXT("C:\\Users\\RAMIRO BORJA F\\AppData\\Local\\MongoDBCompass.exe"),NULL, NULL,SW_SHOWNORMAL); tratar de sacar el GUI
					system("pause");
					system("cls");
					menuMouse();
				}
				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 12)
				{
				    system("cls");
					printf("Gracias por utilizar el traductor.\n\n\n");
					ShellExecute(NULL, TEXT("open"),TEXT("Extras\\WinAppMSAgentsManagementExit.exe"),NULL, NULL,SW_SHOWNORMAL);
					flag=false;
					system("pause");
					system("cls");
					exit(0);
				}
		
			}
		}
	}
}

void cursor(){
	int opcion,opcionTraductor,opcBack;
	bool flag=true,flagTraslate=true;
	char palabra[25],palabraSpa[25],palabraEng[25];
	char *opciones[]={"1) Traductor / Traslater.","2) Imagen.","3) Consulta PDF.","4) Codigo QR.","5) Ayuda o PULSE \"F1\".","6) Backup.","7) Base de Datos (Mongo).","8) Salir / Exit."};
	char *opcionesTraductor[]={"1) Traducir.","2) Insertar palabra al diccionario.","3) Imprimir palabras buscadas.","4) Volver al Menu Principal."};
	char *opcionesBackup[]={"1) Crear Backup.","2) Recuperar informacion.","3) Volver al Menu Principal."};
	Pila *objPalabra=new Pila();
	Pila *palabrasBuscadas=new Pila();
	char nombre[2000];
		
	AltEnter();
	CreateDirectory ("D:\\Traductor", NULL);
	system("copy palabrasDiccionario.txt D:\\Traductor\\palabrasDiccionario.txt");
	system("cls");
	ShellExecute(NULL, TEXT("open"),TEXT("C:\\data\\DB\\mongod.exe"),NULL, NULL,SW_SHOWNORMAL);
	ShellExecute(NULL, TEXT("open"),TEXT("Extras\\WinAppMSAgentsManagementBienvenida.exe"),NULL, NULL,SW_SHOWNORMAL);
	objPalabra->generarPila();
	do
	{
		flag=true;
		opcion=menu("Menu Principal",opciones,8);
		system("cls");
		switch(opcion)
		{
			case 1:
				do
				{
					flagTraslate=true;
					opcionTraductor=menu("Traductor / Traslater",opcionesTraductor,4);
					system("cls");
					switch(opcionTraductor)
					{
						case 1:
							do
							{
								printf("Ingrese la palabra que desea traducir: ");
								fflush(stdin);
								gets(palabra);
								objPalabra->buscar(palabra);
								objPalabra->buscar(palabra,palabrasBuscadas);
							}while(validacionCaracter(palabra));
							break;
						case 2:
							do
							{
								printf("Ingrese la palabra en espa%col que desea agregar al diccionario: ",164);
								fflush(stdin);
								gets(palabraSpa);
							}while(validacionCaracter(palabraSpa));
							do
							{
								printf("Ingrese la palabra en ingles que desea agregar al diccionario: ",164);
								fflush(stdin);
								gets(palabraEng);
							}while(validacionCaracter(palabraEng));
							objPalabra->pushNew(palabraSpa,palabraEng);
							break;
						case 3:
							palabrasBuscadas->imprimir();
							break;
						case 4:
							flagTraslate=false;
							break;
					}
					if(opcionTraductor!=4)
					{
						printf("Presione cualquier tecla para volver al menu . . .");
						getch();
					}
				}while(flagTraslate);
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
				system("start Extras\\CreateCodigoQR.jar");	 //cada que ingrese una palabra generar el qr
				break;
			case 5:
				ShellExecute(NULL, TEXT("open"),TEXT("Extras\\Ayuda-Hotel.chm"),NULL, NULL,SW_SHOWNORMAL);		
				break;
			case 6:
				opcBack=1;
				do{
					opcBack=menu("RESPALDO DE INFORMACION",opcionesBackup,3);
					switch(opcBack){
						case 1:
							palabrasBuscadas->crearBackup(nombre,1);
							palabrasBuscadas->crearBackup(nombre,2);
							ShellExecute(NULL, TEXT("open"),TEXT("Extras\\WinAppMSAgentsManagementBackup.exe"),NULL, NULL,SW_SHOWNORMAL);
							break;
						case 2:
							palabrasBuscadas->generarPila(0);
							break;
					}
				}while(opcBack!=3);
				
				
				break;
			case 7:
				ShellExecute(NULL, TEXT("open"),TEXT("Extras\\WinAppMSAgentsManagementBDMongo.exe"),NULL, NULL,SW_SHOWNORMAL);
				system("start Extras\\MongoTXT.Tabla.jar");
				imprimirTXT("D:\\Traductor\\BDConsole.txt");
				//system("start C:\\Users\\RAMIRO BORJA F\\AppData\\Local\\MongoDBCompass.exe");
				//ShellExecute(NULL, TEXT("open"),TEXT("C:\\Users\\RAMIRO BORJA F\\AppData\\Local\\MongoDBCompass.exe"),NULL, NULL,SW_SHOWNORMAL); tratar de sacar el GUI
				getch();
				break;
			case 8:
				printf("Gracias por utilizar el traductor.\n\n\n");
				ShellExecute(NULL, TEXT("open"),TEXT("Extras\\WinAppMSAgentsManagementExit.exe"),NULL, NULL,SW_SHOWNORMAL);
				flag=false;
				break;
		}
		if(opcion==1)
		{
			printf("Presione cualquier tecla para volver al menu principal. . .");
			getch();
		}
	}while(flag);
}

int main(int argc, char** argv) {

	menuMouse();
	return 0;
}
