#include <stdio.h>
#include <stdlib.h>

int inputArray(int **arr, int *n)
{
    printf("Enter the size of the array: ");
    scanf("%d", n);
    if (n <= 0)
    {
        printf("\nError: Invalid size entered!");
        return 0;
    }
    *arr = (int *)malloc(*n * sizeof(int));
    for (int i = 0; i < *n; i++)
    {
        printf("Enter element[%d]: ", i + 1);
        scanf("%d", *arr + i);
    }
    return 1;
}

void printArray(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if(i + 1 < n) printf(", ");
    }
    putchar('\n');
}

void bubbleSort(int *arr, int n)
{
    int isSorted = 1;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
            if (arr[j] > arr[j + 1])
            {
                isSorted = 0;
                arr[j] = arr[j] ^ arr[j + 1];
                arr[j + 1] = arr[j] ^ arr[j + 1];
                arr[j] = arr[j] ^ arr[j + 1];
            }
        if (isSorted)
            return;
    }
}

void insertionSort(int *arr, int n)
{
    int i, j, t;
    for (i = 1; i < n; i++)
    {
        t = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > t; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = t;
    }
}

void selectionSort(int *arr, int n)
{
    int smallest = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallest])
                smallest = j;
        }
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
    }
}

void countingSort(int *arr, int n)
{
    int maximum = arr[0], i, j;
    for (i = 1; i < n; i++)
        if (arr[i] > maximum)
            maximum = arr[i];
    int *aux = (int *)calloc(maximum + 1, sizeof(int));
    for (i = 0; i < n; i++)
        aux[arr[i]]++;
    for (i = j = 0; i < n; j++)
    {
        if (aux[j]){
            arr[i++] = j;
            --aux[j--];
        }
    }
}

void sort(int *arr, int n)
{
    int option;
    printf("\nInitial array: ");
    printArray(arr, n);
    printf("\nWhich sorting algorithm do you want to use?");
    printf("\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Counting sort\n5. Exit program\n");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        bubbleSort(arr, n);
        break;
    case 2:
        selectionSort(arr, n);
        break;
    case 3:
        insertionSort(arr, n);
        break;
    case 4:
        countingSort(arr, n);
        break;
    case 5:
        return;
    default:
        printf("\nError: Invalid option entered!");
        break;
    }
    printf("\nAfter sorting: ");
    printArray(arr, n);
}

int main()
{
    int *arr, n;
    if (!inputArray(&arr, &n))
        return -1;
    sort(arr, n);
    return 0;
}