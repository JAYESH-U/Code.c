#include<stdio.h>
#include<stdlib.h>

struct circQueue
{
    int f,r,size,*a;
}cq;

void createQueue(int n)
{
    cq.a = (int*)malloc(n*sizeof(int));
    cq.f = cq.r = 0;
    cq.size = n;
    printf("\nCircular Queue has been created.\n");
}

void enqueue(int x)
{
    if(((cq.r+1)%cq.size) == cq.f)
    {
        printf("\nCircular queue is full.");
        return;
    }
    cq.a[(cq.r++)%cq.size] = x;
    printf("\nEnqueued %d.",cq.a[cq.r-1]);
}

int dequeue()
{
    if(cq.f == cq.r)
    {
        printf("\nCircular queue is empty.");
        return -1;
    }
    printf("\nDequeued %d.",cq.a[(cq.f)%cq.size]);
    return (cq.a[(++cq.f)%cq.size]);
}

void display()
{
    printf("\n\nCircular queue : ");

    if((cq.f%cq.size) == cq.r)
    {
        printf("Empty.\n");
        return;
    }

    for(int i = cq.f; i != cq.r; i=(i+1)%cq.size)
    {
        printf("%d ",cq.a[i]);
    }
    printf("\n");
}

void main()
{
    createQueue(10);

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    enqueue(70);
    enqueue(80);
    enqueue(90);
    enqueue(100);
    //enqueue(200);
    //enqueue(200);

    display();

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    //dequeue();
    //dequeue();

    display();
}
