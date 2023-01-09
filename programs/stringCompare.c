#include<stdio.h>
#include<string.h>

void main()
{
    char a[10] = "2GI21is024";
    char b[10] = "2GI21cs024";
    printf("strupr(a) = %s\n",strupr(a));
    printf("strupr(b) = %s\n",strupr(b));
    int diff = strcmp(b,a);
    printf("Diff = %d\n",diff);
}
