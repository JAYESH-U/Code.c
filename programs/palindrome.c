#include<stdio.h>
void main()
{
    int a,rem,rev=0,temp;
    printf("enter the number to reverse : ");
    scanf("%d",&a);
    temp=a;
    while(a!=0)
    {
        rem=a%10;
        rev=rev*10+rem;
        a=a/10;
    }
    if(temp==rev)
        printf("the number %d is a palindrome",temp);
    else
        printf("the number %d is a not a palindrome",temp);    
}