#include<stdio.h>
float fact(int);
void main()
{
    int n,r;
    float f;
    printf("enter the values of n : ");
    scanf("%d",&n);
    f=fact(n);
    printf("fact=%.1f",f);
}
float fact(int n)
{
    if(n==0)
        return 1;
    else
        return (n*fact(n-1));
}
//fact(5)
//fact(5) * fact (4)
//fact(5) * fact (4) * fact (3)
//so on..........