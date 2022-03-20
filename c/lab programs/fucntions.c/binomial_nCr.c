#include<stdio.h>
float fact(int);
void main()
{
    int n,r;
    float ncr;
    printf("enter the values of n and r : ");
    scanf("%d%d",&n,&r);
    ncr=(fact(n)/(fact(n-r)*fact(r)));
    printf("n=%d, r=%d ,nCr=%.1f",n,r,ncr);
}
float fact(int n)
{
    if(n==0)
        return 1;
    else
        return (n*fact(n-1));
}