#include<stdio.h>
void main()
{
    int a,n=0;
    printf("enter the number : ");
    scanf("%d",&a);
    while(a!=0)
    {
        a=a/10;
        n++;
    }
    printf("the number of integers in a number is : %d",n);
}