#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <assert.h>

void insertion_sort(int arr[], int n)
{
        for(int i = 0; i<n; i++)
        {
                for(int j = i; j>0; j--)
                {
                        if(arr[j]<arr[j-1])
                        {
                                int temp = arr[j];
                                arr[j] = arr[j-1];
                                arr[j-1] = temp;
                        }
                        else break;
                }
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

        insertion_sort(arr, n);

        struct timeval after;
        gettimeofday(&after, NULL);
        long long after_millis = after.tv_sec*1000LL + after.tv_usec/1000;

        return after_millis-before_millis;
}
void test_sample()
{
        int arr[7] = {5,2,1,7,8,4,9};
        int exp_out[7] = {1,2,4,5,7,8,9};

        insertion_sort(arr,7);

        //for (int i = 0; i<7 ;i++) printf("%d ",arr[i]);
        for (int i = 0; i<7 ;i++) assert(arr[i]==exp_out[i]);
}
int main()
{
        long long t1 = Time_passed(32000);
        long long t2 = Time_passed(64000);

        printf("%lf", t2*1.0/t1);
        test_sample();
        return 0;
}

                      
