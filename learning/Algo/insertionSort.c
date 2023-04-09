#include<stdio.h>

void insertionSort(int a[], int n)
{
    for(int i=1;i<n;i++)
    {
        int key = a[i];
        int j=i-1;
        while(j>=0 && (a[j]>key))
        {
            int t=a[j];
            a[j]=a[j+1];
            a[j+1] = t;
            j--;
        }
    }
}

int main()
{
    int a[10] = {1,19,5,15,11,13,7,3,17,9};
    insertionSort(a,10);

    for(int i=0;i<10;i++)
        printf("%d ",a[i]);
    printf("\n");
}