#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void push(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if (t == NULL)
        printf("\nstack is full");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    struct Node *t;
    int x = -1;

    if (top == NULL)
    {
        printf("\nStack is Empty");
        return x;
    }
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    if(x!=-1)
        printf("\npopped : %d", x);
    else
        printf("\nStack is Empty");

    return x;
}

void Display()
{
    printf("\nStack : ");
    struct Node *p;
    p = top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    //printf("\n");
}

int main()
{
    push(10);
    push(20);
    push(30);

    Display();

    pop();
    pop();
    pop();
    pop();
    
    Display();

    return 0;
}