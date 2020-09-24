/*
 * alumno.c
 *
 *  Created on: Sep 22, 2020
 *      Author: ezemanzano
 */
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "alumno.h"


// intentar fn modificar pensar dejar de pedir indice al user






 // agregar lo de isempty y el indice por defecto



int alumno_init(Alumno * pArrayAlumnos, int limite){
	int retorno = -1;
	if (pArrayAlumnos != NULL && limite >0){
		for (int i = 0; i<limite; i++ )
		{
			pArrayAlumnos[i].isEmpty = TRUE;
		}
		retorno = 0;
	}

	return retorno;
}



int alumno_alta (Alumno * pArrayAlumnos, int limite){
int retorno = -1;
Alumno bufferAlumno;
	if (pArrayAlumnos != NULL && limite >0){

		for (int i=0 ; i<limite ; i++){
			if (pArrayAlumnos[i].isEmpty == TRUE){
				if (utn_getnumero(&bufferAlumno.legajo, "\n Legajo?", "error",  MIN_LEGAJO, MAX_LEGAJO,2) == 0){
								pArrayAlumnos[i].legajo = bufferAlumno.legajo;
						} else {
							printf("horror");
						}
						if (utn_getNombre(bufferAlumno.nombre, LONG, " \n Ingrese nombre","ERROR",3) == 1){
								strncpy(pArrayAlumnos[i].nombre,bufferAlumno.nombre,LONG);

						}else {
							printf("horror");
						}
						pArrayAlumnos[i].isEmpty = FALSE;
						break;
			} else {
				printf(" \n No quedan espacios libres");
			}

		}
	}

return retorno ;
}

int alumno_imprimir (Alumno * pArrayAlumnos , int limite) {
	int retorno = -1;
	if (pArrayAlumnos != NULL && limite >0){
		for (int i=0 ; i<limite ; i++)
		{
			if(pArrayAlumnos[i].isEmpty == FALSE)
			{
				printf("\nNombre: %s - Legajo: %d",pArrayAlumnos[i].nombre,pArrayAlumnos[i].legajo);
			}
		}
		retorno = 0;
	}
return retorno;
}


int alumno_baja (Alumno * pArrayAlumnos, int limite){
	int retorno = -1;
	int buffer;
			if (pArrayAlumnos != NULL && limite>0){
			alumno_imprimir(pArrayAlumnos, limite);
			utn_getnumero(&buffer,"Ingrese legajo de alumno a borrar","Error", MIN_LEGAJO, MAX_LEGAJO,3);
			for (int i = 0 ; i<limite ;  i++){
				if (buffer == pArrayAlumnos[i].legajo){
					pArrayAlumnos[i].isEmpty = TRUE;
				}
			}
		}

	return retorno;

}

int alumno_modificar (Alumno * pArrayAlumnos, int limite){
	int retorno = -1;
	char modificar[20];
	int buffer;
	Alumno bufferAlumno;
			if (pArrayAlumnos != NULL && limite>0){
			alumno_imprimir(pArrayAlumnos, limite);
			utn_getnumero(&buffer,"Ingrese legajo de alumno a modificar","Error", MIN_LEGAJO, MAX_LEGAJO,3);
			for (int i = 0 ; i<limite ;  i++){
				if (buffer == pArrayAlumnos[i].legajo){
				utn_getNombre(modificar, 20, "Que desea modificar? (nombre / legajo)", "error", 2);
				if (strcmp(modificar, "legajo") == 0){
					if (utn_getnumero(&bufferAlumno.legajo, "\n Nuevo Legajo?", "error",  MIN_LEGAJO, MAX_LEGAJO,2) == 0){
							pArrayAlumnos[i].legajo = bufferAlumno.legajo;
					} else {
						printf("horror");
					}
				}else {
					if (utn_getNombre(bufferAlumno.nombre, LONG, " \n Ingrese nuevo nombre","ERROR",3) == 1){
						strncpy(pArrayAlumnos[i].nombre,bufferAlumno.nombre,LONG);
				}else {
					printf("horror");
				}
				}
				}
			}
		}

	return retorno;

}

