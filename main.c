#include <stdio.h>
#include "employee.h"
#include "heap.h"

// constants
#define MAX_EMPLOYEES 5 /** maximum allowed length of Employees array */

// The driver function should create an array of MAX_EMPLOYEES elements, and fill it with values from the user.
int main(int argc, char *argv[])
{
	Employee E[MAX_EMPLOYEES];
	char name[MAX_NAME_LEN];
	int salary;

	Employee test_worker = { "Goose Duckduck\0", 2000};
    for (int i = 0; i < MAX_EMPLOYEES; ++i) {
        //
    }


	for (int i = 0; i < MAX_EMPLOYEES; i++)
	{
		printf("Enter the name of an Employee: ");
		scanf("%s", &name);
		E[i].name = name;

		printf("Enter Employee %s's salary: ", &name);
		scanf("%d", &salary);
		E[i].salary = salary;
	}
	return 0;
}