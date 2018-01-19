#include "PersonalLibrary.h"
#include "Pila.h"

int main(int argc, char** argv) {
	int opcion,opcionTraductor,opcBack;
	bool flag=true,flagTraslate=true;
	char palabra[25],palabraSpa[25],palabraEng[25];
	char *opciones[]={"1) Traductor / Traslater.","2) Imagen.","3) Consulta PDF.","4) Codigo QR.","5) Ayuda o PULSE \"F1\".","6) Backup.","7) Base de Datos (Mongo).","8) Salir / Exit."};
	char *opcionesTraductor[]={"1) Traducir.","2) Insertar palabra al diccionario.","3) Eliminar palabra del diccionario.","4) Volver al Menu Principal."};
	char *opcionesBackup[]={"1) Crear Backup.","2) Recuperar informacion.","3) Volver al Menu Principal."};
	Pila *objPalabra=new Pila();
	Pila *palabrasBuscadas=new Pila();
	char nombre[2000];
	
	
	AltEnter();
	CreateDirectory ("D:\\Traductor", NULL);
	system("copy palabrasDiccionario.txt D:\\Traductor\\palabrasDiccionario.txt");
	system("cls");
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
							/*do
							{
								printf("Ingrese la palabra que desea eliminar: ");
								fflush(stdin);
								gets(palabra);
								objPalabra->popPalabra(palabra); corregir el eliminar
							}while(validacionCaracter(palabra));
							break;*/
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
							
							break;
					}
				}while(opcBack!=3);
				
				
				break;
			case 7:
				ShellExecute(NULL, TEXT("open"),TEXT("Extras\\WinAppMSAgentsManagementBDMongo.exe"),NULL, NULL,SW_SHOWNORMAL);
				objPalabra->imprimir();
				system("pause");				
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
	return 0;
}
