#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>

void merge(int arr[], int aux[], int first, int mid, int last)
{
        for(int i = first; i<=last; i++) aux[i]=arr[i];

        int i = first;
        int j = mid + 1;

        for(int k = first; k<=last; k++)
        {
                if(j>last) arr[k] = aux[i++];
                else if(i>mid) arr[k] = aux[j++];
                else if (aux[i]<=aux[j]) arr[k] = aux[i++];
                else arr[k] = aux[j++];
        }
}

void merge_sort_recursive(int arr[], int aux[], int first, int last)
{
        if(first>=last) return;

        int mid = first + (last - first)/2;
        merge_sort_recursive(arr, aux, first, mid);
        merge_sort_recursive(arr, aux, mid+1, last);
        merge(arr, aux, first, mid, last);
}


void merge_sort(int arr[],int n)
{
        int *aux = (int *)malloc(n*sizeof(int));

        merge_sort_recursive(arr, aux, 0, n-1);
        free(aux);

}
long long Time_passed(int n)
{
        int *arr = (int *) malloc(n*sizeof(int));

        srand(time(NULL));
        for(int i = 0; i < n; i++) arr[i] = rand();

        struct timeval before;
        gettimeofday(&before, NULL);
        long long before_millis = before.tv_sec*1000LL + before.tv_usec/1000;

        merge_sort(arr, n);

        struct timeval after;
        gettimeofday(&after, NULL);
        long long after_millis = after.tv_sec*1000LL + after.tv_usec/1000;

        return after_millis-before_millis;
}



int main()
{
        long long t1 = Time_passed(32000);
        long long t2 = Time_passed(64000);

        printf("%lf", t2*1.0/t1);
        return 0;
}
