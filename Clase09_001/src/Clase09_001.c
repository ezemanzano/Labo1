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




int main(void) {
	int opcion;
	Alumno arrayAlumno[SIZESTRUCT_ALUMNO];
	if (alumno_init(arrayAlumno, SIZESTRUCT_ALUMNO) == 0){
		do {
			 utn_getnumero(&opcion, "\n 1-Alta \n 2- Imprimir \n 3-Baja  \n  4-Modificar 5-SALIR \n ", "serror",1,4,2);
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
				 alumno_modificar (arrayAlumno,SIZESTRUCT_ALUMNO);
				 break;
			 }
		 }while (opcion != 5);


	}


}


