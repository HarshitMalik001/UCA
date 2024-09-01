#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>


int main()
{
	struct rusage start;
	getrusage(RUSAGE_SELF, &start);

	int *array = (int *) malloc(1000000 *sizeof(int));

	for(int i = 0; i < 1000000; i++)
	{
		array[i] = i%10;
	}

	struct rusage end;
        getrusage(RUSAGE_SELF, &end);

	long mem_usd = end.ru_maxrss - start.ru_maxrss;

	printf("%ld KB \n", mem_usd);

	free(array);
	return 0;
}
