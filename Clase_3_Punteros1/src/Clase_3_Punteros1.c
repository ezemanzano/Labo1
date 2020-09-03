/*
 ============================================================================
 Name        : Clase_3_Punteros1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
float division (int operador1,int operador2, float* memoriaResultado);

int main(void) {
	setbuf (stdout, NULL);
		int numero1;
		int numero2;
		float resultado;
		int huboError;


		printf ("Ingrse nùmero... ");
		__fpurge(stdin);
		scanf ("%d",&numero1 );
		printf ("Ingrse nùmero... ");
		__fpurge(stdin);
		scanf ("%d",&numero2 );
		huboError = division(numero1,numero2, &resultado) ;
		if (huboError == 1) {
			printf ("No se puede dividir por 0 ");
		} else {
			printf("El resultado es: %.2f", resultado);
		}
}

float division (int operador1,int operador2, float* memoriaResultado) {
		float resul;
		int huboError;
		if (operador2 == 0) {
			huboError = 1;
		} else {
			resul = (float)operador1 / operador2 ;
			(*memoriaResultado) = resul;
			huboError =0 ;
		}
		return huboError;
}
