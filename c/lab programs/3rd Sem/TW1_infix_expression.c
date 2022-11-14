/*
    write a c Program to check correctness of infix expression and evaluate it using stacks
*/

#include <stdio.h>
int main()
{
    char a[100], stk[20], oper;
    int i, j = 0, st[3];
    printf("enter the expression\n");
    scanf("%s", a);
    for (i = 0; a[i] != '\0'; i++)
        if (a[i] == '(')
            stk[j++] = '(';
        else if (a[i] == ')')
            j--;
    if (j == 0)
    {
        printf("valid expression\n");
        for (i = 0; a[i] != '\0'; i++)
        {
            if (a[i] == '(')
                continue;
            else if (a[i] == ')')
            {
                switch (oper)
                {
                case '+':
                    printf("%d+%d\n", st[j - 1], st[j - 2]);
                    st[j - 2] = st[j - 1] + st[j - 2];
                    j -= 1;
                    break;
                case '*':
                    st[j - 2] = st[j - 2] * st[j - 1];
                    j -= 1;
                    break;
                case '-':
                    st[j - 2] = st[j - 2] - st[j - 1];
                    j -= 1;
                    break;
                case '/':
                    st[j - 2] = st[j - 2] / st[j - 1];
                    j -= 1;
                }
            }
            else
            {
                if (a[i] >= '0' && a[i] <= '9')
                {
                    st[j++] = a[i] - '0';
                }
                else
                {
                    oper = a[i];
                }
            }
        }
        printf("ans = %d", st[0]);
    }
    else
        printf("invalid");

    return 0;
}