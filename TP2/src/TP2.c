/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>

#include "ArrayEmployees.h"
#include "utn.h"


int main(void) {
	int menuOption;
	int idLookingFor;
	int indexID;

	Employee ArrayEmployees[EMPLOYEE_QTY];
	initEmployees(ArrayEmployees, EMPLOYEE_QTY);
	do{
		utn_getNumber(&menuOption, "\n Menu \n 1- ALTA 2-IMP", "\n Error", 1,5, 2);
		switch(menuOption)
		{
		case 1:
			newEmployee(ArrayEmployees, EMPLOYEE_QTY);
			break;
		case 2:
			printEmployees (ArrayEmployees, EMPLOYEE_QTY);
			if (utn_getNumber(&idLookingFor, "\n Input ID you want to modify..", "Error", 0, 5000, 2) == 0 )
			{
				if (modifyEmployee(ArrayEmployees,EMPLOYEE_QTY,idLookingFor)== 0)
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
			break;

		case 3:
			if (utn_getNumber(&idLookingFor, "Input ID you are looking for...", "Error", 0, 5000, 2) == 0 ){
				indexID = findEmployeeById(ArrayEmployees, EMPLOYEE_QTY, idLookingFor);

			} else {
				printf("error");
			}
			break;
		case 4:
			printEmployees (ArrayEmployees, EMPLOYEE_QTY);
			if (utn_getNumber(&idLookingFor, "\n Input ID you want to remove..", "Error", 0, 5000, 2) == 0 )
			{

				if (removeEmployee(ArrayEmployees,EMPLOYEE_QTY,idLookingFor)== 0){
					printf("Employee Succesfully removed.");
				}
				else{
					printf("We coudnt find the ID.");
				}
			}
			else
			{
				printf("error");
			}


		}


	}while (menuOption!=5);


}
