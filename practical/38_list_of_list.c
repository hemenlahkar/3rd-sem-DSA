#include "../headers/singly_LL.h"

typedef struct list{
    Node *list;
    struct list *next;
} List;

void printListOfList(List *node)
{
    while(node != NULL)
    {
        for(Node *temp = node->list; temp != NULL; temp = temp->next)
            printf("%2d, ", temp->data);
        putchar('\n');
        node = node->next;
    }
}

List *createListNode(Node *element)
{
    List *l = (List *)malloc(sizeof(List));
    l->list = element;
    l->next = NULL;
}

int insert_list_first(List **l, Node *head)
{
    if(head == NULL) return 0;
    if(*l == NULL)
    {
        *l = createListNode(head);
        return 1;
    }
    List *temp = createListNode(head);
    temp->next = *l;
    *l = temp;
    return 1;
}

int main()
{
    Node *list1, *list2, *list3;
    List *l = NULL;
    list1 = list2 = list3 = NULL;

    for(int i = 0; i < 5; i++)
    {
        insert_first(&list1, 2 * i + 2);
        insert_first(&list2, i + 3);
        insert_first(&list3, i + 20);
    }

    insert_list_first(&l, list1);
    insert_list_first(&l, list2);
    insert_list_first(&l, list3);
    printListOfList(l);
    return 0;
}