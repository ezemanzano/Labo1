/*
 * envio.c
 *
 *  Created on: Nov 13, 2020
 *      Author: ezemanzano
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "envio.h"
#include "parser.h"
#include "utn.h"

int envio_loadFromText(char* path , LinkedList* pArrayListEnvios)
{
	int retorno=-1;
	FILE* pFile;
	if (pArrayListEnvios!=NULL)
	{
		pFile = fopen(path,"r");
		if (pFile == NULL)
		{
			printf("error");
			retorno=-1;
		}
		if (parser_EnviosFromText(pFile, pArrayListEnvios)==0)
		{
			printf("\n-Carga de datos Correcta-");
			retorno =0;
		}
	}
return retorno;
}



Envio* envio_new(void)
{
	return (Envio*)malloc(sizeof(Envio));
}


Destino* destino_new(void)
{
	return (Destino*)malloc(sizeof(Destino));
}

Destino* destino_newParam( char * zona_destino)
{
	Destino* this = destino_new();
	if(this != NULL)
	{
		strncpy(this->zona_destino,zona_destino,(int)sizeof(Destino));
	return this;
	}
return NULL;
}



Envio* envio_newParam(int idProducto, char* nombre_producto, int id_camion, char * zona_destino, int km_recorridos, int tipo_entrega, int costo_envio)
{
	Envio* this = envio_new();
	if(this != NULL)
	{
		if(!(envio_setIdProducto(this, idProducto))
			&& !(envio_setNombre_producto(this, nombre_producto))
			&& !(envio_setId_camion(this, id_camion))
			&& !(envio_setZona_destino(this, zona_destino))
			&& !(envio_setKm_recorridos(this, km_recorridos))
			&& !(envio_setTipo_entrega(this, tipo_entrega))
			&& !(envio_setCosto_envio(this, costo_envio)))
		{
			return this;
		}
	}
	return NULL;
}

int envio_getIdProducto(Envio* this)
{
	return this->idProducto;
}

int envio_setIdProducto(Envio* this, int idProducto)
{
	int output = -1;
	if(this != NULL  && isValidIdProducto(idProducto))
	{
		this->idProducto = idProducto;
		output = 0;
	}
	 return output;
}

int isValidIdProducto(int idProducto)
{
	return 1;
}

int envio_getNombre_producto(Envio* this, char * nombre_producto)
{
	strncpy(nombre_producto, this->nombre_producto,(int)sizeof(this->nombre_producto));
	return 0;
}

int envio_setNombre_producto(Envio* this, char* nombre_producto)
{
	int output = -1;
	if(this != NULL && isValidNombre_producto(nombre_producto) == 1)
	{
		strncpy(this->nombre_producto,nombre_producto,(int)sizeof(this->nombre_producto));
		output = 0;
	}
	return output;
}

int isValidNombre_producto(char * nombre_producto)
{
	return 1;
}

int envio_getId_camion(Envio* this)
{
	return this->id_camion;
}

int envio_setId_camion(Envio* this, int id_camion)
{
	int output = -1;
	if(this != NULL  && isValidId_camion(id_camion))
	{
		this->id_camion = id_camion;
		output = 0;
	}
	 return output;
}

int isValidId_camion(int id_camion)
{
	return 1;
}

int envio_getZona_destino(Envio* this, char * zona_destino)
{
	strncpy(zona_destino, this->zona_destino,(int)sizeof(this->zona_destino));
	return 0;
}

int envio_setZona_destino(Envio* this, char* zona_destino)
{
	int output = -1;
	if(this != NULL && isValidZona_destino(zona_destino) == 1)
	{
		strncpy(this->zona_destino,zona_destino,(int)sizeof(this->zona_destino));
		output = 0;
	}
	return output;
}

int isValidZona_destino(char * zona_destino)
{
	return 1;
}

int envio_getKm_recorridos(Envio* this)
{
	return this->km_recorridos;
}

int envio_setKm_recorridos(Envio* this, int km_recorridos)
{
	int output = -1;
	if(this != NULL  && isValidKm_recorridos(km_recorridos))
	{
		this->km_recorridos = km_recorridos;
		output = 0;
	}
	 return output;
}

int isValidKm_recorridos(int km_recorridos)
{
	return 1;
}

int envio_getTipo_entrega(Envio* this)
{
	return this->tipo_entrega;
}

int envio_setTipo_entrega(Envio* this, int tipo_entrega)
{
	int output = -1;
	if(this != NULL  && isValidTipo_entrega(tipo_entrega))
	{
		this->tipo_entrega = tipo_entrega;
		output = 0;
	}
	 return output;
}

int isValidTipo_entrega(int tipo_entrega)
{
	return 1;
}

int envio_getCosto_envio(Envio* this)
{
	return this->costo_envio;
}

int envio_setCosto_envio(Envio* this, int costo_envio)
{
	int output = -1;
	if(this != NULL  &&	isValidCosto_envio(costo_envio))
	{
		this->costo_envio = costo_envio;
		output = 0;
	}
	 return output;
}

int isValidCosto_envio(int costo_envio)
{
	return 1;
}

int envio_imprimirTodos(void*thisA){
	Envio *EnvioA = thisA;
	int retorno =-1;
	int idAux =envio_getIdProducto(EnvioA);
	char nombreAux[128];
	int idCamionAux=envio_getId_camion(EnvioA);
	char zonaDestinoAux[128];
	int kmRecorridosAux=envio_getKm_recorridos(EnvioA);
	int tipoEntregaAux=envio_getTipo_entrega(EnvioA);
	int costoEnvioAux = envio_getCosto_envio(EnvioA);
	if(envio_getNombre_producto(EnvioA,nombreAux) == 0 && envio_getZona_destino(EnvioA, zonaDestinoAux)==0)
	{
		printf(" %04d | %-15s | %-6d | %-16s | %-6d | %-6d | %-6d  \n", idAux, nombreAux, idCamionAux, zonaDestinoAux,kmRecorridosAux,tipoEntregaAux, costoEnvioAux);
		retorno = 0;
	}


	return retorno;
}

int envio_calcularCostos(void*thisA)
{
	int retorno =-1;
	Envio*EnvioA=thisA;
	int kmRecorridosAux=envio_getKm_recorridos(EnvioA);
	int tipoEntregaAux=envio_getTipo_entrega(EnvioA);
	int costoEnvio;
	int costoFijo;
	if (kmRecorridosAux<50)
	{
		costoEnvio=150;
	}
	else
	{
		costoEnvio=100;
	}
	if (tipoEntregaAux==0)
	{
		costoFijo = 350;
	}else if (tipoEntregaAux==1)
	{
		costoFijo = 420;
	}
	else
	{
		costoFijo=275;
	}
	costoEnvio = (costoEnvio*kmRecorridosAux)+costoFijo;
	if (envio_setCosto_envio(EnvioA, costoEnvio)==0)
	{
		retorno = 0;
	}

return retorno;
}

int envio_filtrarPorZona(void*thisA, char* zonaFiltrar)
{
	Envio * pEnvio=thisA;
	int retorno = -1;
	char zonaAux[128];
	envio_getZona_destino(pEnvio, zonaAux);
	if (strcmp(zonaAux,zonaFiltrar)==0)
	{
		retorno=0;
	}
	else
	{
		retorno =1;
	}
	return retorno;
}

int envio_saveAsText(char* path , LinkedList* pArrayListEnvios)
{
	int retorno=-1;
	int idProductoAux;
	char nombreAux[128];
	int idCamionAux;
	char zonaAux[128];
	int kmAux;
	int tipoEntregaAux;
	int costoAux;
	int len = ll_len(pArrayListEnvios);
	Envio * envios;
	envios=envio_new();
	FILE* pFile;
	if (envios!=NULL&&pArrayListEnvios!=NULL&&len>0)
	{
		pFile = fopen(path,"w");
				fprintf(pFile,"id_producto, nombre_producto, id_camion, zona_destino, km_recorridos, tipo_entrega, costo_envio\n");
				for (int i= 0;i<len;i++)
				{
					envios=ll_get(pArrayListEnvios, i);

					idProductoAux=envio_getIdProducto(envios);
					envio_getNombre_producto(envios, nombreAux);
					idCamionAux= envio_getId_camion(envios);
					envio_getZona_destino(envios, zonaAux);
					kmAux=envio_getKm_recorridos(envios);
					tipoEntregaAux=envio_getTipo_entrega(envios);
					costoAux=envio_getCosto_envio(envios);

					fprintf(pFile,"%d,%s,%d,%s,%d,%d,%d\n",idProductoAux,nombreAux,idCamionAux,zonaAux,kmAux,tipoEntregaAux,costoAux);
					retorno=0;
				}
				printf("\nEl archivo fue guardado exitosamente..");
			}

	fclose(pFile);
return retorno;
}




int envio_listaDestinos(LinkedList* pArrayListEnvios, LinkedList * pArrayDestino)
{
	int retorno =-1;
	char zonaDestinoAux[128];
	Envio * envioAux;
	Destino * destinoNew;
	for (int i = 1;i<ll_len(pArrayListEnvios);i++)
	{
		envioAux = ll_get(pArrayListEnvios, i);
		envio_getZona_destino(envioAux, zonaDestinoAux);

		if (envios_isDestinoInList(zonaDestinoAux,pArrayDestino)==1)
		{
			destinoNew =destino_newParam(zonaDestinoAux);
			ll_add(pArrayDestino, destinoNew);
		}
	}
	return retorno;
}

int envios_isDestinoInList(char * destino, LinkedList * pArrayDestino){
int retorno=-1;
char zonaAux[128];
Destino * destinoAux;
if (ll_len(pArrayDestino)==0)
{
retorno =1;
}
else
{
for (int i = 0;i<ll_len(pArrayDestino);i++)
{

	destinoAux = ll_get(pArrayDestino, i);
	destino_getZona_destino(destinoAux, zonaAux);
	if(strcmp(zonaAux,destino)!=0)
	{
	retorno =1;
	}
	else
	{
	retorno=0;
	break;
	}
}
}
return retorno;
}

int destino_imprimirLista(void*thisA)
{
	int retorno =-1;
	Destino * destinoA=thisA;
	char zonaAux[128];
	destino_getZona_destino(destinoA,zonaAux);
	printf("\n%s",zonaAux);

	return retorno;
}

int destino_getZona_destino(Destino* this, char * zona_destino)
{
	strncpy(zona_destino, this->zona_destino,(int)sizeof(this->zona_destino));
	return 0;
}
