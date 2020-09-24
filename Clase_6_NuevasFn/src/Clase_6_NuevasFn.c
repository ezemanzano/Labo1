/*
 ============================================================================
 Name        : Clase_6_NuevasFn.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>

int main(void) {
	//char numero[4096];
	int numero;

	for (int i = 0; i<4; i++) {
	utn_getnumero(&numero, "\n ingresa un num","error",-50,10,3);
	printf ("\n Numero es %d",numero);
	}
}
