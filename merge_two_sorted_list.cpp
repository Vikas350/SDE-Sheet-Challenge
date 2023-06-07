#include <bits/stdc++.h>

// Following is the linked list node structure.

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

Node<int> *sortTwoLists(Node<int> *list1, Node<int> *list2)
{
    // Write your code here.
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }
    if (list1 == NULL && list2 == NULL)
    {
        return NULL;
    }

    Node<int> *ans = NULL, *last = NULL;
    if (list1->data <= list2->data)
    {
        ans = list1;
        last = list1;
        list1 = list1->next;
        last->next = NULL;
    }
    else
    {
        ans = list2;
        last = list2;
        list2 = list2->next;
        last->next = NULL;
    }

    while (list1 && list2)
    {
        if (list1->data <= list2->data)
        {
            last->next = list1;
            last = list1;
            list1 = list1->next;
            last->next = NULL;
        }
        else // if(list1->val > list2->val)
        {
            last->next = list2;
            last = list2;
            list2 = list2->next;
            last->next = NULL;
        }
    }

    if (list1)
    {
        last->next = list1;
    }
    else
    {
        last->next = list2;
    }

    return ans;
}
