#include<stdio.h>

int pass(int a[],int n)
{
    a[n-1] = 10;
    //array elements will change
}

void main()
{
    int a[10] = {1,2,3,4,5};
    int n = 5;
    printf("\nBefore Pass :");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

    pass(a,n);

    printf("\nAfter Pass : ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}