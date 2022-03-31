#include<stdio.h>
void main()
{
    char ch;
    printf("enter the charecter : ");
    scanf("%c",&ch);
    switch(ch)
    {
        case 'a': printf("%c is a vowel.",ch);
            break;
        case 'e': printf("%c is a vowel.",ch);
            break;
        case 'i': printf("%c is a vowel.",ch);
            break;
        case 'o': printf("%c is a vowel.",ch);
            break;
        case 'u': printf("%c is a vowel.",ch);
            break;
        default: printf("%c is a consonant.",ch);
            break;
    }
}