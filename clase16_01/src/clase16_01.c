/*
 ============================================================================
 Name        : clase16_01.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "publicacion.h"
#define CLIENTE_QTY 100
#define PUBLICACION_QTY 1000

int main(void) {

	Cliente * pAlArrayCliente[CLIENTE_QTY];
	Publicacion * pAlArrayPublicacion[PUBLICACION_QTY];

	cliente_init(pAlArrayCliente,CLIENTE_QTY);
	publicacion_init(pAlArrayPublicacion, PUBLICACION_QTY);
	cliente_altaForzada(pAlArrayCliente,"Ezequiel", "Manzano","22222");
	cliente_altaForzada(pAlArrayCliente,"alvaro", "jae","22-22");
	publicacion_altaForzada(pAlArrayPublicacion, PUBLICACION_QTY, 1, 1, "testeo");
	publicacion_altaForzada(pAlArrayPublicacion, PUBLICACION_QTY, 2, 4, "testeo");
	utn_menuPrincipal(pAlArrayPublicacion, PUBLICACION_QTY, pAlArrayCliente, CLIENTE_QTY);

	return EXIT_SUCCESS;
}


