#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *prev, *next;
} Node;

void printList(Node *head)
{
    while(head != NULL)
    {
        printf("%d", head->data);
        head = head->next;
        if(head != NULL) printf(", ");
    }
    putchar('\n');
}

void printListReverse(Node *head)
{
    while(head->next != NULL) head = head->next;
    while(head != NULL)
    {
        printf("%d", head->data);
        head = head->prev;
        if(head != NULL) printf(", ");
    }
    putchar('\n');
}

Node *createNode(int x)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if(temp == NULL)
    {
        printf("\nCouldn't create node: Out of memory!!\n");
        return NULL;
    }
    temp->data = x;
    temp->next = temp->prev = NULL;
    return temp;
}

int insert_first(Node **head, int x)
{
    Node *temp = createNode(x);
    if(temp == NULL) return 0;
    if(*head == NULL)
    {
        *head = temp;
        return 1;
    }
    temp->next = *head;
    (*head)->prev = temp;
    *head = temp;
    return 1;
}

int insert_last(Node **head, int x)
{
    Node *temp = createNode(x);
    if (temp == NULL) return 0;
    if (*head == NULL)
    {
        *head = temp;
        return 1;
    }
    Node *location = *head;
    while(location->next != NULL) location = location->next;
    location->next = temp;
    temp->prev = location;
    return 1;
}

int insert_at_position(Node **head, int x, int position)
{
    Node *location, *temp = createNode(x);
    int i = 0;
    if(temp == NULL) return 0;
    if(position < 0) return 0;
    if(*head == NULL) return 0;
    for(location = *head; location != NULL && i < position - 1; location = location->next, i++);

    temp->next = location->next;
    temp->prev = location;
    location->next = temp;
    return 1;
}

int main()
{
    Node *head = NULL;
    for(int i = 1; i < 6; i++)
        insert_first(&head, i+2);
    for(int i = 1; i < 6; i++)
        insert_last(&head, i * i + 3);
    printList(head);
    printListReverse(head);
    insert_at_position(&head, 100, 4);
    printList(head);
    return 0;
}