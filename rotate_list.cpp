#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};
Node *rotate(Node *head, int k)
{
    // Write your code here.
    Node *tail = head;
    int len = 1;
    while (tail->next)
    {
        tail = tail->next;
        len++;
    }

    // now make it cyclic
    tail->next = head;

    while (k > len)
        k = k - len;

    for (int i = 1; i <= len - k; i++)
    {
        tail = tail->next;
    }

    head = tail->next;
    tail->next = NULL;

    return head;
}