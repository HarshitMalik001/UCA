#include <stdio.h>
#include <assert.h>

void exch(int arr[], int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void quick_sort(int arr[], int first, int last)
{
  if(first >= last) return;
  int i = first + 1, j = first + 1;

  while(i <= last)
    {
      if(arr[i] < arr[first])
      {
        exch(arr, j++ , i);
      }
      i++;
    }
  exch(arr, --j, first);
  quick_sort(arr, first, j - 1);
  quick_sort(arr, j + 1, last);
}

void quick_sort_recursion(int arr[], int size)
{
  quick_sort(arr, 0, size - 1);
}

void test_sample()
{
  int arr[] = {7,3,2,7,4,1,0};
  int exp_arr[] = {0,1,2,3,4,7,7};
  quick_sort_recursion(arr, 7);

  for(int i = 0; i < 7; i++)
    {
      assert(arr[i] == exp_arr[i]);
    }
}

int main()
{
  test_sample();
  return 0;
}
