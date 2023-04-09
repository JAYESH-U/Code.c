#include<stdio.h>

void mergeSort(int a[], int l, int m, int h)
{
    int i=0, j=0;
    int k=l;
    int s1 = m-l+1;
    int s2 = h-m;
    // int c[s1], b[s2];
    
    int c[11], b[11];

    for(int p=0;p<s1;p++)
        c[p] = a[l+p];
    for(int q=0;q<s2;q++)
        b[q] = a[m+q+1];

    for(; i<s1 && j<s2;)
    {
        if(c[i]>=b[j])
            a[k++]=b[j++];
        else 
            a[k++] = c[i++];
    }
    while(i!=s1&&i<s1)
        a[k++]=c[i++];
    
    while(j!=s2&&j<s2)
        a[k++] =b[j++];
}

void sort(int a[],int l, int h)
{
    if(l<h)
    {
        int m = (l+h)/2;
        sort(a,l,m);
        sort(a,m+1,h);
        mergeSort(a,l,m,h);
    }
}

int main()
{
    int a[10] = {1,19,5,15,11,13,7,3,17,9};
    sort(a,0,10);

    for(int i=0;i<10;i++)
        printf("%d ",a[i]);
    printf("\n");
}