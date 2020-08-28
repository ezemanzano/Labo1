
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	 setbuf(stdout,NULL);
	 int numero;
	 int contPos = 0;
	 int contNeg = 0;
	 int i;
	 int scan;
	 	 for (i = 0; i<3; i++)
	 	 {
	 	 printf ("Ingrese numero...");
	 	 fflush(stdin);
	 	 scan = scanf("%d",&numero);
	 	 while (scan == 0) {
	 		 printf ("Error - Ingrese numero...");
	 		 fflush(stdin);
	 		 scan = scanf("%d",&numero);
	 	 	 }
	 	 if (numero>=0) {
	 		 contPos++;
	 	 } else
	 		 contNeg++;

	 	}
	 	 printf ("La cantidad de positivos es: %d \n La cantidad de negativos es: %d",contPos, contNeg);
		}
