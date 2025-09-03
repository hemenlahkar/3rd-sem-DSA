#include <stdio.h>
#include <stdlib.h>
#include "stack_node.c"

void preorder_iterative(Node *root)
{
    Stack *top = NULL;
    Node *popped_item;
    push(&top, root);
    while (isEmpty(top))
    {
        pop(&top, &popped_item);
        printf(" %d", popped_item->data);
        if(popped_item->right != NULL)
            push(&top, popped_item->right);
        if(popped_item->left != NULL)
            push(&top, popped_item->left);
    }
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf(" %d", root->data);
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    printf(" %d", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf(" %d", root->data);
}

int insert(Node **root, int item)
{
    Node *newNode, *location, *parent;
    if (*root == NULL)
    {
        newNode = (Node *)malloc(sizeof(Node));
        if (newNode == NULL)
        {
            printf("Insufficient memory!\n");
            return 0;
        }
        newNode->data = item;
        newNode->left = newNode->right = NULL;
        *root = newNode;
        return 1;
    }
    for (parent = NULL, location = *root; location != NULL && location->data != item;)
    {
        parent = location;
        location = location->data > item ? location->left : location->right;
    }
    if (location != NULL)
    {
        printf("Node with value %d already exists!\n", item);
        return 0;
    }
    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = item;
    newNode->left = newNode->right = NULL;
    if (parent->data > item)
        parent->left = newNode;
    else
        parent->right = newNode;
    return 1;
}

int main()
{
    Node *root = NULL;
    insert(&root, 70);
    insert(&root, 30);
    insert(&root, 90);
    insert(&root, 10);
    insert(&root, 50);
    insert(&root, 40);
    insert(&root, 20);
    insert(&root, 90);
    printf("\nInorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    return 0;
}