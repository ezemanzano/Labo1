
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define sizeArray 5


int main(void) {

	int numeros[sizeArray];
	int contador;
	float promedio;
	for (int i = 0; i<sizeArray ; i++ )
	{
		if (utn_getnumero ( &numeros[i] , "Ingrese numero 0-50","Error - Ingrese edad 0-50",0, 50,3) == 0)
		{

		} else
		{
			printf("Se acabaron los intentos...");
		}

	}
	imprimirArray(numeros, sizeArray);
	contador = ordenarArrayMinMax(numeros,sizeArray);
	printf ("\n Cantidad de iteraciones %d", contador);
	printf ("\n El numero màs chico es: %d", numeros[0]);
	printf ("\n El numeero mas grande es: %d", numeros[sizeArray-1]);
	if ( promediarArray(numeros, sizeArray, &promedio)== 0) {
		printf ("\n El promedio es: %.2f", promedio);
	}
	imprimirArray(numeros, sizeArray);

}




