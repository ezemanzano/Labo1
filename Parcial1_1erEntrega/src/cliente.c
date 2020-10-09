/*
 * cliente.c
 *
 *  Created on: Sep 22, 2020
 *      Author: ezemanzano
 */
#include "cliente.h"

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"

static int cliente_generarNuevoId (void);

int cliente_init(Cliente * pArrays, int limite){
	int retorno = -1;
	if (pArrays != NULL && limite >0){
		for (int i = 0; i<limite; i++ )
		{
			pArrays[i].isEmpty = TRUE;
		}
		retorno = 0;
	}

	return retorno;
}


int cliente_alta (Cliente * pArrays, int limite)
{
	int retorno = -1;
	int indice;

	Cliente bufferCliente;
	if (pArrays != NULL && limite >0)
	{
		if (cliente_buscarLibreRef (pArrays, limite, &indice) == 0)
		{
				if (utn_getNombre(bufferCliente.nombre,SIZE_NOMBRE , "\n Nombre?", "error",2) == 0 &&
					utn_getNombre(bufferCliente.apellido, SIZE_NOMBRE, " \n Apellido?","ERROR",3) == 0 &&
					utn_getCuit(bufferCliente.cuit, SIZE_CUIT,"\n Cuit?","herror",3) == 0 )
				{
						pArrays[indice] = bufferCliente;
						pArrays[indice].id = cliente_generarNuevoId();
						pArrays[indice].isEmpty = FALSE;
						retorno = 0;
				} else
					{
						printf("horror");
					}
			} else
			{
				printf(" \n No quedan espacios libres");
			}
		}
		return retorno ;
}


int cliente_imprimir (Cliente * pArrays , int limite) {
	int retorno = -1;
	if (pArrays != NULL && limite >0){
		for (int i=0 ; i<limite ; i++)
		{
			if(pArrays[i].isEmpty == FALSE)
			{
			printf("\nNombre: %s - Apellido: %s - Cuit %s - ID %d",pArrays[i].nombre,pArrays[i].apellido, pArrays[i].cuit, pArrays[i].id);
			}
		}
		retorno = 0;
	}
return retorno;
}





int cliente_baja (Cliente * pArrays, int limite){
	int retorno = -1;
	int idABorrar;
	int indiceABorrar;

	if (pArrays != NULL && limite>0)
	{
		cliente_imprimir(pArrays, limite);
		if(utn_getNumero(&idABorrar,"Ingrese pais de cliente a borrar","Error",0,9999,3)==0)
		{

			if(cliente_buscarIndicePorIdRef(pArrays, limite, idABorrar, &indiceABorrar)== 0)
			{
				pArrays[indiceABorrar].isEmpty=TRUE;
			}
		}
	}
	return retorno;
}

// ver de no perder el ID y usar las nuevas FN
int cliente_modificar (Cliente * pArrays, int limite)
{
	int retorno = -1;
	int idBuscar;
	int indiceAModificar = -1;
	Cliente bufferCliente;

	if (pArrays != NULL && limite>0)
	{
		cliente_imprimir(pArrays, limite);

		if(utn_getNumero(&idBuscar,"\n --- Ingrese ID del cliente a modificar ----:","ERROR!",0,9999,2)==0)
		{


			if(cliente_buscarIndicePorIdRef(pArrays, limite,idBuscar,&indiceAModificar) == 0)
			{
				bufferCliente = pArrays[indiceAModificar]; // IMPORTANTE!

				if (utn_getNombre(bufferCliente.nombre, SIZE_NOMBRE ,"\n Nuevo nombre?", "error",2) == 0 &&
					utn_getNombre(bufferCliente.apellido, SIZE_NOMBRE, " \n Ingrese nuevo apellido","ERROR",3) == 0 &&
					utn_getCuit(bufferCliente.cuit, SIZE_CUIT, "nuevo Cuit?", "errror", 2)==0)
					{
						pArrays[indiceAModificar] = bufferCliente; // COPIAMOS AL ARRAY
						retorno = 0;
					}
				}
			}
		}
	return retorno;
}





