#include  <stdio.h>

int recursion(int matrix[][100], int i,int j, int n, int m)
{
    if(i >= n || j >= m) return 0;
    if(i == n && j == m)
    {
        int l = matrix[i][j];
        printf("%d \n",l);
        return l;
    }

    // right

    int a = recursion(matrix, i + 1, j , n, m) + matrix[i][j] ;

    // down
    int b = recursion(matrix, i, j + 1 , n, m) + matrix[i][j] ;

    if (a > b) return a;
    return b;
}

int main()
{
    int n;
    int m;
    scanf("%d",&n);
    scanf("%d",&m);

    int matrix[100][100];

    for(int i = 0; i < n; i++)
    {

        for(int j = 0; j < m; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    
    printf("%d",recursion(matrix , 0, 0, n, m));
    return 0;
}