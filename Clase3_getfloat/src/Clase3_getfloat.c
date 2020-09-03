#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {
	float numero1;
	setbuf (stdout, NULL);
	if (getfloat("Ingrese numero", "Error",2, &numero1) == -1) {
		printf ("Se te acabaron los intentos :(");
	} else
	printf("%f", numero1);
	return 0;

}
