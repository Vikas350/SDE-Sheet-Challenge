#include <bits/stdc++.h>
using namespace std;

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode<T> *random;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    map<LinkedListNode<int> *, LinkedListNode<int> *> vk;
    LinkedListNode<int> *ptr = head;
    while (ptr)
    {
        vk[ptr] = new LinkedListNode<int>(ptr->data);
        ptr = ptr->next;
    }

    ptr = head;

    while (ptr)
    {
        vk[ptr]->next = vk[ptr->next];
        vk[ptr]->random = vk[ptr->random];
        ptr = ptr->next;
    }

    return vk[head];
}