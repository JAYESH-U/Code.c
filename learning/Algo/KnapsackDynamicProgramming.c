#include <stdio.h>

void displayIncludedIndexes(int w[], int i, int j, int k[5][9])
{
    printf("Weights and inclusion :\n");
    while (i > 0 || j > 0)
    {
        if (k[i][j] == k[i - 1][j])
            printf("\t%d = 0\n", w[i--]);
        else
        {
            j -= w[i];
            printf("\t%d = 1\n", w[i--]);
        }
    }
}

int max(int i, int j)
{
    if (i > j)
        return i;
    return j;
}

int main()
{
    int p[5] = {0, 1, 2, 5, 6};
    int w[5] = {0, 2, 3, 4, 5};
    int m = 8, n = 4;
    int k[5][9];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                k[i][j] = 0;
            else if (w[i] <= j)
                k[i][j] = max(p[i] + k[i - 1][j - w[i]], k[i - 1][j]);
            else
                k[i][j] = k[i - 1][j];
        }
    }
    printf("Max weight can be carried : %d\n", k[n][m]);

    displayIncludedIndexes(w, n, m, k);
}