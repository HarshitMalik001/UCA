#include <stdio.h>
#include <time.h>
#include<unistd.h>

int main()
{
	clock_t start, end;

	start = clock();
	int sum = 0;
	for(int i = 0; i < 1000000; i++)
	{
		sum += i;
	}

	end = clock();

	printf("%d %f\n",sum, (double)((end - start)/CLOCKS_PER_SEC));

	return 0;
}
