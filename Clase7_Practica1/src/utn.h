/*
 * utn.h
 *
 *  Created on: Sep 10, 2020
 *      Author: ezemanzano
 */

#ifndef UTN_H_
#define UTN_H_
float utn_getnumero (float* pResultado, char* mensaje, char* mensajeError,int minimo, int maximo, int intentos);
int esNumerica(char*cadena);

int esNombre (char*cadena) ;
int getChar (char * pResultado, int len);

#endif /* UTN_H_ */
