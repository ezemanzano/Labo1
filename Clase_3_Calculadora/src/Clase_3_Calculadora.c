
#include <stdio_ext.h>
#include <stdlib.h>
int suma (int operador1, int operador2);
int resta (int operador1, int operador2);
int multiplicacion (int operador1, int operador2);
float division (int operador1, int operador2);
int main(void) {
	setbuf (stdout, NULL);
	int numero1;
	int numero2;
	char operador;
	float total;

	printf ("Ingrse nùmero... ");
	__fpurge(stdin);
	scanf ("%d",&numero1 );
	printf ("Ingrese operador");
	__fpurge(stdin);
	scanf ("%c",&operador);
	printf ("Ingrse nùmero... ");
	__fpurge(stdin);
	scanf ("%d",&numero2 );
	switch (operador){
	case '+' :
		total = suma(numero1,numero2);
		break;
	case '-':
		total = resta(numero1,numero2);
		break;
	case '*' :
		total =  multiplicacion(numero1,numero2);
		break;
	case '/' :
		total = division(numero1,numero2);
		break;
	default :
		printf ("Error.");
		break;
	}
	printf("El resultado es: %.2f", total);

}

int suma (int operador1, int operador2) {
	int resultado;
	resultado = operador1+operador2;
	return resultado;
}

int resta (int operador1, int operador2){
	int resultado;
	resultado = operador1-operador2;
	return resultado;
}

int multiplicacion (int operador1, int operador2) {
	int resultado;
		resultado = operador1*operador2;
		return resultado;
}

float division (int operador1, int operador2) {
	float resultado;
		if (operador2 == 0) {
		 printf ("Error - No puede dividir por cero - Ingrese nùmero...");
		__fpurge(stdin);
		 scanf ("%d",&operador2);
		}
		resultado = (float)operador1/operador2;
		return resultado;
}



