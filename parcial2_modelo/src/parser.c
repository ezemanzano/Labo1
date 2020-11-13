#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "envio.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EnviosFromText(FILE* pFile , LinkedList* pArrayListEnvios)
{
	int retorno = -1;
	int r;
	char var[64],var2[64],var3[64],var4[64],var5[64],var6[64];
	if (pArrayListEnvios!=NULL && pFile!=NULL)
	{
		do
		{
		r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n],%[^,],%[^,]",var,var2,var3,var4,var5,var6);
		if (r==6)
			{
				Envio* Aux = envio_new();
				if (Aux!=NULL)
				{
				Aux=envio_newParam(atoi(var),var2,atoi(var3),var4,atoi(var5),atoi(var5),0);
				ll_add(pArrayListEnvios,Aux);
				retorno=0;
				}
			printf("aca");
			}

		} while (!feof(pFile));
	fclose(pFile);
	}
	else
	{
		printf("\n No se encontro el archivo");
	}

	return retorno;
}
