

#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {
		float numero1;
		float numero2;
		float resultados[6];

		if (utn_getnumeroFloat (&numero1,"Ingrese numero... ","Error - INGRESAR NUMERO",3) == 0) {

		} else
		{
			printf("Se acabaron los intentos");
		}
		if (utn_getnumeroFloat (&numero2,"Ingrese numero... ","Error - INGRESAR NUMERO",3) == 0) {

		} else
		{
			printf("Se acabaron los intentos");
		}
		resultados[0] = sumar(numero1,numero2);
		printf ("suma es : %.2f",resultados[0]);
		resultados[1] = restar(numero1,numero2);
		printf ("resta es : %.2f",resultados[1]);
		resultados[2] = multiplicar(numero1,numero2);
		printf ("multiplicacion es : %.2f",resultados[2]);
		if (dividir(numero1,numero2,&resultados[3]) == 0){
			printf ("dividir da %.2f",resultados[3]);
		} else {
			printf ("No se puede dividir por cero");
		}

		if (factorial(numero1, numero2,&resultados[4],&resultados[5]) == 0){
			printf ("el factorial de 1 es  %.2f y el factorial de 2 es %.2f",resultados[4],resultados[5]);
		} else {
			printf("error");
		}





}
