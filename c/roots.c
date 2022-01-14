#include<stdio.h>
#include<math.h>
void main()
{
    float a,c,b,d=0,root1=0,root2=0,imag=0,real=0;
    printf("enter the values of three numbers : ");
    scanf("%f%f%f",&a,&b,&c);
    d=(b*b)-(4*a*c);
    printf("degree is : %f\n",d);
    if(d>0)
    {
        printf("\nroots are real and distinct : \n");
        root1=(-b+(sqrt(d)))/(2*a);
        root1=(-b-(sqrt(d)))/(2*a);
        printf("root1 : %.2f\n",root1);
        printf("root2 : %.2f\n",root2);
    }
    else if(d==0)
    {
        root1=root2=-b/(2*a);
        printf("root1 : %.2f\n",root1);
        printf("root2 : %.2f\n",root2);
    }
    else
    {
        printf("roots are imaginary\n");
        real=-b/(2*a);
        imag=(sqrt(-d)) / (2 * a);
        printf("root1=%.2f+%.2fi\n",real,imag);
        printf("root1=%.2f-%.2fi\n",real,imag);
    }
}