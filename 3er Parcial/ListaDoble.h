#include "Nodo.h"

class ListaDoble
{
	private:
		Nodo *lista;
		char jugador[25];
		int contadorNodo;

	public:
		ListaDoble()
		{
			lista=NULL;
			contadorNodo=0;
		}
		void insertarAlFinal(int);
		void impresionArchivos();
		void impresion();
		void juego();
		
};

void ListaDoble::impresionArchivos()
{
	Nodo* Aux=new Nodo();
	FILE *archivoPDF,*archivoQR,*archivoDB;
	archivoQR=fopen("C:\\JuegoSnake\\PuntajeJugador.txt","w");
	archivoPDF=fopen("C:\\JuegoSnake\\Puntajes.txt","a+");
	archivoDB=fopen("C:\\JuegoSnake\\DB.txt","w");
	
	Aux=lista;
	printf("Jugador: %s.\n\n",jugador);
	fprintf(archivoPDF,"Jugador: %s\n\n",jugador);
	fprintf(archivoQR,"Jugador: %s.\n\n",jugador);
	if(Aux == NULL)
	{
	  	printf("Usted ha finalizado el juego sin haber comido ningun numero.\n\n");
    	fprintf(archivoPDF,"Usted ha finalizado el juego sin haber comido ningun numero.\n\n");	
    	fprintf(archivoQR,"Usted ha finalizado el juego sin haber comido ningun numero.\n\n");
    }
	else
    {
	    printf("\t\tNumeros comidos.\n\n ==> ");
	    fprintf(archivoPDF,"\t\tNumeros comidos.\n\n ==> ");
	    fprintf(archivoQR,"\t\tNumeros comidos.\n\n ==> ");
		while(Aux != NULL)
		{
	        printf("%d, ",Aux->getNumero());
	        fprintf(archivoPDF,"%d, ",Aux->getNumero());
	        fprintf(archivoQR,"%d, ",Aux->getNumero());
	        Aux=Aux->getSiguienteDireccion();
	    }
		printf("\b\b. \n\nSu Puntaje es: %d\n\n",contadorNodo);
		fprintf(archivoPDF,"\b\b\b. \n\nSu Puntaje es: %d\n\n----------------------------------------------------\n",contadorNodo);	
		fprintf(archivoQR,"\b\b\b. \n\nSu Puntaje es: %d",contadorNodo);
	}
	fprintf(archivoDB,"%s;%d",jugador,contadorNodo);
	fclose(archivoPDF);
	fclose(archivoQR);
	fclose(archivoDB);
}

void ListaDoble::impresion()
{
	Nodo* Aux=new Nodo();
	
	Aux=lista;
	printf("Jugador: %s.\n\n",jugador);

	if(Aux == NULL)
	  	printf("Usted ha finalizado el juego sin haber comido ningun numero.\n\n");
	else
    {
	    printf("\t\tNumeros comidos.\n\n ==> ");
		while(Aux != NULL)
		{
	        printf("%d, ",Aux->getNumero());
	        Aux=Aux->getSiguienteDireccion();
	    }
		printf("\b\b. \n\nSu Puntaje es: %d\n\n",contadorNodo);	
	}
}

void ListaDoble::insertarAlFinal(int numero)
{
	Nodo* Nuevo=new Nodo();
	Nodo* Actual=new Nodo();
		
	if(contadorNodo==0)
	{	
		Actual->setNumero(numero);
		Actual->setAnteriorDireccion(NULL);
		Actual->setSiguienteDireccion(NULL);
		lista=Actual;	
	}
	else
	{
		Actual=lista;
		while(Actual->getSiguienteDireccion()!=NULL)
		{
			Actual=Actual->getSiguienteDireccion();
		}
		Nuevo->	setNumero(numero);
        Nuevo->	setSiguienteDireccion(NULL);
        Actual->setSiguienteDireccion(Nuevo);
        Nuevo->	setAnteriorDireccion(Actual);
	}
	contadorNodo++;
}

int aleatorio(int caso)
{
	if(caso==1)
		return rand()%9+1;
	else
		if(caso==2)
			return rand()%(39-4+1)+4;
		else
			return rand()%(99-2+1)+2;
}

void margen()
{  
	color(121);
    for(int i=2; i < 100; i++)
	{
    	//PARTE SUPERIOR
    	gotoxy (i, 3); printf("%c",178);
    	//PARTE INFERIOR
        gotoxy(i, 40); printf("%c",178);
    }
    for(int j=4; j < 40; j++)
	{
    	//PARTE IZQUIERDA
        gotoxy (2,j);  printf("%c",178);
        //PARTE DERECHA
        gotoxy(100,j);  printf("%c",178);
    }
    //ESQUINAS
    gotoxy  (2,3);	printf("%c",178);
    gotoxy (2,40);	printf("%c",178);
    gotoxy (100,3);	printf("%c",178);
    gotoxy(100,40);	printf("%c",178);
	color(15); 
}

void ListaDoble::juego()
{
	bool primera=true;
	char tecla=0;
	int x=3,y=4;
	int col,fil;
	int numero;
	
	srand(time(NULL));
	lista=NULL;
	contadorNodo=0;
	
	do
	{
		printf("Ingrese el nombre del jugador: ");
		gets(jugador);
		fflush(stdin);
	}while(validacionCaracter(jugador));
	
	do{
		system("cls");
		margen();
		gotoxy(0,0);
		printf("\t\t\t::::::::::::::::::::Juego del Snake::::::::::::::::");
		if(primera)
		{
			col=aleatorio(3);
			fil=aleatorio(2);
			numero=aleatorio(1);			
			primera=false;	
		}
		if((col==x+2||col==x)&&(fil==y))
		{
			col=aleatorio(3);
			fil=aleatorio(2);
			insertarAlFinal(numero);
			numero=aleatorio(1);		
		}
		gotoxy(col,fil);
		printf("%d",numero);
		gotoxy(x,y); //Posicion del caracter
		printf("<=>");	
		tecla=getch();
		switch(tecla)
		{
			case TECLA_ARRIBA:
				y--;
				if(y<=3)
					y=39;			
				break;
			case TECLA_ABAJO:
				y++;
				if(y>=40)
					y=4;
				break;
			case TECLA_DERECHA:
				x++;
				if(x>=98)
					x=3;
				break;
			case TECLA_IZQUIERDA:
				x--;
				if(x<=3)
					x=97;
				break;
		}
	}while(tecla!=TECLA_ENTER);
	system("cls");
	impresionArchivos();
}



