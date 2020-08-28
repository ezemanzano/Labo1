#include <stdio.h>
#include <stdlib.h>


int main(void) {
	  setbuf(stdout,NULL);
	  int numero1;
	  int numero2;
	  int resultado;
	  int rtascan;

	  printf("Ingrese Numero...");
	  fflush(stdin);
	  rtascan = scanf ("%d", &numero1);
	  while (rtascan == 0) {
		  printf("Error - Ingrese Numero...");
		  fflush(stdin);
		  rtascan = scanf ("%d", &numero1);
	  }

	  printf("Ingrese 2do Numero...");
		  fflush(stdin);
		  rtascan = scanf ("%d", &numero2);
		  while (rtascan == 0) {
			  printf("Error - Ingrese 2do Numero...");
			  fflush(stdin);
			  rtascan = scanf ("%d", &numero2);
		  }

		 resultado = numero1 - numero2 ;
		 printf("El resultado es: %d", resultado);

}
