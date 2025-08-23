#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct stack
{
    char *arr;
    int size, top;
} Stack;
Stack s;

int isFull()
{
    return (s.top == s.size - 1);
}

int isEmpty()
{
    return s.top == -1;
}

int push(char element)
{
    if (isFull())
    {
        printf("Stack overflow!\n");
        return 0;
    }
    s.arr[++(s.top)] = element;
    return 1;
}

char pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow");
        return 0;
    }
    (s.top)--;
    return s.arr[s.top + 1];
}

int isoperator(char a)
{
    return a == '+' || a == '-' || a == '*' || a == '/';
}

int precedence(char a)
{
    if(a == '*' || a == '/') return 3;
    if(a == '+' || a == '-') return 2;
    return 0;
}

char *infix_to_postfix(char *str)
{
    int length, j = 0;
    for (length = 0; str[length] != 0; length++);
    char *postfix = (char *)malloc(length * sizeof(char));
    s.size = length;
    s.arr = (char *)malloc(length * sizeof(char));
    s.top = -1;
    for (int i = 0; i < length; i++)
    {
        if (isdigit(str[i]))
        {
            postfix[j++] = str[i];
        }
        else if (isoperator(str[i]))
        {
            if(isEmpty(&s) || precedence(str[i]) > precedence(s.arr[s.top]))
            {
                push(str[i]);
            }
            else
            {
                while(precedence(str[i]) <= precedence(s.arr[s.top]))
                    postfix[j++] = pop();
            }
        }
    }
    while(!isEmpty())
        postfix[j++] = pop();
    postfix[j] = 0;
    return postfix;
}

int main()
{
    char infix[] = "8 + 5 * 4";
    char *postfix = infix_to_postfix(infix);
    printf("%s", postfix);
    return 0;
}