#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *left, *right;
} *first = NULL;

void insertFront(struct node *p, int x)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->left = NULL;
    t->right = p;
    first = t;
}

void insertRear(struct node *p, int x)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->right = NULL;
    while (p->right != NULL)
    {
        p = p->right;
    }
    p->right = t;
    t->left = p;
}

void insertAtRight(struct node *p, int k, int x)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    struct node *q = p->right;
    t->data = x;
    while (p->data != k && p)
    {
        p = q;
        q = p->right;
    }
    t->right = q;
    t->left = p;
    p->right = t;
    if(q)
         q->left = t;
}

void insertAtLeft(struct node *p, int k, int x)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    struct node *q=NULL;
    t->data = x;
    while (p->data != k && p)
    {
        q = p;
        p = p->right;
    }
    t->right = p;
    t->left = q;
    p->left = t;
    if(q)
        q->right = t;
    first = t;
}

void display(struct node *p)
{
    printf("\n");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->right;
    }
}

void main()
{
    insertFront(first, 10);
    insertFront(first, 20);
    insertFront(first, 30);

    insertRear(first, 40);
    insertRear(first, 50);
    insertRear(first, 60);

    // insertAtRight(first, 60, 70);

    insertAtLeft(first, 30, 70);

    display(first);
}