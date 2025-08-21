#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

void print_LL(Node *head)
{
    while (head != NULL)
    {
        printf("%d, ", head->data);
        head = head->next;
    }
    putchar('\n');
}

int isFull(Node *top)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
        return 1;
    free(p);
    return 0;
}

int isEmpty(Node *top)
{
    if (top == NULL)
        return 1;
    return 0;
}

int push(Node **top, int key)
{
    if (isFull(*top))
    {
        printf("Stack Overflow!!\n");
        return 0;
    }
    Node *t = (Node *)malloc(sizeof(Node));
    t->data = key;
    t->next = *top;
    *top = t;
    return 1;
}

int pop(Node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack Underflow!!\n");
        return -99999;
    }
    int x = (*top)->data;
    Node *p = *top;
    *top = (*top)->next;
    free(p);
    return x;
}

int peek(Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack is empty!\n");
        return -99999;
    }
    return top->data;
}

int main()
{
    Node *top = NULL;

    for (int i = 3; i < 8; i++)
        push(&top, i * i);

    printf("Peek: %d\n", peek(top));

    for (int i = 0; i < 5; i++)
        printf("%d ", pop(&top));

    return 0;
}