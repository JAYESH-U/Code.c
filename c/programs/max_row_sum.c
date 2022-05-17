#include<stdio.h>
void main()
{
    int a[100][100],i,j,rs[100],m,n,l=0,ls;
    printf("enter the number of students : ");
    scanf("%d",&m);
    printf("enter the number of subjects : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {   
        rs[i]=0;
        printf("enter the marks of student %d : ",i);
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            rs[i]=rs[i]+a[i][j];
        }
        if(rs[i]>=l)
        {
            l=rs[i];
            ls=i;
        }
    }
    printf("the largest marks of the student is %d by student number %d.",l,ls);
}