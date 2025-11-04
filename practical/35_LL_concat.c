#include "../headers/singly_LL.h"

int concat_list(Node **head1, Node **head2)
{
    if(*head1 == NULL || *head2 == NULL)
    {
        printf("\nError: One of the list is empty!!\n");
        return 0;
    }
    Node *temp = *head1;
    while(temp->next != NULL) temp = temp->next;
    temp->next = *head2;
    return 1;
}

int main()
{
    Node *list1 = NULL, *list2 = NULL;
    for (int i = 5; i < 17; i++)
    {
        insert_last(&list1, i);
        insert_last(&list2, 50 - i);
    }

    printList(list1);
    printList(list2);
    concat_list(&list1, &list2);
    printList(list1);
    return 0;
}