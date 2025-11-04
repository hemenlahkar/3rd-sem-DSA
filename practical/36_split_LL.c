#include "../headers/singly_LL.h"

int split_at_position(Node **head, int k, Node **ret)
{
    if(k <= 0) return 0;
    if(*head == NULL)
    {
        printf("\nError: list is empty!\n");
        return 0;
    }
    if((*head)->next == NULL)
    {
        printf("\nError: list too short to split!!\n");
        return 0;
    }
    int i = 1;
    Node *temp = *head;
    while(i < k && temp != NULL) temp = temp->next, i++;
    if(temp == NULL)
    {
        printf("\nError: Invalid position entered!\n");
        return 0;
    }
    *ret = temp->next;
    temp->next = NULL;
    return 1;
}

int main()
{
    Node *list1 = NULL, *list2 = NULL;
    for (int i = 1; i <= 15; i++)
        insert_first(&list1, i * i - 1);
    printList(list1);
    split_at_position(&list1, 7, &list2);
    printList(list1);
    printList(list2);
    
    return 0;
}