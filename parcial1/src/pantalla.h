/*
 * pantalla.h
 *
 *  Created on: Sep 29, 2020
 *      Author: ezemanzano
 */

#ifndef PANTALLA_H_
#define PANTALLA_H_

#define SIZE_NOMBRE 50
#define TRUE 1
#define FALSE 0
#define PANTALLA_TIPO_LED 0
#define PANTALLA_TIPO_LCD 1

	typedef struct {
		char nombre[SIZE_NOMBRE];
		int tipo;
		char direccion[SIZE_NOMBRE];
		float precio;
		int isEmpty;
		int id;
		} Pantalla;

	int pantalla_init(Pantalla * pArrayPantallas, int limite);

	int pantalla_alta (Pantalla * pArrayPantallas, int limite);

	int pantalla_imprimir (Pantalla * pArrayPantallas , int limite);
	int pantalla_baja (Pantalla * pArrayPantallas, int limite);
	int pantalla_modificar (Pantalla * pArrayPantallas, int limite);

	int pantalla_imprimirPorIndice (Pantalla * pArrays , int limite, int indice);
	int pantalla_imprimirPrecioPorIndice (Pantalla * pArrays , int limite, int indice) ;

	int pantalla_buscarLibre (Pantalla * pArrayPantallas, int limite);
	int pantalla_buscarLibreRef (Pantalla * pArrayPantallas, int limite, int * pIndice);
	int pantalla_buscarIndicePorIdRef (Pantalla * pArrays, int limite,int idBuscar,int * pIndice);
	int pantalla_buscarIndicePorId (Pantalla * pArrays, int limite,int idBuscar);

	int pantalla_altaForzada(Pantalla * pArray, int limite , char * nombre, int  tipo , float precio, char * direccion);

#endif /* PANTALLA_H_ */
