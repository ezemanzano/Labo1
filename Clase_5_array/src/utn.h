/*
 * utn.h
 *
 *  Created on: Sep 3, 2020
 *      Author: ezemanzano
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getnumero (int* pResultado, char* mensaje, char* mensajeError,int minimo, int maximo, int intentos);
void imprimirArray(int array[], int len);
int ordenarArrayMinMax(int *pArray , int size);

#endif /* UTN_H_ */
