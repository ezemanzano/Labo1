/*
 ============================================================================
 Name        : Clase_1_Eje003.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	  setbuf(stdout,NULL);
		  int numero1;
		  int numero2;
		  int resultado;
		  int rtascan;
		  do {
		  printf("Ingrese Numero...");
		  fflush(stdin);
		  rtascan = scanf ("%d", &numero1);
		  while (rtascan == 0) {
			  printf("Error - Ingrese Numero...");
			  fflush(stdin);
			  rtascan = scanf ("%d", &numero1);
		  	  }
		  	  } while (numero1==0);
		  do {
		  printf("Ingrese 2do Numero...");
			  fflush(stdin);
			  rtascan = scanf ("%d", &numero2);
			  while (rtascan == 0) {
				  printf("Error - Ingrese 2do Numero...");
				  fflush(stdin);
				  rtascan = scanf ("%d", &numero2);
			  }
		  } while (numero2==0);

		  resultado = numero1 - numero2 ;
		  if (resultado>0) {
				 printf("El resultado es positivo");
			 } else if (resultado<0) {
				 printf ("El resultado es negativo");
			 } else {
				 printf("El resultado es 0");
			 }
}
