#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

void printList(Node *head)
{
    while(head != NULL)
    {
        printf("%d", head->data);
        head = head->next;
        if(head->next != NULL) printf(", ");
    }
    putchar('\n');
}

Node *createNode(int x)
{
    Node *ret = (Node *)malloc(x * sizeof(int));
    if(ret == NULL)
    {
        printf("\nCouldn't create node: out of memory!!\n");
        return NULL;
    }
    ret->data = x;
    ret->next = NULL;
    return ret;
}

int insert_first(Node **head, int x)
{
    Node *temp = createNode(x);
    if(temp == NULL) return 0;
    temp->next = *head;
    *head = temp;
    return 1;
}

int insert_last(Node **head, int x)
{
    Node *temp = createNode(x);
    if(temp == NULL) return 0;
    if(*head = NULL)
    {
        *head = temp;
        return 1;
    }
    Node *last;
    for(last = *head; last->next != NULL; last = last->next);
    last->next = temp;
    return 1;
}

int insert_at_position(Node **head, int x, int position)
{
    if(position < 0)
    {
        printf("\nInvalid position entered!!\n");
        return 0;
    }
    if(position == 0) insert_first(head, x);
    Node *location = *head;
    int i;
    for(i = 0; location != NULL && i < position; i++);

    if(location == NULL)
    {
        printf("\nInvalid position entered!!\n");
        return 0;
    }
    Node *temp = createNode(x);
    temp->next = location->next;
    location->next = temp;
    return 1;
}

int delete_first(Node **head)
{
    if(*head == NULL)
    {
        printf("\nCouldn't delete node: list is empty!!\n");
        return 0;
    }
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
    return 1;
}

int delete_last(Node **head)
{
    if(*head == NULL)
    {
        printf("\nCouldn't delete node: list is empty!!\n");
        return 0;
    }
    Node *location = *head;
    for(;location->next != NULL; location = location->next);
    Node *temp = location->next;
    location->next = NULL;
    free(temp);
    return 1;
}

int delete_from_position(Node **head, int position)
{
    if(position < 0)
    {
        printf("\nCouldn't delete Node: Invalid poisition Entred!!\n");
        return 0;
    }
    if(*head == NULL)
    {
        printf("\nCouldn't delete Node: List is empty!!\n");
        return 0;
    }
    Node *location = *head;
    int i;
    for(i = 0; location->next != NULL && i < 0; location = location->next);
    Node *temp = location->next;
    location->next = NULL;
    if(temp->next != NULL) location->next = temp->next;
    free(temp);
    return 1;
}



int main()
{
    Node *head = createNode(3);
    return 0;
}