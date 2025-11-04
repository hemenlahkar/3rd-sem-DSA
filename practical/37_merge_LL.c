#include "../headers/singly_LL.h"

int merge_sorted(Node **head1, Node **head2, Node **merged)
{
    if(*head1 == NULL || *head2 == NULL)
    {
        printf("\nCan't merge empty list\n");
        return 0;
    }
    Node *temp1 = *head1, *temp2 = *head2;
    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1->data < temp2->data)
        {
            insert_last(merged, temp1->data);
            temp1 = temp1->next;
        }
        else
        {
            insert_last(merged, temp2->data);
            temp2 = temp2->next;
        }
    }
    while(temp1 != NULL) {
        insert_last(merged, temp1->data);
        temp1 = temp1->next;
    }
    while(temp2 != NULL) {
        insert_last(merged, temp2->data);
        temp2 = temp2->next;
    }
    return 1;
}

int main()
{
    Node *list1 = NULL, *list2 = NULL, *merged_list = NULL;

    for(int i = 1; i < 8; i++)
    {
        insert_last(&list1, i+3);
        insert_last(&list2, i*i);
    }

    merge_sorted(&list1, &list2, &merged_list);
    printList(list1);
    printList(list2);
    printList(merged_list);
    return 0;
}