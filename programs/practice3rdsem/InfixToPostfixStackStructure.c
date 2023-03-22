#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct stack
{
    int size, top, *s;
} st;

void createStack(int n)
{
    st.s = (int *)malloc(n * sizeof(int));
    st.top = -1;
    st.size = n;
    printf("\nThe stack st has been created.\n");
}

void push(char x)
{
    if (st.top < st.size)
    {
        st.s[++st.top] = x;
        // printf("\nPushed %c into stack.",x);
    }
    else
        printf("\nStack is full.");
}

char pop()
{
    if (st.top < 0)
    {
        printf("\nStack is empty.");
        return 0;
    }
    // printf("\nPopped %c.",st.s[st.top]);
    return st.s[st.top--];
}

int priority(char c)
{
    if (c == '(')
        return 0;
    else if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
}

void main()
{
    char e[100];
    printf("Enter Infix expression : ");
    scanf("%s", e);

    // printf("sizeOfExp = %d",strlen(e));

    createStack(strlen(e));

    int i;
    for (i = 0; e[i] != '\0'; i++)
    {
        char x;
        if (isdigit(e[i]))
            printf("%c", e[i]);
        else if (e[i] == '(')
            push(e[i]);
        else if (e[i] == ')')
        {
            while ((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while (priority(st.s[st.top]) >= priority(e[i]))
                printf("%c", pop());
            push(e[i]);
        }
    }
    while (st.top != -1)
        printf("%c", pop());
}
