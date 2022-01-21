#include<stdio.h>
void main()
{
    int amt,w,b=10000,ch;
    while(1)
    {
        printf("\nmenu\n");
        printf("1.deposite cash. \n2,withdraw cash. \n3.check balance. \n4.exit.");
        printf("\nenter the choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1: printf("enter the amount to be diposited : ");
                scanf("%d",&amt);
                b=b+amt;
                break;
            case 2: printf("enter the amount to be withdrawed : ");
                scanf("%d",&w);
                if(w<=b)
                    b=b-w;
                else 
                    printf("insufficient balance in your account....");
                break;
            case 3: printf("the balance amount in your account is : %d\n",b);
                break;
            case 4: exit(0);
                break;
            default: printf("error!... enterd charector in invalid....");
                break;
        }
    }
}