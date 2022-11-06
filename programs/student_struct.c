#include<stdio.h>
struct student
{
    char n[100];
    int rn,m1,m2,m3,sum;
    float avg;
};
void main()
{
    struct student s[100];
    int n,i,ln;
    float l;
    printf("enter the number of students : ");
    scanf("%d",&n);
    printf("enter name, roll number, marks of three subjects : ");
    for(i=0;i<n;i++)
    {
        scanf("%s%d%d%d%d",s[i].n,&s[i].rn,&s[i].m1,&s[i].m2,&s[i].m3);
        s[i].sum=s[i].m1+s[i].m2+s[i].m3;
        s[i].avg=s[i].sum/3;
        if(s[i].avg>l)
        {
            l=s[i].avg;
            ln=i;
        }
    }
    printf("name\troll.no\ttotal.m\taverage:\n");
    for(i=0;i<n;i++)
    {
        printf("%s\t%d\t%d\t%.3f\n",s[i].n,s[i].rn,s[i].sum,s[i].avg);
    }
    printf("highest average marks is %.3f by %s.",l,s[ln].n);
}