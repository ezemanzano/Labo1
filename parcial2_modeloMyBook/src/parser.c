#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "usuario.h"
#include "post.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_postFromText(FILE* pFile , LinkedList* pArrayListEnvios)
{
	int retorno = -1;
	int r;
	char var[64],var2[64],var3[64],var4[2000];
	if (pArrayListEnvios!=NULL && pFile!=NULL)
	{
		do
		{
		r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",var,var2,var3,var4);
		if (r==4)
			{
				Post * postAux=post_new();
				if (postAux!=NULL)
				{
				postAux=post_newParam(atoi(var),atoi(var2),atoi(var3),var4);
				if (postAux!=NULL)
				{
				ll_add(pArrayListEnvios, postAux);
				retorno=0;
				}
				printf("aca\n");
				}
				else
				{
					printf("error\n");
					retorno=-1;
				}

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

int parser_UsuariosFromText(FILE* pFile , LinkedList* pArrayListEnvios)
{
	int retorno = -1;
	int r;
	char var[64],var2[128],var3[64];
	if (pArrayListEnvios!=NULL && pFile!=NULL)
	{
		do
		{
		r = fscanf(pFile,"%[^,],%[^,],%[^,\n]",var,var2,var3);
		if (r==3)
			{
				Usuario* usuarioAux= usuario_new();
				if (usuarioAux!=NULL)
				{
				usuarioAux=usuario_newParam(atoi(var),var2,atoi(var3));
				if (usuarioAux!=NULL)
				{
					ll_add(pArrayListEnvios,usuarioAux);
					retorno=0;
				}

				}
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

