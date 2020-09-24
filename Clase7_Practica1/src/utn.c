/*
 * utn.c
 *
 *  Created on: Sep 10, 2020
 *      Author: ezemanzano
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

static int myGets (char* cadena, int longitud);

static int myGets (char* cadena, int longitud){
		__fpurge (stdin);
		fgets(cadena,longitud,stdin);
		cadena[strnlen(cadena,sizeof(cadena))-1]='\0';
		return 1;
}

int esNombre (char*cadena, int limite) {
	int retorno = 1;
	int i ;
	for (i = 0 ; i<=limite && cadena[i] != '\0'; i++){
		if	((cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
		{
			retorno = 0;
			break;
		}}
	return retorno;
}



int getChar (char * pResultado, int len){
	int retorno = 0 ;
	char buffer[4096];
	if ( myGets(buffer,sizeof(buffer)) && esNombre(buffer, len) ){
		retorno = 1;
		strncpy(pResultado,buffer,len);
			}
	return retorno;
}





