#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};
Node *firstNode(Node *head)
{

    if (!head || !head->next)
        return NULL;
    //    Write your code here.
    Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    if (slow != fast)
        return NULL;

    Node *r = head;
    while (fast != r && fast)
    {
        fast = fast->next;
        r = r->next;
    }

    return r;
}