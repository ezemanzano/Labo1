
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define numeros_len 5
void imprimirArray(int array[],int len);
int promediarArray(int array[], int len, float* pPromedio);
int main(void) {
	int numeros[numeros_len];
	float resultado ;

	for (int i=0 ; i<numeros_len ; i++)
		{
		if (utn_getnumero (&numeros[i], "Ingrese edad 0-100","Error - Ingrese edad 0-100",0, 100,3)==0)
		{

		}
		else {
			printf("Error - Se acabaron los intentos");
		}
		}

	//imprimirArray(numeros,numeros_len);
	if (promediarArray (numeros,5,&resultado) == 0){
	printf ("%f", resultado);
	} else {
		printf("error");
	}

}

void imprimirArray(int array[], int len) {

	for (int j=0; j<len;j++)
	{
		printf("%d ",array[j]);
	}

}

int promediarArray(int array[], int len, float* pPromedio) {
		int acum = 0;
		for (int i=0; i<len; i++) {
			acum = acum + array[i] ;
			}
		*pPromedio = (float)acum / len;
		return 0;
}


