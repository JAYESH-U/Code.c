#include<stdio.h>
void main()
{
    int n,a[100],i,j,g,l=1,temp,rem=0,n1,d;
    printf("enter the number of elements to find LCM, GCD : ");
    scanf("%d",&n);
    printf("enter the elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        l=l*a[i];
    }
    //sorting
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
            if(a[i]>a[i+1])
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
    //logic
    n1=a[n-1];
    d=a[n-2];
    rem=n1%d;
    for(i=n-2;(i>=0);i--)
    {
        while(rem!=0)
        {
            n1=a[i];
            d=rem;
            rem=n%d;
        }
    }
    g=d;
    l=l/g;
    printf("LCM = %d\t GCD = %d",l,g);
}