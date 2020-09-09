

#include <stdio_ext.h>
#include "utn.h"
#include <stdlib.h>

int main(void) {
	int edad ;
	float peso;
	char inicial;
	int respuesta;
	respuesta = utn_getnumero (&edad,"Edad? \n","error- edad debe ser de 0-100",0,100, 2);
	if (respuesta == 0) {
		printf ("La edad es %d\n", edad);
	} else {
		printf ("Se acabaron los intentos.\n");
	}

	respuesta = utn_getnumeroFloat (&peso,"Peso? \n","error- peso debe ser de 0-300",0.0,299.99, 2);
		if (respuesta == 0) {
			printf ("El peso es %.2f\n", peso);
		} else {
			printf ("Se acabaron los intentos.\n");
		}

	respuesta = utn_getChar (&inicial, "Ingrese su INICIAL...", "Error - Ingrese LETRA A - J", 'A', 'J', 3);
		if (respuesta == 0)
		{
		printf("Su inicial es %c", inicial);
		}
		else
		{
			printf ("Se acabaron los intnteos");
		}


}
