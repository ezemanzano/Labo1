/*
 ============================================================================
 Name        : archivos_primerClase.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char cadena[54];
	char cadena2[54];
	char cadena3[54];
	FILE * fp = fopen("prueba.txt","r");
		if (fp!=NULL)
		{
			do {

				fscanf(fp,"%[^,],%[^,],%[^\n]",cadena,cadena2,cadena3);
				printf("\nlei :%s",cadena);
				printf("\nlei :%s",cadena2);
				printf("\nlei :%s",cadena3);

			} while (feof(fp)==0);
			fclose(fp);
		}


}

/*
 * char cadena[64];
	sprintf(cadena,"Flaquito");
	printf("La cadena vale: %s\n",cadena);
	typedef struct {
		char nombre[8];
		int edad;
	}Empleado;
	Empleado emp;
	emp.edad=9;
	sprintf(emp.nombre,"tete");
	FILE * fp = fopen("prueba.data","w");
	if (fp!=NULL)
	{
		//fwrite(cadena,strlen(cadena),1,fp);
		fprintf(fp,"%s",cadena);
		fprintf(fp,"%s %d",emp.nombre, emp.edad);
		fclose(fp);
	}
 */
/*
 *
 *
 *typedef struct {	char nombre[8];
	int edad;
}Empleado;
	Empleado emp;
 *
	emp[0].edad = 9;
	int numeros[5]={102,112,5,22,250};


	FILE* fp = fopen("archivo1","w");
	if (fp !=NULL)
	{
			sprintf(emp.nombre,"Flaco");
			fwrite(&emp,sizeof(Empleado),1,fp);
			fclose(fp);
	}

	FILE* fp = fopen("archivo1","r");
		if (fp !=NULL)
		{
			fread(&emp,sizeof(Empleado),1,fp);
			printf("nombre_%s",emp.nombre);
			fclose(fp);
		}
}


 */
