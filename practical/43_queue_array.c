#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int *arr;
    int front, rear;
    int size;
} Queue;

Queue *createQueue(int size)
{
    Queue *ret = (Queue *)malloc(sizeof(Queue));
    if(ret == NULL) return NULL;
    ret->arr = (int *)malloc(size * sizeof(int));
    if(ret->arr == NULL)
    {
        free(ret);
        return NULL;
    }
    ret->front = ret->rear = -1;
    ret->size = size;
    return ret;
}

int isFull(Queue *q)
{
    return q->rear == q->size - 1;
}

int isEmpty(Queue *q)
{
    return q->front == q->rear;
}

int enqueue(Queue *q, int item)
{
    if(isFull(q)) return 0;
    q->arr[++(q->rear)] = item;
    return 1;
}

int dequeue(Queue *q, int *item)
{
    if(isEmpty(q)) return 0;
    *item = q->arr[++(q->front)];
    return 1;
}

int main()
{
    Queue *q = createQueue(10);
    int i;
    
    for(i = 0; i < 10; i++)
        enqueue(q, 2 * i + 1);
    
    while(dequeue(q, &i))
        printf("%d ", i);
    
    return 0;
}