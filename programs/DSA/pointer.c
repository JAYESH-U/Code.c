#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i=100;
    int *j=&i;
    // // j=0;
    // printf("%d\n",i);
    // printf("%d\n",&i);
    // printf("%d\n",j);
    // printf("%d\n",*j);//if j=0; this won't print anything as j is pointing nowhere.
    int *pa,a[10];
    // pa=(int*)malloc(n*sizeof(int));
    pa=a;
    for(i=0;i<10;i++)
    {
        scanf("%d",pa+i);
    }
    int k;
    scanf("%d",&k);
    for(i=0;i<10;i++)
    {
        if(*(pa+i)==k)
            printf("%d ",*(pa+i));
    }
}