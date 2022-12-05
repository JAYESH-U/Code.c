#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size, front, rear;
    int *elements;
};

void initialize(struct queue *qp, int s)
{
    qp->front = qp->rear = -1;
    qp->size = s;
    qp->elements = calloc(s, sizeof(int));
}

int queue_empty(struct queue *qp)
{
    if (qp->front == qp->rear)
        return 1;
    return 0;
}

int queue_full(struct queue *qp)
{
    if (qp->rear == (qp->size - 1))
        return 1;
    return 0;
}

int insert(struct queue *qp, int ele)
{
    if (queue_full(qp) != 1)
    {
        qp->elements[++qp->rear] = ele;
        printf("%d has been enqueued.\n", ele);
        return 1;
    }
    return 0;
}

int delete(struct queue *qp, int ne)
{
    int ele, i;
    for (i = 0; i < ne; i++)
    {
        if (!queue_empty(qp))
        {
            ele = qp->elements[++qp->front];
            printf("%d has been dequeued...\n", ele);
        }
        else
            return 0;
    }
}

void display(struct queue *qp)
{
    int i = qp->front + 1;
    while (i != qp->size)
    {
        printf("%d ", qp->elements[i++]);
    }
    printf("\n");
}

int main()
{
    struct queue q;
    int n, e, i, ch, ne;
    printf("Enter the total size of the queue : ");
    scanf("%d", &n);
    initialize(&q, n);
    // printf("size %d",q.size);
    while (1)
    {
        printf("Enter your choice :\n1.Enqueue.\n2.Dequeue.\n3.Display.\n4.Exit.\n:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the number of elements to be enqueued : ");
            scanf("%d", &ne);
            printf("Enter %d elements : ", ne);
            for (i = 0; i < ne; i++)
            {
                scanf("%d", &e);
                if (insert(&q, e) == 0)
                    printf("Queue overflow.\n");
            }
            break;
        case 2:
            printf("Enter the number of elements to be dequeued : ");
            scanf("%d", &ne);
            if (!delete (&q, ne))
                printf("Queue is empty..\n");
            break;
        case 3:
            display(&q);
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice...!!!\n");
        }
    }
}