#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,i,j,m,f;
    printf("enter the range : ");
    scanf("%d%d",&n,&m);
    printf("the prime numbers are : ");
    for(i=n;i<=m;i++)
    {
        f=0;
        for(j=2;j<=i/2;j++)
        {
            if(i%j==0)
                f=1;
        }
        if(f==0)
            printf("%d ",i);
    }
}