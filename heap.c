/*
 * heapsort.c
 *
 *  Created on: Jul 1, 2023
 *      Author: Emilee Oquist
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"

/**
 * Sorts a list of n employees in descending order of Salary
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void heapSort(Employee *A, int n)
{
	buildHeap(A, n);

	n--; // for index
	while (n > 0)
	{
		swap(&A[n], &A[0]);
		heapify(A, 0, n);
		n--;
	}
}

/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void buildHeap(Employee *A, int n) // TODO - heapify() every element from A[n/2] down-to A[0]
{
	for (int i = n / 2; i >= 0; i--)
	{
		heapify(A, i, n);
	}
}

/**
 * We want to start with A[i] and percolate it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the heap
 */
void heapify(Employee *A, int i, int n)
{
	// get index of left and right child of element i
	int l_ind = 2 * (i + 1) - 1,
		r_ind = 2 * (i + 1);
	int smaller = -1;

	// determine which child has a smaller salary.
	if (l_ind < n)
	{
		smaller = l_ind;

		if ((r_ind < n) && A[r_ind].salary < A[l_ind].salary)
		{
			smaller = r_ind;
		}

		if (A[i].salary > A[smaller].salary)
		{
			swap(&A[i], &A[smaller]);
		}
		heapify(A, smaller, n);
	}
}

/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(Employee *e1, Employee *e2) // a swap accepting two pointers
{
	Employee tmp = *e1;
	*e1 = *e2;
	*e2 = tmp;
}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(Employee *A, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("[id=%s sal=%d]", A[i].name, A[i].salary);
	}
	printf("\n");
}
