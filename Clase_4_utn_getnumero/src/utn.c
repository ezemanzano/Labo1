#include <stdio_ext.h>
#include <stdlib.h>

int utn_getnumero (int* pResultado, char* mensaje, char* mensajeError,int minimo, int maximo, int intentos){

	int retorno = -1;
	int resultadoScan ;
	int bufferInt;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && maximo>minimo && intentos>=0) {
	do {
		printf("%s\n", mensaje);
		__fpurge(stdin);
		resultadoScan = scanf ("%d", &bufferInt);

		if (resultadoScan != 0 && bufferInt >= minimo && bufferInt <= maximo)
		{

		*pResultado = bufferInt;
		retorno = 0;
		break;
		}
		else
		{
		printf("%s \n", mensajeError);
		intentos--;
		}
	} while (intentos >= 0 );

	}
	return retorno;
}

int utn_getnumeroFloat (float* fResultado, char* mensaje, char* mensajeError,float minimo, float maximo, int intentos){

		int retorno = -1;
		int resultadoScan ;
		float bufferFloat;
		if (fResultado != NULL && mensaje != NULL && mensajeError != NULL && maximo>minimo && intentos>=0) {
		do {
			printf("%s\n", mensaje);
			__fpurge(stdin);
			resultadoScan = scanf ("%f", &bufferFloat);

			if (resultadoScan != 0 && bufferFloat >= minimo && bufferFloat <= maximo)
			{
			*fResultado= bufferFloat;
			retorno = 0;
			break;
			}
			else
			{
			printf("%s \n", mensajeError);
			intentos--;
			}
		} while (intentos >= 0 );

		}
		return retorno;
}


int utn_getChar (char* pResultado, char* mensaje, char* mensajeError,char minimo, char maximo, int intentos)
{

	int retorno = -1;
	int resultadoScan ;
	char bufferChar;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && maximo>minimo && intentos>=0) {

	do {
		printf("%s\n", mensaje);
		__fpurge(stdin);
		resultadoScan = scanf ("%c", &bufferChar);

		if (resultadoScan != 0 && bufferChar >= minimo && bufferChar <= maximo)
		{

		*pResultado = bufferChar;
		retorno = 0;
		break;
		}
		else
		{
		printf("%s \n", mensajeError);
		intentos--;
		}
	} while (intentos >= 0 );
	}
	return retorno;
}
