#include<stdio.h>
void main()
{
    int income, tax=0;
    printf("enter the salary : ");
    scanf("%d",&income);
    if(income<=250000)
        tax=0;
    else if(income>250000 && income<=500000)
        tax=(income-250000)*0.1;
    else if(income>500000 && income<=1000000)
        tax=25000+(income-500000)*0.2;
    else
        tax=125000+(income-1000000)*0.3;
    
    printf("the income is : %d\n",income);
    printf("the taxpay is : %d\n",tax);
}