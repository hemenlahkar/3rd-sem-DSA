#include<stdio.h>
#include<stdlib.h>

int *getEvenIndex(int *array, int size)
{
    int *ret = (int *)malloc(size * sizeof(int));
    int i, j;
    for(i = j = 0; i < size; i++)
    {
        if(!(array[i]%2))
            ret[j++] = i;
    }
    ret[j] = -1;
    return ret;
}

int main()
{
    int array[10];
    for(int i = 0; i < 10; i++)
        array[i] = (i+1) * 3;

    int *evenIndexes = getEvenIndex(array, 10);

    printf("Indexes on which even numbers exits('0' being the first index): ");
    for(int i = 0; evenIndexes[i] != -1; i++)
        printf("%d, ", evenIndexes[i]);
    return 0;
}