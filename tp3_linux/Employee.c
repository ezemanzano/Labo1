#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"
#include "Controller.h"



Employee* employee_new(void)
{
	return (Employee*)malloc(sizeof(Employee));
}

Employee* employee_newParametros(char * idStr,char* nombre,char * horasTrabajadas,char *sueldo)
{
	Employee* this = employee_new();
	if(this != NULL)
	{
		if((employee_setNombre(this, nombre)==0)
			&& (employee_setHorasTrabajadas(this, atoi(horasTrabajadas)))==0
			&& (employee_setSueldo(this, atoi(sueldo))) ==0
			&& employee_setId(this,atoi(idStr))==0)

		{
			return this;
		}
	}
	return NULL;
}


int employee_setId(Employee* this,int val)
{
	int ret=-1;
	if(this!=NULL && val>0)
	{
		this->id =val;
		ret=0;
	}
	return ret;
}

int employee_getNombre(Employee* this,char* nombre)
{    if(this != NULL)
    {
        strncpy(nombre, this->nombre,(int)sizeof(this->nombre));
        return 0;
    }
    else
        return -1;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno=0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{    if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        return 0;
    }
    else
        return -1;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    if(this != NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas = horasTrabajadas;
        return 0;
    }
    return -1;
}



int isValidNombre(char * nombre)
{
	/*int retorno = 0;
		int i ;
		for (i = 0 ; i<=sizeof(nombre) && nombre[i] != '\0'; i++)
		{
		if	((nombre[i] < 'a' || nombre[i] > 'z') && (nombre[i] < 'A' || nombre[i] > 'Z'))
			{
				retorno = 0;

				break;
			}
		}
*/
		return 0;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo>0)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}


int employee_getSueldo(Employee* this,int* sueldo)
{    if(this != NULL)
    {
        *sueldo =this->sueldo;
        return 0 ;
    }
    else
        return -1;
}

int isValidSueldo(int sueldo)
{
	int retorno=-1;
	if(sueldo>=0)
	{
		retorno = 0;
	}
	return retorno;
}


int isValidHorasTrabajadas(int horasTrabajadas)
{
	int retorno=-1;
	if(horasTrabajadas>=0)
	{
		retorno = 0;
	}
	return retorno;
}



 int	employee_generarNuevoId () {
	static int id = 0;
	id = id+1;
	return id;
}

int employee_getId(Employee* this,int* id)
 {
	 if(this != NULL)
     {
         *id =this->id;
         return 0;
     }
     else
         return -1;
 }


