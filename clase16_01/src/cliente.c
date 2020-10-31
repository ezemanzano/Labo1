/*
 * cliente.c
 *
 *  Created on: Sep 22, 2020
 *      Author: ezemanzano
 */


#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "cliente.h"

static int cliente_generarNuevoId (void);
static int esNombre (char*cadena, int limite);
static int esCuit(char*cadena, int limite);

/**
 * \brief Inicializa el array de clientes
 * \param Cliente * pArrayCliente  Es el puntero al array de cliente
 * \param int limiteCliente, es el tamaño de array de clientes
  * \return (-1) Error / (0) Ok
 *
 */

int cliente_init(Cliente * pArrays[], int limite){
	int retorno = -1;
	if (pArrays != NULL && limite >0){
		for (int i = 0; i<limite; i++ )
		{
			pArrays[i]=NULL;
		}
		retorno = 0;
	}

	return retorno;
}
/**
 * \brief Da de alta un clinete pidiendole los datos al usuario.-
 * \param Cliente * pArrayCliente  Es el puntero al array de cliente
 * \param int limiteCliente, es el tamaño de array de clientes
 * \return (-1) Error / (0) Ok
  */

int cliente_alta (Cliente * pArrays[], int limite)
{
	int retorno = -1;
	int indice;

	Cliente bufferCliente;
	if (pArrays != NULL && limite >0)
	{

		if (cliente_buscarPunteroLibreRef (pArrays, limite, &indice) == 0)
		{
				if (utn_getNombre(bufferCliente.nombre,SIZE_NOMBRE , "\n Nombre?", "\n ERROR",2) == 0 &&
					utn_getNombre(bufferCliente.apellido, SIZE_NOMBRE, " \n Apellido?","\n ERROR",3) == 0 &&
					utn_getCuit(bufferCliente.cuit, SIZE_CUIT,"\n Cuit?","\n ERROR",3) == 0)
				{
					pArrays[indice]=cli_new(bufferCliente.nombre, bufferCliente.apellido, bufferCliente.cuit);
					retorno = 0;
					printf("\n SUCCESS - Nuevo cliente OK");
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
 * \brief Modifica un clinete pidiendole los datos al usuario.-
 * \param Cliente * pArrayCliente  Es el puntero al array de cliente
 * \param int limiteCliente, es el tamaño de array de clientes
 * \return (-1) Error / (0) Ok
  */


int cliente_modificar (Cliente * pArrays[], int limite)
{
	int retorno = -1;
	int idBuscar;
	int indiceAModificar = -1;
	Cliente bufferCliente;

	if (pArrays != NULL && limite>0)
	{
		cliente_printAll(pArrays, limite);

		if(utn_getNumero(&idBuscar,"\n --- Ingrese ID del cliente a modificar ----:","\n ERROR!",0,9999,2)==0)
		{


			if(cliente_buscarIndicePorIdRef(pArrays, limite,idBuscar,&indiceAModificar) == 0)
			{
				cliente_getId(pArrays[indiceAModificar],&bufferCliente.id);

				if (utn_getNombre(bufferCliente.nombre, SIZE_NOMBRE ,"\n Nuevo nombre?", "\n ERROR",2) == 0 &&
					utn_getNombre(bufferCliente.apellido, SIZE_NOMBRE, " \n Ingrese nuevo apellido","ERROR",3) == 0 &&
					utn_getCuit(bufferCliente.cuit, SIZE_CUIT, "nuevo Cuit?", "\n ERROR", 2)==0)
					{
					cliente_setId(pArrays[indiceAModificar], cliente_generarNuevoId());
					cliente_setName(pArrays[indiceAModificar], bufferCliente.nombre, SIZE_NOMBRE);
					cliente_setLastname(pArrays[indiceAModificar],bufferCliente.apellido, SIZE_NOMBRE);
					cliente_setCuit(pArrays[indiceAModificar],bufferCliente.cuit,SIZE_CUIT);
						printf("\n Cliente Modificado.");
						retorno = 0;
					}
				}
			else
			{
				printf("\n No se encontrò un cliente con ese id. Vuelva a intentar");
			}
			}
		}
	return retorno;
}

int cliente_buscarIndicePorId (Cliente * pArrays[], int limite,int idBuscar){
	int retorno = -1;
	int i ;
	int id;
		if (pArrays != NULL && limite >0 && idBuscar >= 0)
		{
				for ( i = 0; i<limite; i++)
				{
					cliente_getId(pArrays[i], &id);
					if(id== idBuscar)
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



int cliente_buscarPunteroLibreRef (Cliente * pArrays[], int limite, int * pIndice){
	int retorno = -1;
	int i ;
		if (pArrays != NULL && limite >0 && pIndice != NULL){
			for ( i = 0; i<limite; i++) {
				if(pArrays[i]== NULL)
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
/**
 * \brief Busca el indice del cliente en el array de clientes en base al ID
 * \param Cliente * pArrayCliente  Es el puntero al array de cliente
 * \param int limiteCliente, es el tamaño de array de clientes
* \param int idBuscar, es el id de cliente a buscarle el indice.
 * \return (-1) Error / (0) Ok
  */

int cliente_buscarIndicePorIdRef (Cliente * pArrays[], int limite,int idBuscar, int * pIndice){
	int retorno = -1;
	int i ;
		if (pArrays != NULL && limite >0 && idBuscar >= 0 && pIndice!=NULL)
		{
				for ( i = 0; i<limite; i++)
				{
					if(pArrays[i]->id == idBuscar)
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
 * \brief Imprime la informacion del cliente
 * \param Cliente * pArrayCliente  Es el puntero al array de cliente
 * \param int limiteCliente, es el tamaño de array de clientes
 * \param int idCliente -> se da por parametro el id del cliente a imprimir
 * \return (-1) Error / (0) Ok
 *
 */

/*

int cliente_informacionCliente(Cliente * pArrayCliente, int limiteCliente, int idCliente){

	int retorno = 0;
	int indice;
	if (pArrayCliente!= NULL && limiteCliente>0 && idCliente>0)
	{
		cliente_buscarIndicePorIdRef (pArrayCliente, limiteCliente,idCliente,&indice);
		printf("\n Nombre: %s - Apellido: %s - Cuit: %s ",pArrayCliente[indice].nombre,pArrayCliente[indice].apellido,pArrayCliente[indice].cuit);
	}
	else
	{
		printf("\n ERROR");
	}

	return retorno;
}

/*/
/**
 * \brief Hardcode de un clinete
 * \param Cliente * pArrayCliente  Es el puntero al array de cliente
 * \param int limite, es el tamaño de array de clientes
 * \param char * nombre, nombre a guardar
 * \param char * apellido, apellido a guardar
 * \param char * cuit, cuit a guardar
 * \return (-1) Error / (0) Ok
  */

int cliente_altaForzada(Cliente * pArray[], char * nombre, char * apellido, char * cuit){

	int retorno = -1;
	int indice;
	cliente_buscarPunteroLibreRef(pArray,100,&indice);
	pArray[indice]=cli_new(nombre,apellido,cuit);
	retorno=0;

return retorno;
}

/**
 * \brief Chequea si hay algun cliente de alta para poder continuar
 * \param Cliente * pArrayCliente  Es el puntero al array de cliente
 * \param int limiteCliente, es el tamaño de array de clientes
 * \return (-1) Error / (1) Si lo hay
 *
 */

int cliente_sePuedeSeguir(Cliente * pArrayCliente[], int limiteCliente){
	int retorno = -1;
	if (pArrayCliente!=NULL && limiteCliente>0)
	{
		for (int i = 0; i<limiteCliente;i++)
		{
			if (pArrayCliente[i] != NULL)
			{
				retorno=1;
				break;
			}
		}
	}
return retorno;
}


/**
 * \brief Chequea si hay algun cliente de alta con el mismo cuit ingresado
 * \param Cliente * pArrayCliente  Es el puntero al array de cliente
 * \param int limiteCliente, es el tamaño de array de clientes
 * \param char * cuitIngresado, es el cuit a buscar entre los cuits ya existentes
 * \return (-1) Error / (1) Si lo hay
 *
 */
int cliente_noSeRepiteCuit(Cliente * pArrayCliente, int limiteCliente, char  * cuitIngresado){
	int retorno = -1;
	if (pArrayCliente!=NULL && limiteCliente>0)
	{
		for(int i = 0; i<limiteCliente;i++)
		{
			if(strncmp(cuitIngresado,pArrayCliente[i].cuit,SIZE_CUIT)==0)
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


Cliente * cli_new(char *name,  char * apellido, char * cuit){
	Cliente * pArray = NULL;
	pArray = (Cliente *)malloc(sizeof(Cliente));
	if (pArray!= NULL)
	{
		cliente_setId(pArray, cliente_generarNuevoId());
		cliente_setName(pArray, name, SIZE_NOMBRE);
		cliente_setLastname(pArray, apellido, SIZE_NOMBRE);
		cliente_setCuit(pArray,cuit,SIZE_CUIT);
	}

	return pArray;
}

int cliente_PrintOne(Cliente* pCliente)
{
    int output = -1;
    int id;
    char nombre[SIZE_NOMBRE];
    char apellido[SIZE_NOMBRE];
    char cuit [SIZE_CUIT];
    if(pCliente!=NULL)
    {
    	cliente_getName(pCliente, nombre, SIZE_NOMBRE);
    	cliente_getLastname(pCliente, apellido, SIZE_NOMBRE);
    	cliente_getCuit(pCliente, cuit, SIZE_CUIT);
    	cliente_getId(pCliente, &id);
    	printf("# %d %s %s %s\n", id,nombre,apellido,cuit);
        output = 0;
    }
    return output;
}


int cliente_printAll(Cliente* pArray[], int len)
{
    int output = -1;
    if (pArray != NULL && len > 0)
    {

        for (int x = 0; x < len; x++)
        {
            cliente_PrintOne(pArray[x]);
        }
        output = 0;
    }
    return output;
}

int cliente_setId(Cliente* pArray,int val)
{
	int ret=-1;
	if(pArray!=NULL && val>0)
	{
		pArray->id =val;
		ret=0;
	}
	return ret;
}

 int cliente_setName(Cliente* pArray,char* val, int size)
{
	int ret=-1;
	if(pArray!=NULL && val>0&& size>0&& esNombre(val, size))
	{
		strncpy(pArray->nombre,val,size);
		ret=0;
	}
	return ret;
}


int cliente_setLastname(Cliente* pArray,char * val, int size)
{
	int ret=-1;
	if(pArray!=NULL && val>0&& size>0 && esNombre(val, size))
	{
		strncpy(pArray->apellido,val,size);
		ret=0;
	}
	return ret;
}

int cliente_setCuit(Cliente* pArray,char * val, int size)
{
	int ret=-1;
	if(pArray!=NULL && val>0&& size>0 && esCuit(val, size))
	{
		strncpy(pArray->cuit,val,size);
		ret=0;
	}
	return ret;
}

int cliente_getId(Cliente* pArray, int* pVal)
{
	int ret=-1;
	if(pArray!=NULL)
	{
		*pVal = pArray->id;
		ret=0;
	}
	return ret;
}
int cliente_getName(Cliente* pArray,char * val, int size)
{
	int ret=-1;
	if(pArray!=NULL && val>0&& size>0)
	{
		strncpy(val,pArray->nombre,size);
		ret=0;
	}
	return ret;
}

int cliente_getLastname(Cliente* pArray,char * val, int size)
{
	int ret=-1;
	if(pArray!=NULL && val>0&& size>0)
	{
		strncpy(val,pArray->apellido,size);
		ret=0;
	}
	return ret;
}



int cliente_getCuit(Cliente* pArray,char * val, int size)
{
	int ret=-1;
	if(pArray!=NULL && val>0&& size>0)
	{
		strncpy(val,pArray->cuit,size);
		ret=0;
	}
	return ret;
}


static int esNombre (char*cadena, int limite) {
	int retorno = 1;
	int i ;
	for (i = 0 ; i<=limite && cadena[i] != '\0'; i++){
		if	((cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
		{
			retorno = 0;
			break;
		}}
	return retorno;
}

static int esCuit(char*cadena, int limite) {
	int retorno = 1;
	int contador = 0;
	int i ;
	for (i = 0 ; i<=limite && cadena[i] != '\0'; i++)
	{
		if	(cadena[i]< '0' || cadena[i] > '9')
		{
			if (cadena[i] == '-')
			{
				contador++;
				if (contador>2)
				{
					retorno = 0;
					break;
				}

			}
			else
			{
				retorno = 0;
				break;
			}


		}
	}
	return retorno;
}
