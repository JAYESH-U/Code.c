#include<stdio.h>
#include<stdlib.h>

int a[30], cnt;

int place(int pos)
{
    int i;
    for (i = 1; i < pos; i++)
    {
        if ((a[i] == a[pos]) || ((abs(a[i] - a[pos]) == abs(i - pos))))
            return 0;
    }
    return 1;
}

void queen(int n)
{
    cnt = 0;
    int k = 1;
    a[k] = 0;
    while (k != 0)
    {
        a[k] = a[k] + 1;
        while ((a[k] <= n) && !place(k))
            a[k]++;
        if (a[k] <= n)
        {
            if (k == n)
                print_sol(n);
            else
            {
                k++;
                a[k] = 0;
            }
        }
        else
            k--;
    }
}

void print_sol(int N)
{
    int i, j;
    cnt++;

    printf("\n\nSolution %d :\n",cnt);
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            if (a[i] == j)
                printf("Q\t");
            else
                printf("*\t");
        }
        printf("\n");
    }
}

void main()
{
    int N = 4;

    queen(N);
    printf("\nTotal solutions= %d", cnt);
}
