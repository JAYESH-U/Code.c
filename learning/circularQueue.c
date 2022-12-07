#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size, front, rear, *Q;
};

void create(struct queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct queue *q, int x)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("The queue is full.\n");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct queue *q)
{
    if (q->front == q->rear)
    {
        printf("The queue is empty.\n");
        return -1;
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        return q->Q[q->front];
    }
}

void display(struct queue q)
{
    int i = q.front + 1;
    do
    {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);

    printf("\n");
}

int main()
{
    struct queue q;
    create(&q, 5);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    display(q);

    printf("%d has been dequeued.\n", dequeue(&q));

    display(q);

    enqueue(&q, 50);

    display(q);

    printf("%d has been dequeued.\n", dequeue(&q));

    enqueue(&q, 60);
    
    display(q);

    return 0;
}