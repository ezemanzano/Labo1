/*
 * utn.c
 *
 *  Created on: Sep 10, 2020
 *      Author: ezemanzano
 */

#include <stdio_ext.h>
#include <stdlib.h>

static int myGets (char* cadena, int longitud);
static int getInt (int* pResultado);
static int esNumerica (char* cadena);

static int myGets (char* cadena, int longitud){
		__fpurge (stdin);
		fgets(cadena,longitud,stdin);
		return 0;
}
static int getInt (int* pResultado){
	int retorno = -1 ;
	char buffer[4096];
	if (myGets(buffer,sizeof(buffer)) == 0  && esNumerica(buffer)== 0){
		retorno = 0;
		*pResultado = atoi(buffer);
	}
	return retorno;
}
static int esNumerica(char*cadena){
	int retorno = 1 ;
	int i = 0;
	if (cadena[0] == '-'){
		i = 1;
	}
	for (;cadena[i] != '\0';i++) {
		if (cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}


int utn_getnumero (int* pResultado, char* mensaje, char* mensajeError,int minimo, int maximo, int intentos){

	int retorno = -1;
	int bufferInt;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && maximo>minimo && intentos>=0) {
	do {
		printf("%s\n", mensaje);
		__fpurge(stdin);
		if (getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
		{
		*pResultado = bufferInt;
		retorno = 0;
		break;
		}
		else
		{
		printf("%s \n", mensajeError);
		intentos--;
		}
	} while (intentos >= 0 );

	}
	return retorno;
}
