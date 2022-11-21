#include<stdio.h>
void main()
{
    FILE *f;
    int n,q,i,nm;
    float p,v;
    char item[100],fn[100];

    printf("enter the filename : ");
    scanf("%s",fn);

    f=fopen(fn,"w");

    printf("enter the number of items : ");
    scanf("%d",&nm);

    printf("input the %s data : \n",fn);
    printf("Item name   number  price   quantity ");
    for(i=0;i<nm;i++)
    {
        fscanf(stdin,"%s %d %f %d",item,&n,&p,&q);
        fprintf(f,"%s %d %f %d",item,n,p,q);
    }

    fclose(f);
    fprintf(stdout,"\n\n");

    f=fopen(fn,"r");

    printf("Item name   number  price   quantity value\n");
    for(i=0;i<nm;i++)
    {
        fscanf(f,"%s %d %f %d",item,&n,&p,&q);
        v=p*q;
        fprintf(stdout,"%-8s %7d %8.2f %8d %11.2f\n",item,n,p,q,v);
    }
    fclose(f);
}