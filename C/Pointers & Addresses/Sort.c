#include <stdio.h>

void sort(int arr[], int n, int (*compare)(int, int))
{
        for(int i = 0; i<n; i++)
        {
                for(int j = i; j>0; j--)
                {
                        if(compare(arr[j-1], arr[j]))
                        {
                                int temp = arr[j];
                                arr[j] = arr[j-1];
                                arr[j-1] = temp;
                        }
                        else break;
                }
        }

}

int compareAsc(int a, int b)
{
        return a > b;
}

int compareDesc(int a, int b)
{
        return a < b;
}

void printArray(int arr[], int size)
{
        for(int i = 0; i < size; i++)
        {
                printf("%d ",arr[i]);
        }
        printf("\n");
}
int main()
{
        int n;
        printf("Size of array: ");
        scanf("%d",&n);
        int arr[n];

        for(int i = 0; i < n; i++)
        {
                scanf("%d",&arr[i]);
        }

        int ( *compare )(int, int) = compareAsc;

        printArray(arr, n);

        sort(arr, n, compare);
        printArray(arr, n);

        compare = &compareDesc;

        sort(arr, n, compare);
        printArray(arr, n);

        return 0;
}
    
