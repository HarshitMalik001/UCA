// A Google Interview Question: -

// Find the maximum length substring containing at most 2 distinct characters

// Example -

// S = “eceba”

// Ans = 3

// Explanation: - “ece” has at most 2 distinct character e and c and is the largest substring with the fulfilled conditions

#include <stdio.h>

int len(char test[])
{
    int n = 0;
    while(test[n] != '\0')
    {
        n++;
    }
    return n;
}

int main()
{
    char test[100];
    scanf("%s", test);
    printf("%s \n", test);
    
    int arr[26];
    for(int i = 0; i < 26; i++) arr[i] = 0;
    int n = len(test);
    int count = 0;

    int start = 0;
    int max_ = 0;
    for(int end = 0; end < n; end++)
    {
        if(arr[test[end] - 'a'] == 0) count++; 
        arr[test[end] - 'a']++;

        if(count > 2)
        {
            while(count > 2)
            {
                arr[test[start] - 'a']--;
                if(arr[test[start] - 'a'] == 0) count--;
                start++;
            }
        }

        max_ = (end - start + 1) > max_ ? end - start + 1: max_ ; 
    }

    printf("%d\n",max_);

    return 0;
}