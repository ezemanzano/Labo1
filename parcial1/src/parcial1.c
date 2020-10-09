/*
 ============================================================================
 Name        : parcial1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "pantalla.h"
#include "contratacion.h"
#include "utn.h"
#define PANTALLAS_QTY 100
#define CONTRATACIONES_QTY 1000

int main(void) {
	int opcion;
	float ppp;
	Pantalla arrayPantallas[PANTALLAS_QTY];
	Contratacion arrayContratacion[CONTRATACIONES_QTY];
	pantalla_init(arrayPantallas,PANTALLAS_QTY);
	contratacion_init(arrayContratacion,CONTRATACIONES_QTY);
	pantalla_altaForzada(arrayPantallas, PANTALLAS_QTY, "Obelisco", 1, 23, "9 de julio");
	pantalla_altaForzada(arrayPantallas, PANTALLAS_QTY, "Sid campeador", 0, 232, "Av. tu vieja");
	contratacion_altaForzada(arrayContratacion,CONTRATACIONES_QTY, "sorete.mov", 5, 111,2);
	contratacion_altaForzada(arrayContratacion,CONTRATACIONES_QTY, "pepito.mov", 2, 111,1);
	contratacion_altaForzada(arrayContratacion,CONTRATACIONES_QTY, "labora.mov", 2, 1151,2);
	contratacion_altaForzada(arrayContratacion,CONTRATACIONES_QTY, "labora.mov", 2, 112,2);
	do {
		if (utn_getNumero(&opcion, "\n -Menu-\n1) Alta Pantalla \n2) Modificar Pantalla \n3) Baja Pantalla \n4) Alta Contratacion "
				"\n5) Modificar contratacion \n6) Baja Contratacion	\n7) Consultar facturacion", "error", 1,11, 2)== 0)
		{
			switch (opcion)
			{
			case 1:
				if (pantalla_alta(arrayPantallas, PANTALLAS_QTY) == 0)
				{
					printf("\nALTA OK");
				}
				else
				{
					printf("\nERROR");
				}
				break;
			case 2:
				if (pantalla_modificar(arrayPantallas,PANTALLAS_QTY) == 0)
				{
					printf("\nPANTALLA MODIFICADA OK");
				}
				else
				{
					printf("\nERROR");
				}
				break;
			case 3:
				if (pantalla_baja(arrayPantallas,PANTALLAS_QTY) == 0){
					printf("\n PANTALLA DADA DE BAJA OK");
				}
				else
				{
					printf("\nERROR");
				}
				break;
			case 4:
				//pantalla_imprimir(arrayPantallas,PANTALLAS_QTY);
				if (contratacion_alta(arrayContratacion,CONTRATACIONES_QTY, arrayPantallas , PANTALLAS_QTY) == 0 )
				{
					printf("Contratacion ON");
				}
				break;
			case 5:
				if (contratacion_modificar(arrayContratacion,CONTRATACIONES_QTY, arrayPantallas, PANTALLAS_QTY)==0)
				{
					printf("Contrato modificado");
				}
				break;
			case 6:
				if(contratacion_baja(arrayContratacion, CONTRATACIONES_QTY, arrayPantallas, PANTALLAS_QTY)==0)
				{
				printf("Contrato dado de baja");
				}
				break;
			case 7:
				contratacion_ConsultarPrecioPorCuit(arrayContratacion, CONTRATACIONES_QTY,arrayPantallas,PANTALLAS_QTY);
				//consultar facturacion
				break;
			case 8:
				pantalla_imprimir(arrayPantallas, PANTALLAS_QTY);
				break;
			case 9:
				contratacion_imprimir(arrayContratacion, CONTRATACIONES_QTY , arrayPantallas , PANTALLAS_QTY);
				break;
			case 10:
				//contratacion_listarClientes(arrayContratacion, CONTRATACIONES_QTY,arrayPantallas,PANTALLAS_QTY);
				//contratacion_listarClienteCaro(arrayContratacion, CONTRATACIONES_QTY,arrayPantallas,PANTALLAS_QTY);
				//ppp = contratacion_calcularImporteAPagar(arrayContratacion, CONTRATACIONES_QTY , arrayPantallas , PANTALLAS_QTY, 111, 1);
				//printf("%f", ppp);
				contratacion_listarClientes (arrayContratacion, CONTRATACIONES_QTY);
				break;
			}
		}


	}while (opcion!=11);
}

