/*
 * generico.h
 *
 *  Created on: Sep 29, 2020
 *      Author: ezemanzano
 */

#ifndef GENERICO_H_
#define GENERICO_H_

#define SIZE_NOMBRE 50
#define SIZE_CUIT 20
#define TRUE 1
#define FALSE 0

	typedef struct {
		int numero;
		int numero2;
		float flotante;
		float flotante2;
		char nombre[SIZE_NOMBRE];
		char apellido[SIZE_NOMBRE];
		char cuit[SIZE_CUIT];
		int isEmpty;
		int id;
		} Generico;

	int generico_init(Generico * pArrayGenericos, int limite);

	int generico_alta (Generico * pArrayGenericos, int limite);
	int generico_imprimir (Generico * pArrayGenericos , int limite);
	int generico_baja (Generico * pArrays, int limite, int  idGenericoBaja);
	int generico_modificar (Generico * pArrayGenericos, int limite);

	int generico_imprimirPorIndice (Generico * pArray , int limite, int indice);
	int generico_imprimirPrecioPorIndice (Generico * pArray , int limite, int indice) ;
	int generico_informacionGenerico(Generico * pArrayGenerico, int limiteGenerico, int idGenerico);

	int generico_buscarLibre (Generico * pArrayGenericos, int limite);
	int generico_buscarLibreRef (Generico * pArrayGenericos, int limite, int * pIndice);
	int generico_buscarIndicePorIdRef (Generico * pArray, int limite,int idBuscar,int * pIndice);
	int generico_buscarIndicePorId (Generico * pArray, int limite,int idBuscar);

	int generico_altaForzada(Generico * pArray, int limite , char * nombre, char * apellido, char * cuit);
	int generico_sePuedeSeguir(Generico * pArrayGenerico, int limiteGenerico);
	int generico_noSeRepiteCuit(Generico * pArrayGenerico, int limiteGenerico, char * cuitIngresado);

#endif /* GENERICO_H_ */
