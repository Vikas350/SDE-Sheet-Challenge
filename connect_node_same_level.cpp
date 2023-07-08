#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode<T> *next;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

void connectNodes(BinaryTreeNode<int> *root)
{
    // Write your code here.
    if (!root)
        return;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = q.size();
        BinaryTreeNode<int> *prev = q.front();
        for (int i = 0; i < sz; i++)
        {
            BinaryTreeNode<int> *top = q.front();
            q.pop();

            if (i > 0 && prev != NULL)
            {
                prev->next = top;
                prev = prev->next;
            }

            if (i == sz - 1)
            {
                top->next = NULL;
            }

            if (top->left)
                q.push(top->left);
            if (top->right)
                q.push(top->right);
        }
    }
}