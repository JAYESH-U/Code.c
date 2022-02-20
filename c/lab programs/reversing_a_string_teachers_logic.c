#include<stdio.h>
#include<string.h>
void main()
{
    char a[50],temp;
    int j=0,i=0,c=0;
    printf("enter the string the you want to reverse : ");
    gets(a);
    while (a[j]!='\0')
    {
        j++;
    }
    j=j-1;
    while (i<j)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;
        j--;
    }
    printf("the reversed string is : %s\n",a);
}