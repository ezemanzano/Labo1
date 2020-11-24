
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "post.h"
#include "usuario.h"



int controller_loadFromPost(char* path , LinkedList* pArrayListPost)
{
	int retorno=-1;
	FILE* pFile;
	if (pArrayListPost!=NULL)
	{
		pFile = fopen(path,"r");
		if (pFile == NULL)
		{
			printf("error");
			retorno=-1;
		}
		if (parser_postFromText(pFile, pArrayListPost)==0)
		{
			printf("\n-Carga de datos Correcta-");
			retorno =0;
		}
	}
return retorno;
}


int controller_loadFromTextUsers(char* path , LinkedList* pArrayListUsers)
{
	int retorno=-1;
	FILE* pFile;
	if (pArrayListUsers!=NULL)
	{
		pFile = fopen(path,"r");
		if (pFile == NULL)
		{
			printf("error");
			retorno=-1;
		}
		if (parser_UsuariosFromText(pFile, pArrayListUsers)==0)
		{
			printf("\n-Carga de datos Correcta-");
			retorno =0;
		}
	}
return retorno;
}

int controller_sortUsers(void*thisA, void*thisB)
{
	Usuario  * usuarioA= thisA;
	Usuario * usuarioB= thisB;
	int retorno=-1;
	int popularidadA=-1;
	int popularidadB=-1;
	popularidadA=usuario_getPopularidadUsuario(usuarioA);
	popularidadB=usuario_getPopularidadUsuario(usuarioB);
	if (popularidadA>=0 &&	popularidadB>=0)
	{

		if (popularidadA>popularidadB)
		{
			retorno =1;
		}
		else if (popularidadA<popularidadB)
		{
			retorno =-1;
		}
		else
		{
			retorno =0;
		}
	}


	return retorno;
}
