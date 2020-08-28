#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);
	int numero;
	int acum = 0;
	float resultado;
	int respuestaScan;
	int i ;
	for ( i = 0;i<5;i++)
	{
		printf ("Ingrese Numero:");
		fflush(stdin);
		respuestaScan = scanf ("%d", &numero) ;
		while (respuestaScan == 0)
		{
			printf ("Error - Ingrese Numero:");
			fflush(stdin);
			respuestaScan = scanf ("%d", &numero) ;
		}
		acum = acum + numero ;
	}
	resultado = (float)acum / i ;
	printf ("El resultado es %.2f" , resultado);
}
