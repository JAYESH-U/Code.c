#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,i,r,p=0,s=0;
    printf("enter a number : ");
    scanf("%d",&n);
    while(n!=0)
    {
        s=0;
        while(n!=0)
        {
            r=n%10;
            s=s+r;
            n=n/10;
        }
        p++;
        if(s>10)
            n=s; 
    }
    printf("additive persistance is : %d",p);
}