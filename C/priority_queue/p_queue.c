#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int capacity = 1;
int Csize = 0;
int *arr = NULL;

int isEmpty()
{
    return (Csize == 0);
}

int size()
{
    return Csize;
}


int exchange(int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void swim(int k)
{
    while(k > 1 && arr[k / 2] < arr[k])
    {
        exchange(k / 2, k);
        k = k / 2;
    }   
}

void sink(int k)
{
    while(2 * k <= Csize)
    {
        int j = 2 * k;
        if(j < Csize && arr[j] < arr[j + 1]) j++;
        if(arr[k] >= arr[j]) break;
        exchange(j, k);
        k = j;
    }
}

void resize_arr(int new_size)
{
    arr = realloc(arr, new_size * sizeof(int));
    if(arr == NULL)
    {
        printf("ERROR");
    }
}

void insert(int data)
{
    if (Csize + 1 >= capacity) { 
        resize_arr(2 * capacity); 
    	capacity *= 2;
    }

    arr[++Csize] = data;  
    swim(Csize);

}

int del()
{
    if(isEmpty()) return -1;
    int temp = arr[1];
    exchange(Csize--, 1);
    sink(1);

    if(Csize == capacity / 4){
        resize_arr(capacity / 2);
        capacity /= 2;
    }
    
    return temp;
}



int main()
{
    arr = malloc(capacity * sizeof(int));

    insert(4);
    insert(6);
    insert(4);
    insert(2);
    insert(7);
    insert(2);

    assert(del() == 7);
    assert(size() == 5);
    assert(del() == 6);
    assert(size() == 4);
    assert(del() == 4);
    assert(size() == 3);
    assert(del() == 4);
    assert(size() == 2);
    assert(del() == 2);
    assert(size() == 1);
    assert(del() == 2);
    assert(isEmpty() == 1);

    free(arr);
    return 0;
}
