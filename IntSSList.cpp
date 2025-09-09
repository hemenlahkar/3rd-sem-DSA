#include <iostream>
#include "headers/IntSSList.h"
using namespace std;

void IntSLList::display()
{
    IntSLLNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

int IntSLList::insert_sorted(int element)
{
    IntSLLNode *newNode = new IntSLLNode(element), *location;
    if (newNode == nullptr)
    {
        cout << "Out of memory!" << endl;
        return 0;
    }
    if (head == nullptr || element < head->info)
    {
        newNode->next = head;
        head = tail = newNode;
        return element;
    }
    for (location = head; location->next != NULL && location->next->info < element; location = location->next)
        ;
    newNode->next = location->next;
    location->next = newNode;
    if (newNode->next == nullptr)
        tail = newNode;
    else
    {
        while (location->next != nullptr)
        {
            location = location->next;
        }
        tail = location;
    }
    return element;
}

IntSLList *IntSLList::merge(IntSLList &list2)
{
    IntSLLNode *i, *j, *x;
    IntSLList *final_list = new IntSLList;
    for (i = this->head, j = list2.head; j != nullptr && i != nullptr;)
    {

        if (i->info > j->info)
        {
            x = new IntSLLNode(j->info);
            j = j->next;
        }
        else
        {
            x = new IntSLLNode(i->info);
            i = i->next;
        }
        x->next = nullptr;
        if (final_list->head == nullptr)
            final_list->head = final_list->tail = x;
        else
        {
            final_list->tail->next = x;
            final_list->tail = final_list->tail->next;
        }
    }
    while (i != nullptr)
    {
        x = new IntSLLNode(i->info);
        x->next = nullptr;
        if (final_list->head == nullptr)
            final_list->head = final_list->tail = x;
        else
        {
            final_list->tail->next = x;
            final_list->tail = final_list->tail->next;
        }
        i = i->next;
    }
    while (j != nullptr)
    {
        x = new IntSLLNode(j->info);
        x->next = nullptr;
        if (final_list->head == nullptr)
            final_list->head = final_list->tail = x;
        else
        {
            final_list->tail->next = x;
            final_list->tail = final_list->tail->next;
        }
        j = j->next;
    }
    return final_list;
}

IntSLList::~IntSLList()
{
    for (IntSLLNode *p; !isEmpty();)
    {
        p = head->next;
        delete head;
        head = p;
    }
}

int main()
{
    IntSLList list1, list2;
    for (int i = 1; i < 5; i++)
        list1.insert_sorted(i * i + 1);
    for (int i = 1; i < 8; i++)
        list2.insert_sorted(i * i + 5);
    list1.display();
    list2.display();
    IntSLList merged_list = *(list1.merge(list2));
    merged_list.display();
    return 0;
}