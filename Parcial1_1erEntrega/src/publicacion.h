/*
 * publicacion.h
 *
 *  Created on: Sep 29, 2020
 *      Author: ezemanzano
 */

#ifndef PUBLICACION_H_
#define PUBLICACION_H_

#define SIZE_AVISO 64
#define TRUE 1
#define FALSE 0
#define PUBLICACION_ACTIVA 1
#define PUBLICACION_PAUSADA 0
#include "cliente.h"

	typedef struct {
		int idCliente;
		int rubro;
		char aviso[SIZE_AVISO];
		int estado;
		int isEmpty;
		int id;
		} Publicacion;

	int publicacion_init(Publicacion * pArrayPublicacions, int limite);

	int publicacion_alta (Publicacion * pArrayPublicacions, int limite, Cliente * pArrayCliente , int limiteCliente);


	int publicacion_imprimirTodas(Publicacion * pArrayPublicacions , int limite , Cliente * pArrayCliente , int limiteCliente);
	int publicacion_imprimirActivas (Publicacion * pArrayPubli , int limite , Cliente * pArrayCliente , int limiteCliente);
	int publicacion_baja (Publicacion * pArrayPublicacions, int limite , Cliente * pArrayCliente , int limiteCliente);
	int publicacion_modificar (Publicacion * pArrayPublicacions, int limite,Cliente * pArrayCliente, int limiteCliente);
	int publicacion_pausar (Publicacion * pArrayPubli, int limite , Cliente * pArrayCliente, int limiteCliente);
	int publicacion_reanudar (Publicacion * pArrayPubli, int limite , Cliente * pArrayCliente, int limiteCliente);

	int publicacion_buscarLibre (Publicacion * pArrayPublicacions, int limite);
	int publicacion_buscarLibreRef (Publicacion * pArrayPublicacions, int limite, int * pIndice);
	int publicacion_buscarIndicePorId (Publicacion * pArrays, int limite,int idBuscar,int * pIndice);
	int publicacion_buscarIndicePorCuit (Publicacion * pArrays, int limite,int cuitBuscar,int * pIndice);
	int publicacion_buscarIndicePorCuitYId (Publicacion * pArrays, int limite,int cuitBuscar, int id,int * pIndice);
	float publicacion_calcularImporteAPagar(Publicacion * pArrays, int limite, Cliente * pArrayCliente , int limiteCliente, int cuit , int idCont);

	int publicacion_altaForzada(Publicacion * pArray, int limite ,int idCliente,int rubro,  char * aviso);
	int publicacion_imprimirPublicacionesPorCuit (Publicacion * pArrays, int limite, Cliente * pArrayCliente , int limiteCliente, int cuit);
	int publicacion_ConsultarPrecioPorCuit (Publicacion * pArrays, int limite, Cliente * pArrayCliente , int limiteCliente);
	void publicacion_listarClientes (Publicacion * pArrays , int limite);
	int publicacion_listarClienteCaro (Publicacion * pArrays , int limite , Cliente * pArrayCliente , int limiteCliente);
#endif /* PUBLICACION_H_ */
