#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct stack
{
    double *arr;
    int top;
    int size;
} Stack;

Stack *createStack_double(int x)
{
    Stack *ret = (Stack *)malloc(sizeof(Stack));
    ret->arr = (double *)malloc(x * sizeof(double));
    ret->size = x;
    ret->top = -1;
    return ret;
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int push(Stack *s, double item)
{
    if (s == NULL)
        return 0;
    if (s->arr == NULL)
        return 0;
    if (s->top == s->size - 1)
        return 0;
    s->arr[++s->top] = item;
    return 1;
}

int pop(Stack *s, double *popped_item)
{
    if (s == NULL)
        return 0;
    if (s->arr == NULL)
        return 0;
    if (s->top == -1)
        return 0;
    *popped_item = s->arr[s->top--];
    return 1;
}

void deleteStack(Stack *s)
{
    free(s->arr);
    free(s);
}

double evaluate_postfix(char *postfix)
{
    Stack *s = createStack_double(strlen(postfix));
    char c = postfix[0];
    double x;
    int i = 0;

    while (i < strlen(postfix))
    {
        if (c >= '0' && c <= '9')
        {
            x = 0;
            while ((c = postfix[i++]) != ' ' && c != 0)
                x = x * 10 + c - '0';
            push(s, x);
        }
        while ((c = postfix[i]) == ' ')
            i++;
        if (isOperator(c))
        {
            double a, b;
            pop(s, &b);
            pop(s, &a);
            switch (c)
            {
            case '+':
                x = a + b;
                break;
            case '-':
                x = a - b;
                break;
            case '*':
                x = a * b;
                break;
            case '/':
                x = a / b;
                break;

            default:
                printf("Invlid operator");
                break;
            }
            c = postfix[++i];
            push(s, x);
        }
    }
    double ret;
    pop(s, &ret);
    deleteStack(s);
    return ret;
}

int main()
{
    char postfix[100];
    printf("\nEach number and operator should be separated by spaces");
    printf("\nEnter the postfix expression: ");
    scanf("%[^\n]", postfix);
    double result = evaluate_postfix(postfix);
    printf("result = %.2f\n", result);
    return 0;
}