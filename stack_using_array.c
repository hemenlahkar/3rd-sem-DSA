#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int *arr, size, top;
} Stack;

Stack *stack_constructor(int size)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->arr = (int *)malloc(size * sizeof(int));
    s->top = -1;
    return s;
}

int isFull(Stack *S)
{
    return (S->top == S->size - 1);
}

int isEmpty(Stack *S)
{
    return S->top == -1;
}

int push(Stack *S, int element)
{
    if (isFull(S))
    {
        printf("Stack overflow!\n");
        return 0;
    }
    S->arr[++(S->top)] = element;
}

int pop(Stack *S)
{
    if (isEmpty(S))
    {
        printf("Stack Underflow");
        return -99999;
    }
    (S->top)--;
    return S->arr[S->top + 1];
}

int peek(Stack *S){
    if (isEmpty(S))
    {
        printf("Stack is empty");
        return -99999;
    }
    return S->arr[S->top];
}

int main()
{
    Stack *s = stack_constructor(10);
    for(int i = 0; i < 5; i ++)
        push(s, i+1);
    for(int i = 0; i < 5; i++)
        printf("%d ", pop(s));
    return 0;
}