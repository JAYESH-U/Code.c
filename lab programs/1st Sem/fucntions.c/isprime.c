#include<stdio.h>
int isprime(int);
void main()
{
    int n, p;
    printf("enter the number : ");
    scanf("%d",&n);
    p=isprime(n);
    if(p==0)
        printf("not a prime number..");
    else
        printf("prime number..");
}
int isprime(int n)
{
    int i;
    for (i=2;i<=n/2;i++)
        if(n%i==00)
            return 0;
    return 1;
}