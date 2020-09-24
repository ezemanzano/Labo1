/*
 ============================================================================
 Name        : Clase7_Practica1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


int main(void) {

	char nombre[50] ;
	printf("Ingrese nombre");
	if (getChar(nombre,50)){
		printf("%s",nombre);
	} else {
		printf("error");
	}


}
