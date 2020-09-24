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

void imprimirArray(int array[], int len) {

	for (int j=0; j<len;j++)
	{
		printf("\n %d ",array[j]);
	}

}
int ordenarArrayMinMax(int *pArray , int limite)
{
	int retorno = -1;
	int buffer;
	int contador;
	int i;
	int flagSwap;
	if(pArray!= NULL &&  limite > 0)
	{
		do {
		flagSwap = 0;
		for(i = 0; i < limite - 1 ;i++)
		{
			if(pArray[i] > pArray[i+1])
			{
				flagSwap = 1;
				buffer = pArray[i];
				pArray[i] = pArray[i+1];
				pArray[i+1] = buffer ;
				}
			contador++;
		}
		}while (flagSwap);
		retorno = contador;
	}
	return retorno;
}
