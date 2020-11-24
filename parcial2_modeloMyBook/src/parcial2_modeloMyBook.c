/*
 ============================================================================
 Name        : parcial2_modeloMyBook.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "post.h"
#include "usuario.h"
#include "controller.h"

int main(void) {

LinkedList* pArrayListUsers=ll_newLinkedList();
LinkedList* pArrayListPost=ll_newLinkedList();
int opcion;

do
{
	utn_getNumero(&opcion, "menu", "error", 1,4,2);
switch (opcion)
{
case 1:
	controller_loadFromPost("mensajes.csv", pArrayListPost);
	controller_loadFromTextUsers("usuarios.csv", pArrayListUsers);
	break;
case 2:
	ll_map(pArrayListPost,post_imprimirTodos);
	ll_map(pArrayListUsers, usuario_imprimirTodos);
	break;
case 3:
	ll_sort(pArrayListUsers, controller_sortUsers, 0);
	ll_map(pArrayListUsers, usuario_imprimirTodos);
}
}while(opcion!=4);

}
