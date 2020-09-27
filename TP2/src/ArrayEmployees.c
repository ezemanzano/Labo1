#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include "string.h"
#include "ArrayEmployees.h"
static int employeeNewId (void);
static int menuModify (Employee * list ,int indexId);
/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* pArrayEmployee to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

int initEmployees(Employee * pArrayEmployee, int len){

	int retorno = -1;
	if (pArrayEmployee != NULL && len >0){
		for (int i = 0; i<len; i++ )
		{
			pArrayEmployee[i].isEmpty = TRUE;
		}
		return  0;
	}
return retorno;
}
// hacer descrip

int employeeFreeIndex (Employee * list, int len, int * pIndex){
	int output = -1;
	int i ;
		if (list != NULL && len >0 && pIndex != NULL)
		{
			for ( i = 0; i<len; i++)
			{
				if(list[i].isEmpty == TRUE)
					{
					*pIndex = i;
					printf("%d", i);
					output = 0;
					break;
					}
			}
		}
	return output;
}




/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector, int index)
{
	int output =-1;
	if (len>0){
		list[index].sector = sector;
		list[index].salary = salary;
		list[index].id = id;
		strncpy(list[index].name,name,LONG);
		strncpy(list[index].lastname,lastName,LONG);
		list[index].isEmpty = FALSE;
		output = 0;
	}

return output;
}

int newEmployee (Employee* list, int len){
	int output = -1;
	int index;
	char name[LONG];
	char lastName[LONG];
	float salary;
	int sector;
	int id;


	if (list != NULL && len >0)
	{
		if (employeeFreeIndex(list, len, &index) == 0)
		{
			if (utn_getName(name,LONG, "Input Name...","ERROR - Name only has letters", 2) == 0 &&
				utn_getName(lastName,LONG,"Input Lastname..","ERROR - lastname only has letters",2) == 0 &&
				utn_getNumber(&sector, "Input Sector... (0-20)","ERROR - Sector numbers goes from 0 to 20. Try again", 0, 20, 2) == 0 &&
				utn_getFloat(&salary, "Input Salary..(0-10.000 - NO $)", "Error - Salary goes from 0 to 10.000", 0,10000, 2)== 0 ) {
				id = employeeNewId ();
				if (addEmployee(list, EMPLOYEE_QTY, id, name, lastName, salary, sector, index) == 0) {
					printf("SUCCESS! - New employee added ");
				} else {
					printf("Coding ERROR");
				}

			}

		}
		else
		{
				printf(" \n NO MORE SLOTS AVAILABLE");
		}
		}

	return output;
}

static int employeeNewId (void) {
	static int id = 0;
	id = id+1;
	return id;
}

int printEmployees (Employee* list, int length) {
	int output = -1;
	if (list != NULL && length >0){
		for (int i=0 ; i<length ; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf("\n ID: %d Name: %s Lastname: %s Sector: %d Salary: %.2f ",list[i].id, list[i].name, list[i].lastname, list[i].sector, list[i].salary);
			}
		}
		output = 0;
	}
return output;
}

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id)
{
	int output = -1;
	int i ;
	if (list != NULL && len >0 && id>0){
		for ( i = 0; i<len; i++) {
			if(list[i].id == id)
				{
				output = i;
				break;
				}
		}
	}
	return output;
}
int removeEmployee(Employee* list, int len, int id)
{
	int output = -1;
	int indexId;
		if (list != NULL && len>0 && id>0)
		{
			indexId = findEmployeeById(list, len, id);
			list[indexId].isEmpty = TRUE;
			output = 0;
		}
		return output;
	}


int modifyEmployee (Employee*list, int len , int id){
	int output = -1;
	int indexId;
	if (list != NULL && len>0 && id>0 )
	{
		indexId = findEmployeeById(list, len, id);
		menuModify(list,indexId);
		output = 0;
	}



	return output;

}

static int menuModify (Employee * list ,int indexId){
	int menuOption;
	int output= -1;
	Employee bufferEmployee;
	if (utn_getNumber(&menuOption,"What would you like to modify? \n 1) Name \n 2) Lastname \n 3) Salary  \n 4) Sector ", "Wrong- Options goes from 1 to 4",1, 4, 2) == 0)
	{
		switch (menuOption) {
		case 1 :
			if (utn_getName(bufferEmployee.name,LONG, "\n Input NEW Name...","ERROR - Name only has letters", 2) == 0) {
				strncpy(list[indexId].name,bufferEmployee.name,LONG);
				output = 0;
			} else {
				printf("ERROR - TRY AGAIN");
			}
			break;
		case 2 :
			if (utn_getName(bufferEmployee.lastname,LONG, "\n Input NEW Lastname...","ERROR - Lastame only has letters", 2) == 0)
			{
				strncpy(list[indexId].lastname,bufferEmployee.lastname,LONG);
				output = 0;
			} else {
				printf("ERROR - TRY AGAIN");
			}
			break;
		case 3 :
			if (utn_getFloat(&bufferEmployee.salary, "\n Input NEW Salary..(0-10.000 - NO $)", "Error - Salary goes from 0 to 10.000", 0,10.000, 2)== 0 ) {
				list[indexId].salary = bufferEmployee.salary;
			}
			break;
		case 4 :
		if(utn_getNumber(&bufferEmployee.sector, "\n Input NEW Sector... (0-20)","ERROR - Sector numbers goes from 0 to 20. Try again", 0, 20, 2) == 0 ){
			list[indexId].sector = bufferEmployee.sector;
			output = 0;
		}
		else {
			printf("ERROR - TRY AGAIN");
		}
			break;
		}
	}
	return output;
}



