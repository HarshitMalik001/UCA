#include <stdio.h>

int main()
{
 	FILE *file = fopen("output.txt", "w");
    	if (file == NULL) {
      	 	printf("Failed to open the file.\n");
       		return 1;
   	}
	int num = 22;
	double pi = 3.14;
	char str[] = "hello g";

	fprintf(stdout, "Integer %d \n",num);
	fprintf(stdout, "Floating-point: %f\n", pi);
        fprintf(stdout, "String: %s\n", str);

        fclose(file);

        return 0;
}
