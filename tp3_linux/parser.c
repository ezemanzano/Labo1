#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int r;
	int idMax;
	int flagMax=0;

	char var[64],var2[64],var3[64],var4[64];
	do
		{
		r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",var,var2,var3,var4);
		if (r==4)
			{
				Employee * Aux = employee_new();
				if (Aux!=NULL)
				{
				Aux=employee_newParametros(var,var2,var3,var4);
				ll_add(pArrayListEmployee,Aux);
				if (idMax<atoi(var) || flagMax==0)
				{
					idMax=atoi(var);
					retorno= idMax;
					flagMax=1;
				}
				}
				//retorno= 0;
			}

		} while (!feof(pFile));
	fclose(pFile);
	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
