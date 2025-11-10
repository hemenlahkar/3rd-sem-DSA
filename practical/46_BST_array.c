#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *arr, size, isEmpty;
} Tree;

Tree *createTree(int s)
{
    Tree *ret = (Tree *)malloc(sizeof(Tree));
    if (ret == NULL)
        return 0;
    ret->arr = (int *)calloc(s, sizeof(int));
    if (ret->arr == NULL)
    {
        free(ret);
        return 0;
    }
    ret->size = s;
    ret->isEmpty = 1;
    return ret;
}

int insert(Tree *t, int item)
{
    if (t == NULL)
        return 0;
    if (t->arr == NULL)
        return 0;
    if (t->isEmpty)
    {
        t->arr[0] = item;
        t->isEmpty = 0;
        return 1;
    }
    int i = 0;
    while (t->arr[i] && i < t->size)
    {
        if (t->arr[i] == item)
            return 0;
        if (t->arr[i] > item)
            i = 2 * i + 1;
        else
            i = 2 * i + 2;
    }
    if (i >= t->size)
        return 0;
    t->arr[i] = item;
    return 1;
}

int search_element(Tree *t, int element)
{
    if (t == NULL)
        return -1;
    if (t->arr == NULL)
        return -1;
    int i = 0;
    while (t->arr[i])
    {
        if (t->arr[i] == element)
            return i;
        if (t->arr[i] < element)
            i = 2 * i + 2;
        else
            i = 2 * i + 1;
    }
    return -1;
}

int printPreorder(Tree *t, int head)
{
    if (t == NULL)
        return 0;
    if (t->arr == NULL)
        return 0;
    if (t->isEmpty)
        return 0;
    if (head >= t->size)
        return 0;
    int i = 0;
    if (t->arr[head])
    {
        printf("%d ", t->arr[head]);
        i = 1;
    }
    i += printPreorder(t, 2 * head + 1);
    i += printPreorder(t, 2 * head + 2);
    return i;
}

int printInorder(Tree *t, int head)
{
    if (t == NULL)
        return 0;
    if (t->arr == NULL)
        return 0;
    if (t->isEmpty)
        return 0;
    if (head >= t->size)
        return 0;
    int i = 0;
    i += printInorder(t, 2 * head + 1);
    if (t->arr[head])
    {
        printf("%d ", t->arr[head]);
        i += 1;
    }
    i += printInorder(t, 2 * head + 2);
    return i;
}

int printPostorder(Tree *t, int head)
{
    if (t == NULL)
        return 0;
    if (t->arr == NULL)
        return 0;
    if (t->isEmpty)
        return 0;
    if (head >= t->size)
        return 0;
    int i = 0;
    i += printPostorder(t, 2 * head + 1);
    i += printPostorder(t, 2 * head + 2);
    if (t->arr[head])
    {
        printf("%d ", t->arr[head]);
        i += 1;
    }
    return i;
}

int main()
{
    Tree *t = createTree(20);
    insert(t, 20);
    insert(t, 23);
    insert(t, 15);
    insert(t, 10);
    insert(t, 18);
    insert(t, 22);
    insert(t, 25);

    printf("\nPre order: ");
    int x = printPreorder(t, 0);
    printf("\nIn order: ");
    printInorder(t, 0);
    printf("\nPost order: ");
    printPostorder(t, 0);
    printf("\nTotal nodes: %d", x);
    return 0;
}