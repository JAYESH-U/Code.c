#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *first = NULL;

void create(int a[], int n)
{
    int i;
    struct node *t, *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = a[0];
    first->next = NULL;
    last = first; // in for loop last->next = t;
    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = NULL;
        last->next = t; // here.
        last = t;
    }
}

// display function
void display(struct node *p)
{
    printf("\n");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void displayRec(struct node *p)
{
    printf("\n");
    if (p)
    {
        printf("%d ", p->data);
        displayRec(p->next);
    }
}

// counting number of nodes.
int count(struct node *p)
{
    int c = 0;
    while (p != NULL)
    {
        p = p->next;
        c++;
    }
    return c;
}

int countRec(struct node *p)
{
    int c = 0;
    if (p)
    {
        return countRec(p->next) + 1;
    }
    // or
    // if(p)
    // {
    //     c = countRec(p->next);
    //     return c+1;
    // }
    // else
    // {
    //     return c;
    // }
}

// addition of data.
int add(struct node *p)
{
    int sum = 0;
    while (p)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}

int addRec(struct node *p)
{
    if (!p)
        return 0;
    else
        return add(p->next) + p->data;
}

// max function
int max(struct node *p)
{
    int m = -32768;
    while (p)
    {
        if (p->data > m)
            m = p->data;
        p = p->next;
    }
    return m;
}

int maxRec(struct node *p)
{
    int x = 0;
    if (!p)
        return -32768;
    else
    {
        x = max(p->next);
        if (x > p->data)
            return x;
        else
            return p->data;
    }
}

int maxRecTernary(struct node *p)
{
    int x = 0;
    if (!p)
        return -32768;
    x = max(p->next);
    return x > p->data ? x : p->data;
}

// search node
struct node* search(struct node *p, int k)
{
    while (p != NULL)
    {
        if (k == p->data)
            return p;
        p = p->next;
    }
}
struct node *searchRec(struct node *p, int k)
{
    if (p == NULL)
        return NULL;
    if (k == p->data)
        return p;
    return searchRec(p->next, k);
}

struct node* searchMoveFront(struct node *p, int k)
{
    struct node *q;
    while (p != NULL)
    {
        if (k == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
}

//inserting new element.
void insert(struct node*p,int index,int ele){
    if(index<0 || index>count(p))
        return;
    struct node *t=(struct node *)malloc(sizeof(struct node));
    t->data = ele;
    
    if(index == 0){
        t->next = first;
        first = t;
    }
    else{
        for(int i=0;i<index-1;i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    create(a, 5);

    // display(first);
    displayRec(first);

    // printf("\nNumber of nodes : %d",count(first));
    printf("\nNumber of nodes : %d", countRec(first));

    // printf("\nSum of data : %d", add(first));
    printf("\nSum of data : %d", addRec(first));
    printf("\nSum of data : %d", addRec(first));

    // printf("\nMax value in the List : %d", max(first));
    // printf("\nMax value in the List : %d", maxRec(first));
    printf("\nMax value in the List : %d", maxRecTernary(first));

    struct node *key ;
    // key = search(first, 4);
    // key = searchRec(first, 6);
    key = searchMoveFront(first, 4);    //move the key element to front(first).
    key = searchMoveFront(first, 3);    //move the key element to front(first).
    if (key)
        printf("\nKey element %d is found.", key->data);
    else
        printf("\nKey 6 not found.");

    insert(first,0,10); //we can use insert function to create(initialize) a linked list.
    insert(first,4,20);
    insert(first,10,20);    //invalid index(will not be inserted.)

    display(first);
    return 0;
}