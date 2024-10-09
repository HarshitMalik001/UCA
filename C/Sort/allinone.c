#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


void Bubble_sort(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr, j , j + 1);
            }
        }
    }
}


void Selection_sort(int arr[], int n)
{
    int min = 0;

    for(int i = 0; i < n; i++)
    {
        min = i;
        for(int j = i; j < n; j++)
        {
            if(arr[min] > arr[j])
            {
                min = j;
            }
        }
        swap(arr, i, min);
    }
}


void Insertion_sort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int num = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > num)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = num;
    }
}


void merge(int arr[], int aux[], int start, int mid, int end)
{

    for(int i = start; i <= end; i++)
    {
        aux[i] = arr[i];
    }

    int i = start;
    int j = mid + 1;
    int index = start; 
    while(i <= mid || j <= end)
    {
        if(i > mid) arr[index] = aux[j++];
        else if(j > end) arr[index] = aux[i++];
        else if(aux[i] < aux[j]) arr[index] = aux[i++];
        else arr[index] = aux[j++];
        index++; 
    }

}

void Merge_rec(int arr[],int aux[], int start, int end)
{
    if(start >= end) return;
    int mid = (start + end)/2;
    Merge_rec(arr,aux, start, mid);
    Merge_rec(arr,aux, mid + 1, end);
    merge(arr,aux, start, mid, end);
}

void mergeSort(int arr[], int n)
{
    int aux[n];
    Merge_rec(arr, aux, 0, n - 1);
}


void quick_rec(int arr[], int start, int end)
{
    if(start >= end) return ;
    
    int i = start + 1;
    int j = start + 1;
    
    while(j <= end){
        if(arr[j] < arr[start])
        {
            swap(arr, i++, j++);
        }
        else
        {
            j++;
        }
    }
    

    swap(arr, start, --i);

    quick_rec(arr, start, i - 1);
    quick_rec(arr, i + 1, end);
    
}

void Quick_sort(int arr[], int n)
{
    quick_rec(arr, 0, n - 1);
}


int mannual_test_case()
{
    int arr[10] = {6,3,7,9,8,5,2,4,1,0};
    int res[10] = {0,1,2,3,4,5,6,7,8,9};


    // Bubble_sort(arr,10);
    // Selection_sort(arr,10);
    // Insertion_sort(arr,10);
    // mergeSort(arr, 10);
    Quick_sort(arr,10);
    for(int i = 0; i < 10; i++)
    {
        assert(arr[i] == res[i]);
        // printf("%d ",arr[i]);
    }
    return 0;
}

int main()
{
    mannual_test_case();
    return 0;
}

