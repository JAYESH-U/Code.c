#include<stdio.h>
void main()
{
        int a,rem,rev=0,n=0;
        printf("enter the number to reverse : ");
        scanf("%d",&a);
        while(a!=0)
        {
            rem=a%10;
            rev=rev*10+rem;
            a=a/10;
            n++;
        }
        printf("the reversed number is : %d\n",rev);
        printf("the number digits is : %d",n);
}