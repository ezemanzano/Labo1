/*
 ============================================================================
 Name        : Clase7_EJ001.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {
	int numero1;
	int numero2;
	int resultado;

	 if (utn_getnumero(&numero1,"Ingrese primer numero","Error - el numero debe estar entre 0-100",0, 100, 3)== 0) {
		 	 if (utn_getnumero(&numero2,"Ingrese primer numero","Error - el numero debe estar entre 0-100",0, 100, 3)== 0) {
		 		if (calcularMayor(&resultado, numero1,numero2) == 0) {
		 			printf("El mayor es : %d", resultado);
		 		} else {
		 			printf("Los numeros son iguales");
		 		}
		 	 } else {
		 		printf("Error2.");
		 	 }
	 } else {
		 printf("Error1.");
	 }

}
