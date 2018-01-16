#include "PersonalLibrary.h"
#include "Pila.h"

int main(int argc, char** argv) {
	int opcion,opcionTraductor;
	bool flag=true,flagTraslate=true;
	char palabra[25];
	char *opciones[]={"1) Traductor / Traslater.","2) Imagen.","3) Consulta PDF.","4) Codigo QR.","5) Ayuda o PULSE \"F1\".","6) Backup.","7) Base de Datos (Mongo).","8) Salir / Exit."};
	char *opcionesTraductor[]={"1) Traducir.","2) Insertar palabra al diccionario.","3) Eliminar palabra del diccionario.","4) Volver al Menu Principal"};
	Pila *objPalabra=new Pila();
		
	AltEnter();
	ShellExecute(NULL, TEXT("open"),TEXT("Extras\\WinAppMSAgentsManagementBienvenida.exe"),NULL, NULL,SW_SHOWNORMAL);
	do
	{
		objPalabra->generarPila();
		opcion=menu("Menu Principal",opciones,8);
		system("cls");
		switch(opcion)
		{
			case 1:
				do
				{
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
				break;
			case 2:
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
				
				break;
			case 7:
				
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
