#include <stdio.h>
#include "employee.h"
#include "heap.h"

// constants
#define MAX_EMPLOYEES 2 /** maximum allowed length of Employees array */

// The driver function should create an array of MAX_EMPLOYEES elements, and fill it with values from the user.
int main(int argc, char *argv[])
{
	Employee E[MAX_EMPLOYEES];
	int size_e = sizeof(E) / sizeof(E[0]);
	char name[MAX_NAME_LEN];
	int salary;

	for (int i = 0; i < MAX_EMPLOYEES; i++)
	{
		printf("Employee's name: ");
		scanf("%s", E[i].name);

		printf("%s's salary: ", E[i].name);
		scanf("%d", &E[i].salary);

		printf("\n");
	}
	heapSort(E,size_e);
	return 0;
}