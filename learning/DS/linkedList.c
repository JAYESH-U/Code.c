#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
} *first = NULL, *last = NULL, *second = NULL, *third = NULL;

void create(int a[], int n)
{
    int i;
    // struct node *t, *last;
    struct node *t;
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

void create2(int a[], int n)
{
    int i;
    // struct node *t, *last;
    struct node *t;
    second = (struct node *)malloc(sizeof(struct node));
    second->data = a[0];
    second->next = NULL;
    last = second; // in for loop last->next = t;
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
struct node *search(struct node *p, int k)
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

struct node *searchMoveFront(struct node *p, int k)
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

// inserting new element.
void insert(struct node *p, int index, int ele)
{
    if (index < 0 || index > count(p))
        return;
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = ele;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

void insertSortedList(struct node *p, int x)
{
    struct node *q = NULL;
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;
    if (first == NULL)
        first = last = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

// delete an element
int delete(struct node *p, int index)
{
    struct node *q = NULL;
    int x = -1, i;
    if (index < 1 || index > count(p))
        return -1;
    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}

// check sort
int checkSort(struct node *p)
{
    int x = -32768;
    while (p)
    {
        if (p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

// delete duplicates
void deleteDuplicate(struct node *p)
{
    struct node *q = p->next;
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

// reverse list.
void reverseArr(struct node *p)
{
    int *a, i = 0;
    struct node *q = p;

    a = (int *)malloc(sizeof(int) * count(p));

    while (q)
    {
        a[i] = q->data;
        q = q->next;
        i++;
    }

    q = p; // assign again.
    i--;

    while (q)
    {
        q->data = a[i];
        q = q->next;
        i--;
    }
}

void reversePoint(struct node *p)
{
    struct node *q = NULL, *r = NULL;

    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void reverseRec(struct node *q, struct node *p)
{
    if (p)
    {
        reverseRec(p, p->next);
        p->next = q;
    }
    else
        first = q;
}

// concatination
void concat(struct node *p, struct node *q)
{
    third = p;
    while (p->next)
        p = p->next;
    p->next = q;
}

// merging
void merge(struct node *p, struct node *q)
{
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p)
        last->next = p;
    if (q)
        last->next = q;
}

// check if link has loop
int loop(struct node *f)
{
    struct node *q, *p;
    p = q = f;

    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while (p && q && p != q);

    if (p == q)
        return 1;
    else
        return 0;
}

int main()
{
    int a[] = {10, 20, 30, 40, 50}; // sorted elements
    create(a, 5);

    // int b[] = {5, 15, 25, 35, 45};  // sorted elements
    // create2(b, 5);

    printf("\nFirst: ");
    display(first);
    // displayRec(first);

    // printf("\nSecond: ");
    // display(second);

    /*
        struct node *t1,*t2;
        t1 = first->next->next;
        t2 = first->next->next->next->next;
        t2->next=t1;

        printf("\nIs loop : %d",loop(first));
    */

    /*
        //comment these before merging..
        concat(first, second);

        printf("\nconcatinated : ");
        // display(first);
        display(third);
    */

    /*
        merge(first, second);

        printf("\nMerged : ");
        display(third);
        // display(first); //wont consider first element..
    */

    /*
        // printf("\nNumber of nodes : %d",count(first));
        printf("\nNumber of nodes : %d", countRec(first));

        // printf("\nSum of data : %d", add(first));
        printf("\nSum of data : %d", addRec(first));
        printf("\nSum of data : %d", addRec(first));

        // printf("\nMax value in the List : %d", max(first));
        // printf("\nMax value in the List : %d", maxRec(first));
        printf("\nMax value in the List : %d", maxRecTernary(first));

        struct node *key;
        // key = search(first, 4);
        // key = searchRec(first, 6);
        // key = searchMoveFront(first, 4); // move the key element to front(first).
        // key = searchMoveFront(first, 3); // move the key element to front(first).
        // if (key)
        // printf("\nKey element %d is found.", key->data);
        // else
        // printf("\nKey 6 not found.");

        insertSortedList(first, 10); // comment insert call, search move front, then execute.
        insertSortedList(first, 30);
        insertSortedList(first, 15);

        insert(first, 0, 10); // we can use insert function to create(initialize) a linked list.
        // insert(first, 5, 20);   //it wint be sorted after this..-->DONT BE SURPRISED.
        insert(first, 10, 20); // invalid index(will not be inserted.)

        // delete(first,4);
        printf("\nDeleted element : %d", delete (first, 4));

        if (checkSort(first))
            printf("\nList is sorted.");
        else
            printf("\nList is not sorted.");

        insertSortedList(first, 10); // comment insert call, search move front, then execute.
        insertSortedList(first, 30);
        insertSortedList(first, 15);

        display(first);

        deleteDuplicate(first);

        printf("\nreverse list :");
        reverseArr(first);

        printf("\nreverse list :");
        reversePoint(first);

        printf("\nreverse list :");
        reverseRec(NULL, first);

        display(first);
    */
    return 0;
}