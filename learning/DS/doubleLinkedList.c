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
    if(p)
        p->left = t;
    first = t;
    printf("Inserted %d at front.\n", x);
}

void insertRear(struct node *p, int x)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->right = NULL;
    if (!p)
    {
        t->left = NULL;
        first = t;
        printf("List is null and Inserted %d at rear.\n", x);
        return;
    }

    else
    {
        while (p->right != NULL)
        {
            p = p->right;
        }
    }

    p->right = t;
    t->left = p;
    printf("Inserted %d at rear.\n", x);
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
    if (q)
        q->left = t;
    printf("Inserted %d at right of %d.\n", x, k);
}

void insertAtLeft(struct node *p, int k, int x)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    struct node *q = NULL;
    t->data = x;
    while (p->data != k && p)
    {
        q = p;
        p = p->right;
    }
    t->right = p;
    t->left = q;
    p->left = t;
    if (q)
        q->right = t;
    else
        first = t;
    printf("Inserted %d at left of %d.\n", x, k);
}

void display(struct node *p)
{
    printf("List : ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->right;
    }
    printf("\n\n");
}

void reverse(struct node *p)
{
    struct node *q = NULL;
    while (p)
    {
        q = p->right;
        p->right = p->left;
        p->left = q;
        p = p->left;
        if (p && p->right == NULL)
            first = p;
    }
}

void delete(struct node *p, int x)
{
    struct node *q = NULL;
    if(p->data == x)
    {
        first = p->right;
        p->right->left =NULL;
    }
    else
    {
        while (p->data != x)
        {
            q = p;
            p = p->right;
        }
        if(p->right)
        {
            q->right = p->right;
            p->right->left = q;
        }
        else
        {
            p->left->right = NULL;
        }
    }
    free(p);
    printf("\ndeleted %d.\n",x);
}

void main()
{

    insertFront(first, 30);
    insertFront(first, 20);
    insertFront(first, 10);
    display(first);

    insertRear(first, 50);
    insertRear(first, 60);
    insertRear(first, 70);
    display(first);

    insertAtRight(first, 70, 80);
    insertAtLeft(first, 50, 40);
    display(first);

    delete(first,80);
    display(first);

    reverse(first);
    printf("reversed ");
    display(first);
}