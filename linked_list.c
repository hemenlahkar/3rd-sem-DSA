#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

void print_LL(Node *head)
{
    while (head != NULL)
    {
        printf(" %d,", head->data);
        head = head->next;
    }
    putchar('\n');
}

Node *insert_at_beginning(Node *head, int key)
{
    Node *t = (Node *)malloc(sizeof(Node));
    if (t == NULL)
    {
        printf("Couldn't allocate memory");
        return head;
    }
    t->data = key;
    t->next = head;
    return t;
}

Node *insert_at_end(Node *head, int key)
{
    Node *t = (Node *)malloc(sizeof(Node)), *p;
    t->data = key;
    t->next = NULL;
    if (head == NULL)
    {
        return t;
    }
    for (p = head; p->next != NULL; p = p->next)
        ;
    p->next = t;
    return head;
}

Node *insert_at_position(Node *head, int position, int key)
{
    Node *t = (Node *)malloc(sizeof(Node));
    Node *p = head;
    t->data = key;
    for (int i = 1; i < position - 1 && p != NULL; i++, p = p->next)
        ;
    if (p == NULL)
    {
        printf("Invalid position!!\n");
        return head;
    }
    t->next = p->next;
    p->next = t;
    return head;
}

Node *delete_from_beginning(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *t = head;
    head = head->next;
    free(t);
    return head;
}

Node *delete_from_end(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    Node *p;
    for (p = head; p->next->next != NULL; p = p->next)
        ;
    Node *t = p->next;
    p->next = NULL;
    free(t);
    return head;
}

int main()
{
    Node *head = NULL;
    for (int i = 0; i < 5; i++)
        head = insert_at_beginning(head, i + 5);
    print_LL(head);
    for (int i = 0; i < 4; i++)
        head = insert_at_end(head, i + 1);
    print_LL(head);
    head = delete_from_beginning(head);
    print_LL(head);
    head = delete_from_end(head);
    print_LL(head);
    head = insert_at_position(head, 4, 43);
    print_LL(head);
    return 0;
}