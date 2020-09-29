/*
 * utn.c
 *
 *  Created on: Sep 10, 2020
 *      Author: ezemanzano
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"



static int myGets (char* cadena, int longitud);
static int getInt (int* pResultado);
static int getFlt (float* pResultado);
static int esNumerica (char* cadena);
static int esNombre (char*cadena, int limite);


static int myGets (char* cadena, int longitud){
		__fpurge (stdin);
		fgets(cadena,longitud,stdin);
		cadena[strnlen(cadena,sizeof(cadena))-1]='\0';
		return 1;
}

static int getInt (int* pResultado){
	int retorno = -1 ;
	char buffer[4096];
	if (myGets(buffer,sizeof(buffer)) == 1  && esNumerica(buffer)== 1){
		retorno = 0;
		*pResultado = atoi(buffer);
	}
	return retorno;
}
static int getFlt (float* pResultado){
	int retorno = -1 ;
	char buffer[4096];
	if (myGets(buffer,sizeof(buffer)) == 1  && esNumerica(buffer)== 1){
		retorno = 0;
		*pResultado = atof(buffer);
	}
	return retorno;
}

int esNumerica(char*cadena){
	int retorno = 1 ;
	int i = 0;
	int contadorPuntos = 0 ;
	if (cadena[0] == '-' || cadena[0] == '+'){
		i = 1;
	}
	for (;cadena[i] != '\0';i++) {
		if (cadena[i] > '9' || cadena[i] < '0')
		{
			if (cadena[i] == '.'){
				contadorPuntos++;
				if (contadorPuntos >1){
					retorno = 0;
					break;
				}
			}
			else
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int utn_getNumber (int* pResultado, char* mensaje, char* mensajeError,int minimo, int maximo, int intentos){

	int retorno = -1;
	int bufferInt;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && maximo>minimo && intentos>=0) {
	do {
		printf("%s\n", mensaje);
		__fpurge(stdin);
		if (getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
		{
		*pResultado = bufferInt;
		retorno = 0;
		break;
		}
		else
		{
		printf("%s \n", mensajeError);
		intentos--;
		}
	} while (intentos >= 0 );

	}
	return retorno;
}

int utn_getFloat (float* pResultado, char* mensaje, char* mensajeError,float minimo, float maximo, int intentos){

	int retorno = -1;
	float bufferFloat;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && maximo>minimo && intentos>=0) {
	do {
		printf("%s\n", mensaje);
		__fpurge(stdin);
		if (getFlt(&bufferFloat) == 0 && bufferFloat >= minimo && bufferFloat <= maximo)
		{
		*pResultado = bufferFloat;
		retorno = 0;
		break;
		}
		else
		{
		printf("%s \n", mensajeError);
		intentos--;
		}
	} while (intentos >= 0 );

	}
	return retorno;
}


int utn_getName (char * pResultado, int len, char *mensaje, char* mensajeError, int intentos){
	int retorno = -1 ;
	char buffer[4096];
	if (pResultado != NULL && len>0 && mensaje != NULL && mensajeError != NULL  && intentos>=0) {
		do {
			printf("%s\n", mensaje);
			__fpurge(stdin);
			if ( myGets(buffer,sizeof(buffer)) && esNombre(buffer,len) )
			{
				retorno = 0;
				strncpy(pResultado,buffer,len);
				break;
			}
			else
			{
			printf("%s \n", mensajeError);
			intentos--;
			}
		} while (intentos >= 0 );

		}



	return retorno;
}

static int esNombre (char*cadena, int limite) {
	int retorno = 1;
	int i ;
	for (i = 0 ; i<=limite && cadena[i] != '\0'; i++){
		if	((cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
		{
			retorno = 0;
			break;
		}}
	return retorno;
}
int askForId (int * id){
	int output = -1;
	int idLookingFor;
if (utn_getNumber(&idLookingFor, "\n Input ID you are looking for..", "Error", 0, 5000, 2) == 0 )
			{
				*id = idLookingFor;
				output = 0;
			}
			else
			{
				printf("error");
			}
return output;

}


int askForOrder (int * order){
	int output = -1;
	int whichOrder;
if (utn_getNumber(&whichOrder, "\n Input 0 to order from a-z, otherwise input 1", "Error", 0, 1, 2) == 0 )
			{
				*order = whichOrder;
				output = 0;
			}
			else
			{
				printf("error");
			}
return output;

}

void menu(Employee * list , int len ){
	int menuOption;
	int idLookingFor;
	int indexID;
	int flagFirstInit = 0;
	int order;

	do{
			utn_getNumber(&menuOption, "\n Menu \n 1- ADD \n 2- MODIFY  \n 3- REMOVE \n 4- SORT BY...", "\n Error", 1,5, 2);
			switch(menuOption)
			{
			case 1:
				newEmployee(list, len);
				flagFirstInit = 1;
				break;

			case 2:
				if (flagFirstInit == 1) {
				printEmployees (list, len);
				if (utn_getNumber(&idLookingFor, "\n Input ID you want to modify..", "Error", 0, 5000, 2) == 0 )
				{
					if (modifyEmployee(list,len,idLookingFor)== 0)
					{
						printf("Employee Succesfully modified.");
					}
					else
					{
						printf("We coudnt find the ID.");
					}
				}
				else
				{
					printf("error");
				}
				} else {
					printf("There is no employees to modify, please add a new one");
				}
				break;

			case 3:
				if (flagFirstInit == 1){
				printEmployees (list, len);
				if (askForId(&idLookingFor) == 0 )
				{
					if (removeEmployee(list,len,idLookingFor)== 0)
					{
						printf("Employee Succesfully removed.");
					}
					else
					{
						printf("We coudnt find the ID.");
					}
				}
				else
				{
					printf("error");
				}
				}
				else
				{
					printf("There is NO employees to remove, please add a new one");
				}
				break;
			case 4:

				if (flagFirstInit == 1){
					menu4(list,len);
				}
					else
				{
					printf("There no employees to show, please add a new one");
				}
				break;
			}


		}while (menuOption!=5);
}




void menu4 (Employee * list, int len){
	int option;
	int order;
	if (utn_getNumber(&option, "\n What would you like to do? \n 1) SORT BY LASTNAME \n 2) SHOW AVARAGE SALARY \n 3", "Wrong - JUST CHOOSE 1 - 2 - 3) EXIT", 1, 3, 2) ==0){
		if (option == 1){
			askForOrder (&order);
			sortEmployees(list,len, order);
			printEmployees(list, len);
		} else if (option == 2){
			averageSalary(list, len);
		}
	}
}
