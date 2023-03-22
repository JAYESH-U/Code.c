#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct studentInfo
{
    char name[50], branch[20], usn[11]; //+1 size for usn for '\0' charecter.
    int roll;
};

struct node
{
    struct studentInfo data;
    struct node *l, *r;
}*root=NULL;

void insert(struct node *q, struct studentInfo d)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = d;
    t->r = t->l = NULL;

    if(!q)
    {
        root = t;
        printf("\nData Inserted. %s",t->data.usn);
        return;
    }

    struct node *p;

    while(q)
    {
        p = q;
        if(strcmp(t->data.usn, q->data.usn)<0)
            q = q->l;
        else
            q = q->r;
    }

    if(strcmp(t->data.usn,p->data.usn)<0)
        p->l = t;
    else
        p->r = t;

    printf("\nData Inserted. %s",t->data.usn);
}

void displayStdInfo(struct studentInfo data)
{
    printf("\nDetails of student : ");
    printf("\n\tUSN : %s",data.usn);
    printf("\n\tRoll no. : %d",data.roll);
    printf("\n\tName : %s",data.name);
    printf("\n\tBranch : %s",data.branch);
    printf("\n");
}

void display(struct node *q)
{
    if(!q)
        return;
    display(q->l);
    displayStdInfo(q->data);
    display(q->r);
}

void main()
{
    struct studentInfo data;

    data.roll = 25;
    strcpy(data.usn,"2GI21IS025");
    strcpy(data.name,"Jayesh Uramanatti");
    strcpy(data.branch,"ISE");
    insert(root,data);

    data.roll = 31;
    strcpy(data.usn,"2GI21IS031");
    strcpy(data.name,"Manoj Patil");
    strcpy(data.branch,"ISE");
    insert(root,data);

    data.roll = 12;
    strcpy(data.usn,"2GI21IS012");
    strcpy(data.name,"Aryan Thapa");
    strcpy(data.branch,"ISE");
    insert(root,data);

    printf("\n");
    display(root);
}
