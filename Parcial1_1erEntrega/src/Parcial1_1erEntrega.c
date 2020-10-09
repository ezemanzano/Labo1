#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "publicacion.h"

#define CLIENTE_QTY 100
#define PUBLICACION_QTY 1000
int main(void) {
	int opcion;
	Cliente pArrayCliente[CLIENTE_QTY];
	Publicacion pArrayPublicacion[PUBLICACION_QTY];

	cliente_init(pArrayCliente,CLIENTE_QTY);
	publicacion_init(pArrayPublicacion, PUBLICACION_QTY);

	cliente_altaForzada(pArrayCliente, CLIENTE_QTY,"Ezequiel","Manzano","20-39626870-9");
	cliente_altaForzada(pArrayCliente, CLIENTE_QTY,"Sofia","Gonzalez","20-25626870-9");
	cliente_altaForzada(pArrayCliente, CLIENTE_QTY,"Martina","Dirago","20-52623270-9");
	cliente_altaForzada(pArrayCliente, CLIENTE_QTY,"Alicia","Finella","20-18604225-9");
	cliente_altaForzada(pArrayCliente, CLIENTE_QTY,"Claudio","Manzano","20-17409871-9");

	publicacion_altaForzada(pArrayPublicacion,PUBLICACION_QTY,2,4,"Vendo clio 2010");
	publicacion_altaForzada(pArrayPublicacion,PUBLICACION_QTY,3,4,"Vendo fitito nunca taxi 2010");
	publicacion_altaForzada(pArrayPublicacion,PUBLICACION_QTY,1,2,"Vendo heladera samsung");
	publicacion_altaForzada(pArrayPublicacion,PUBLICACION_QTY,1,1,"QEPD EZEQUIEL MANZANO - Siempre en nuestros corazones");
	publicacion_altaForzada(pArrayPublicacion,PUBLICACION_QTY,5,5,"Se alquila casa en canning super barata 100000 usd");

	do {
		if (utn_getNumero(&opcion,"\n -----Menu ----- \n 1) Alta Clinte \n 2) Modificar Cliente\n 3) Baja Cliente", "Error", 1, 9, 2) == 0)
		{
			switch(opcion)
			{
			case 1:
				cliente_alta(pArrayCliente, CLIENTE_QTY);
				break;
			case 2:
				cliente_modificar(pArrayCliente,CLIENTE_QTY);
				break;
			case 3:
				cliente_baja(pArrayCliente,CLIENTE_QTY);
				break;
			case 4 :
				publicacion_alta(pArrayPublicacion, PUBLICACION_QTY, pArrayCliente, CLIENTE_QTY);
				break;
			case 5:
				publicacion_pausar(pArrayPublicacion, PUBLICACION_QTY, pArrayCliente, CLIENTE_QTY);
				break;
			case 6:
				publicacion_reanudar(pArrayPublicacion, PUBLICACION_QTY, pArrayCliente, CLIENTE_QTY);
				break;
			case 7:
				publicacion_imprimirTodas(pArrayPublicacion, PUBLICACION_QTY, pArrayCliente, CLIENTE_QTY);
				break;
			}

		}

	}while (opcion!=9);

}


