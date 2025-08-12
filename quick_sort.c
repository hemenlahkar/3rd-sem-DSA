#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr + i, arr + j);
        }
    }
    i++;
    swap(arr + i, arr + high);
    return i;
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[64], n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    if (n < 0 || n > 64) {
        printf("Invalid number of elements. Must be between 0 and 64.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter element [%d]: ", i);
        scanf("%d", arr + i);
    }

    quick_sort(arr, 0, n - 1);

    printf("\nAfter sorting: ");
    for (int i = 0; i < n; i++)
        printf(" %d", arr[i]);
    return 0;
}