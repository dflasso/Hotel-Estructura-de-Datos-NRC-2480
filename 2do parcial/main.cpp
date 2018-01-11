#include "PersonalLibrary.h"
#include "Nodo.h"

int main(int argc, char** argv) {
	Pila *objPalabra=new Pila();
	objPalabra->generarPila();
	
	int opcion;
	bool flag=true;
	char *opciones[]={"1) Traductor / Traslater.","2) Imagen.","3) Consulta PDF.","4) Codigo QR.","5) Ayuda o PULSE \"F1\".","6) Backup.","7) Base de Datos (Mongo).","8) Salir / Exit."};
	
	AltEnter();
	do
	{
		opcion=menu("Menu Principal",opciones,8);
		system("cls");
		switch(opcion)
		{
			case 1:
				break;
			case 2:
				ShellExecute(NULL, TEXT("open"),TEXT("Extras\\image.exe"),NULL, NULL,SW_SHOWNORMAL);
				break;
			case 3:
				system("start Extras\\CreatePDF.jar");
				break;
			case 4:
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
				printf("Gracias por utilizar el sistema.\n\n\n");
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
