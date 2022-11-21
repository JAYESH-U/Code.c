#include<stdio.h>
void main()
{
    int n, a[20], i, j, temp;
    printf("Enter number of array elements : ");
    scanf("%d", &n);
    printf("Enter %d numbers :", n);
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    for(i=0; i<n-1; i++)
        for(j=0; j<n-i-1; j++)
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
    printf("Sorted array is:");
    for(i=0; i<n; i++)
        printf("%d ", a[i]);
}