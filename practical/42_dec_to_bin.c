#include "../headers/stack.h"

void decimalToBinary(int d)
{
    Stack *s = createStack(64);
    while(d != 0)
    {
        push(s, d%2);
        d /= 2;
    }
    while(!isEmpty(s))
    {
        int popped;
        pop(s, &popped);
        printf("%d", popped);
    }
}

int main()
{
    int decimal;
    printf("Enter the decimal number: ");
    scanf("%d", &decimal);
    decimalToBinary(decimal);
}