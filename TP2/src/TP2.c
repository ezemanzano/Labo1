
#include <stdio_ext.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "utn.h"

int main(void) {
	Employee ArrayEmployees[EMPLOYEE_QTY];
	initEmployees(ArrayEmployees, EMPLOYEE_QTY);
	menu(ArrayEmployees,EMPLOYEE_QTY);

}
