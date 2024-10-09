#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

struct Node
{
	int val;
	struct Node* next;	
};


typedef struct Node Node;
Node *head = NULL;
int N = 0;

int push(int n)
{
	Node* oldHead = head;
        head = (Node *) malloc(sizeof(Node));
        head->val = n;
        head->next = oldHead;
        N++;	
	return 0;
}

int csize()
{
        return N;
}

int isEmpty()
{
        return (N == 0);
}

int pop()
{
	if(N == 0) return INT_MIN;
	int tempv = head->val;
	Node * temp = head;
	head = head->next;
	free(temp);
	N--;
	return tempv;
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
	test_cases();
	return 0;
}
