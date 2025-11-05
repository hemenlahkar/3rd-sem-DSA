#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int *arr;
    int size;
    int top;
} Stack;

Stack *createStack(int size)
{
    Stack *ret = (Stack *)malloc(sizeof(Stack));
    if(ret == NULL)
    {
        printf("\nCouldn't allocate memory!\n");
        return NULL;
    }
    ret->arr = (int *)malloc(size * sizeof(int));
    if(ret->arr == NULL)
    {
        printf("\nCouldn't allocate array!\n");
        free(ret);
        return NULL;
    }
    ret->size = size;
    ret->top = -1;
    return ret;
}

int isFull(Stack *s)
{
    return s->top == s->size - 1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int push(Stack *s, int element)
{
    if(s == NULL) return 0;
    if(isFull(s))
    {
        printf("\nCouldn't push: Stack is full!!\n");
        return 0;
    }
    s->arr[++(s->top)] = element;
    return 1;
}

int pop(Stack *s, int *popped_item)
{
    if(s == NULL) return 0;
    if(isEmpty(s))
    {
        printf("\nCouldn't pop: Stack is empty!\n");
        return 0;
    }
    *popped_item = s->arr[(s->top)--];
    return 1;
}

int peek(Stack *s)
{
    if(s == NULL)
    {
        printf("\nFailed to peek!\n");
        return -99999;
    }
    if(s->arr == NULL)
    {
        printf("\nFailed to peek!\n");
        return -99999;
    }
    return s->arr[s->top];
}

int main()
{
    Stack *s = createStack(10);
    int popped_item;
    for(int i = 0; i < 10; i++)
        push(s, i + 1);
    
    printf("\nTop of the stack: %d\n", peek(s));
    
    while(pop(s, &popped_item))
        printf("%d, ", popped_item);
    return 0;
}