#include <bits/stdc++.h>
using namespace std;

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

LinkedListNode<int> *getMid(LinkedListNode<int> *head)
{
    LinkedListNode<int> *slow = head, *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

LinkedListNode<int> *reverseList(LinkedListNode<int> *head)
{
    LinkedListNode<int> *p = head, *q = NULL, *r = NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    return q;
}

bool isPalindrome(LinkedListNode<int> *head)
{
    // Write your code here.
    if (head == NULL || head->next == NULL)
        return true;

    LinkedListNode<int> *part2 = getMid(head);

    LinkedListNode<int> *temp = part2->next;

    part2->next = reverseList(temp);

    LinkedListNode<int> *part1 = head;
    LinkedListNode<int> *part3 = part2->next;

    while (part3)
    {
        if (part1->data != part3->data)
        {
            return false;
        }

        part1 = part1->next;
        part3 = part3->next;
    }

    return true;
}