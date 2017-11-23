#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

bool validacionCedula(char Cedula[]){ 
    long int ced,coc,var1;
    int numpar,numimpar,v,digito,mul,res2,sumat,A[15],aux;
    numpar=numimpar=0;
	ced=atol(Cedula);
	var1=ced;
	var1=(var1/100000000);
	if ((var1>=1)&&(var1<=24))
	{
	    coc=ced/10;
	    A[9]=ced%10;
	    digito=A[9];
	    ced=coc;
	    for (int i=8;i>=0;i--)
	    {
	        coc=ced/10;
	        A[i]=ced%10;
	        ced=coc;
			if ((i%2)==0)
	        {
	            mul=A[i]*2;
	            if (mul>9)
	            {
	                mul-=9;
	            }
	            numimpar+=mul;
	        }
	        else
	        {
	            numpar+=A[i];
	        }
	    }
	    sumat=numimpar+numpar;
	    res2=sumat%10;
	    v=10-res2;
	    if(v==10)
	            v=0;
	    if(v==digito)
	    {
	        aux=1;
	        //strcpy(Cedula,cedula);
	        return false;
	    }
	    else{
	    	printf("_____________________\n\nCedula Incorrecta !!\n_____________________\n\n");
	        aux=-1;
	        return true;
		}

	}
	else
	{
	    printf("_____________________\n\nCedula Incorrecta !!\n_____________________\n\n");
	    aux=-1;
	    return true;
	}
	if(aux==1)
	{
		//strcpy(Cedula,cedula);
		return false;
	}
	else
	{
		//strcpy(Cedula,"0");
	}
}

bool validacionNombreYApellido(char cadena[]){
	int i;
	for(i=0;cadena[i]!=NULL;i++)
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

bool validacionCelular(char celular[]){
	int i;
	for(i=0;celular[i]!=NULL;i++)
	{
		if(celular[i]<48||celular[i]>57||strlen(celular)!=10)
		{
			printf("_________________________________________________________________________\nNumero de celular incorrecto !!\nVerifique su numero de celular...\nLos dos primeros digitos deben ser 09 y debe tener 10 digitos en total\n_________________________________________________________________________\n\n");
			return true;
			break;
		}
	}
	if(strlen(celular)==10&&celular[0]=='0'&&celular[1]=='9')
	{
		return false;
	}
}

bool validacionNumero(char numero[]){
	int i;
	for(i=0;numero[i]!=NULL;i++)
	{
		if(numero[i]<48||numero[i]>57)
		{
			printf("___________________________________________________\nDato Incorrecto !!\nNo puede contener caracteres especiales, ni letras\nVuelva a ingresar por favor\n___________________________________________________\n\n");
			return true;
			break;
		}
	}
	return false;	
}

bool validacionEmail(char email[]){
	int i;
	bool arroba=true,com;
	for(i=0;email[i]!=NULL;i++)
	{
		if(email[i]==64)
			arroba=false;
	}
	i=strlen(email)-1;
	if(((email[i]=='m')&&(email[i-1]=='o')&&(email[i-2]=='c')&&(email[i-3]=='.'))||((email[i]=='c')&&(email[i-1]=='e')&&(email[i-2]=='.')))
		com=false;
	else
		com=true;
						
	if(arroba||com)
		printf("_____________________________\nDato Incorrecto !!\nCorreo mal ingresado\nVuelva a ingresar por favor\n_____________________________\n");
	
	return arroba||com;
}

bool validacionEdad(char edad[])
{
	int edad1;
	if(validacionNumero(edad))
	{
		return true;
	}
	else
	{	
		edad1=atoi(edad);
		if(edad1>66||edad1<18)
		{
			printf("______________________________________________________________________\nEdad no permitida, tiene que ser mayor a 18 y menor a 66 a%cos de edad.\nVuelva a ingresar por favor\n______________________________________________________________________\n\n",164);			
			return true;
		}
		return false;
	}
	
}

