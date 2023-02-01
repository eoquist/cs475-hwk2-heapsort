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
	scanf("Before: ");
	printList(A, n);

	buildHeap(A, n);

	while (n > 0) // no clue lmao !!!
	{
		swap(&A[n - 1], &A[0]);
		n--;
		heapify(A, 0, n);
	}

	scanf("After: ");
	printList(A, n);
}

/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void buildHeap(Employee *A, int n)
{
	// TODO - heapify() every element from A[n/2] down-to A[0]
	for (int i = (n / 2) - 1; i >= 0; i--)
	{
		heapify(A, n, i);
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
	int l_ind = 2 * (i + 1) - 1, r_ind = 2 * (i + 1); // get index of left and right child of element i
	int smaller = i;

	// TODO - determine which child has a smaller salary.
	if (A[i].salary > A[l_ind].salary && A[i].salary > A[r_ind].salary)
	{
		if (A[l_ind].salary < A[r_ind].salary)
		{
			smaller = l_ind;
		}
		else if (A[l_ind].salary > A[r_ind].salary)
		{
			smaller = r_ind;
		}
	}

	// TODO - recursively check if the salary at A[i] > the salary at A[smaller]. If it is, swap the two.
	//			Then recursively heapify A[smaller].
	// TODO - Continue recursion as long as i is within range AND either right_child and left_child are still within range.
}

/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(Employee *e1, Employee *e2) // a swap accepting two ??? variables vs pointers
{
	Employee *tmp = e1;
	e1 = e2;
	e2 = tmp;
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
