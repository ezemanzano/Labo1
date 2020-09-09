#include <stdio_ext.h>
#include <stdlib.h>

int utn_getnumeroFloat (float* fResultado, char* mensaje, char* mensajeError, int intentos){

		int retorno = -1;
		int resultadoScan ;
		float bufferFloat;
		if (fResultado != NULL && mensaje != NULL && mensajeError != NULL && intentos>=0) {
		do {
			printf("%s\n", mensaje);
			__fpurge(stdin);
			resultadoScan = scanf ("%f", &bufferFloat);

			if (resultadoScan != 0 )
			{
			*fResultado= bufferFloat;
			retorno = 0;
			break;
			}
			else
			{
			printf("%s \n", mensajeError);
			intentos--;
			}
		} while (intentos >= 0 );

		} else {
			printf("\n INGRESA BIEN LOS PARAMETROS ");
		}
		return retorno;
}
/**
 * \brief - Solicita UN caracter al user
 * \param - char* pResultado - Puntero al espacio de memoria donde se guarda el caracter.
 * \param - char* mensaje - Mensaje a mostrar al usuario
 * \param - char* mensajeError - Mensaje de error a mostrar al usuario
 * \param - char minimo - valor minimo que se puede ingresar
 * \param - char maximo - valor maximo que se peude ingresar
 * \param - int intentos - cantidad de intentos que se le da al usuario.
 * \return -
 */

int utn_getChar (char* pResultado, char* mensaje, char* mensajeError,char minimo, char maximo, int intentos)
{
	int retorno = -1;
	int resultadoScan ;
	char bufferChar;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && maximo>minimo && intentos>=0) {
	do {
		printf("%s\n", mensaje);
		__fpurge(stdin);
		resultadoScan = scanf ("%c", &bufferChar);

		if (resultadoScan != 0 && bufferChar >= minimo && bufferChar <= maximo)
		{
		*pResultado = bufferChar;
		retorno = 0;
		break;
		}
		else
		{
		printf("%s \n", mensajeError);
		intentos--;
		}
	} while (intentos >= 0 );
	} else {
		printf("\n INGRESA BIEN LOS PARAMETROS ");
	}
	return retorno;
}
float sumar (float operador1,float operador2) {
	float resul;
	resul = operador1 + operador2 ;
	return resul ;
}

float restar (float operador1,float operador2){
	float resul;
	resul = operador1 - operador2 ;
	return resul ;
}

float multiplicar(float operador1, float operador2) {
		float resul;
		resul = operador1 * operador2 ;
		return resul ;
	}


float dividir (float operador1,float operador2, float* pResultado) {
		float resul;
		int huboError;
		if (operador2 == 0) {
			huboError = 1;
		} else {
			resul = operador1 / operador2 ;
			*pResultado = resul;
			huboError =0 ;
		}
		return huboError;
}

// revisar el factorial - probar con int
int factorial(float operador1, float operador2, float* pFactorial1, float* pFactorial2){
		float factorialOperador1 = 1.00;
		float factorialOperador2 = 1.00;
		int retorno = -1;
		for (float i = 0 ; i<operador1; i++){
			factorialOperador1 = factorialOperador1 * i;
			*pFactorial1 = factorialOperador1;
			return retorno;
		}
		for (float i = 0 ; i<operador1; i++)
		{
				factorialOperador2 = factorialOperador2 * i;
				*pFactorial2 = factorialOperador2;
				return retorno;
		}

		return retorno;


}

