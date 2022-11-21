#include<stdio.h>
void main()
{
    int n=0,i=0,f;
    char s[100],temp;
    printf("enter the sting : ");
    scanf("%s",s);
    while(s[i]!='\0')
    {
        i++;
    }
    n=i-1;
    i=0;
    while(i<n)
    {
        if(s[i]!=s[n])
        {
            f=1;
            break;
        }
        i++;
        n--;
    }
    if(f==1)
        printf("not a palindrome.");
    else
        printf("string is a pallindrome.");
}