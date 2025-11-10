#include<stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

typedef struct queue{
    Node *front, *rear;
} Queue;

Node *createNode(int n)
{
    Node *ret = (Node *)malloc(sizeof(Node));
    if(ret == NULL) return NULL;
    ret->data = n;
    ret->next = NULL;
    return ret;
}

int isFull(Queue q)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if(temp == NULL) return 1;
    free(temp);
    return 0;
}

int isEmpty(Queue q)
{
    return q.front == NULL || q.rear == NULL;
}

int enqueue(Queue *q, int item)
{
    if(isFull(*q)) return 0;
    Node *n = createNode(item);
    if(isEmpty(*q))
    {
        q->front = q->rear = n;
        return 1;
    }
    q->rear->next = n;
    q->rear = q->rear->next;
    return 1;
}

int dequeue(Queue *q, int *item)
{
    if(isEmpty(*q)) return 0;
    Node *temp = q->front;
    *item = temp->data;
    if(q->front == q->rear)
        q->front = q->rear = NULL;
    else
        q->front = q->front->next;
    free(temp);
    return 1;
}

int main()
{
    Queue q;
    q.front = q.rear = NULL;
    int i;

    for(i = 0; i < 10; i++)
        enqueue(&q, i + 1);
    
    while(dequeue(&q, &i))
        printf("%d ", i);
    return 0;
}