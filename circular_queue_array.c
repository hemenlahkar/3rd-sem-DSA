#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct queue
{
    int *arr, front, rear, size;
} circularQueue;

bool isFull(circularQueue q)
{
    if (q.front == (q.rear + 1) % q.size)
    {
        return 1;
    }
    return 0;
}

bool isEmpty(circularQueue q)
{
    if (q.front == q.rear)
        return 1;
    return 0;
}

int enqueue(circularQueue *q,int key)
{
    if(isFull(*q)){
        printf("Queue is full!\n");
        return 0;
    }
    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = key;
    return 1;
}

int dequeue(circularQueue *q)
{
    if(isEmpty(*q))
    {
        printf("This circular queue is empty!\n");
        return -999999;
    }
    q->front++;
    return q->arr[q->front];
}

int main()
{
    circularQueue q;
    q.size = 10;
    q.front = q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // Enqueue
    for(int i = 0; i < 10; i++)
        enqueue(&q, i+2);
    for(int i = 0; i < 10; i++)
        printf("%d, ", dequeue(&q));
    if (isEmpty(q))
    {
        printf("\nThe queue is now empty!");
    }
    
    return 0;
}