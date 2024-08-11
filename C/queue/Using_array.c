#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include "queue.h"


int *arr = NULL;
int N = 0;
int start = 0;
int end = 0;
int max_size = 1;

int resize_array(int new_size)
{
  int* new_array = (int *) malloc(new_size * sizeof(int));
  for(int i = 0; i < N; i++)
    {
      new_array[i] = arr[start];
      start = (start + 1) % max_size;
    }
  start = 0;
  end = N;
  int *temp = arr;
  arr = new_array;
  free(temp);
}


void push(int data)
{
  if(N == 0) resize_array(max_size);
  if(N == max_size)
  {
    resize_array(max_size * 2);
    max_size *= 2;
  }
  arr[end] = data;
  end = (end + 1) % max_size;
  N++;
}


int pop()
{
  if(N == 0) return INT_MIN;
  int data = arr[start];
  start = (start + 1) % max_size;
  N--;
  if(N == max_size/4)
  {
    resize_array(max_size/2);
    max_size /= 2;
  }
  
  return data;
}

int size()
{
        return N;
}

bool isEmpty()
{
        return N==0;
}

void test_queue()
{
  push(4);
  push(7);
  push(1);
  push(8);
  push(7);

  assert(pop() == 4);
  assert(pop() == 7);
  assert(pop() == 1);
  push(6);
  push(2);
  assert(pop() == 8);
  assert(pop() == 7);
  assert(pop() == 6);
  assert(pop() == 2);
  assert(pop() == INT_MIN);
}

int main()
{
  arr = (int *)malloc(max_size*sizeof(int));
  test_queue();
  return 0;
}
