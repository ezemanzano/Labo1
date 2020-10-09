/*
 * contratacion.h
 *
 *  Created on: Sep 29, 2020
 *      Author: ezemanzano
 */

#ifndef CONTRATACION_H_
#define CONTRATACION_H_

#define SIZE_NOMBRE 50
#define TRUE 1
#define FALSE 0
#include "pantalla.h"

	typedef struct {
		char nombreArchivo[SIZE_NOMBRE];
		int cuitCliente;
		int idPantalla;
		int cantidadDias;
		int isEmpty;
		int id;
		} Contratacion;

	int contratacion_init(Contratacion * pArrayContratacions, int limite);

	int contratacion_alta (Contratacion * pArrayContratacions, int limite, Pantalla * pArrayPantalla , int limitePantalla);

	int contratacion_imprimir (Contratacion * pArrayContratacions , int limite , Pantalla * pArrayPantalla , int limitePantalla);
	int contratacion_baja (Contratacion * pArrayContratacions, int limite , Pantalla * pArrayPantalla , int limitePantalla);
	int contratacion_modificar (Contratacion * pArrayContratacions, int limite,Pantalla * pArrayPantalla, int limitePantalla);


	int contratacion_buscarLibre (Contratacion * pArrayContratacions, int limite);
	int contratacion_buscarLibreRef (Contratacion * pArrayContratacions, int limite, int * pIndice);
	int contratacion_buscarIndicePorId (Contratacion * pArrays, int limite,int idBuscar,int * pIndice);
	int contratacion_buscarIndicePorCuit (Contratacion * pArrays, int limite,int cuitBuscar,int * pIndice);
	int contratacion_buscarIndicePorCuitYId (Contratacion * pArrays, int limite,int cuitBuscar, int id,int * pIndice);
	float contratacion_calcularImporteAPagar(Contratacion * pArrays, int limite, Pantalla * pArrayPantalla , int limitePantalla, int cuit , int idCont);

	int contratacion_altaForzada(Contratacion * pArray, int limite , char * nombre, int  dias , int cuit, int idPantalla);
	int contratacion_imprimirContratacionesPorCuit (Contratacion * pArrays, int limite, Pantalla * pArrayPantalla , int limitePantalla, int cuit);
	int contratacion_ConsultarPrecioPorCuit (Contratacion * pArrays, int limite, Pantalla * pArrayPantalla , int limitePantalla);
	void contratacion_listarClientes (Contratacion * pArrays , int limite);
	int contratacion_listarClienteCaro (Contratacion * pArrays , int limite , Pantalla * pArrayPantalla , int limitePantalla);
#endif /* CONTRATACION_H_ */
