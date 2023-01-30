#include <stdio.h>
#include "employee.h"
#include "heap.h"

// constants
#define MAX_EMPLOYEES 5 /** maximum allowed length of Employees array */

int main(int argc, char *argv[])
{
	Employee
		// The driver function should create an array of MAX_EMPLOYEES elements, and fill it with values from the user.
		fgets(tmp, MAX_INPUT_LEN, stdin);
	// TODO
	Employee e1, e2;
	strcpy(e1.name, "1");
	strcpy(e2.name, "2");

	e1.salary = 10;
	e2.salary = 20;

	swap(&e1, &e2);
	printf("%s", e1.name);
	printf("%s", e2.name);

	return 0;
}