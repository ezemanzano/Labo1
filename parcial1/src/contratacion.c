/*
 * contratacion.c
 *
 *  Created on: Sep 22, 2020
 *      Author: ezemanzano
 */
#include "contratacion.h"

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"

static int contratacion_generarNuevoId (void);
//static void contratacion_buscarTotal (Contratacion * pArrays , int limite , Pantalla * pArrayPantalla , int limitePantalla , int indicePantalla , int indice ,int * total);
int contratacion_init(Contratacion * pArrays, int limite){
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


int contratacion_alta (Contratacion * pArrays, int limite, Pantalla * pArrayPantalla , int limitePantalla)
{
	int retorno = -1;
	int indice;

	Contratacion bufferContratacion;
	if (pArrays != NULL && limite >0)
	{
		if (contratacion_buscarLibreRef (pArrays, limite, &indice) == 0)
		{
		pantalla_imprimir(pArrayPantalla,limitePantalla);
				if (utn_getNumero(&bufferContratacion.idPantalla,"Ingrese id de patalla","error",0,99999,2) == 0 &&
					pantalla_buscarIndicePorId(pArrayPantalla, limitePantalla, bufferContratacion.idPantalla) != -1 &&
					utn_getNombre(bufferContratacion.nombreArchivo,SIZE_NOMBRE , "\n Nombre del archivo?", "error",2) == 0 &&
					utn_getNumero(&bufferContratacion.cuitCliente,"Ingrese CUIT del cliente", "error",0,99999,2) == 0 &&
					utn_getNumero(&bufferContratacion.cantidadDias,"Ingrese cantidad de dìas", "error",0,99999,2) == 0
					 )

				{
						pArrays[indice] = bufferContratacion;
						pArrays[indice].id = contratacion_generarNuevoId();
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


int contratacion_imprimir (Contratacion * pArrays , int limite , Pantalla * pArrayPantalla , int limitePantalla) {
	int retorno = -1;
	int indicePantalla;
	if (pArrays != NULL && limite >0 && pArrayPantalla != NULL && limitePantalla >0){
		for (int i=0 ; i<limite ; i++)
		{
			if(pArrays[i].isEmpty == FALSE)
			{
				pantalla_buscarIndicePorIdRef(pArrayPantalla, limitePantalla, pArrays[i].idPantalla, &indicePantalla);
				printf("\nNombre Archivo: %s - Cuit: %d - Cantidad de dias %d -ID Contratacion %d ",pArrays[i].nombreArchivo,pArrays[i].cuitCliente , pArrays[i].cantidadDias, pArrays[i].id);
				pantalla_imprimirPorIndice(pArrayPantalla, limitePantalla,indicePantalla);
			}

		}

		retorno = 0;
	}
return retorno;
}





int contratacion_baja (Contratacion * pArrays, int limite,Pantalla * pArrayPantalla, int limitePantalla){
	int retorno = -1;
	int cuitABorrar;
	int indiceABorrar;

	if (pArrays != NULL && limite>0)
	{
		contratacion_imprimir(pArrays, limite,pArrayPantalla, limitePantalla);
		if(utn_getNumero(&cuitABorrar,"Ingrese cuit a borrar","Error",0,9999,3)==0)
		{

			if(contratacion_buscarIndicePorCuit(pArrays,limite,cuitABorrar,&indiceABorrar)==0)
			{
								pArrays[indiceABorrar].isEmpty=TRUE;
			}
		}
	}
	return retorno;
}

// ver de no perder el ID y usar las nuevas FN
int contratacion_modificar (Contratacion * pArrays, int limite,Pantalla *pArrayPantalla,int limitePantalla)
{
	int retorno = -1;
	int idBuscar;
	int cuitBuscar;
	int indiceAModificar;
	Contratacion bufferContratacion;

	if (pArrays != NULL && limite>0)
	{

		if(utn_getNumero(&cuitBuscar,"\nCUIT del cliente a modificar?:","ERROR!",0,9999,2)==0)
		{
			contratacion_imprimirContratacionesPorCuit(pArrays, limite, pArrayPantalla, limitePantalla, cuitBuscar);
			utn_getNumero(&idBuscar, "\n Ingrese ID de contratacion a modificar ", "Error",0, 9999, 2);
			if(contratacion_buscarIndicePorId(pArrays, limite,idBuscar,&indiceAModificar)==0)
			{
				bufferContratacion = pArrays[indiceAModificar]; // IMPORTANTE!

					if (utn_getNombre(bufferContratacion.nombreArchivo,SIZE_NOMBRE , "\n Nombre del archivo?", "error",2) == 0 &&
						utn_getNumero(&bufferContratacion.cantidadDias,"Ingrese cantidad de dias", "error",0,99999,2) == 0 &&
						utn_getNumero(&bufferContratacion.idPantalla,"Ingrese id de patalla","error",0,99999,2) == 0 &&
						pantalla_buscarIndicePorId(pArrayPantalla, limitePantalla, bufferContratacion.idPantalla) != -1 )
					{

						pArrays[indiceAModificar] = bufferContratacion; // COPIAMOS AL ARRAY
						retorno = 0;
					}
				}
			}
		}
	return retorno;
	}





int contratacion_buscarLibre (Contratacion * pArrays, int limite){
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

int contratacion_buscarLibreRef (Contratacion * pArrays, int limite, int * pIndice){
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

static int contratacion_generarNuevoId (void) {
	static int id = 0;
	id = id+1;
	return id;
}

int contratacion_buscarIndicePorId (Contratacion * pArrays, int limite,
		               int idBuscar,int * pIndice){
	int retorno = -1;
	int i ;
		if (pArrays != NULL && limite >0 && pIndice != NULL && idBuscar >= 0)
		{
				for ( i = 0; i<limite; i++)
				{
					if(pArrays[i].isEmpty == FALSE  &&
						pArrays[i].id == idBuscar)
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

int contratacion_ordenarPorNombre (Contratacion * pArrays, int limite , int orden)
{
	int retorno = -1;
	int estadoDesordenado = 1;
	Contratacion aux;
	if (pArrays != NULL && limite >0){
	while(estadoDesordenado)//mientras este desordenado
	{
		estadoDesordenado = 0;
		for(int i = 0; i < (limite - 1); i++)
		{
			if((orden == 1 && strncmp(pArrays[i].nombreArchivo, pArrays[i + 1].nombreArchivo,SIZE_NOMBRE)>0)
					||
			  (orden == 0 && strncmp(pArrays[i].nombreArchivo, pArrays[i + 1].nombreArchivo,SIZE_NOMBRE)<0))
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

int contratacion_buscarIndicePorCuit (Contratacion * pArrays, int limite,
		               int cuitBuscar,int * pIndice){
	int retorno = -1;
	int i ;
		if (pArrays != NULL && limite >0 && pIndice != NULL && cuitBuscar >= 0)
		{
				for ( i = 0; i<limite; i++)
				{
					if(pArrays[i].isEmpty == FALSE  &&
						pArrays[i].cuitCliente == cuitBuscar)
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

int contratacion_buscarIndicePorCuitYId (Contratacion * pArrays, int limite,
		               int cuitBuscar, int id,int * pIndice){
	int retorno = -1;
	int i ;
		if (pArrays != NULL && limite >0 && pIndice != NULL && cuitBuscar >= 0)
		{
				for ( i = 0; i<limite; i++)
				{
					if(pArrays[i].isEmpty == FALSE  &&
						pArrays[i].cuitCliente == cuitBuscar &&
						pArrays[i].id == id	)
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



int contratacion_consultarFacturacion (Contratacion * pArrays, int limite , Pantalla * pArrayPantalla , int limitePantalla){

	int retorno = -1;
	int cuitBuscar;
	contratacion_imprimir(pArrays, limite,pArrayPantalla, limitePantalla);
	if (utn_getNumero(&cuitBuscar, "Ingrese cuit del cliente","error", 0,99999, 2) == 0)
	{
		for (int i = 0 ; i<limite; i++)
		{
			if (cuitBuscar == pArrays[i].cuitCliente)
			{
				//if (pArrays[i].idPantalla == )
			}
		}
	}


	return retorno;
}

int contratacion_altaForzada(Contratacion * pArray, int limite , char * nombre, int  dias , int cuit, int idPantalla){

	int retorno = -1;
	int indice;
	if (contratacion_buscarLibreRef(pArray,limite, &indice) == 0){
		strncpy(pArray[indice].nombreArchivo,nombre,SIZE_NOMBRE);
		pArray[indice].cantidadDias = dias;
		pArray[indice].cuitCliente = cuit;
		pArray[indice].idPantalla = idPantalla;
		pArray[indice].id = contratacion_generarNuevoId();
		pArray[indice].isEmpty = FALSE;
	}
	return retorno;
}

int contratacion_imprimirContratacionesPorCuit (Contratacion * pArrays, int limite, Pantalla * pArrayPantalla , int limitePantalla, int cuit){
	int retorno =-1;
	int indicePantalla;
		if (pArrays != NULL && limite > 0 && pArrayPantalla != NULL && limitePantalla>0)
		{
			for(int i = 0; i<limite ; i++)
			{
				if (pArrays[i].isEmpty == FALSE && pArrays[i].cuitCliente ==  cuit)
				{
					retorno = 0;
					pantalla_buscarIndicePorIdRef(pArrayPantalla, limitePantalla, pArrays[i].idPantalla, &indicePantalla);
					printf("\nNombre Archivo: %s - Cuit: %d - Cantidad de dias %d -ID Contratacion %d ",pArrays[i].nombreArchivo,pArrays[i].cuitCliente , pArrays[i].cantidadDias, pArrays[i].id);
					pantalla_imprimirPorIndice(pArrayPantalla, limitePantalla,indicePantalla);
				}
			}
		}

	return retorno;
}

int contratacion_ConsultarPrecioPorCuit (Contratacion * pArrays, int limite, Pantalla * pArrayPantalla , int limitePantalla){
	int retorno =-1;
	int indicePantalla;
	int cuit;
		if (pArrays != NULL && limite > 0 && pArrayPantalla != NULL && limitePantalla>0)
		{
			if(utn_getNumero(&cuit, "Ingrese CUIT", "Error", 0,99999,2)==0)
			{
				for(int i = 0; i<limite ; i++)
				{
					if (pArrays[i].isEmpty == FALSE && pArrays[i].cuitCliente ==  cuit)
					{
						retorno = 0;
						pantalla_buscarIndicePorIdRef(pArrayPantalla, limitePantalla, pArrays[i].idPantalla, &indicePantalla);
						printf("\nNombre Archivo: %s - Cuit: %d - Cantidad de dias %d -ID Contratacion %d ",pArrays[i].nombreArchivo,pArrays[i].cuitCliente , pArrays[i].cantidadDias, pArrays[i].id);
						pantalla_imprimirPrecioPorIndice(pArrayPantalla, limitePantalla,indicePantalla);
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


int contratacion_calcularCantContra(Contratacion * pArray, int limite , int cuit){
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

float contratacion_calcularImporteAPagar(Contratacion * pArrays, int limite, Pantalla * pArrayPantalla , int limitePantalla, int cuit , int idCont) {
	float retorno = -1;
	int indice;
	int indicePantalla;
	float total;
	if (contratacion_buscarIndicePorCuitYId(pArrays, limite, cuit, idCont, &indice)==0)
	{
		pantalla_buscarIndicePorIdRef(pArrayPantalla, limitePantalla, pArrays[indice].idPantalla, &indicePantalla);
		total = (pArrayPantalla[indicePantalla].precio) * (pArrays[indice].cantidadDias);
		retorno = total;

	} else {
		printf("error");
	}


	return retorno;
}


void contratacion_listarClientes (Contratacion * pArrays , int limite) {
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
			if (pArrays[i].cuitCliente == arrayCuits[x])
			{
				flagCuit=1 ;
				break;
			}
		}
		if (flagCuit==0 && pArrays[i].isEmpty == FALSE)
		{
			arrayCuits[indiceCuitLibre] = pArrays[i].cuitCliente;
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















