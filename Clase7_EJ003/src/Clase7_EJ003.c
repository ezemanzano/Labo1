/*
 ============================================================================
 Name        : Clase7_EJ003.c
 Author      : 
 Version     :
 Copyright   :
 Description : VALIDACIÒN DE UN FLOAT.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int main(void) {
	char numero[8] ;
	strcpy(numero,"-1.50");
	if (esNumerica(numero) == 0){
		printf("error");
	} else {
		printf("es float");
	}


}
