/*
Problem Statement 1: Given an unsorted array A of size N that contains
only non-negative integers, find a continuous sub-array which adds to a given
number S and return the left and right index of that subarray.
In case of multiple subarrays, return the subarray indexes which comes first on
moving from left to right.
Note : Assume first element is stored at index 1 and not at 0

Input:
N = 5, S = 12
A[] = {1,2,3,7,5}
Output: 2 4
Explanation:
    The sum of elements from 2nd position to 4th position is 12.
*/

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n, s, *a, i, j, fi, li = 0;
    printf("N : ");
    scanf("%d", &n);

    //dynamic memory allocation.
    a = (int *)malloc(n * sizeof(int));

    printf("S : ");
    scanf("%d", &s);

    printf("A[] : ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    //searching for substring
    for (i = 0; i < n; i++)
    {
        fi = i + 1; //first index initialization.
        int sum = 0;
        for (j = i; j < n; j++)
        {
            sum += a[j];    //addition of elemets of substring
            if (sum == s)
            {
                li = j + 1; //last index initialization.
                i = n;  //terminate first for loop.
            }
            else if (sum > s)
                break;  //break loop.
        }
    }
    printf("Output : %d %d", fi, li);
}