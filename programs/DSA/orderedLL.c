#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *first = NULL;

void insert(struct node *p, int x)
{
    struct node *q = NULL;
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;

    if (!p)
    {
        first = t;
        printf("\nInserted fist %d", first->data);
        return;
    }

    while (p->data < t->data && p->next)
    {
        q = p;
        p = p->next;
    }

    if (p == first && p->data > x)
    {
        t->next = p;
        first = t;
        printf("\nInserted beggining %d", t->data);
    }
    else if (p->data >= x)
    {
        t->next = p;
        q->next = t;
        printf("\nInserted middle %d", t->data);
    }
    else
    {
        p->next = t;
        printf("\nInserted end %d", t->data);
    }
}

void display(struct node *p)
{
    printf("\nList : ");
    while(p)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}

void main()
{
    insert(first, 10);
    insert(first, 20);
    insert(first, 30);
    insert(first, 40);

    insert(first, 5);
    insert(first, 35);

    display(first);
}