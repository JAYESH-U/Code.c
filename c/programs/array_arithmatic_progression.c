//....-4,-2,0,2,4....
//or
//....-5,-3,-1,1,3,5.....
#include<stdio.h>
void main()
{
    int n,i,s;
    printf("enter the number of numbers you want to print : ");
    scanf("%d",&n);
    s=-(n-1);
    printf("the numbers are : ");
    for(i=1;i<=n;i++)
    {
        printf("%d ",s);
        s=s+2;
    }
    printf("\n");
}