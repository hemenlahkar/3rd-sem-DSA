#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;


int enqueue(Node **front, Node **rear, int key)
{
    Node *n = (Node *)malloc(sizeof(Node));
    if (n == NULL)
    {
        printf("Queue is full!!\n");
        return 0;
    }
    n->data = key;
    n->next = NULL;
    if (*front == NULL)
        *front = *rear = n;
    else
    {
        (*rear)->next = n;
        *rear = n;
    }
    return 1;
}

int dequeue(Node **front)
{
    int val = -99999;
    Node *n = *front;
    if (*front == NULL)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        *front = (*front)->next;
        val = n->data;
        free(n);
    }
    return val;
}

int peek(Node *front)
{
    if(front == NULL)
    {
        printf("Queue is empty!!\n");
        return 0;
    }
    return front->data;
}

void print_Queue(Node *front, Node *rear)
{
    while (front != rear)
    {
        printf("%d, ", front->data);
        front = front->next;
    }
    putchar('\n');
}

int main()
{
    Node *front = NULL, *rear = NULL;
    for (int i = 0; i < 5; i++)
        enqueue(&front, &rear, i + 3);
    print_Queue(front, rear);
    dequeue(&front);
    print_Queue(front, rear);
    return 0;
}