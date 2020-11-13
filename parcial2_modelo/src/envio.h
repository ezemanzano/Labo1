/*
 * envio.h
 *
 *  Created on: Nov 13, 2020
 *      Author: ezemanzano
 */

#ifndef ENVIO_H_
#define ENVIO_H_
#include "LinkedList.h"
typedef struct
{
	int idProducto;
	char nombre_producto[128];
	int id_camion;
	char zona_destino[128];
	int km_recorridos;
	int tipo_entrega;
	int costo_envio;

}Envio;

Envio* envio_new(void);
Envio* envio_newParam(int idProducto, char* nombre_producto, int id_camion, char* zona_destino, int km_recorridos, int tipo_entrega, int costo_envio);

int envio_setIdProducto(Envio* this, int idProducto);
int envio_setNombre_producto(Envio* this, char* nombre_producto);
int envio_setId_camion(Envio* this, int id_camion);
int envio_setZona_destino(Envio* this, char* zona_destino);
int envio_setKm_recorridos(Envio* this, int km_recorridos);
int envio_setTipo_entrega(Envio* this, int tipo_entrega);
int envio_setCosto_envio(Envio* this, int costo_envio);
int envio_getIdProducto(Envio* this);
int envio_getNombre_producto(Envio* this, char * nombre_producto);
int envio_getId_camion(Envio* this);
int envio_getZona_destino(Envio* this, char * zona_destino);
int envio_getKm_recorridos(Envio* this);
int envio_getTipo_entrega(Envio* this);
int envio_getCosto_envio(Envio* this);

int isValidCosto_envio(int costo_envio);
int isValidIdProducto(int idProducto);
int isValidNombre_producto(char * nombre_producto);
int isValidId_camion(int id_camion);
int isValidZona_destino(char * zona_destino);
int isValidKm_recorridos(int km_recorridos);
int isValidTipo_entrega(int tipo_entrega);

int envio_imprimirTodos(void*thisA);
int envio_loadFromText(char* path , LinkedList* pArrayListEnvios);
#endif /* ENVIO_H_ */
