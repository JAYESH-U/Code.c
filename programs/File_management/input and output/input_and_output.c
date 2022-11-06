#include<stdio.h>
void main()
{
    FILE *f;
    char c;

    f=fopen("input","w");

    printf("enter the data (type ; to end): ");
    while((c=getchar())!=';')
        putc(c,f);
    
    fclose(f);

    f=fopen("input","r");

    printf("the file contents are : ");
    while((c=getc(f))!=EOF)
        printf("%C",c);
    
    fclose(f);
}