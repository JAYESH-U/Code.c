#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int roll_no;
    char name[20];
    char branch[5];
} Student_info;

void display_stud_info(Student_info *data)
{
    printf("Roll no:%d Name:%s Branch:%s \n", data->roll_no, data->name, data->branch);
}

struct node
{
    Student_info *data;
    struct node *L;
    struct node *R;
};

struct node *insert(struct node *root, Student_info *val)
{
    struct node *p, *q, *r;
    p = (struct node *)malloc(sizeof(struct node));
    if (p != NULL)
    {
        p->data = (Student_info *)malloc(sizeof(Student_info));
        if (p->data != NULL)
        {
            p->data->roll_no = val->roll_no;
            strcpy(p->data->name, val->name);
            strcpy(p->data->branch, val->branch);
        }
        p->L = 0;
        p->R = 0;
    }
    if (root == NULL)
    {
        root = p;
        return root;
    }
    q = root;
    while (q != NULL)
    {
        r = q;
        if (val->roll_no < q->data->roll_no)
            q = q->L;
        else
            q = q->R;
    }
    if (val->roll_no < r->data->roll_no)
        r->L = p;
    else
        r->R = p;
    return root;
}

void in_trav(struct node *root)
{
    if (root == NULL)
        return;
    in_trav(root->L);
    display_stud_info(root->data);
    in_trav(root->R);
}

int main()
{
    Student_info data;
    struct node *root = 0;
    
    data.roll_no = 25;
    strcpy(data.name, "Jayesh");
    strcpy(data.branch, "ISE");
    root = insert(root, &data);

    data.roll_no = 31;
    strcpy(data.name, "Manoj");
    strcpy(data.branch, "ISE");
    root = insert(root, &data);

    data.roll_no = 10;
    strcpy(data.name, "Arnav");
    strcpy(data.branch, "ISE");
    root = insert(root, &data);
    
    in_trav(root);
    return 0;
}