/*
 * nac.c
 *
 *  Created on: Sep 22, 2020
 *      Author: ezemanzano
 */
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "nac.h"

static int nac_generarNuevoId (void);

int nac_init(Nac * pArrays, int limite){
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


int nac_alta (Nac * pArrays, int limite){
int retorno = -1;
int indice;

Nac bufferNac;
	if (pArrays != NULL && limite >0)
	{
		if (nac_buscarLibreRef (pArrays, limite, &indice) == 0)
		{
				if (utn_getNombre(bufferNac.pais,LONG , "\n pais?", "error",2) == 0 &&
					utn_getNombre(bufferNac.nombre, LONG, " \n Ingrese nombre","ERROR",3) == 0)
				{
						pArrays[indice] = bufferNac;
						pArrays[indice].id = nac_generarNuevoId();
						pArrays[indice].isEmpty = FALSE;
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


int nac_imprimir (Nac * pArrays , int limite) {
	int retorno = -1;
	if (pArrays != NULL && limite >0){
		for (int i=0 ; i<limite ; i++)
		{
			if(pArrays[i].isEmpty == FALSE)
			{
				printf("\nNombre: %s - pais: %s - ID %d",pArrays[i].nombre,pArrays[i].pais , pArrays[i].id);
			}
		}
		retorno = 0;
	}
return retorno;
}


int nac_baja (Nac * pArrays, int limite){
	int retorno = -1;
	char buffer[LONG];
			if (pArrays != NULL && limite>0){
			nac_imprimir(pArrays, limite);
			utn_getNombre(buffer,LONG,"Ingrese pais de nac a borrar","Error",3);
			for (int i = 0 ; i<limite ;  i++){
				if (strncmp(pArrays[i].pais,buffer,LONG) == 0){
					pArrays[i].isEmpty = TRUE;
				}
			}
		}

	return retorno;

}
// ver de no perder el ID y usar las nuevas FN
int nac_modificar (Nac * pArrays, int limite){
	int retorno = -1;
	char modificar[20];
	char buffer[LONG];
	Nac bufferNac;
			if (pArrays != NULL && limite>0){
			nac_imprimir(pArrays, limite);
			utn_getNombre(buffer, LONG ,"Ingrese ID de nac a modificar","Error",3);
			for (int i = 0 ; i<limite ;  i++){
				if (buffer == pArrays[i].id){
				utn_getNombre(modificar, 20, "Que desea modificar? (nombre / pais)", "error", 2);
				if (strcmp(modificar, "pais") == 0){
					if (utn_getNombre(bufferNac.pais, LONG ,"\n Nuevo pais?", "error",2) == 0){
						strncpy(pArrays[i].pais,bufferNac.pais,LONG);
					} else {
						printf("horror");
					}
				}else {
					if (utn_getNombre(bufferNac.nombre, LONG, " \n Ingrese nuevo nombre","ERROR",3) == 0){
						strncpy(pArrays[i].nombre,bufferNac.nombre,LONG);
				}else {
					printf("horror");
				}
				}
				}
			}
		}

	return retorno;

}

int nac_imprimirIndice (Nac * pArrays, int limite, int indice){
	int retorno = -1;
		if (pArrays != NULL && limite >0){

				if(pArrays[indice].isEmpty == FALSE)
				{
					printf("\nNombre: %s - pais: %s",pArrays[indice].nombre,pArrays[indice].pais);
				}

			retorno = 0;
		}
	return retorno;
}

int nac_buscarLibre (Nac * pArrays, int limite){
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

int nac_buscarLibreRef (Nac * pArrays, int limite, int * pIndice){
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

static int nac_generarNuevoId (void) {
	static int id = 0;
	id = id+1;
	return id;
}

int nac_buscarIndice (Nac * pArrays, int limite, int idBuscar,int * pIndice){
	int retorno = -1;
	int i ;
		if (pArrays != NULL && limite >0 && pIndice != NULL && idBuscar >= 0)
		{
				for ( i = 0; i<limite; i++)
				{
					if(pArrays[i].id == idBuscar)
					{
					*pIndice = i;
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

int nac_ordenarPorNombre (Nac * pArrays, int limite , int orden){
	int retorno = -1;
	int estadoDesordenado = 1;
	Nac aux;
	if (pArrays != NULL && limite >0){
	while(estadoDesordenado)//mientras este desordenado
	{
		estadoDesordenado = 0;
		for(int i = 0; i < (limite - 1); i++)
		{
			if((orden == 1 && strncmp(pArrays[i].nombre, pArrays[i + 1].nombre,LONG)>0)
					||
			  (orden == 0 && strncmp(pArrays[i].nombre, pArrays[i + 1].nombre,LONG)<0))
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
