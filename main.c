#include <stdio.h>
#include "employee.h"
#include "heap.h"

// constants
#define MAX_EMPLOYEES 4 /** maximum allowed length of Employees array */

// The driver function should create an array of MAX_EMPLOYEES elements, and fill it with values from the user.
int main(int argc, char *argv[])
{
	Employee E[MAX_EMPLOYEES];
	// int size_e = sizeof(E) / sizeof(E[0]);

	for (int i = 0; i < MAX_EMPLOYEES; i++)
	{
		printf("Employee's name: ");
		scanf("%s", E[i].name);

		printf("%s's salary: ", E[i].name);
		scanf("%d", &E[i].salary);

		printf("\n");
	}
	printf("Before: ");
	printList(E, MAX_EMPLOYEES);

	heapSort(E,MAX_EMPLOYEES);

	printf("After: ");
	printList(E, MAX_EMPLOYEES);

	return 0;
}