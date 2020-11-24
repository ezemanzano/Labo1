/*
 * usuario.c
 *
 *  Created on: Nov 17, 2020
 *      Author: ezemanzano
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "usuario.h"

Usuario* usuario_new(void)
{
	return (Usuario*)malloc(sizeof(Usuario));
}

Usuario* usuario_newParam(int idUsuario, char* nick , int popularidadUsuario)
{
	Usuario* this = usuario_new();
	if(this != NULL)
	{
		if(usuario_setIdUsuario(this, idUsuario) == 0 && !(usuario_setNick(this, nick))
			&& !(usuario_setPopularidadUsuario(this,popularidadUsuario)))
		{
			return this;
		}
	}
	return NULL;
}

int usuario_getIdUsuario(Usuario* this)
{
	return this->idUsuario;
}

int usuario_setIdUsuario(Usuario* this, int idUsuario)
{
	int output = -1;
	if(this != NULL  && isValidIdUsuario(idUsuario))
	{
		this->idUsuario = idUsuario;
		output = 0;
	}
	 return output;
}

int isValidIdUsuario(int idUsuario)
{
	if (idUsuario>0)
	{
		return 1;
	}
	return 0;
}

char* usuario_getNick(Usuario* this)
{
	return this->nick;
}

int usuario_setNick(Usuario* this, char* nick)
{
	int output = -1;
	if(this != NULL && isValidNick(nick))
	{
		strncpy(this->nick,nick,(int)sizeof(this->nick));
		output = 0;
	}
	return output;
}

int isValidNick(char* nick)
{
	return 1;
}

int usuario_getPopularidadUsuario(Usuario* this)
{
	return this->popularidadUsuario;
}

int usuario_setPopularidadUsuario(Usuario* this, int popularidadUsuario)
{
	int output = -1;
	if(this != NULL  && isValidPopularidadUsuario(popularidadUsuario))
	{
		this->popularidadUsuario = popularidadUsuario;
		output = 0;
	}
	 return output;
}

int isValidPopularidadUsuario(int popularidadUsuario)
{
	return 1;
}

int usuario_imprimirTodos(void*thisA){
	Usuario *UsuarioA = thisA;
	int retorno =-1;
	int idAux = usuario_getIdUsuario(UsuarioA);
	char nick[128];
	strcpy(nick,usuario_getNick(UsuarioA));
	int popularidadAux = usuario_getPopularidadUsuario(UsuarioA);

	printf(" %04d | %-15s | %-6d  \n", idAux,nick,popularidadAux);
	retorno = 0;
	return retorno;
}
