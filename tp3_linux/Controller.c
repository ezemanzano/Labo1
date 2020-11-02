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
	if (pArrayListEmployee!=NULL)
	{
		pFile = fopen(path,"r");
		if (pFile == NULL)
		{
			retorno=-1;
		}
		if (parser_EmployeeFromText(pFile, pArrayListEmployee)==0)
		{
			printf("\nCarga de datos Correcta...");
			retorno =0;
	}

	}



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
    int retorno = -1;
    if(path != NULL && pArrayListEmployee !=NULL)
    {
        FILE* file;
        file = fopen(path, "rb");
        if(parser_EmployeeFromBinary(file,pArrayListEmployee)==0)
        {
            retorno =0;
        }
    }
    else
    {
    printf("\n No se encontro el archivo");
    }
    return retorno;
} /*
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE* pFile;
	if (pArrayListEmployee!=NULL)
	{
		pFile = fopen(path,"rb");
		if (pFile == NULL)
		{
			retorno=-1;
		}
		else
		{
		parser_EmployeeFromBinary(pFile, pArrayListEmployee);
		retorno = 0;
		}
	}

return retorno;
}
*/
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
 			employee_setId(Aux, controller_encontrarLastId(pArrayListEmployee));
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
			if (utn_getNumero(&idABorrar,"ingrese ID a Borrar","Error",0,1000, 2)==0)
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
        for (int i = 1; i < len; i++)
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
    int error = 1;
    int len = ll_len(pArrayListEmployee);

    Employee* empleado = employee_new();
    Employee* empleadoAux = employee_new();

    printf("\n Se estan ordenando)\n");

    if ( empleado != NULL && empleadoAux != NULL && len != 0)
    {
        for (int i = 1; i < len; i++)
        {
            for ( int j = i + 1; j < len; j++)
            {
                empleado = ll_get(pArrayListEmployee, i);
                empleadoAux = ll_get(pArrayListEmployee, j);
                if ( strcmp(empleado->nombre, empleadoAux->nombre) > 0 )
                {
                    ll_set(pArrayListEmployee,j, empleado);
                    ll_set(pArrayListEmployee,i, empleadoAux);
                }
            }
        }
        error = 0;
        printf("\nSe ordenaron los empleados \n\n");
    }

    return error;
}

/*
{
	int retorno=-1;
	int estadoDesordenado=1;
	char nombre1[128];
	char nombre2[128];
	Employee* empleado;
	Employee* empleado2;
	Employee* empleadoAux;
	empleado=employee_new();
	empleado2=employee_new();
	empleadoAux=employee_new();
	if (pArrayListEmployee!=NULL)
	{
		while(estadoDesordenado)
		{
			for (int i = 1;i<ll_len(pArrayListEmployee);i++)
			{
				estadoDesordenado=0;
				empleado=ll_get(pArrayListEmployee, i);
				empleado2=ll_get(pArrayListEmployee,(i+1));
				employee_getNombre(empleado, nombre1);
				//printf("%s",nombre1);
				employee_getNombre(empleado2, nombre2);
				//printf("-%s",nombre2);
				if(strcmp(nombre1,nombre2)>0)
				{
									ll_set(pArrayListEmployee, i, empleado2);
					ll_set(pArrayListEmployee,(i+1),empleado);

					estadoDesordenado=1;
				}
			}
		}
	}
    return retorno;
}*/

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int idAux;
	int horasAux;
	int sueldoAux;
	char nombreAux[128];
	int len = ll_len(pArrayListEmployee);
	Employee *empleado;
	empleado=employee_new();
	FILE* pFile;
	if (empleado!=NULL&&pArrayListEmployee!=NULL&&len>0)
	{
		pFile = fopen(path,"w");

				fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
				for (int i= 0;i<len;i++)
				{
					empleado=ll_get(pArrayListEmployee, i);
					if (employee_getId(empleado,&idAux)==0 &&
						employee_getNombre(empleado,nombreAux)==0	&&
						employee_getHorasTrabajadas(empleado,&horasAux)==0&&
						employee_getSueldo(empleado,&sueldoAux)==0)
					{
						fprintf(pFile,"%d,%s,%d,%d\n",idAux,nombreAux,horasAux,sueldoAux);
						retorno=0;
					}

				}
			}

	fclose(pFile);
return retorno;
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
	int retorno = -1;
	    Employee* empleadoAux = employee_new();
	    int len = ll_len(pArrayListEmployee);
	    FILE* pFile;

	    if(path != NULL && pArrayListEmployee != NULL && empleadoAux != NULL && len > 0)
	    {
	        pFile = fopen(path,"wb");
	        if (pFile != NULL)
	        {
	            for(int i = 1; i < len; i++)
	            {
	                empleadoAux = ll_get(pArrayListEmployee, i);
	                fwrite(empleadoAux, sizeof(Employee), 1, pFile);
	            }
	            retorno = 0;
	            fclose(pFile);
	        }
	        else
	        {
	            printf("No se pudo abrir el archivo\n");
	        }
	    }
	    return retorno;
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

int controller_encontrarLastId(LinkedList* pArrayListEmployee){
	int retorno=-1;
	int auxId;
	int max;
	Employee * empleadoAux = employee_new();
	int len = ll_len(pArrayListEmployee);
	if (pArrayListEmployee!=NULL)
	{
		for (int i = 1;i<len;i++)
		{
			empleadoAux=ll_get(pArrayListEmployee, i);
			employee_getId(empleadoAux, &auxId);
			if (i==1||auxId>max)
			{
				max = auxId;
				retorno = max+1;
			}
		}

	}
	return retorno;
}

