#include <stdio_ext.h>
#include <stdlib.h>

int main(void) {

	int numero;
	int acum = 0;
	float resultado;
	int respuestaScan;
	int i ;
	for ( i = 0;i<5;i++)
	{
		printf ("Ingrese Numero:");
		__fpurge(stdin);
		respuestaScan = scanf ("%d", &numero) ;
		while (respuestaScan == 0)
		{
			printf ("Error - Ingrese Numero:");
			__fpurge(stdin);
			respuestaScan = scanf ("%d", &numero) ;
		}
		acum = acum + numero ;
	}
	resultado = (float)acum / i ;
	printf ("El resultado es %.2f" , resultado);
}
