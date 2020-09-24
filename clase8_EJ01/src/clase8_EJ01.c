/*
5) Hacer una funcion que reciba el array del punto 4, y verifique que las letras dentro del
 mismo esten en el rango de 'a' a 'z' o de 'A' a 'Z'. Si estan dentro del rango la funcion
 deberá devolver por valor(usando el return) un 0, de lo contrario devolverá -1.
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
int imprimirArray(int array[], int len);
int contadorNumero (int array[], int len ,int numero);
int contadorNumeroDevuelve (int array[], int len , int* pRespuesta );
int buscarCaracter (char array[]);
int main(void) {

	char nombre[80];
	printf("Ingresar nombre..");
	scanf("%s", nombre);

	if (buscarCaracter(nombre)) {
		printf("Nombre valido");
	} else {
		printf("Nombre NO valido");
	}

}

int buscarCaracter (char array[]){
	int retorno = 1;
	int i;

	if (array!=NULL) {
		for (i = 0 ; array[i] != '\0'; i++) {
			if ((array[i] < 'a' || array[i] > 'z') && (array[i] < 'A' || array[i] > 'Z'))
			{
				retorno = 0;
				break;
			}

			}


	}
	return retorno;
}




int contadorNumeroDevuelve (int array[], int len , int* pRespuesta ){
	int retorno = -1;
	int contador=0;
	if (array!=NULL && pRespuesta != NULL && len>0){
	for (int j=0; j<len;j++)
	{
		if (array[j] == 7) {
			contador++;
		}
		*pRespuesta = contador;
	}
			retorno = 0;
		}
return retorno;
}


int contadorNumero (int array[], int len , int numero ){
	int retorno = -1;
	int contador=0;
	if (array!=NULL && len>0){
	for (int j=0; j<len;j++)
	{
		if (array[j] == numero) {
			contador++;
			}
	}
		printf("La cantidad de veces que el numero %d està es %d",numero, contador);
			retorno = 0;
		}
return retorno;
}



int imprimirArray(int array[], int len) {
	int retorno = -1;
	if (array!=NULL && len>0){
		for (int j=0; j<len;j++)
			{
				printf("%d ",array[j]);
			}
		retorno = 0;
	}
	return retorno;

}
