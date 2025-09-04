#include <stdio.h>
#include <stdlib.h>
#include "stack_node.c"

int delete(Node **root, int item)
{
    Node *location, *parent, *inorder_successor_location, *inorder_successor_parent;
    for (parent = NULL, location = *root; location != NULL && location->data != item;)
    {
        parent = location;
        location = location->data > item ? location->left : location->right;
    }

    if (location == NULL)
    {
        printf("Couldn't find the item to be deleted!\n");
        return 0;
    }

    if (location->left == NULL || location->right == NULL)
    {
        if (location == *root)
        {
            *root = (*root)->left != NULL ? (*root)->left : (*root)->right;
            free(location);
            return 1;
        }
        if (location == parent->left)
            parent->left = location->left != NULL ? location->left : location->right;
        else
            parent->right = location->left != NULL ? location->left : location->right;
    }
    else
    {
        for (inorder_successor_parent = location, inorder_successor_location = location->right; inorder_successor_location->left != NULL;)
        {
            inorder_successor_parent = inorder_successor_location;
            inorder_successor_location = inorder_successor_location->left;
        }
        location->data = inorder_successor_location->data;
        if (inorder_successor_location == inorder_successor_parent->left)
            inorder_successor_parent->left = inorder_successor_location->left != NULL ? inorder_successor_location->left : inorder_successor_location->right;
        else
            inorder_successor_parent->right = inorder_successor_location->left != NULL ? inorder_successor_location->left : inorder_successor_location->right;
    }
}

void inorder_iterative(Node *root)
{
    Stack *S = NULL;
    Node *current = root;

    while (current != NULL || !isEmpty(S))
    {
        while (current != NULL)
        {
            push(&S, current);
            current = current->left;
        }

        pop(&S, &current);
        printf(" %d", current->data);

        current = current->right;
    }
}

void preorder_iterative(Node *root)
{
    Stack *top = NULL;
    Node *popped_item;
    push(&top, root);
    while (!isEmpty(top))
    {
        pop(&top, &popped_item);
        printf(" %d", popped_item->data);
        if (popped_item->right != NULL)
            push(&top, popped_item->right);
        if (popped_item->left != NULL)
            push(&top, popped_item->left);
    }
}

void postorder_iterative(Node *root)
{
    Stack *S1 = NULL, *S2 = NULL;
    Node *popped_item;
    push(&S1, root);
    while (!isEmpty(S1))
    {
        if (pop(&S1, &popped_item))
            push(&S2, popped_item);
        if (popped_item->left != NULL)
            push(&S1, popped_item->left);
        if (popped_item->right != NULL)
            push(&S1, popped_item->right);
    }
    while (!isEmpty(S2))
    {
        pop(&S2, &popped_item);
        printf(" %d", popped_item->data);
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
    inorder_iterative(root);
    printf("\nPreorder: ");
    preorder_iterative(root);
    printf("\nPostorder: ");
    postorder_iterative(root);
    delete(&root, 30);
    printf("\nInorder after deleting 30: ");
    inorder_iterative(root);
    return 0;
}