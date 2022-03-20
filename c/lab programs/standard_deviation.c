#include<stdio.h>
#include<math.h>
void main()
{
    int i, n, a[100];
    float sum=0, mean=0, std=0, sum_std=0;
    int *p;
    printf("enter the size of array : ");
    scanf("%d",&n);
    printf("enter the array elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    p=&a[0];
    for(i=0;i<n;i++)
    {
        sum=sum+*p;
        p++;
    }
    mean=sum/n;
    p=&a[0];
    for(i=0;i<n;i++)
    {
        sum_std=sum_std+pow((*p-mean),2);
        p++;
    }
    std=sqrt(sum_std/n);
    printf("sum is : %f\n",sum);
    printf("mean is : %f\n",mean);
    printf("standard deviation is : %f",std);
}