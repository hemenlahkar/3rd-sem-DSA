#include <stdio.h>
#include <stdlib.h>

int inputArray(int *array, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Enter element[%d]: ", i + 1);
        scanf("%d", array + i);
    }
    fflush(stdin);
}

int main()
{
    int size, index;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *array = (int *)malloc(size * sizeof(int));
    inputArray(array, size);
    printf("\nEnter index: ");
    scanf("%d", &index);
    if (index > 0 && index <= size)
        printf("\n%dth element is: %d", index, array[index - 1]);
    else
        printf("\nInvalid index entered.");
    return 0;
}