/*
 * utn.h
 *
 *  Created on: Sep 3, 2020
 *      Author: ezemanzano
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getnumero (int* pResultado, char* mensaje, char* mensajeError,int minimo, int maximo, int intentos);
int utn_getnumeroFloat (float* pResultado, char* mensaje, char* mensajeError,float minimo, float maximo, int intentos);
int utn_getChar (char* pResultado, char* mensaje, char* mensajeError,char minimo, char maximo, int intentos);
#endif /* UTN_H_ */
