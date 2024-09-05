#include <stdio.h>
#include <stdlib.h>

void * mycalloc(int n, int size)
{
    void * ptr = (void *) malloc(n * size);
    char *ptr1 = ptr;
    for(int i = 0; i < n; i++)
    {
        *(ptr1 + 1) &= 0;
    }

    return ptr;
}

int main()
{
    int n;
    printf("Number of char : ");
    scanf("%d", &n);
    char * ptr = (char *) mycalloc(n, sizeof(char));

    for(int i = 0; i < n; i++)
    {
        if(*(ptr + i) == '\0'){
            printf("Null ");
        }
        // printf("%c ", *(ptr + 1));
    }
    printf("\n");
    return 0;
}
