/*
 * alumno.h
 *
 *  Created on: Sep 22, 2020
 *      Author: ezemanzano
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_

#define LONG 50
#define SIZESTRUCT_ALUMNO 2
#define TRUE 1
#define FALSE 0
#define MIN_LEGAJO 1
#define MAX_LEGAJO 5


typedef struct {
	char nombre[LONG];
	int legajo;
	int isEmpty;
	} Alumno;
	int alumno_alta (Alumno * pArrayAlumnos, int limite);
	int alumno_init(Alumno * pArrayAlumnos, int limite);
	int alumno_imprimir (Alumno * pArrayAlumnos , int limite);
	int alumno_baja (Alumno * pArrayAlumnos, int limite);
#endif /* ALUMNO_H_ */
