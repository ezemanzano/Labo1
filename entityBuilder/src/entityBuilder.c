/*
 ============================================================================
 Name        : clase18_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "entityBuilder.h"
int entityBuilder_new();
void menuCampos(Campo * pArray);
int main(void) {
	int opcion;
	char tipoIngresado[30];


	Campo arrayCampos[50];


	do {
		if (utn_getNumero(&opcion,"\n -----Menu ----- \n 1) Nombre de la estructura \n 2) Tipo y Nombre de campos \n 3) Print Setters & Getters "
				"\n 4) Exit \n ", "Error", 1, 4, 2) == 0)
		{
			switch(opcion)
			{
			case 1:
				entityBuilder_new(tipoIngresado);
				break;
			case 2:
				menuCampos(arrayCampos);
				break;
			case 3:

				break;

			}

		}

	}while (opcion!=9);

}

int entityBuilder_new(char * tipoIngresado){
	int retorno=-1;
	char tipo[30];

	if (utn_getString(tipo, 30, "Ingrese Nombre de Entidad", "Error", 2) == 0)
	{

			printf("%s* %s_new(){return (%s*)malloc(sizeof(%s));}",tipo,tipo,tipo,tipo);
	}

	return retorno;
}

void menuCampos(Campo * pArray){
int opcion;
char nombreCampo[20];
static int i = 0;
do
{
	if (utn_getNumero(&opcion, "\n Ingrese tipo y nombre de campo... \n1) int \n2) int * \n3)char \n4) char \n5) float \n6) float* \n7)Volver", "error", 1, 7, 2)==0)
	{
		switch(opcion)
		{
		case 1:
			strcpy(pArray[i].tipoCampo,"int");
			utn_getString(nombreCampo, 20, "\n Ingrese nombre...", "Error", 2);
			strcpy(nombreCampo,pArray[i].nombreCampo);
			i++;
			break;
		case 2:
			strcpy(pArray[i].tipoCampo,"int*");
			utn_getString(nombreCampo, 20, "\n Ingrese nombre...", "Error", 2);
			strcpy(nombreCampo,pArray[i].nombreCampo);
			i++;
			break;
		case 3:
			strcpy(pArray[i].tipoCampo,"char");
			utn_getString(nombreCampo, 20, "\n Ingrese nombre...", "Error", 2);
			strcpy(nombreCampo,pArray[i].nombreCampo);
			i++;
			break;
		case 4:
			strcpy(pArray[i].tipoCampo,"char*");
			utn_getString(nombreCampo, 20, "\n Ingrese nombre...", "Error", 2);
			strcpy(nombreCampo,pArray[i].nombreCampo);
			i++;
			break;
		case 5:
			strcpy(pArray[i].tipoCampo,"float");
			utn_getString(nombreCampo, 20, "\n Ingrese nombre...", "Error", 2);
			strcpy(nombreCampo,pArray[i].nombreCampo);
			i++;
			break;
		case 6:
			strcpy(pArray[i].tipoCampo,"float*");
			utn_getString(nombreCampo, 20, "\n Ingrese nombre...", "Error", 2);
			strcpy(nombreCampo,pArray[i].nombreCampo);
			i++;
			break;
		}

	}else
	{
		printf("error- se quedo sin intentos");
	}

} while (opcion!=7);
}


