#include<stdio.h>
void main()
{
    int n,i;
    printf("enter the number : ");
    scanf("%d",&n);
    printf("the factors are : ");
    for(i=1;i<=n;i++)
    {
            if(n%i==0)
                printf("%d ",i);
    }
}