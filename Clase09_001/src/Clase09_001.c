/*
 ============================================================================
 Name        : Clase09_001.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "alumno.h"
#define SIZESTRUCT_ALUMNO 3




int main(void) {
	int opcion;
	int indice;
	int indice2;
	int idBuscar;

	Alumno arrayAlumno[SIZESTRUCT_ALUMNO];
	if (alumno_init(arrayAlumno, SIZESTRUCT_ALUMNO) == 0){
		do {
			 utn_getNumero(&opcion, "\n 1-Alta \n 2- Imprimir \n 3-Baja  \n  4-Modificar 5-Imprimir indice 6- buscarLibre 7- SALIR \n ", "serror",1,8,2);
			 switch (opcion){
			 case 1:
				alumno_alta(arrayAlumno,SIZESTRUCT_ALUMNO);

				 break;

			 case 2:
				alumno_imprimir(arrayAlumno,SIZESTRUCT_ALUMNO);
				 break;

			 case 3:
				 alumno_baja(arrayAlumno,SIZESTRUCT_ALUMNO);
				 break;
			 case 4:
				utn_getNumero (&idBuscar, "Que ID Desea buscar","ERRROR",0,50,2);
				alumno_buscarIndice (arrayAlumno,SIZESTRUCT_ALUMNO,idBuscar,&indice2);
				printf("%d",indice2);
				alumno_modificar (arrayAlumno,SIZESTRUCT_ALUMNO);
				 break;
			 case 5:
				 utn_getNumero(&indice, "Ingrese indice", "seerror",0,4,2);
				 alumno_imprimirIndice(arrayAlumno,SIZESTRUCT_ALUMNO,indice);
				 break;
			 case 6:
				 indice = alumno_buscarLibre(arrayAlumno,SIZESTRUCT_ALUMNO);
				if (indice != -1){
					printf("El indice libre es: %d", indice);
				} else {
					printf("No hay indices libres :( ");
				}
				break;
			 case 7:
				 alumno_ordenarPorNombre(arrayAlumno,SIZESTRUCT_ALUMNO,1);
				 alumno_imprimir(arrayAlumno, SIZESTRUCT_ALUMNO);
			 }
		 }while (opcion != 8);


	}


}


