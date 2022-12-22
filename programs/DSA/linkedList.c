#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *first = NULL, *last;

void create()
{
    struct node *p, *t;
    int n, *ele;

    printf("Enter number of elements : ");
    scanf("%d", &n);
    ele = (int *)malloc(n * sizeof(int));

    printf("Enter elemetns : ");
    scanf("%d", &ele[0]);

    first = (struct node *)malloc(n * sizeof(struct node));
    first->data = ele[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &ele[i]);
        t->data = ele[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }

    system("CLS");
    printf("New linked list has been created.\n\n");
}

void append()
{
    int n, *ele;
    struct node *t;

    printf("Enter number of elements to append : ");
    scanf("%d", &n);
    ele = (int *)malloc(n * sizeof(int));
    
    printf("Enter elemetns : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ele[i]);
        t = (struct node *)malloc(sizeof(struct node));
        t->data = ele[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }

    system("CLS");
    printf("Appending complete.\n\n");
}

void delete(int ele, struct node *p)
{
    system("CLS");
    while (p)
    {
        if (p->data == ele)
        {
            printf("Eement %d found.\n", ele);
        }
        p = p->next;
    }
}

void display(struct node *p)
{
    system("CLS");
    printf("Elements are : ");
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n\n");
}

void main()
{
    system("CLS");
    int n, *ele, ch, k;
    while (1)
    {
        // system("CLS");
    start:
        printf("Enter your choice :\n0.create new List,\n1.append,\n2.delete,\n3.display,\n4.exit.\n:");
        // printf("Enter your choice :\n1.create new List,\n2.delete,\n3.display,\n4.exit.\n:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            create();
            break;
        case 1:
            if (first == NULL)
            {
                system("CLS");
                printf("Create a list first.\n\n");
                break;
            }
            append();
            break;
        case 2:
            printf("Enter the element to delete : ");
            scanf("%d", &k);
            delete (k, first);
            break;
        case 3:
            display(first);
            break;
        case 4:
            exit(0);
        default:
            system("CLS");
            printf("Invalid Input!!!\n");
            goto start;
        }
    }
}