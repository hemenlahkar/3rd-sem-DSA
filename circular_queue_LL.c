#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

int isEmpty(Node *n)
{
    return n == NULL;
}

int isFull(Node *n)
{
    Node *x = (Node *)malloc(sizeof(Node));
    if (x == NULL)
        return 1;
    free(x);
    return 0;
}

int enqueue(Node **n, int key)
{
    if (isFull(*n))
    {
        printf("\nCouldn't enqueue: Queue is full!\n");
        return 0;
    }
    Node *t = (Node *)malloc(sizeof(Node));
    t->data = key;
    if (isEmpty(*n))
    {
        t->next = t;
        *n = t;
        return 1;
    }
    Node *x, *y;
    x = *n;
    for (y = *n; y->next != x; y = y->next)
        ;
    y->next = t;
    t->next = *n;
    *n = t;
    return 1;
}

int dequeue(Node **n, int *ele)
{
    if (isEmpty(*n))
    {
        printf("\nDequeue failed: Queue already empty!\n");
        *ele = -99999;
        return 0;
    }
    Node *x = *n, *y;
    if (x->next == x)
    {
        *ele = (*n)->data;
        *n = NULL;
        free(x);
        return 1;
    }
    for (y = *n; y->next->next != *n; y = y->next);
    *ele = y->next->data;
    Node *freeable = y->next;
    y->next = x;
    free(freeable);
    *n = y->next;
    return 1;
}

int main()
{
    Node *x = NULL;
    int dequeue_element;
    for (int i = 0; i < 5; i++)
        enqueue(&x, i + 1);
    for (int i = 0; i < 5; i++){
        dequeue(&x, &dequeue_element);
        printf("%d, ", dequeue_element);
    }
    return 0;
}