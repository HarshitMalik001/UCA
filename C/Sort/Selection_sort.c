#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <assert.h>

void selection_sort(int arr[], int n)
{

        for(int i = 0; i < n; i++)
        {
                int min = i;
                for(int j = i+1; j < n; j++)
                {
                        if(arr[min]>arr[j]) min = j;
                }
                int temp = arr[i];
                arr[i] = arr[min];
                arr[min] = temp;
        }
}


long long Time_passed(int n)
{
        int *arr = (int *) malloc(n*sizeof(int));

        srand(time(NULL));
        for(int i = 0; i < n; i++) arr[i] = rand();

        struct timeval before;
        gettimeofday(&before, NULL);
                                    
        long long before_millis = before.tv_sec*1000LL + before.tv_usec/1000;

        selection_sort(arr, n);

        struct timeval after;
        gettimeofday(&after, NULL);
        long long after_millis = after.tv_sec*1000LL + after.tv_usec/1000;

        return after_millis-before_millis;
}


void test_sample()
{
        int arr[7] = {5,2,1,7,8,4,9};
        int exp_out[7] = {1,2,4,5,7,8,9};

        selection_sort(arr,7);

        for (int i = 0; i<7 ;i++) assert(arr[i]==exp_out[i]);
}

int main()
{
        test_sample();
        long long t1 = Time_passed(32000);
        long long t2 = Time_passed(64000);

        printf("%lf", t2*1.0/t1);
        return 0;
}
                                                                                                                   
