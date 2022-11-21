#include<stdio.h>
void main()
{
    char op;
    double a,b;
    printf("\nenter the operator (+,-,*,/) : ");
    scanf("%c",&op);
    if(op=='+' || op=='-' || op=='*' || op=='/')
    {
        printf("\nenter the value of two operands : ");
        scanf("%lf%lf",&a,&b);
        if(op=='+')
        {
            printf("%.1lf + %.1lf = %.1lf",a,b,a+b);
        }
        else if(op=='-')
        {
            printf("%.1lf - %.1lf = %.1lf",a,b,a-b);
        }
        else if(op=='*')
        {
            printf("%.1lf * %.1lf = %.1lf",a,b,a*b);
        }
        else if(op=='/')
        {
            printf("%.1lf / %.1lf = %.1lf",a,b,a/b);
        }
    }
    else
            printf("\nerror! entered operator is invalid...");
}