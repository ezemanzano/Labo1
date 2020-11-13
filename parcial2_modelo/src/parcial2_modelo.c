/*
 ============================================================================
 Name        : parcial2_modelo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include "envio.h"
#include "LinkedList.h"
#include "parser.h"
int main(void) {
int opcion;
LinkedList* pArrrayListEnvios = ll_newLinkedList();

do {
utn_getNumero(&opcion, "---MENU--- \n 1) leer de texto 2) imprimr","Error",1, 6,2);
switch(opcion){
case 1:
	envio_loadFromText("data.csv",pArrrayListEnvios);
	break;
case 2:
	//ll_map(pArrrayListEnvios, envio_imprimirTodos);
	printf("%d",pArrrayListEnvios->size);
	break;
}
}while(opcion!=6);
}
