#include<stdio.h>
void main()
{
    int a[100],i,h,l,m,n,f,k;
    printf("enter the number of array elements : ");
    scanf("%d",&n);
    printf("enter the array elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("enter the key element to search : ");
    scanf("%d",&k);
    l=0;
    h=n-1;
    f=0;
    while(l<=h)
    {
        m=(l+h)/2;
        if(a[m]=k)
        {
            f=1;
            break;
        }
        else
        {
            if(a[m]>k)
                h=m-1;
            else
                l=m+1;
        }
    }
    if(f==1)
        printf("key word %d is found.",k);
    else
        printf("key word %d is found.",k);
}