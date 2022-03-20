#include<stdio.h>
float fact(int);
void main()
{
    int n,r;
    float ncr;
    printf("enter the values of n : ");
    scanf("%d",&n);
    ncr=fact(n);
    printf("n=%d, r=%d ,nCr=%.1f",n,r,ncr);
}
float fact(int n)
{
    if(n==0)
        return 1;
    else
        return (n*fact(n-1));
}