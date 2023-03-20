#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size, front, rear, *Q;
};

void create(struct queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct queue *q, int x)
{
    if (q->rear == q->size - 1)
        printf("The queue is full.\n");
    else
        q->Q[++q->rear] = x;
}

int dequeue (struct queue *q)
{
    if(q->front == q->rear)
    {
        printf("The queue is empty.\n");
        return -1;
    }
    else
        return q->Q[++q->front];
}

void display(struct queue q)
{
    int i;
    for(i = q.front+1;i<=q.rear;i++)
        printf("%d ",q.Q[i]);
    printf("\n");
}

int main()
{
    struct queue q;
    create(&q, 5);

    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    // enqueue(&q,40);
    // enqueue(&q,50);

    display(q);

    printf("%d has been dequeued.",dequeue(&q));

    return 0;
}