#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
    int h=0,m=0,s=0;
    double i=0;
    system("cls");
    printf(" enter the time in hh:mm:ss = ");
    scanf("%d%d%d",&h,&m,&s);
    start:
    for(h;h<24;h++)
    {
        for(m;m<60;m++)
        {
            for(s;s<60;s++)
            {
                system("cls");
                printf("%d:%d:%d",h,m,s);
                if(h<12)
                   {
                       printf("am");
                   }
                   else
                   {
                      printf("pm");
                   }
                for(i=0;i<86199999;i++)
                {
                    i++;
                    i--;
                }
            }
            s=0;
        }
        m=0;
    }
    h=0;
    goto start;
    getch();
}
