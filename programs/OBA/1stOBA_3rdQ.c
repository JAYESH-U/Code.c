/*
Problem Statement 3: Given an array a[] of size N which contains elements from 0
to N-1, you need to find all the elements occurring more than once in the given array.

Example 1:
Input:
N = 4
a[] = {0,3,1,2}
Output: -1
Explanation: N=4 and all elements from 0
to (N-1 = 3) are present in the given
array. Therefore output is -1.

Example 2:
Input:
N = 5
a[] = {2,3,1,2,3}
Output: 2 3
Explanation: 2 and 3 occur more than once
in the given array.
*/

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n,*a,i,j,c=0;
    printf("N = ");
    scanf("%d",&n);

    //Dynamic memory allocation for array   
    a = (int*)malloc(n*sizeof(int));

    printf("a[] = ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    //sorting of array by bubble sort.
    for(i=0;i<n;i++)
        for(j=0;j<n-i-1;j++)
            if(a[j]>a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }

    printf("Output : ");
    for(i=0;i<n;i++)
    {
        int f =0;
        //incrementing the index if element is same.
        while(i<n-1 && a[i]==a[i+1])    
        {
            f=1;
            c++;    //incrementing count if repeating elements encountered.
            i++;
        }
        //print the element if flag is not zero.
        if(f)
            printf("%d ",a[i-1]);
    }

    //if c is zero then print -1.
    if(!c)
        printf("-1");
}