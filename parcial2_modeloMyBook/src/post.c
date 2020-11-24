/*
 * post.c
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
#include "post.h"

Post* post_new(void)
{
	return (Post*)malloc(sizeof(Post));
}

Post* post_newParam(int idPost,int idUsuario, int popularidadMensaje, char* mensajePost)
{
	Post* this = post_new();
	if(this != NULL)
	{
		if(!(post_setIdPost(this, idPost))
			&& !(post_setPopularidadMensaje(this, popularidadMensaje))
			&& !(post_setMensajePost(this, mensajePost))
			&& !(post_setIdUsuarioPost(this, idUsuario)))
		{
			return this;
		}
	}
	return NULL;
}

int post_getIdPost(Post* this)
{
	return this->idPost;
}

int post_setIdPost(Post* this, int idPost)
{
	int output = -1;
	if(this != NULL  && isValidIdPost(idPost)==1)
	{
		this->idPost = idPost;
		output = 0;
	}
	 return output;
}

int isValidIdPost(int idPost)
{
	if (idPost>0)
	{
		return 1;
	}
	return 0;
}

int post_getIdUsuarioPost(Post* this)
{
	return this->idUsuario;
}

int post_setIdUsuarioPost(Post* this, int idUserPost)
{
	int output = -1;
	if(this != NULL )
	{
		this->idUsuario = idUserPost;
		output = 0;
	}
	 return output;
}

int isValidIdUsuarioPost(int idPost)
{
	return 1;
}


int post_getPopularidadMensaje(Post* this)
{
	return this->popularidadMensaje;
}

int post_setPopularidadMensaje(Post* this, int popularidadMensaje)
{
	int output = -1;
	if(this != NULL && isValidPopularidadMensaje(popularidadMensaje)==1)
	{
		this->popularidadMensaje = popularidadMensaje;
		output = 0;
	}
	 return output;
}

int isValidPopularidadMensaje(int popularidadMensaje)
{
	if (popularidadMensaje>=0)
	{
		return 1;
	}
	return 0;
}

char* post_getMensajePost(Post* this)
{
	return this->mensajePost;
}

int post_setMensajePost(Post* this, char* mensajePost)
{
	int output = -1;
	if(this != NULL && isValidMensajePost(mensajePost))
	{
		strncpy(this->mensajePost,mensajePost,(int)sizeof(this->mensajePost));
		output = 0;
	}
	return output;
}

int isValidMensajePost(char* mensajePost)
{
	return 1;
}


int post_imprimirTodos(void*thisA){
	Post *EnvioA = thisA;

	int retorno =-1;
	int idAux =post_getIdPost(EnvioA);
	int idUsuarioAux= post_getIdUsuarioPost(EnvioA);
	char mensajeAux[50000];
	strcpy(mensajeAux,post_getMensajePost(EnvioA));
	int popularidadAux = post_getPopularidadMensaje(EnvioA);

	printf(" %04d | %-15d | %-6d | %s    \n", idAux, idUsuarioAux, popularidadAux,mensajeAux);
	retorno = 0;



	return retorno;
}
