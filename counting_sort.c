#include <stdio.h>
#include <stdlib.h>

void counting_sort(int arr[], int n)
{
    int output[n];
    int max = arr[0];

    for (int i = 0; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    int *auxArr = (int *)calloc(max + 1, sizeof(int));

    for (int i = 0; i < n; auxArr[arr[i]]++, i++);
    for (int i = 1; i< max + 1; auxArr[i] += auxArr[i-1], i++);

    for (int i = 0; i < n; i++){
        int x = arr[n - 1 - i];
        output[auxArr[x]-- - 1] = x;
    }

    for(int i = 0; i < n; i++) 
        arr[i] = output[i];
}

int main()
{
    int arr[] = {4, 2, 5, 2, 6, 3, 5, 9, 7};

    printf("Unsorted array: ");
    for(int i = 0; i < 9; i++)
        printf("%d, ", arr[i]);

    counting_sort(arr, 9);

    printf("Sorted array: ");
    for(int i = 0; i < 9; i++)
        printf("%d, ", arr[i]);
    return 0;
}