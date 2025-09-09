#ifndef INTSLLIST_H
#define INTSLLIST_H

class IntSLLNode
{
public:
    int info;
    IntSLLNode *next;
    IntSLLNode(int element){
        info = element;
        next = nullptr;
    }
    IntSLLNode(int element, IntSLLNode *next)
    {
        info = element;
        this->next = next;
    }
};

class IntSLList
{
    IntSLLNode *head, *tail;
    public:
    IntSLList()
    {
        head = tail = nullptr;
    }
    ~IntSLList();
    int isEmpty()
    {
        return head == 0;
    }
    int insert_sorted(int element);
    void display();
    IntSLList *merge(IntSLList &list2);
};

#endif