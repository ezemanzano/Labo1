/*
 ============================================================================
 Name        : Clase7_EJ002.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#define SIZE 31

void menu() ;
int main(void) {
	float dias[SIZE];
	int opcion;
	int dia;
	float temperatura;


		menu();
		utn_getInt(&opcion,"\n ingresa una opcion","error",0,3,3);
		do {
			switch (opcion)
			{
			case 1:
			imprimirArray(dias, SIZE);
			menu();
			utn_getInt(&opcion,"\n ingresa una opcion","error",0,3,3);

			break;
			case 2:
				utn_getInt(&dia,"Ingrese DIA","error se pasò",1,31, 3);
				printf ("Ingrese temperatura");
				utn_getnumero(&temperatura,"numero..","error",0, 50,2);
				dias[dia-1] = temperatura;
				menu();
				utn_getInt(&opcion,"\n ingresa una opcion","error",0,3,3);
			break;
			default:
					break;
			}

		} while (opcion!=3);





}

void menu() {
	printf("\n Que desea hacer? \n");
	printf("1) Imprimir ARRAY");
	printf("2) Cargar ARRAY");
	printf("3) SALIR");
}
