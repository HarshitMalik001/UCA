#include "stack.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>

int *arr = NULL;
int capacity = 1;
int size = 0;

void resize_arr(int n)
{
	int *new_arr = (int *) malloc(n * sizeof(int));
	for(int i = 0; i < size; i++)
	{
		new_arr[i] = arr[i];
	}
	int * temp = arr;
	arr = new_arr;
	free(temp);
}

void resize_arr1(int n)
{
	arr = (int *) realloc(arr,n * sizeof(int));
}

int push(int n)
{
	if(size >= capacity)
	{
		resize_arr1(capacity * 2);
		capacity *= 2;
	}
	
	arr[size++] = n;
	return 0;
}

int pop()
{
	if(isEmpty()) return INT_MIN;
	int temp = arr[--size];
	if(capacity/4 == size)
	{
		resize_arr1(capacity/2);
		capacity /= 2;
	}
	
	return temp;
}

int csize()
{
	return size;
}

int isEmpty()
{
	return (size == 0);
}


int test_cases()
{
	assert(isEmpty() == 1);
	push(5);
	assert(isEmpty() == 0);
  	assert(csize() == 1);
	push(7);
	push(9);
	push(10);
 	assert(csize() == 4);
        assert(pop() == 10);
	assert(csize() == 3);
 	assert(pop() == 9);
	assert(pop() == 7);
 	assert(pop() == 5);
 	//assert(isEmpty() == 1);
}

int main()
{
	arr = (int *) malloc(sizeof(int) * 1);
	test_cases();
	free(arr);
	return 0;
}
