/*
 * utn.h
 *
 *  Created on: Sep 10, 2020
 *      Author: ezemanzano
 */

#ifndef UTN_H_
#define UTN_H_
int utn_getNumero (int* pResultado, char* mensaje, char* mensajeError,int minimo, int maximo, int intentos);
int utn_getNombre (char * pResultado, int len, char * mensaje, char * mensajeError, int intentos);
int utn_getFloat (float* pResultado, char* mensaje, char* mensajeError,float minimo, float maximo, int intentos);
#endif /* UTN_H_ */
