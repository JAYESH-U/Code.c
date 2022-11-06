#include<stdio.h>
void main()
{
    float n,f=0;
    int i,r,ds=0,fs=0,d=0;
    printf("enter a number : ");
    scanf("%f",&n);
    d=n;
    f=n-d;
    printf("%f %d\n",f,d);
    while(d!=0)
    {
        r=d%10;
        ds=ds+r;
        d=d/10;
    }
    while(f!=0)
    {
        f=f*10;
        i=f;
        printf("%d\n",i);
        fs=fs+i;
        f=f-i;
    }
    printf("%d %d\n",fs,ds);
}//not completed