int cliente_buscarLibre (Cliente * pArrays, int limite){
	int retorno = -1;
	int i ;
		if (pArrays != NULL && limite >0){
			for ( i = 0; i<limite; i++) {
				if(pArrays[i].isEmpty == TRUE)
					{
					retorno = i;
					break;
					}
			}
		}
	return retorno;
}

int cliente_buscarLibreRef (Cliente * pArrays, int limite, int * pIndice){
	int retorno = -1;
	int i ;
		if (pArrays != NULL && limite >0 && pIndice != NULL){
			for ( i = 0; i<limite; i++) {
				if(pArrays[i].isEmpty == TRUE)
					{
					*pIndice = i;
					retorno = 0;
					break;
					}
			}
		}
	return retorno;
}

static int cliente_generarNuevoId (void) {
	static int id = 0;
	id = id+1;
	return id;
}

int cliente_buscarIndicePorIdRef (Cliente * pArrays, int limite,int idBuscar, int * pIndice){
	int retorno = -1;
	int i ;
		if (pArrays != NULL && limite >0 && idBuscar >= 0)
		{
				for ( i = 0; i<limite; i++)
				{
					if(pArrays[i].isEmpty == FALSE &&
					   pArrays[i].id == idBuscar)
					{
					*pIndice= i;
					retorno = 0;
					break;
					}
				}
		}
		else
		{
			printf("errrror");
		}
	return retorno;
}

int cliente_buscarIndicePorId (Cliente * pArrays, int limite,int idBuscar){
	int retorno = -1;
	int i ;
		if (pArrays != NULL && limite >0 && idBuscar >= 0)
		{
				for ( i = 0; i<limite; i++)
				{
					if(pArrays[i].isEmpty == FALSE &&
					   pArrays[i].id == idBuscar)
					{
					retorno = i;
					break;
					}
				}
		}
		else
		{
			printf("errrror");
		}
	return retorno;
}


int cliente_altaForzada(Cliente * pArray, int limite , char * nombre, char * apellido, char * cuit){

	int retorno = -1;
	int indice;
	if (cliente_buscarLibreRef(pArray,limite, &indice) == 0)
	{
		strncpy(pArray[indice].nombre,nombre,SIZE_NOMBRE);
		strncpy(pArray[indice].apellido,apellido,SIZE_NOMBRE);
		strncpy(pArray[indice].cuit,cuit,SIZE_NOMBRE);
		pArray[indice].id = cliente_generarNuevoId();
		pArray[indice].isEmpty = FALSE;
		retorno = 0;
	}
	else
	{
		printf("Error - No quedan libres");
	}
	return retorno;
}






/*
int cliente_ordenarPorNombre (Cliente * pArrays, int limite , int orden)
{
	int retorno = -1;
	int estadoDesordenado = 1;
	Cliente aux;
	if (pArrays != NULL && limite >0){
	while(estadoDesordenado)//mientras este desordenado
	{
		estadoDesordenado = 0;
		for(int i = 0; i < (limite - 1); i++)
		{
			if((orden == 1 && strncmp(pArrays[i].nombre, pArrays[i + 1].nombre,SIZE_NOMBRE)>0)
					||
			  (orden == 0 && strncmp(pArrays[i].nombre, pArrays[i + 1].nombre,SIZE_NOMBRE)<0))
			{
				aux = pArrays[i];
				pArrays[i] = pArrays[i + 1];
				pArrays[i + 1] = aux;
				estadoDesordenado = 1;
			}
		}
	}
	retorno = 0;


	}
	return retorno;
}


int cliente_altaForzada(Cliente * pArray, int limite , char * nombre, int tipo , float precio, char * direccion){

	int retorno = -1;
	int indice;
	if (cliente_buscarLibreRef(pArray,limite, &indice) == 0)
	{
		strncpy(pArray[indice].nombre,nombre,SIZE_NOMBRE);
		strncpy(pArray[indice].direccion,direccion,SIZE_NOMBRE);
		pArray[indice].tipo = tipo;
		pArray[indice].precio = precio;
		pArray[indice].id = cliente_generarNuevoId();
		pArray[indice].isEmpty = FALSE;
		retorno = 0;
	}
	else
	{
		printf("Error - No quedan libres");
	}
	return retorno;
}
*/


