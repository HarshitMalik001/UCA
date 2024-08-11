#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include "queue.h"
#include <stdbool.h>


int *arr = NULL;
int N = 0;
int start = 0;
int end = 0;
int max_size = 4;

void push(int data)
{
  if(N == max_size)
  {
    printf("Array already Full");
    return;
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
  push(9);
  push(1);
  assert(pop() == 8);
  assert(pop() == 6);
  assert(pop() == 2);
  assert(pop() == 9);
  assert(pop() == INT_MIN);
}

int main()
{
  arr = (int *)malloc(max_size*sizeof(int));
  test_queue();
  return 0;
}
