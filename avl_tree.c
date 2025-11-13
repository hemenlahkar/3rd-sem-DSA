#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node
{
    int data;
    int height;
    struct node *left, *right;
} Node;

int getHeight(Node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

int getBalanceFactor(Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + (int)fmax(getHeight(y->left), getHeight(y->right));
    x->height = 1 + (int)fmax(getHeight(x->left), getHeight(x->right));

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + (int)fmax(getHeight(x->left), getHeight(x->right));
    y->height = 1 + (int)fmax(getHeight(y->left), getHeight(y->right));

    return y;
}

Node *insert(Node *head, int element)
{
    if (head == NULL)
    {
        Node *temp = (Node *)malloc(sizeof(Node));
        if (temp == NULL)
        {
            printf("\nError inserting %d: insufficient space\n", element);
            return head;
        }

        temp->left = NULL;
        temp->right = NULL;
        temp->data = element;
        temp->height = 1;

        return temp;
    }

    if (element < head->data)
        head->left = insert(head->left, element);
    else if (element > head->data)
        head->right = insert(head->right, element);
    else
        return head;

    head->height = 1 + (int)fmax(getHeight(head->left), getHeight(head->right));

    int bf = getBalanceFactor(head);

    // LL case
    if (bf > 1 && element < head->left->data)
        return rightRotate(head);

    // RR case
    if (bf < -1 && element > head->right->data)
        return leftRotate(head);

    // LR case
    if (bf > 1 && element > head->left->data)
    {
        head->left = leftRotate(head->left);
        return rightRotate(head);
    }

    // RL case
    if (bf < -1 && element < head->right->data)
    {
        head->right = rightRotate(head->right);
        return leftRotate(head);
    }
    return head;
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf(" %3d", root->data);
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    printf(" %3d", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf(" %3d", root->data);
}

int main()
{
    Node *head = NULL;
    head = insert(head, 23);
    head = insert(head, 34);
    head = insert(head, 3);
    head = insert(head, 56);
    head = insert(head, 5);
    head = insert(head, 1);
    head = insert(head, 12);
    head = insert(head, 78);
    head = insert(head, 89);
    head = insert(head, 100);

    inorder(head);
    putchar('\n');
    preorder(head);

    return 0;
}