#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "ventas.h"
#include "parser.h"
#include "utn.h"

static int isValidIdVenta(int idVenta);
static int isValidEstadoVenta(int estadoVenta);
static int isValidCantidadAfiches(int cantidadAfiches);
static int  isValidIdCliente(int idCliente);
static int isValidEstadoVenta(int estadoVenta);
static int isValidNombreDelArchivo(char* nombreDelArchivo);
static int isValidZona(int zona);


Ventas* ventas_new(void)
{
	return (Ventas*)malloc(sizeof(Ventas));
}

Ventas* ventas_newParam(int idVenta,int idCliente, int cantidadAfiches, char* nombreDelArchivo, int zona, int estadoVenta)
{
	Ventas* this = ventas_new();

	if(this != NULL)
	{
		if(!(ventas_setIdVenta(this, idVenta))
			&&!(ventas_setIdCliente(this, idCliente))
			&& !(ventas_setCantidadAfiches(this, cantidadAfiches))
			&& !(ventas_setNombreDelArchivo(this, nombreDelArchivo))
			&& !(ventas_setZona(this, zona))
			&& !(ventas_setEstadoVenta(this, estadoVenta)))
		{
			return this;
		}
	}
	return NULL;
}

int ventas_getIdVenta(Ventas* this, int * idVenta)
{
	if (this!=NULL)
	{
		*idVenta = this->idVenta;
		return 0;
	}
	return -1;
}

int ventas_setIdVenta(Ventas* this, int idVenta)
{
	int output = -1;
	if(this != NULL  && isValidIdVenta(idVenta))
	{

		this->idVenta = idVenta;
		output = 0;
	}
	 return output;
}

static int isValidIdVenta(int idVenta)
{
 if (idVenta>0)
 {
	 return 1;
 }
 return 0;
}





int ventas_getIdCliente(Ventas* this, int * idCliente)
{
	if (this!=NULL)
	{
		*idCliente = this->idCliente;
		return 0;
	}
	return -1;
}

int ventas_setIdCliente(Ventas* this, int idCliente)
{
	int output = -1;
	if(this != NULL  && isValidIdCliente(idCliente))
	{

		this->idCliente = idCliente;
		output = 0;
	}
	 return output;
}

static int isValidIdCliente(int idCliente)
{
 if (idCliente>0)
 {
	 return 1;
 }
 return 0;
}

int ventas_getCantidadAfiches(Ventas* this, int * cantidadAfiches)
{
	if (this!=NULL)
	{
		*cantidadAfiches =this->cantidadAfiches;
		return 0;
	}
	return -1;
}

int ventas_setCantidadAfiches(Ventas* this, int cantidadAfiches)
{
	int output = -1;
	if(this != NULL  && isValidCantidadAfiches(cantidadAfiches))
	{

		this->cantidadAfiches = cantidadAfiches;
		output = 0;
	}
	 return output;
}

static int isValidCantidadAfiches(int cantidadAfiches)
{
	if (cantidadAfiches>0)
	{
		return 1;
	}
	return -1;

}

int  ventas_getNombreDelArchivo(Ventas* this, char * nombreDelArchivo)
{
	if (this!=NULL)
	{
		strncpy(nombreDelArchivo,this->nombreDelArchivo,(int)sizeof(this->nombreDelArchivo));
		return 0;
	}
	return -1;
}

int ventas_setNombreDelArchivo(Ventas* this, char* nombreDelArchivo)
{
	int output = -1;
	if(this != NULL && isValidNombreDelArchivo(nombreDelArchivo))
	{
		strncpy(this->nombreDelArchivo,nombreDelArchivo,(int)sizeof(this->nombreDelArchivo));
		output = 0;
	}
	return output;
}

