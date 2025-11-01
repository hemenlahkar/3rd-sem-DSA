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

int main()
{
    Node *head = NULL;
    for(int i = 1; i < 6; i++)
        insert_first(&head, i+2);

    printList(head);
    return 0;
}