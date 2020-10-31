/*
 * generico.c
 *
 *  Created on: Sep 22, 2020
 *      Author: ezemanzano
 */
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#include "generico.h"
#include "utn.h"
static int generico_generarNuevoId (void);

/**
 * \brief Inicializa el array de genericos
 * \param Generico * pArrayGenerico  Es el puntero al array de generico
 * \param int limiteGenerico, es el tamaño de array de genericos
  * \return (-1) Error / (0) Ok
 *
 */

int generico_init(Generico * pArrays, int limite){
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
// chequear baja

int generico_baja(Generico * pArrays,int limite, int  idGenericoBaja){
	int retorno =-1;
	if (pArrays != NULL && limite >0 && idGenericoBaja>0)
	{
			pArrays[idGenericoBaja].isEmpty=TRUE;
			retorno = 0;
	}
return retorno;
}
/**
 * \brief Da de alta un clinete pidiendole los datos al usuario.-
 * \param Generico * pArrayGenerico  Es el puntero al array de generico
 * \param int limiteGenerico, es el tamaño de array de genericos
 * \return (-1) Error / (0) Ok
  */

int generico_alta (Generico * pArrays, int limite)
{
	int retorno = -1;
	int indice;

	Generico bufferGenerico;
	if (pArrays != NULL && limite >0)
	{
		if (generico_buscarLibreRef (pArrays, limite, &indice) == 0)
		{
				if (utn_getNumero(&bufferGenerico.numero, "\n Ingrese numero", "\n ERROR", 0, 9999, 2) == 0 &&
					utn_getNumero(&bufferGenerico.numero2, "\n Ingrese numero 2", "\n ERROR", 0, 9999, 2) == 0 &&
					utn_getFloat(&bufferGenerico.flotante, "\n Ingrese Flotante", "\n ERROR", 0, 9999, 2) == 0 &&
					utn_getFloat(&bufferGenerico.flotante2, "\n Ingrese Flotante 2", "\n ERROR", 0, 9999, 2) == 0 &&
					utn_getNombre(bufferGenerico.nombre,SIZE_NOMBRE , "\n Nombre?", "\n ERROR",2) == 0 &&
					utn_getNombre(bufferGenerico.apellido, SIZE_NOMBRE, " \n Apellido?","\n ERROR",3) == 0 &&
					utn_getCuit(bufferGenerico.cuit, SIZE_CUIT,"\n Cuit?","\n ERROR",3) == 0 &&
					generico_noSeRepiteCuit(pArrays, limite,(bufferGenerico.cuit))==0 )
				{
						pArrays[indice] = bufferGenerico;
						pArrays[indice].id = generico_generarNuevoId();
						pArrays[indice].isEmpty = FALSE;
						retorno = 0;
						printf("\n SUCCESS - Nuevo generico OK");
				} else
					{
						printf("\n ERROR");
					}
			} else
			{
				printf(" \n No quedan espacios libres");
			}
		}
		return retorno ;
}

/**
 * \brief Imprime los genericos con su respectivos datos
 * \param Generico * pArrayGenerico  Es el puntero al array de generico
 * \param int limiteGenerico, es el tamaño de array de genericos
 * \return (-1) Error / (0) Ok
  */
int generico_imprimir (Generico * pArrays , int limite) {
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
/**
 * \brief Modifica un clinete pidiendole los datos al usuario.-
 * \param Generico * pArrayGenerico  Es el puntero al array de generico
 * \param int limiteGenerico, es el tamaño de array de genericos
 * \return (-1) Error / (0) Ok
  */

int generico_modificar (Generico * pArrays, int limite)
{
	int retorno = -1;
	int idBuscar;
	int indiceAModificar = -1;
	Generico bufferGenerico;

	if (pArrays != NULL && limite>0)
	{
		generico_imprimir(pArrays, limite);

		if(utn_getNumero(&idBuscar,"\n --- Ingrese ID del generico a modificar ----:","\n ERROR!",0,9999,2)==0)
		{


			if(generico_buscarIndicePorIdRef(pArrays, limite,idBuscar,&indiceAModificar) == 0)
			{
				bufferGenerico = pArrays[indiceAModificar]; // IMPORTANTE!

				if (utn_getNumero(&bufferGenerico.numero, "\n Ingrese numero", "\n ERROR", 0, 9999, 2) == 0 &&
					utn_getNumero(&bufferGenerico.numero2, "\n Ingrese numero 2", "\n ERROR", 0, 9999, 2) == 0 &&
					utn_getFloat(&bufferGenerico.flotante, "\n Ingrese Flotante", "\n ERROR", 0, 9999, 2) == 0 &&
					utn_getFloat(&bufferGenerico.flotante2, "\n Ingrese Flotante 2", "\n ERROR", 0, 9999, 2) == 0 &&
					utn_getNombre(bufferGenerico.nombre, SIZE_NOMBRE ,"\n Nuevo nombre?", "\n ERROR",2) == 0 &&
					utn_getNombre(bufferGenerico.apellido, SIZE_NOMBRE, " \n Ingrese nuevo apellido","ERROR",3) == 0 &&
					utn_getCuit(bufferGenerico.cuit, SIZE_CUIT, "nuevo Cuit?", "\n ERROR", 2)==0 &&
					generico_noSeRepiteCuit(pArrays, limite, bufferGenerico.cuit)==0)
					{
						pArrays[indiceAModificar] = bufferGenerico; // COPIAMOS AL ARRAY
						printf("\n Generico Modificado.");
						retorno = 0;
					}
				}
			else
			{
				printf("\n No se encontrò un generico con ese id. Vuelva a intentar");
			}
			}
		}
	return retorno;
}

/**
 * \brief Busca una posicion vacìa en el array de genericos.
 * \param Generico * pArrayGenerico  Es el puntero al array de generico
 * \param int limiteGenerico, es el tamaño de array de genericos
 * \return (-1) Error / (0) Ok
  */

int generico_buscarLibre (Generico * pArrays, int limite){
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

int generico_buscarLibreRef (Generico * pArrays, int limite, int * pIndice){
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

static int generico_generarNuevoId (void) {
	static int id = 0;
	id = id+1;
	return id;
}

int generico_buscarIndicePorIdRef (Generico * pArrays, int limite,int idBuscar, int * pIndice){
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
			printf("\n ERROR");
		}
	return retorno;
}

/**
 * \brief Busca el indice del generico en el array de genericos en base al ID
 * \param Generico * pArrayGenerico  Es el puntero al array de generico
 * \param int limiteGenerico, es el tamaño de array de genericos
* \param int idBuscar, es el id de generico a buscarle el indice.
 * \return (-1) Error / (0) Ok
  */

int generico_buscarIndicePorId (Generico * pArrays, int limite,int idBuscar){
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
			printf("\n ERROR");
		}
	return retorno;
}

/**
 * \brief Imprime la informacion del generico
 * \param Generico * pArrayGenerico  Es el puntero al array de generico
 * \param int limiteGenerico, es el tamaño de array de genericos
 * \param int idGenerico -> se da por parametro el id del generico a imprimir
 * \return (-1) Error / (0) Ok
 *
 */


int generico_informacionGenerico(Generico * pArrayGenerico, int limiteGenerico, int idGenerico){

	int retorno = 0;
	int indice;
	if (pArrayGenerico!= NULL && limiteGenerico>0 && idGenerico>0)
	{
		generico_buscarIndicePorIdRef (pArrayGenerico, limiteGenerico,idGenerico,&indice);
		printf("\n Nombre: %s - Apellido: %s - Cuit: %s ",pArrayGenerico[indice].nombre,pArrayGenerico[indice].apellido,pArrayGenerico[indice].cuit);
	}
	else
	{
		printf("\n ERROR");
	}

	return retorno;
}
/**
 * \brief Hardcode de un clinete
 * \param Generico * pArrayGenerico  Es el puntero al array de generico
 * \param int limite, es el tamaño de array de genericos
 * \param char * nombre, nombre a guardar
 * \param char * apellido, apellido a guardar
 * \param char * cuit, cuit a guardar
 * \return (-1) Error / (0) Ok
  */

int generico_altaForzada(Generico * pArray, int limite , char * nombre, char * apellido, char * cuit){

	int retorno = -1;
	int indice;
	if (generico_buscarLibreRef(pArray,limite, &indice) == 0)
	{
		strncpy(pArray[indice].nombre,nombre,SIZE_NOMBRE);
		strncpy(pArray[indice].apellido,apellido,SIZE_NOMBRE);
		strncpy(pArray[indice].cuit,cuit,SIZE_NOMBRE);
		pArray[indice].id = generico_generarNuevoId();
		pArray[indice].isEmpty = FALSE;
		retorno = 0;
	}
	else
	{
		printf("\n Error - No quedan libres");
	}
	return retorno;
}

/**
 * \brief Chequea si hay algun generico de alta para poder continuar
 * \param Generico * pArrayGenerico  Es el puntero al array de generico
 * \param int limiteGenerico, es el tamaño de array de genericos
 * \return (-1) Error / (1) Si lo hay
 *
 */

int generico_sePuedeSeguir(Generico * pArrayGenerico, int limiteGenerico){
	int retorno = -1;
	if (pArrayGenerico!=NULL && limiteGenerico>0)
	{
		for (int i = 0; i<limiteGenerico;i++)
		{
			if (pArrayGenerico[i].isEmpty == FALSE)
			{
				retorno=1;
				break;
			}
		}
	}
return retorno;
}


/**
 * \brief Chequea si hay algun generico de alta con el mismo cuit ingresado
 * \param Generico * pArrayGenerico  Es el puntero al array de generico
 * \param int limiteGenerico, es el tamaño de array de genericos
 * \param char * cuitIngresado, es el cuit a buscar entre los cuits ya existentes
 * \return (-1) Error / (1) Si lo hay
 *
 */
int generico_noSeRepiteCuit(Generico * pArrayGenerico, int limiteGenerico, char  * cuitIngresado){
	int retorno = -1;
	if (pArrayGenerico!=NULL && limiteGenerico>0)
	{
		for(int i = 0; i<limiteGenerico;i++)
		{
			if(strncmp(cuitIngresado,pArrayGenerico[i].cuit,SIZE_CUIT)==0)
			{
				printf("Error - Ese cuit ya existe");
				retorno = -1;
				break;
			}
			else
			{
				retorno = 0;
			}
		}
	}
return retorno;
}

