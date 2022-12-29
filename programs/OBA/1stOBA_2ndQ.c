/*
Problem Statement 2: Given an array arr[] and an integer K where K is smaller
than size of array, the task is to find the Kth smallest element in the given array. It
is given that all array elements are distinct

Example-->
Input:
N = 6
arr[] = 7 10 4 3 20 15
K = 3
Output: 7
Explanation:
    3rd smallest element in the given array is 7
*/

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n, *a, k, i, j;

    printf("N : ");
    scanf("%d", &n);

    // dynamic memory allocation for array.
    a = (int *)malloc(n * sizeof(int));

    // array input
    printf("arr[] : ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("K : ");
    scanf("%d", &k);

    // sorting the array in ascending order.
    for (i = 0; i < n; i++)
        for (j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }

    // printing the kth smallest element in the array.
    // as Array starts from index 0, we print k-1 th element.
    printf("Output : %d", a[k - 1]);
}