#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
    float x, salary;
    start:
    printf("enter the number of products sold : ");
    scanf("%f",&x);
    if(x<100)
        salary=4*x+100;
    else if(x==100)
        salary=300;
    else
        salary=4.5*x+150;
    printf("the salary of the worker is : %f\n",salary);
    goto start;
}