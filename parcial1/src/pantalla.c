/*
 * pantalla.c
 *
 *  Created on: Sep 22, 2020
 *      Author: ezemanzano
 */
#include "pantalla.h"

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"

static int pantalla_generarNuevoId (void);

int pantalla_init(Pantalla * pArrays, int limite){
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


int pantalla_alta (Pantalla * pArrays, int limite)
{
	int retorno = -1;
	int indice;

	Pantalla bufferPantalla;
	if (pArrays != NULL && limite >0)
	{
		if (pantalla_buscarLibreRef (pArrays, limite, &indice) == 0)
		{
				if (utn_getNombre(bufferPantalla.nombre,SIZE_NOMBRE , "\n Nombre?", "error",2) == 0 &&
					utn_getNombre(bufferPantalla.direccion, SIZE_NOMBRE, " \n Direccion?","ERROR",3) == 0 &&
					utn_getFloat(&bufferPantalla.precio, "Precio? (1-10000)","error", 1, 10000, 2) == 0 &&
					utn_getNumero(&bufferPantalla.tipo, "Tipo ? (0-LED / 1-LCD)","ERROR",0,1,2) == 0 )
				{
						pArrays[indice] = bufferPantalla;
						pArrays[indice].id = pantalla_generarNuevoId();
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


int pantalla_imprimir (Pantalla * pArrays , int limite) {
	int retorno = -1;
	char strTipo[8];
	if (pArrays != NULL && limite >0){
		for (int i=0 ; i<limite ; i++)
		{
			if(pArrays[i].isEmpty == FALSE)
			{
				if (pArrays[i].tipo == PANTALLA_TIPO_LCD){
					strncpy(strTipo,"LCD",8);
				}
				else
				{
					strncpy(strTipo,"LED",8);
				}

				printf("\nNombre: %s - Direccion: %s - Tipo %s - Precio %.2f- ID %d",pArrays[i].nombre,pArrays[i].direccion,strTipo, pArrays[i].precio , pArrays[i].id);
			}
		}
		retorno = 0;
	}
return retorno;
}





int pantalla_baja (Pantalla * pArrays, int limite){
	int retorno = -1;
	int idABorrar;
	int indiceABorrar;

	if (pArrays != NULL && limite>0)
	{
		pantalla_imprimir(pArrays, limite);
		if(utn_getNumero(&idABorrar,"Ingrese pais de pantalla a borrar","Error",0,9999,3)==0)
		{

			if(pantalla_buscarIndicePorIdRef(pArrays, limite, idABorrar, &indiceABorrar)== 0)
			{
				pArrays[indiceABorrar].isEmpty=TRUE;
			}
		}
	}
	return retorno;
}

// ver de no perder el ID y usar las nuevas FN
int pantalla_modificar (Pantalla * pArrays, int limite)
{
	int retorno = -1;
	int idBuscar;
	int indiceAModificar = -1;
	Pantalla bufferPantalla;

	if (pArrays != NULL && limite>0)
	{
		pantalla_imprimir(pArrays, limite);

		if(utn_getNumero(&idBuscar,"ID:","ERROR!",0,9999,2)==0)
		{


			if(pantalla_buscarIndicePorIdRef(pArrays, limite,idBuscar,&indiceAModificar) == 0)
			{
				bufferPantalla = pArrays[indiceAModificar]; // IMPORTANTE!

				if (utn_getNombre(bufferPantalla.nombre, SIZE_NOMBRE ,"\n Nuevo nombre?", "error",2) == 0 &&
					utn_getNombre(bufferPantalla.direccion, SIZE_NOMBRE, " \n Ingrese nuevo direccion","ERROR",3) == 0 &&
					utn_getFloat(&bufferPantalla.precio, "Ingrese precio","error", 1, 10000, 2) == 0 &&
					utn_getNumero(&bufferPantalla.tipo, "iNGRESE TIPO","ERROR",0,1,2) == 0 )
					{
						pArrays[indiceAModificar] = bufferPantalla; // COPIAMOS AL ARRAY
						retorno = 0;
					}
				}
			}
		}
	return retorno;
}





int pantalla_buscarLibre (Pantalla * pArrays, int limite){
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

int pantalla_buscarLibreRef (Pantalla * pArrays, int limite, int * pIndice){
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

static int pantalla_generarNuevoId (void) {
	static int id = 0;
	id = id+1;
	return id;
}

int pantalla_buscarIndicePorIdRef (Pantalla * pArrays, int limite,int idBuscar, int * pIndice){
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

int pantalla_buscarIndicePorId (Pantalla * pArrays, int limite,int idBuscar){
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



int pantalla_ordenarPorNombre (Pantalla * pArrays, int limite , int orden)
{
	int retorno = -1;
	int estadoDesordenado = 1;
	Pantalla aux;
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


int pantalla_altaForzada(Pantalla * pArray, int limite , char * nombre, int tipo , float precio, char * direccion){

	int retorno = -1;
	int indice;
	if (pantalla_buscarLibreRef(pArray,limite, &indice) == 0)
	{
		strncpy(pArray[indice].nombre,nombre,SIZE_NOMBRE);
		strncpy(pArray[indice].direccion,direccion,SIZE_NOMBRE);
		pArray[indice].tipo = tipo;
		pArray[indice].precio = precio;
		pArray[indice].id = pantalla_generarNuevoId();
		pArray[indice].isEmpty = FALSE;
		retorno = 0;
	}
	else
	{
		printf("Error - No quedan libres");
	}
	return retorno;
}

int pantalla_imprimirPorIndice (Pantalla * pArrays , int limite, int indice) {
	int retorno = -1;
	char strTipo[8];

			if(pArrays[indice].isEmpty == FALSE)
			{
				if (pArrays[indice].tipo == PANTALLA_TIPO_LCD){
					strncpy(strTipo,"LCD",8);
				}
				else
				{
					strncpy(strTipo,"LED",8);
				}

				printf("-->  ID Pantalla %d - NombrePantalla: %s - DireccionPantalla: %s - Tipo %s - Precio %.2f ",pArrays[indice].id,pArrays[indice].nombre,pArrays[indice].direccion,strTipo, pArrays[indice].precio);
				retorno = 0;
			}

return retorno;
}

int pantalla_imprimirPrecioPorIndice (Pantalla * pArrays , int limite, int indice) {
	int retorno = -1;
	char strTipo[8];

			if(pArrays[indice].isEmpty == FALSE)
			{
				if (pArrays[indice].tipo == PANTALLA_TIPO_LCD){
					strncpy(strTipo,"LCD",8);
				}
				else
				{
					strncpy(strTipo,"LED",8);
				}

				printf("-->  ID Pantalla %d - Precio Por dia $ %.2f ",pArrays[indice].id,pArrays[indice].precio);
				retorno = 0;
			}

return retorno;
}

