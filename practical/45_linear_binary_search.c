#include <stdio.h>
#include <stdlib.h>

int linear_search(int *arr, int n, int key)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

int binary_search(int *arr, int n, int key)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if(arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("key = 8\nLinear search result: %d\nBinary search result: %d\n", linear_search(arr, n, 8), binary_search(arr, n, 8));
    return 0;
}