#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left, *right;
} *root = NULL;

struct node *createNode(int x)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->right = t->left = NULL;
    return t;
}

void insert(struct node *p, int x)
{
    struct node *t = createNode(x);
    struct node *q = NULL;
    if (!p)
    {
        root = t;
        printf("\n%d is the root.\n",x);
        return;
    }
    else
    {
        while (p)
        {
            q = p;
            if(t->data < p->data)
                p = p->left;
            else
                p = p->right;
        }
        if(t->data < q->data)
        {
            q->left = t;
            printf("\n%d is inserted at left.",x);
        }
        else
        {
            q->right = t;
            printf("\n%d is inserted at right.",x);
        }
    }
    printf("\nNode with data %d has been inserted.\n",x);
}

void display(struct node *p)
{
    if(p==NULL)
        return; 
    display(p->left);
    printf("%d ",p->data);
    display(p->right);
}

void main()
{
    insert(root,10);
    insert(root,20);
    insert(root,15);
    insert(root,25);
    insert(root,05);
    
    printf("\nsorted Tree : ");
    display(root);
}