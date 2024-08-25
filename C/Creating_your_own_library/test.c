#include <stdio.h>
#include "calculator.h"

int main()
{
        int a = -10, b = 5;

        printf("%d %d %d %d \n",add(a, b), subtract(a, b), multiply(a, b), divide(a, b));

        return 0;
}
