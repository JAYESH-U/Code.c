#include <stdio.h>

void floyd(int a[4][4], int n)
{
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (a[i][j] > a[i][k] + a[k][j])
					a[i][j] = a[i][k] + a[k][j];
					
	printf("All Pairs Shortest Path is :\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

int main()
{
	int i, j;
	int cost[4][4] = {{0, 3, 999, 4},
					  {8, 0, 2, 999},
					  {5, 999, 0, 1},
					  {2, 999, 999, 0}};

	int n = 4;

	printf("path between each pair:\n");
	for (int i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			// printf("(%d,%d) -> %d\n",i,j,cost[i][j]);
			if (cost[i][j] == 999)
				printf("* ");
			else
				printf("%d ", cost[i][j]);
		}
		printf("\n");
	}
	

	floyd(cost, n);
}
