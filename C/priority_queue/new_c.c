#include <stdio.h>
// Priority Queue
#include <stdlib.h>
#include <assert.h>

int *arr = NULL;
int capacity = 1;
int n = 0;


int isEmpty()
{
	return (n == 0);
}

int size()
{
	return n;
}

void resize_arr(int new_size)
{
	arr = (int *) realloc(arr, new_size * sizeof(int));
}

void swap(int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void swim(int k)
{
	while(k > 1 && arr[k/2] < arr[k])
	{
		swap(k/2, k);
		k = k/2;
	}
}


int insert(int data)
{
	n++;
	if(n >= capacity)
	{
		resize_arr(capacity * 2);
		capacity *= 2;
	}
	
	arr[n] = data;
	swim(n);
	return 0;
}

void sink(int k)
{
	while(2 * k <= n)
	{
		int l = 2 * k;
		if(l + 1 <= n && arr[l + 1] > arr[l]) l++;
		
		if(arr[l] <= arr[k]) break;

		swap(l, k);
		k = l;
	}

}


int del()
{
	if(isEmpty()) return -1;

	int temp = arr[1];
	swap(0,n--);
	
	if(n <= capacity/4)
	{
		resize_arr(capacity/2);
		capacity /= 2;
	}

	sink(0);
	
	return temp;
}


int main()
{
	arr = (int *)(malloc(sizeof(int) * capacity));
	insert(4);
   	 insert(6);
   	 insert(4);
	 insert(2);
   	 insert(7);
   	 insert(2);

   	 assert(del() == 7);
   	 assert(size() == 5);
   	 assert(del() == 6);
   	 assert(size() == 4);
   	 assert(del() == 4);
   	 assert(size() == 3);
   	 assert(del() == 4);
   	 assert(size() == 2);
   	 assert(del() == 2);
   	 assert(size() == 1);
   	 assert(del() == 2);
   	 assert(isEmpty() == 1);

    	free(arr);

	return 0;		
}
