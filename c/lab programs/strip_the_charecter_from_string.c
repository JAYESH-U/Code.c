#include<stdio.h>
void main()
{
    int i, j, n=0;
    char s[100], ch, temp;
    printf("enter the string : ");
    scanf("%s",&s);
    printf("enter the charecter : ");
    scanf(" %c",&ch);
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]==ch)
        {
            n=n+1;
            for(j=i;s[j]!='\0';j++)
                s[j]=s[j+1];
            i=i-1;
        }
    }
    printf("the occourance of the charecter is : %d\n",n);
    printf("the string is : %s\n",s);
}