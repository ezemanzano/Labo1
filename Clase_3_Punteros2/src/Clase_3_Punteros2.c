// Calculadora constante con control de variables y de
#include <stdio_ext.h>
#include <stdlib.h>
float suma (float operador1, float operador2, float *pResultado);
float resta (float operador1, float operador2);
float multiplicacion (float operador1, float operador2)	;
float division (float operador1, float operador2, float* memoriaResultado);
int main(void) {
	setbuf (stdout, NULL);
	float numero1;
	float numero2;
	char operador;
	float total;
	int rta = 1;
	int rtaScan;
	int noDividePorCero;

	do {
		printf ("Ingrse nùmero... ");
		__fpurge(stdin);
		rtaScan = scanf ("%f",&numero1 );
		while(rtaScan == 0) {
		printf ("Ingrse nùmero... ");
		__fpurge(stdin);
		rtaScan = scanf ("%f",&numero1 );
		}

	printf ("Ingrese operador (+,-,*,/)");
	__fpurge(stdin);
	scanf ("%c",&operador);
	printf ("Ingrse nùmero... ");
			__fpurge(stdin);
			rtaScan = scanf ("%f",&numero2 );
			while(rtaScan == 0) {
			printf ("Ingrse nùmero... ");
			__fpurge(stdin);
			rtaScan = scanf ("%f",&numero2 );
			}
	switch (operador){
	case '+' :
		suma(numero1,numero2,&total);

		break;
	case '-':
		total = resta(numero1,numero2);
		break;
	case '*' :
		total =  multiplicacion(numero1,numero2);
		break;
	case '/' :
		noDividePorCero = division(numero1,numero2, &total);
		if (noDividePorCero == 1) {
			printf("Error - No se puede dividir por cero");
		}
		break;
	default :
		printf ("Error.");
		break;
	}
	printf("El resultado es: %.2f", total);

	printf ("Desea continuar ? 1 para continuar /0 para salir");
	__fpurge(stdin);
	scanf ("%d", &rta);
} while (rta != 0) ;


}
float suma (float operador1, float operador2, float* pResultado) {

	int error = -1;
	(*pResultado)= operador1+operador2;
	error = 0;
	return error;
}

float resta (float operador1, float operador2){
	float resultado;
	resultado = operador1-operador2;
	return resultado;
}

float multiplicacion (float operador1, float operador2) {
	float resultado;
		resultado = operador1*operador2;
		return resultado;
}

float division (float operador1, float operador2, float* pResultado) {
		float resultado;
		int error;
		if (operador2 == 0) {
		 error = -1;
		} else {
		 resultado = (float)operador1/operador2;
		 (*pResultado) = resultado;
		error = 0;
		}
		return error;
}






