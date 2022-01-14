#include<stdio.h>
void main()
{
    char op;
    double a,b;
    printf("enter the operand (+,-,*,/) : ");
    scanf("%c",&op);
    printf("enter the value of two operands : ");
    scanf("%lf%lf",&a,&b);
    switch (op)
    {
        case '+':
        printf("%.1lf + %.1lf = %.1lf",a,b,a+b); // writing %.1f or %.2f will reduce the precision to 1 or 2 digits respectively.
        break;

        case '-':
        printf("%.1lf - %.1lf = %.1lf",a,b,a-b);
        break;

        case '*':
        printf("%.1lf * %.1lf = %.1lf",a,b,a*b);
        break;

        case '/':
        printf("%.1lf / %.1lf = %.1lf",a,b,a/b);
        break;

        default:
        printf("error! entered operator is invalid");
    }
}