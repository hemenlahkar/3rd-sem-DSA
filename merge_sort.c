#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int low, int mid, int high)
{
    int temp[100];
    int l1, l2, i;
    for (l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++)
    {
        if (arr[l2] > arr[l1])
            temp[i] = arr[l1++];
        else
            temp[i] = arr[l2++];
    }
    while (l1 <= mid)
        temp[i++] = arr[l1++];
    while (l2 <= high)
        temp[i++] = arr[l2++];
    for (i = low; i <= high; i++)
        arr[i] = temp[i];
}

void merge_sort(int arr[], int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{
    int arr[50], n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter element [%d]:", i);
        scanf("%d", arr + i);
    }
    printf("\nArray before sorting: ");
    for (int i = 0; i < n; i++)
        printf(" %d", arr[i]);
    merge_sort(arr, 0, n - 1);
    printf("\nArray after sorting: ");
    for (int i = 0; i < n; i++)
        printf(" %d", arr[i]);
    return 0;
}