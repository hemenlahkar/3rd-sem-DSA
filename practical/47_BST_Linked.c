#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} Node;

Node *createNode(int key)
{
    Node *ret = (Node *)malloc(sizeof(Node));
    if (ret == NULL)
        return NULL;
    ret->data = key;
    ret->left = ret->right = NULL;
    return ret;
}

int insert(Node **top, int key)
{
    Node *temp = createNode(key);
    if (*top == NULL)
    {
        *top = temp;
        return 1;
    }
    Node *i = *top;
    while (1)
    {
        if(i->data == key) return 0;
        if (i->data > key)
        {
            if (i->left != NULL)
                i = i->left;
            else
            {
                i->left = temp;
                return 1;
            }
        }
        else
        {
            if(i->right != NULL)
                i = i->right;
            else
            {
                i->right = temp;
                return 1;
            }
        }
    }
}

void printPreOrder(Node *top)
{
    if(top == NULL) return;
    printf("%d ", top->data);
    printPreOrder(top->left);
    printPreOrder(top->right);
}

void printInOrder(Node *top)
{
    if(top == NULL) return;
    printInOrder(top->left);
    printf("%d ", top->data);
    printInOrder(top->right);
}

void printPostOrder(Node *top)
{
    if(top == NULL) return;
    printPostOrder(top->left);
    printPostOrder(top->right);
    printf("%d ", top->data);
}

int main()
{
    Node *top = NULL;
    insert(&top, 20);
    insert(&top, 23);
    insert(&top, 15);
    insert(&top, 10);
    insert(&top, 18);
    insert(&top, 22);
    insert(&top, 25);

    printf("\nPre order: ");
    printPreOrder(top);
    printf("\nIn order: ");
    printInOrder(top);
    printf("\nPost order: ");
    printPostOrder(top);
    
    return 0;
}