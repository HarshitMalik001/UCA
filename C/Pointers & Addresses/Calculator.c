#include <stdio.h>
#include "calc.h"

int add(int a, int b)
{
        return a + b;
}

int subtract(int a, int b)
{
        return a - b;
}

int multiply(int a, int b)
{
        return a * b;
}

int divide(int a, int b)
{
        return a / b;
}

void performOperation(int (*operation)(int, int), int a, int b)
{
        printf("%d ",(*operation)(a,b));

}

int main()
{
        int a , b;
        char oper ;
        printf("Enter a : ");
        scanf("%d",&a);
        printf("Enter op : ");
        scanf(" %c",&oper);
        printf("Enter b : ");
        scanf("%d",&b);
        int (* operation ) (int ,int);
        switch(oper)
        {
                case '+':
                        operation =  &add;
                        performOperation(operation, a, b);
                        break;

                case '-':
                        operation =  &subtract;
                        performOperation(operation, a, b);
                        break;
                case '*':
                        operation =  &multiply;
                        performOperation(operation, a, b);
                        break;
                case '/':
                        operation =  &divide;
                        performOperation(operation, a, b);
                        break;
        }
        return 0;
}
