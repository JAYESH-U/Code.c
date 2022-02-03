//my logic..........
#include<stdio.h>
#include<string.h>
void main()
{
    char a[50];
    int i,n=0;
    printf("enter the string the you want to reverse : ");
    gets(a);
    n=strlen(a);
    for(i=n-1;i>=0;i--)
        printf("%c",a[i]);
    printf("\n");
}