#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include <string.h>
#include "parser.h"
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE* pFile;

	pFile = fopen(path,"r");
	if (pFile == NULL)
	{
		retorno=-1;
	}
	parser_EmployeeFromText(pFile, pArrayListEmployee);

	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{

	int retorno=-1;
	char nombre[64];
	int sueldo;
	int horasTrabajadas;

 	if (utn_getNombre(nombre,64, "\nIngrese nombre","Error",2)== 0 &&
 		utn_getNumero(&sueldo,"\nIngrese Sueldo", "error",0,99999,2)== 0 &&
		utn_getNumero(&horasTrabajadas,"\nIngrese horas trabajadas", "error",0,9999,2)== 0)

 	{
 		Employee * Aux = employee_new();
 		if(Aux!=NULL)
 		{
 			employee_setNombre(Aux, nombre);
 			employee_setHorasTrabajadas(Aux, horasTrabajadas);
 			employee_setSueldo(Aux, sueldo);
 			employee_setId(Aux, employee_generarNuevoId());
 		}
 		ll_add(pArrayListEmployee,Aux);
 		retorno=0;


 	}
 	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno =-1;
	int idAModificar;
	int auxIndex;
	int auxId;
	int auxHT;
	int auxSueldo;
	char auxNombre[128];
	char nombreModify[128];
	int horasTModify;
	int sueldoModify;
	int opcionModify;
	Employee * empleadoAux = employee_new();
	if (empleadoAux!=NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		if (utn_getNumero(&idAModificar,"ingrese ID a Modificar","Error",0,1000, 2)==0)
		{
			if (controller_buscarEmployeeIndicePorId(pArrayListEmployee, idAModificar, &auxIndex)==0)
			{
				empleadoAux = ll_get(pArrayListEmployee, auxIndex);
				employee_getId(empleadoAux, &auxId);
				employee_getHorasTrabajadas(empleadoAux, &auxHT);
				employee_getSueldo(empleadoAux, &auxSueldo);
				employee_getNombre(empleadoAux, auxNombre);
				printf(" Empleado a modificar: %04d | %-15s | %-16d | %-6d \n", auxId, auxNombre, auxHT, auxSueldo);
				if (utn_getNumero(&opcionModify,"\nQue desea modificar? \n1- Nombre 2- Sueldo 3-HorasTrabajadas", "error", 1, 4, 2)==0)
				{
					switch(opcionModify)
					{
					case 1:
						if (utn_getNombre(nombreModify,128, "\nIngrese nuevo nombre","Error",2)== 0)
								{
								employee_setNombre(empleadoAux, nombreModify);
								}
						break;
					case 2:
						if (utn_getNumero(&sueldoModify, "\nIngrese nuevo sueldo","Error",0,99999,2)== 0)
							{
							employee_setSueldo(empleadoAux, sueldoModify);
							}
						break;
					case 3:
						if (utn_getNumero(&horasTModify, "\nIngrese nuevas horas Trabajadas","Error",0,99999,2)== 0)
							{
							employee_setSueldo(empleadoAux, sueldoModify);
							}
						break;

					}
				}
			}
		}
	}

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int idABorrar;
	int auxIndex;

			controller_ListEmployee(pArrayListEmployee);
			if (utn_getNumero(&idABorrar,"ingrese ID a Modificar","Error",0,1000, 2)==0)
			{
				if (controller_buscarEmployeeIndicePorId(pArrayListEmployee, idABorrar, &auxIndex)==0)
					{
					ll_remove(pArrayListEmployee, auxIndex);
					//empleadoAux = ll_get(pArrayListEmployee, auxIndex);
					}
			}

return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int auxId;
    int auxHT;
    int auxSueldo;
    char auxNombre[128];
    int len = ll_len(pArrayListEmployee);
    Employee* empleado = employee_new();
    if ( empleado != NULL && len != 0)
    {
        printf("\n ID   NOMBRE            HORAS TRABAJADAS    SUELDO\n");
        for (int i = 0; i < len; i++)
        {
            empleado = ll_get(pArrayListEmployee, i);
            employee_getId(empleado, &auxId);
            employee_getHorasTrabajadas(empleado, &auxHT);
            employee_getSueldo(empleado, &auxSueldo);
            employee_getNombre(empleado, auxNombre);
            printf(" %04d | %-15s | %-16d | %-6d \n", auxId, auxNombre, auxHT, auxSueldo);
        }
        retorno = 0;
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

int employee_lastId(LinkedList* pArrayListEmployee){
	int id=0;
	int lastLl;
	Employee * empleado =employee_new();;
	lastLl = ll_len(pArrayListEmployee);
	empleado =ll_get(pArrayListEmployee, lastLl-1);
	employee_getId(empleado,&id);
return id;
};


int controller_buscarEmployeeIndicePorId(LinkedList* pArrayListEmployee, int idBuscar, int*indexEncontrado){
	int retorno =-1;
	int idEncontrado;
	int i;
	Employee * empleado=employee_new();
	int len = ll_len(pArrayListEmployee);
	for (i=0;i<len;i++)
	{
		empleado = ll_get(pArrayListEmployee, i);
		employee_getId(empleado, &idEncontrado);

		if (idBuscar == idEncontrado)
		{
			*indexEncontrado = i;
			printf("i=%d",i);
			retorno = 0;
			break;
		}
	}
	return retorno;
}



