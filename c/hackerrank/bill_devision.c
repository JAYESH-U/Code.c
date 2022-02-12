#include<stdio.h>
void main()
{
    int n,k,b[100000],bch,co,tb=0,htb,op,i;
    printf("enter the number of orders requested and cancelled : "); //position is terms of 0,1,2,3,4...
    scanf("%d%d",&n,&k);
    printf("enter the cost of orders : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
        tb=tb+b[i];
    }
    printf("enter the bill charged after splitting amount : ");
    scanf("%d",&bch);
    co=b[k];
    htb=(tb-co)/2;
    if(htb==bch)
        printf("bill is splitted into perfect halfs without considering the cancelled one.. ");
    else 
    {
        op=bch-htb;
        printf("difference between bill charged and actual bill : %d\n",op);  //actual bill= witout adding the cancelled order amount...
    }
}