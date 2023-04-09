#include<stdio.h>

void mergeSort(int a[], int b[], int c[], int l1, int l2)
{
    int i=0, j=0, k=0;
    for(; i<l1 && j<l2;)
    {
        if(a[i]>=b[j])
            c[k++]=b[j++];
        else 
            c[k++] = a[i++];
    }
    while(i!=l1&&i<l1)
        c[k++]=a[i++];
    
    while(j!=l2&&j<l2)
            c[k++] =b[j++];
}


int main()
{
    int a[12] = {1,3,5,7,9,11,13,15,17,19,22,24};
    int b[10] = {2,4,6,8,10,12,14,16,18,20,};
    int c[40];
    mergeSort(a,b,c,12,10);

    for(int i=0;i<22;i++)
        printf("%d ",c[i]);
    printf("\n");
}