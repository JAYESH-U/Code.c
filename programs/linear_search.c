#include<stdio.h>
#include<stdlib.h>
void main()
{
    int k,a[10],i,f=0,n;
    printf("enter the number of array elements : ");
    scanf("%d",&n);
    printf("enter the array elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("enter the keyword should be searched : ");
    scanf("%d",&k);
    for(i=0;i<n;i++)
        if(a[i]==k)
        {
            printf("the key is found...\n");
            exit(0);
        }
    if(f==0)
        printf("not found..");
    printf("thanks");
}