int isValidNombreDelArchivo(char* nombreDelArchivo)
{
	int retorno = 1;
		int contador = 0;

		int i ;
		for (i = 0 ; i<=strlen(nombreDelArchivo) && nombreDelArchivo[i] != '\0'; i++)
		{
			if	((nombreDelArchivo[i]< '0' || nombreDelArchivo[i] > '9') &&
				(nombreDelArchivo[i] < 'a' || nombreDelArchivo[i] > 'z') &&
				(nombreDelArchivo[i] < 'A' || nombreDelArchivo[i] > 'Z'))
			{
				if (nombreDelArchivo[i] == '.')
				{
					contador++;
					if (contador>1)
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

int ventas_getZona(Ventas* this , int * zona)
{
	if (this!=NULL)
		{
			*zona = this->zona;
			return 0;
		}
		return-1;
}

int ventas_setZona(Ventas* this, int zona)
{
	int output = -1;
	if(this != NULL  && isValidZona(zona))
	{
		this->zona = zona;
		output = 0;
	}
	 return output;
}

static int isValidZona(int zona)
{
	return 1;
	/*if(zona>=0 && zona <=2)

	{
		return 1;
	}
return 0;
*/
}

int ventas_getEstadoVenta(Ventas* this, int *estadoVenta)
{
	if (this!=NULL)
	{
		*estadoVenta =this->estadoVenta;
		return 0;
	}
	return 1;
}

int ventas_setEstadoVenta(Ventas* this, int estadoVenta)
{
	int output = -1;
	if(this != NULL  && isValidEstadoVenta(estadoVenta))
	{
		this->estadoVenta = estadoVenta;
		output = 0;
	}
	 return output;
}

static int isValidEstadoVenta(int estadoVenta)
{
	if (estadoVenta == 0 || estadoVenta ==1)
	{
		return 1;
	}
	return 0;
}

int ventas_imprimirTodos(void*thisA){
	Ventas * ventasA = thisA;
	int retorno =-1;
	int idAux;
	int idClienteAux;
	int cantidadAfichesAux;
	char nombreAux [128];
	int zonaAux;
	int estadoAux;
	char strZona[15];
	char strEstado[10];
	 if(!(ventas_getIdVenta(ventasA, &idAux))
		&&!(ventas_getIdCliente(ventasA, &idClienteAux))
		&&!(ventas_getCantidadAfiches(ventasA, &cantidadAfichesAux))
		&&!(ventas_getNombreDelArchivo(ventasA, nombreAux))
		&&!(ventas_getZona(ventasA, &zonaAux))
		&&!(ventas_getEstadoVenta(ventasA, &estadoAux)))
	{
		if (zonaAux == 0)
		{
			strcpy(strZona,"CABA");
		}
		else if (zonaAux == 1)
		{
			strcpy(strZona,"ZONA SUR");
		}
		else
		{
			strcpy(strZona,"ZONA OESTE");
		}
		if (estadoAux == 0)
		{
			strcpy(strEstado,"A cobrar");
		}
		else
		{
			strcpy(strEstado,"Cobrada");
		}
		printf("\n %04d | %04d | %04d | %-30s | %01d - %-15s  | %10s | ", idAux, idClienteAux, cantidadAfichesAux,nombreAux,zonaAux,strZona,strEstado);
		retorno = 0;
	}


	return retorno;
}

int ventas_printOne(void*thisA, int idVenta)
{
	Ventas * ventasA = thisA;
	int retorno =-1;
	int idAux;
	int idClienteAux;
	int cantidadAfichesAux;
	char nombreAux [128];
	int zonaAux;
	int estadoAux;
	char strZona[15];
	char strEstado[10];
	 if(!(ventas_getIdVenta(ventasA, &idAux)) && (idVenta == idAux)
		&&!(ventas_getIdCliente(ventasA, &idClienteAux))
		&&!(ventas_getCantidadAfiches(ventasA, &cantidadAfichesAux))
		&&!(ventas_getNombreDelArchivo(ventasA, nombreAux))
		&&!(ventas_getZona(ventasA, &zonaAux))
		&&!(ventas_getEstadoVenta(ventasA, &estadoAux)))
	{
		if (zonaAux == 0)
		{
			strcpy(strZona,"CABA");
		}
		else if (zonaAux == 1)
		{
			strcpy(strZona,"ZONA SUR");
		}
		else
		{
			strcpy(strZona,"ZONA OESTE");
		}
		if (estadoAux == 0)
		{
			strcpy(strEstado,"A cobrar");
		}
		else
		{
			strcpy(strEstado,"Cobrada");
		}
		printf(" idVenta | idCliente | Cantidad afiches | Nombre del Archivo |    Zona       | Estado");
		printf("\n   %04d  | %04d      |   %04d           |%-18s  | %01d - %-10s| %10s | ", idAux, idClienteAux, cantidadAfichesAux,nombreAux,zonaAux,strZona,strEstado);
		retorno = 0;
	}


	return retorno;
}



int ventas_imprimirACobrar(void*thisA){
	Ventas * ventasA = thisA;
	int retorno =-1;
	int idAux;
	int idClienteAux;
	int cantidadAfichesAux;
	char nombreAux [128];
	int zonaAux;
	int estadoAux;
	char strZona[15];
	char strEstado[10];
	 if(!(ventas_getIdVenta(ventasA, &idAux))
		&&!(ventas_getIdCliente(ventasA, &idClienteAux))
		&&!(ventas_getCantidadAfiches(ventasA, &cantidadAfichesAux))
		&&!(ventas_getNombreDelArchivo(ventasA, nombreAux))
		&&!(ventas_getZona(ventasA, &zonaAux))
		&&!(ventas_getEstadoVenta(ventasA, &estadoAux))
		&& estadoAux == 0)
	{
		 if (zonaAux == 0)
		{
			strcpy(strZona,"CABA");
		}
		else if (zonaAux == 1)
		{
			strcpy(strZona,"ZONA SUR");
		}
		else
		{
			strcpy(strZona,"ZONA OESTE");
		}
		 if (estadoAux == 0)
		{
			strcpy(strEstado,"A cobrar");
		}


		printf("\n %04d | %04d | %04d | %-30s | %01d - %-15s | %10s | ", idAux, idClienteAux, cantidadAfichesAux,nombreAux,zonaAux,strZona,strEstado);
		retorno = 0;
	}


	return retorno;
}



int ventas_idExiste (LinkedList * pArrayListVentas, int idVenta)
{
	int retorno = -1;
	int idAux;
	if (pArrayListVentas!=NULL)
	{
		for (int i = 0;i<ll_len(pArrayListVentas);i++)
		{
			Ventas * ventasAux =ll_get(pArrayListVentas, i);
			if (ventas_getIdVenta(ventasAux, &idAux) == 0 && idAux == idVenta)
			{
				retorno = 0;
				break;
			}

		}
	}
	return retorno;
}


int ventas_imprimirCobradas(void*thisA){
	Ventas * ventasA = thisA;
	int retorno =-1;
	int idAux;
	int idClienteAux;
	int cantidadAfichesAux;
	char nombreAux [128];
	int zonaAux;
	int estadoAux;
	char strZona[15];
	char strEstado[10];
	 if(!(ventas_getIdVenta(ventasA, &idAux))
		&&!(ventas_getIdCliente(ventasA, &idClienteAux))
		&&!(ventas_getCantidadAfiches(ventasA, &cantidadAfichesAux))
		&&!(ventas_getNombreDelArchivo(ventasA, nombreAux))
		&&!(ventas_getZona(ventasA, &zonaAux))
		&&!(ventas_getEstadoVenta(ventasA, &estadoAux))
		&& estadoAux == 1)
	{
		 if (zonaAux == 0)
			{
				strcpy(strZona,"CABA");
			}
			else if (zonaAux == 1)
			{
				strcpy(strZona,"ZONA SUR");
			}
			else
			{
				strcpy(strZona,"ZONA OESTE");
			}
		 if (estadoAux == 1)
			{
				strcpy(strEstado," Cobrada");
			}

		printf("\n %04d | %04d | %04d | %-30s | %01d - %-15s | %10s | ", idAux, idClienteAux, cantidadAfichesAux,nombreAux,zonaAux,strZona,strEstado);
		retorno = 0;
	}


	return retorno;
}


int ventas_findbyId(void*thisA,int indice)
{
	int retorno = 0;
	int idAux;
	Ventas * ventas =(Ventas*)thisA;

	ventas_getIdVenta(ventas,&idAux);
	if (idAux == indice)
	{
		retorno =1;
	}
	return retorno;
}


int ventas_filtrarPorCobradas(void*thisA, int Cobradas)
{
	Ventas* ventasAux=thisA;
	int retorno = -1;
	int estadoAux;
	ventas_getEstadoVenta(ventasAux, &estadoAux);
	if (estadoAux == Cobradas)
	{
		retorno=0;
	}
	else
	{
		retorno =1;
	}
	return retorno;
}

int ventas_findMaxAfiches (LinkedList * pArrayListVentas)
{
	int retorno =-1;
	int maxAfiches;
	int estado;
	int afichesAux;
	Ventas * ventasAux;
	for (int i = 0; i<ll_len(pArrayListVentas);i++)
	{
		ventasAux = ll_get(pArrayListVentas, i);
		ventas_getCantidadAfiches(ventasAux, &afichesAux);
		ventas_getEstadoVenta(ventasAux, &estado);
		if (i == 0 || (estado ==1 &&afichesAux>=maxAfiches))
		{
			maxAfiches = afichesAux;
			retorno = i;
		}
	}
	return retorno;
}



int ventas_cobradasPorCliente(void* thisA, int idCliente)
{
	Ventas* ventasAux=thisA;
		int retorno = 0;
		int estadoAux;
		int idClienteAux;
		ventas_getEstadoVenta(ventasAux, &estadoAux);
		ventas_getIdCliente(ventasAux, &idClienteAux);
		if (idCliente == idClienteAux && estadoAux == 0)
		{
			retorno=1;
		}

		return retorno;
}


int ventas_aCobrarPorCliente(void* thisA, int idCliente)
{
	Ventas* ventasAux=thisA;
		int retorno = 0;
		int estadoAux;
		int idClienteAux;
		ventas_getEstadoVenta(ventasAux, &estadoAux);
		ventas_getIdCliente(ventasAux, &idClienteAux);
		if (idCliente == idClienteAux && estadoAux == 1)
		{
			retorno=1;
		}

return retorno;
}

