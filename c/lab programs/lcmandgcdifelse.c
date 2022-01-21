#include<stdio.h>
void main()
{
    int n1,n2,gcd,lcm,rem,n,d;
    printf("enter two numbers : ");
    scanf("%d%d",&n1,&n2);
    if(n1>n2)
    {
        n=n1;
        d=n2;
    }
    else
    {
        n=n2;
        d=n1;
    }
    rem=n%d;
    while(rem!=0)\
    {
        n=d;
        d=rem;
        rem=n%d;
    }
    gcd=d;
    lcm=(n1*n2)/gcd;
    printf("the lcm and gcd of %d and %d is : %d and %d\n",n1,n2,lcm,gcd);
}