#include "../headers/singly_LL.h"

typedef struct stack{
    Node *top;
} Stack;

Stack *createStack()
{
    Stack *ret = (Stack *)malloc(sizeof(Stack));
    ret->top = NULL;
    return ret;
}

int push(Stack *s, int x)
{
    if(s == NULL)
    {
        printf("\nStack is not initialized!\n");
        return 0;
    }
    if(s->top == NULL)
    {
        Node *temp = createNode(x);
        s->top = temp;
        return 1;
    }
    Node *temp = createNode(x);
    temp->next = s->top;
    s->top = temp;
    return 1;
}

int pop(Stack *s, int *popped_item)
{
    if(s == NULL) return 0;
    if(s->top == NULL) return 0;
    *popped_item = s->top->data;
    Node *t = s->top;
    s->top = s->top->next;
    free(t);
    return 1;
}

int isEmpty(Stack *s)
{
    if(s == NULL) return 1;
    return (s->top == NULL);
}

int isFull(Stack *s)
{
    int ret = 0;
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL) ret = 1;
    else free(temp);
    return ret;
}

int main()
{
    Stack *s = createStack();
    int popped;
    push(s, 5);
    push(s, 7);
    push(s, 9);
    while(pop(s, &popped))
    {
        printf("%d, ", popped);
    }
    return 0;
}