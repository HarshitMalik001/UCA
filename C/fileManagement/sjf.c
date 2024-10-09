#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int no;
	int * AT;
	int * BT;
	int * CT;
	int * WT;
	int * TAT;
	int * completed;
} SJF;

SJF sjf;

void initialize(int n)
{
	sjf.no = n;
	sjf.AT = (int *)(malloc(n * sizeof(int)));
	sjf.BT = (int *)(malloc(n * sizeof(int)));
	sjf.TAT = (int *)(malloc(n * sizeof(int)));
	sjf.CT = (int *)(malloc(n * sizeof(int)));
	sjf.WT = (int *)(malloc(n * sizeof(int)));
	sjf.completed = (int *)(calloc(n , sizeof(int)));
}

void free1()
{
	free(sjf.AT);
	free(sjf.TAT);
	free(sjf.BT);
	free(sjf.WT);
	free(sjf.CT);
	free(sjf.completed);
}

int main()
{
	int n;
	printf("Enter No. of Process : ");
	scanf("%d",&n);

	initialize(n);

	free1();
	return 0;
}
