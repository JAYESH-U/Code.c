#include<stdio.h>
void main()
{
    int n,i,j;
    printf("enter the number of lines of pattern you want to get : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=i;j>0;j--)
        {
            printf("%d",j);
        }
        printf("\n");
    }
}