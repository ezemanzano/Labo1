/*
 * usuario.h
 *
 *  Created on: Nov 17, 2020
 *      Author: ezemanzano
 */

#ifndef USUARIO_H_
#define USUARIO_H_

typedef struct
{
	int idUsuario;
	char nick[128];
	int popularidadUsuario;
}Usuario;

Usuario* usuario_new(void);
Usuario* usuario_newParam(int idUsuario, char* nick , int popularidadUsuario);
int usuario_setIdUsuario(Usuario* this, int idUsuario);
int usuario_setNick(Usuario* this, char* nick);
int usuario_setPopularidadUsuario(Usuario* this, int popularidadUsuario);
int usuario_getIdUsuario(Usuario* this);
char* usuario_getNick(Usuario* this);
int usuario_getPopularidadUsuario(Usuario* this);

int isValidNick(char* nick);
int isValidPopularidadUsuario(int popularidadUsuario);
int isValidIdUsuario(int idUsuario);

int usuario_imprimirTodos(void*thisA);
#endif /* USUARIO_H_ */
