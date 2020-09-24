/*
 * utn.h
 *
 *  Created on: Sep 10, 2020
 *      Author: ezemanzano
 */

#ifndef UTN_H_
#define UTN_H_
float utn_getnumero (float* pResultado, char* mensaje, char* mensajeError,int minimo, int maximo, int intentos);
int utn_getInt (int* pResultado, char* mensaje, char* mensajeError,int minimo, int maximo, int intentos);
int calcularMayor(int* pResultado, int numero1, int numero2);
void imprimirArray(float array[], int len);

#endif /* UTN_H_ */
