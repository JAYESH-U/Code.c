#include<stdio.h>
#include<string.h>
int main()
{
    FILE *f1,*f2;
    char ch, ch1, line[100];
    f1=fopen("input.txt","w");
    printf("enter the text (type END to terminate) : ");
    do
    {
        gets(line);
        if(strcmp(line,"END")==0)
            break;
        fputs(line,f1);
        fputs("\n",f1);
    } while (1);
    fclose(f1);
    f1=fopen("input.txt","r");
    f2=fopen("output.txt","w");
    while((ch=getc(f1))!=EOF)
    {
        if(ch==' ' && ch==ch1)
            continue;
        putc(toupper(ch),f2);
        ch1=ch;
    }
    fclose(f1);
    fclose(f2);
    printf("\ncopied to the output file. \n");
    return 0;

}