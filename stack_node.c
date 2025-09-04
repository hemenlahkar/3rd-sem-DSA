#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} Node;

typedef struct stk
{
    Node *data;
    struct stk *next;
} Stack;

int isEmpty(Stack *head)
{
    return head == NULL;
}

int isFull(Stack *head)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (s == NULL)
        return 1;
    free(s);
    return 0;
}

int push(Stack **top, Node *item)
{
    if (isFull(*top))
    {
        printf("Stack Overflow!\n");
        return 0;
    }
    Stack *x = (Stack *)malloc(sizeof(Stack));
    x->data = item;
    x->next = *top;
    *top = x;
    return 1;
}

int pop(Stack **head, Node **popped_item)
{
    if (isEmpty(*head))
    {
        printf("Stack already empty!\n");
        return 0;
    }
    if ((*head)->data == NULL)
        return 0;
    *popped_item = (*head)->data;
    Stack *pop = *head;
    *head = (*head)->next;
    free(pop);
    return 1;
}