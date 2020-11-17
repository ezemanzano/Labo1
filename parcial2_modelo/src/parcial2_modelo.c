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
LinkedList * pArrayClone;
LinkedList * pArrayDestino = ll_newLinkedList();
char zonaAFiltrar[128];

do {
utn_getNumero(&opcion, "---MENU--- \n 1) leer de texto 2) imprimr","Error",1, 6,2);
switch(opcion){
case 1:
	envio_loadFromText("data.csv",pArrrayListEnvios);
	break;
case 2:
	ll_map(pArrrayListEnvios, envio_imprimirTodos);
	//printf("%d",pArrrayListEnvios->size);
	break;
case 3:
	ll_map(pArrrayListEnvios,envio_calcularCostos);
	ll_map(pArrrayListEnvios, envio_imprimirTodos);
	break;
case 4:
	//buscar la forma de darle ingresarle la zona
	 pArrayClone =ll_clone(pArrrayListEnvios);
	 envio_listaDestinos(pArrrayListEnvios,pArrayDestino);
	 ll_map(pArrayDestino,destino_imprimirLista );
	if (utn_getString(zonaAFiltrar,128, "\n Ingrese zona a filtrar", "error", 2)==0)
	{
		ll_filterByZone(pArrayClone,envio_filtrarPorZona,zonaAFiltrar);
		ll_map(pArrayClone,envio_calcularCostos);
		ll_map(pArrayClone, envio_imprimirTodos);
		envio_saveAsText("zona.csv", pArrayClone);
	}
	break;
case 5:
	printf("\n *** Listado de zonas ***");
	 envio_listaDestinos(pArrrayListEnvios,pArrayDestino);
	 ll_map(pArrayDestino,destino_imprimirLista );
break;
}
}while(opcion!=6);
}
