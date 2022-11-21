#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
    float x, salary;
    start:
    printf("enter the number of products sold : ");
    scanf("%f",&x);
    salary=(x!=100)?((x<100)?(4*x+100):(4.5*x+150)):300;
    printf("the salary of the worker is : %f\n",salary);
    goto start;
}