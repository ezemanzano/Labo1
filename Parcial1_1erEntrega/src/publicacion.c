/*
 * publicacion.c
 *
 *  Created on: Sep 22, 2020
 *      Author: ezemanzano
 */
#include "publicacion.h"

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"

static int publicacion_generarNuevoId (void);
//static void publicacion_buscarTotal (Publicacion * pArrayPubli , int limite , Cliente * pArrayCliente , int limiteCliente , int indiceCliente , int indice ,int * total);
int publicacion_init(Publicacion * pArrayPubli, int limite){
	int retorno = -1;
	if (pArrayPubli != NULL && limite >0){
		for (int i = 0; i<limite; i++ )
		{
			pArrayPubli[i].isEmpty = TRUE;
		}
		retorno = 0;
	}

	return retorno;
}


int publicacion_alta (Publicacion * pArrayPubli, int limite, Cliente * pArrayCliente , int limiteCliente)
{
	int retorno = -1;
	int indice;

	Publicacion bufferPublicacion;
	if (pArrayPubli != NULL && limite >0)
	{
		if (publicacion_buscarLibreRef (pArrayPubli, limite, &indice) == 0)
		{
		cliente_imprimir(pArrayCliente,limiteCliente);
				if (utn_getNumero(&bufferPublicacion.idCliente,"Ingrese id de cliente","error",0,99999,2) == 0 &&
					cliente_buscarIndicePorId(pArrayCliente, limiteCliente, bufferPublicacion.idCliente) != -1 &&
					utn_getNumero(&bufferPublicacion.rubro,"Ingrese Rubro", "error",0,99999,2) == 0 &&
					utn_getString(bufferPublicacion.aviso, SIZE_AVISO, "Ingrese Aviso", "Error", 2) == 0)

				{
						pArrayPubli[indice] = bufferPublicacion;
						pArrayPubli[indice].estado = PUBLICACION_ACTIVA;
						pArrayPubli[indice].id = publicacion_generarNuevoId();
						pArrayPubli[indice].isEmpty = FALSE;
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


int publicacion_imprimirTodas (Publicacion * pArrayPubli , int limite , Cliente * pArrayCliente , int limiteCliente) {
	int retorno = -1;
	char strEstado[10];
	if (pArrayPubli != NULL && limite >0 && pArrayCliente != NULL && limiteCliente >0){
		for (int i=0 ; i<limite ; i++)
		{
			if (pArrayPubli[i].estado == PUBLICACION_ACTIVA)
			{
				strncpy(strEstado,"ACTIVA",10);
			}
			else
			{
				strncpy(strEstado,"PAUSADA",10);
			}


			if(pArrayPubli[i].isEmpty == FALSE)
			{
				printf("\n ID Cliente: %d - Rubro: %d  - Aviso: %s - Estado: %s - ID Publicacion %d",pArrayPubli[i].idCliente, pArrayPubli[i].rubro,pArrayPubli[i].aviso,strEstado, pArrayPubli[i].id);
			}

		}

		retorno = 0;
	}
return retorno;
}


int publicacion_imprimirActivas (Publicacion * pArrayPubli , int limite , Cliente * pArrayCliente , int limiteCliente) {
	int retorno = -1;
	char strEstado[10];
	int flagActivas = 0;
	if (pArrayPubli != NULL && limite >0 && pArrayCliente != NULL && limiteCliente >0){
		for (int i=0 ; i<limite ; i++)
		{
			if (pArrayPubli[i].estado == PUBLICACION_ACTIVA)
			{
				strncpy(strEstado,"ACTIVA",10);
			}
			else
			{
				strncpy(strEstado,"PAUSADA",10);
			}


			if(pArrayPubli[i].isEmpty == FALSE && pArrayPubli[i].estado == PUBLICACION_ACTIVA)
			{
				printf("\n ID Cliente: %d - Rubro: %d  - Aviso: %s - Estado: %s - ID Publicacion %d",pArrayPubli[i].idCliente, pArrayPubli[i].rubro,pArrayPubli[i].aviso,strEstado, pArrayPubli[i].id);
				flagActivas =1;
			}

		}
		if (flagActivas==0)
		{
			printf("No hay publicaciones ACTIVAS");
		}

		retorno = 0;
	}
return retorno;
}


int publicacion_imprimirPausadas (Publicacion * pArrayPubli , int limite , Cliente * pArrayCliente , int limiteCliente) {
	int retorno = -1;
	char strEstado[10];
	int flagPausadas = 0;
	if (pArrayPubli != NULL && limite >0 && pArrayCliente != NULL && limiteCliente >0){
		for (int i=0 ; i<limite ; i++)
		{
			if (pArrayPubli[i].estado == PUBLICACION_ACTIVA)
			{
				strncpy(strEstado,"ACTIVA",10);
			}
			else
			{
				strncpy(strEstado,"PAUSADA",10);
			}


			if(pArrayPubli[i].isEmpty == FALSE && pArrayPubli[i].estado == PUBLICACION_PAUSADA)
			{
				printf("\n ID Cliente: %d - Rubro: %d  - Aviso: %s - Estado: %s - ID Publicacion %d",pArrayPubli[i].idCliente, pArrayPubli[i].rubro,pArrayPubli[i].aviso,strEstado, pArrayPubli[i].id);
				flagPausadas =1;
			}

		}
		if (flagPausadas==0)
		{
			printf("No hay publicaciones PAUSADAS");
		}

		retorno = 0;
	}
return retorno;
}






int publicacion_pausar (Publicacion * pArrayPubli, int limite , Cliente * pArrayCliente, int limiteCliente){
	int retorno = -1;
	int idBuscar;
	int indice;
	if (pArrayPubli != NULL && limite>0)
	{
		publicacion_imprimirActivas(pArrayPubli, limite,pArrayCliente, limiteCliente);
		if(utn_getNumero(&idBuscar,"Ingrese ID de Publicacion a Pausar","Error",0,9999,3)==0)
		{
			 if (publicacion_buscarIndicePorId(pArrayPubli, limite, idBuscar, &indice) == 0)
			 {
				 pArrayPubli[indice].estado = PUBLICACION_PAUSADA;
			 }
			 else
			 {
				 printf("Error - No se encuentra ese ID de Publicacion....");
			 }
		}
	}
	return retorno;
}


int publicacion_reanudar (Publicacion * pArrayPubli, int limite , Cliente * pArrayCliente, int limiteCliente){
	int retorno = -1;
	int idBuscar;
	int indice;
	if (pArrayPubli != NULL && limite>0)
	{
		publicacion_imprimirPausadas(pArrayPubli, limite,pArrayCliente, limiteCliente);
		if(utn_getNumero(&idBuscar,"Ingrese ID de Publicacion a Reanudar","Error",0,9999,3)==0)
		{
			 if (publicacion_buscarIndicePorId(pArrayPubli, limite, idBuscar, &indice) == 0)
			 {
				 pArrayPubli[indice].estado = PUBLICACION_ACTIVA;
			 }
			 else
			 {
				 printf("Error - No se encuentra ese ID de Publicacion....");
			 }
		}
	}
	return retorno;
}



/*

int publicacion_baja (Publicacion * pArrayPubli, int limite,Cliente * pArrayCliente, int limiteCliente){
	int retorno = -1;
	int cuitABorrar;
	int indiceABorrar;

	if (pArrayPubli != NULL && limite>0)
	{
		publicacion_imprimirTodas(pArrayPubli, limite,pArrayCliente, limiteCliente);
		if(utn_getNumero(&cuitABorrar,"Ingrese cuit a borrar","Error",0,9999,3)==0)
		{

			if(publicacion_buscarIndicePorCuit(pArrayPubli,limite,cuitABorrar,&indiceABorrar)==0)
			{
								pArrayPubli[indiceABorrar].isEmpty=TRUE;
			}
		}
	}
	return retorno;
}

// ver de no perder el ID y usar las nuevas FN
int publicacion_modificar (Publicacion * pArrayPubli, int limite,Cliente *pArrayCliente,int limiteCliente)
{
	int retorno = -1;
	int idBuscar;
	int cuitBuscar;
	int indiceAModificar;
	Publicacion bufferPublicacion;

	if (pArrayPubli != NULL && limite>0)
	{

		if(utn_getNumero(&cuitBuscar,"\nCUIT del cliente a modificar?:","ERROR!",0,9999,2)==0)
		{
			publicacion_imprimirPublicacionesPorCuit(pArrayPubli, limite, pArrayCliente, limiteCliente, cuitBuscar);
			utn_getNumero(&idBuscar, "\n Ingrese ID de publicacion a modificar ", "Error",0, 9999, 2);
			if(publicacion_buscarIndicePorId(pArrayPubli, limite,idBuscar,&indiceAModificar)==0)
			{
				bufferPublicacion = pArrayPubli[indiceAModificar]; // IMPORTANTE!

					if (utn_getNombre(bufferPublicacion.nombreArchivo,SIZE_NOMBRE , "\n Nombre del archivo?", "error",2) == 0 &&
						utn_getNumero(&bufferPublicacion.cantidadDias,"Ingrese cantidad de dias", "error",0,99999,2) == 0 &&
						utn_getNumero(&bufferPublicacion.idCliente,"Ingrese id de patalla","error",0,99999,2) == 0 &&
						pantalla_buscarIndicePorId(pArrayCliente, limiteCliente, bufferPublicacion.idCliente) != -1 )
					{

						pArrayPubli[indiceAModificar] = bufferPublicacion; // COPIAMOS AL ARRAY
						retorno = 0;
					}
				}
			}
		}
	return retorno;
	}


*/


int publicacion_buscarLibre (Publicacion * pArrayPubli, int limite){
	int retorno = -1;
	int i ;
		if (pArrayPubli != NULL && limite >0){
			for ( i = 0; i<limite; i++) {
				if(pArrayPubli[i].isEmpty == TRUE)
					{
					retorno = i;
					break;
					}
			}
		}
	return retorno;
}

int publicacion_buscarLibreRef (Publicacion * pArrayPubli, int limite, int * pIndice){
	int retorno = -1;
	int i ;
		if (pArrayPubli != NULL && limite >0 && pIndice != NULL){
			for ( i = 0; i<limite; i++) {
				if(pArrayPubli[i].isEmpty == TRUE)
					{
					*pIndice = i;
					retorno = 0;
					break;
					}
			}
		}
	return retorno;
}

static int publicacion_generarNuevoId (void) {
	static int id = 0;
	id = id+1;
	return id;
}

int publicacion_buscarIndicePorId (Publicacion * pArrayPubli, int limite,
		               int idBuscar,int * pIndice){
	int retorno = -1;
	int i ;
		if (pArrayPubli != NULL && limite >0 && pIndice != NULL && idBuscar >= 0)
		{
				for ( i = 0; i<limite; i++)
				{
					if(pArrayPubli[i].isEmpty == FALSE  &&
						pArrayPubli[i].id == idBuscar)
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

int publicacion_altaForzada(Publicacion * pArray, int limite ,int idCliente,int rubro,  char * aviso){

	int retorno = -1;
	int indice;
	if (publicacion_buscarLibreRef(pArray,limite, &indice) == 0)
	{
		strncpy(pArray[indice].aviso,aviso,SIZE_AVISO);
		pArray[indice].idCliente = idCliente;
		pArray[indice].rubro=rubro;
		pArray[indice].estado=PUBLICACION_ACTIVA;
		pArray[indice].id = publicacion_generarNuevoId();
		pArray[indice].isEmpty = FALSE;
		retorno=0;
	}
	return retorno;
}



/*
int publicacion_ordenarPorNombre (Publicacion * pArrayPubli, int limite , int orden)
{
	int retorno = -1;
	int estadoDesordenado = 1;
	Publicacion aux;
	if (pArrayPubli != NULL && limite >0){
	while(estadoDesordenado)//mientras este desordenado
	{
		estadoDesordenado = 0;
		for(int i = 0; i < (limite - 1); i++)
		{
			if((orden == 1 && strncmp(pArrayPubli[i].nombreArchivo, pArrayPubli[i + 1].nombreArchivo,SIZE_NOMBRE)>0)
					||
			  (orden == 0 && strncmp(pArrayPubli[i].nombreArchivo, pArrayPubli[i + 1].nombreArchivo,SIZE_NOMBRE)<0))
			{
				aux = pArrayPubli[i];
				pArrayPubli[i] = pArrayPubli[i + 1];
				pArrayPubli[i + 1] = aux;
				estadoDesordenado = 1;
			}
		}
	}
	retorno = 0;


	}
	return retorno;
}

int publicacion_buscarIndicePorCuit (Publicacion * pArrayPubli, int limite,
		               int cuitBuscar,int * pIndice){
	int retorno = -1;
	int i ;
		if (pArrayPubli != NULL && limite >0 && pIndice != NULL && cuitBuscar >= 0)
		{
				for ( i = 0; i<limite; i++)
				{
					if(pArrayPubli[i].isEmpty == FALSE  &&
						pArrayPubli[i].cuitCliente == cuitBuscar)
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

int publicacion_buscarIndicePorCuitYId (Publicacion * pArrayPubli, int limite,
		               int cuitBuscar, int id,int * pIndice){
	int retorno = -1;
	int i ;
		if (pArrayPubli != NULL && limite >0 && pIndice != NULL && cuitBuscar >= 0)
		{
				for ( i = 0; i<limite; i++)
				{
					if(pArrayPubli[i].isEmpty == FALSE  &&
						pArrayPubli[i].cuitCliente == cuitBuscar &&
						pArrayPubli[i].id == id	)
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



int publicacion_consultarFacturacion (Publicacion * pArrayPubli, int limite , Cliente * pArrayCliente , int limiteCliente){

	int retorno = -1;
	int cuitBuscar;
	publicacion_imprimir(pArrayPubli, limite,pArrayCliente, limiteCliente);
	if (utn_getNumero(&cuitBuscar, "Ingrese cuit del cliente","error", 0,99999, 2) == 0)
	{
		for (int i = 0 ; i<limite; i++)
		{
			if (cuitBuscar == pArrayPubli[i].cuitCliente)
			{
				//if (pArrayPubli[i].idCliente == )
			}
		}
	}


	return retorno;
}

i

int publicacion_imprimirPublicacionesPorCuit (Publicacion * pArrayPubli, int limite, Cliente * pArrayCliente , int limiteCliente, int cuit){
	int retorno =-1;
	int indiceCliente;
		if (pArrayPubli != NULL && limite > 0 && pArrayCliente != NULL && limiteCliente>0)
		{
			for(int i = 0; i<limite ; i++)
			{
				if (pArrayPubli[i].isEmpty == FALSE && pArrayPubli[i].cuitCliente ==  cuit)
				{
					retorno = 0;
					pantalla_buscarIndicePorIdRef(pArrayCliente, limiteCliente, pArrayPubli[i].idCliente, &indiceCliente);
					printf("\nNombre Archivo: %s - Cuit: %d - Cantidad de dias %d -ID Publicacion %d ",pArrayPubli[i].nombreArchivo,pArrayPubli[i].cuitCliente , pArrayPubli[i].cantidadDias, pArrayPubli[i].id);
					pantalla_imprimirPorIndice(pArrayCliente, limiteCliente,indiceCliente);
				}
			}
		}

	return retorno;
}

int publicacion_ConsultarPrecioPorCuit (Publicacion * pArrayPubli, int limite, Cliente * pArrayCliente , int limiteCliente){
	int retorno =-1;
	int indiceCliente;
	int cuit;
		if (pArrayPubli != NULL && limite > 0 && pArrayCliente != NULL && limiteCliente>0)
		{
			if(utn_getNumero(&cuit, "Ingrese CUIT", "Error", 0,99999,2)==0)
			{
				for(int i = 0; i<limite ; i++)
				{
					if (pArrayPubli[i].isEmpty == FALSE && pArrayPubli[i].cuitCliente ==  cuit)
					{
						retorno = 0;
						pantalla_buscarIndicePorIdRef(pArrayCliente, limiteCliente, pArrayPubli[i].idCliente, &indiceCliente);
						printf("\nNombre Archivo: %s - Cuit: %d - Cantidad de dias %d -ID Publicacion %d ",pArrayPubli[i].nombreArchivo,pArrayPubli[i].cuitCliente , pArrayPubli[i].cantidadDias, pArrayPubli[i].id);
						pantalla_imprimirPrecioPorIndice(pArrayCliente, limiteCliente,indiceCliente);
					}
					else
					{
						printf("No se encontrò el cuit");
						break;
					}
				}
			}
		}

	return retorno;
}


int publicacion_calcularCantContra(Publicacion * pArray, int limite , int cuit){
	int retorno = -1;
	int cantidadCont=0;
	for (int i = 0; i<limite; i++)
	{
		if (pArray[i].cuitCliente == cuit)
		{
			cantidadCont++;
		}
	}
	return retorno;
}

float publicacion_calcularImporteAPagar(Publicacion * pArrayPubli, int limite, Cliente * pArrayCliente , int limiteCliente, int cuit , int idCont) {
	float retorno = -1;
	int indice;
	int indiceCliente;
	float total;
	if (publicacion_buscarIndicePorCuitYId(pArrayPubli, limite, cuit, idCont, &indice)==0)
	{
		pantalla_buscarIndicePorIdRef(pArrayCliente, limiteCliente, pArrayPubli[indice].idCliente, &indiceCliente);
		total = (pArrayCliente[indiceCliente].precio) * (pArrayPubli[indice].cantidadDias);
		retorno = total;

	} else {
		printf("error");
	}


	return retorno;
}


void publicacion_listarClientes (Publicacion * pArrayPubli , int limite) {
	int arrayCuits[1000];
	int flagCuit = 0;
	int indiceCuitLibre=0;
	for (int j = 0 ; j<1000;j++){
		arrayCuits[j] = 0;
	}

	for (int i = 0 ; i<limite; i++)
	{

		flagCuit=0;
		for (int x = 0 ; x<=indiceCuitLibre;x++)
		{
			if (pArrayPubli[i].cuitCliente == arrayCuits[x])
			{
				flagCuit=1 ;
				break;
			}
		}
		if (flagCuit==0 && pArrayPubli[i].isEmpty == FALSE)
		{
			arrayCuits[indiceCuitLibre] = pArrayPubli[i].cuitCliente;
			indiceCuitLibre++;
		}
	}

	for (int x = 0 ; x<=indiceCuitLibre;x++)
	{
		if (arrayCuits[x]!=0)
		{
			printf("Cuit: %d \n", arrayCuits[x]);
		}

	}

}






*/







