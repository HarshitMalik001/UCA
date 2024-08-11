#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include "queue.h"

struct Node 
{
  int data;
  struct Node* next ;
};

typedef struct Node Node;
Node * head = NULL;
Node * back = NULL;
int N = 0;

void push(int item)
{
  Node* new_back = (Node*)malloc(sizeof(Node));
  new_back->data = item;
  new_back->next = NULL;
  if (back == NULL )
  {
    back = new_back;
    head = new_back;
  }
  else {
    back->next = new_back;
    back = new_back;
  }
  
  N++;
}

int pop()
{
  if(N==0) return INT_MIN;
  Node *temp = head;
  int item = head->data;
  
  if(N == 1) back = back->next;
  
  head = head->next;
  free(temp);
  N--;
  return item;
}

int size()
{
  return N;
}

bool isEmpty()
{
  return N == 0;
}

int testQueue()
{
  push(3);
  push(10);
  push(19);

  assert(size() == 3);
  assert(pop() == 3);
  assert(size() == 2);
  assert(pop() == 10);
  assert(size() == 1);
  assert(pop() == 19);
  assert(size() == 0);
  assert(isEmpty());
}

int main()
{
  testQueue();
  return 0;
}

