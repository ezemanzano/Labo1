#include <stdio_ext.h>
#include <stdlib.h>

int getfloat (char *mensaje, char *mensajeError, int intentos ,float *resultado){

	int retorno = -1;
	int resultadoScan ;
	float bufferFloat;


	printf("%s",mensaje);
	__fpurge(stdin);
	 resultadoScan = scanf("%f",&bufferFloat);

	 while (resultadoScan == 0 && intentos>0) {
		 intentos--;
		 printf("%s - Intentos restantes %d", mensajeError,intentos);
		 __fpurge(stdin);
		 resultadoScan = scanf("%f",&bufferFloat);
	 }
	 if (resultadoScan != 0) {
		 *resultado = bufferFloat;
	 }

	 return retorno;

}
