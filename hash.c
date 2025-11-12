#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *arr;
    int capacity;
} hashtable;

int initializeHTable(hashtable *h, int capacity)
{
    h->arr = (int *)malloc(capacity * sizeof(int));
    if (h->arr == NULL)
        return 0;
    for (int i = 0; i < capacity; i++)
        h->arr[i] = -9999;
    h->capacity = capacity;
    return 1;
}

int hash_division(hashtable h, int key)
{
    return key % h.capacity;
}

int insert(hashtable *h, int key)
{
    if (h == NULL)
        return 0;
    if (h->arr == NULL)
        return 0;

    int i = 0;

    int hash = hash_division(*h, key);
    while (h->arr[hash + i * i] != -9999 && hash + i * i < h->capacity)
        i++;
    h->arr[hash + i * i] = key;
    return 1;
}

int search(hashtable *h, int key)
{
    int hash = hash_division(*h, key);
    int i = 0;
    while (h->arr[hash + i * i] != -9999 && hash + i * i < h->capacity)
    {
        if (h->arr[hash + i * i] == key)
            return hash + i * i;
        i++;
    }

    return -9999;
}

int main()
{
    hashtable h;
    initializeHTable(&h, 100);
    insert(&h, 10);
    insert(&h, 8);
    insert(&h, 208);
    insert(&h, 408);
    printf("Index of 408: %d", search(&h, 408));
    return 0;
}