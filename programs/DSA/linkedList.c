#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *first = NULL, *last;

void create(int ele[], int n)
{
    struct node *p, *t;
    first = (struct node *)malloc(n * sizeof(struct node));
    first->data = ele[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = ele[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// void append(int ele[],int n)
// {
//     if(last==NULL)
//     {
//         printf("create a list first.!!");
//         return;
//     }
//     struct node *t;
//     for (int i = 1; i < n; i++)
//     {
//         t = (struct node *)malloc(sizeof(struct node));
//         t->data = ele[i];
//         t->next = NULL;
//         last->next = t;
//         last = t;
//     }
// }

void delete(int ele,struct node * p)
{
    while(p)
    {
        if(p->data == ele)
        {
            printf("Eement %d found.",ele);
        }
        p = p->next;
    }
}

void display(struct node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void main()
{
    int n, *ele, ch, k;
    while (1)
    {
        // system("CLS");
    start:
        // printf("Enter your choice :\n0.append,\n1.create new List,\n2.delete,\n3.display,\n4.exit.\n:");
        printf("Enter your choice :\n1.create new List,\n2.delete,\n3.display,\n4.exit.\n:");
        scanf("%d", &ch);
        switch (ch)
        {
        // case 0 :
        //     append(ele,n); break;
        case 1:
            printf("Enter number of data elements : ");
            scanf("%d", &n);
            ele = (int *)malloc(n * sizeof(int));
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &ele[i]);
            }
            create(ele, n);
            break;
        case 2:
            printf("Enter the element to delete : ");
            scanf("%d",&k);
            delete(k,first);
            break;
        case 3:
            display(first);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Input!!!");
            goto start;
        }
    }
}