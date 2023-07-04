#include <bits/stdc++.h>
using namespace std;
template <typename T>

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

bool searchInBST(BinaryTreeNode<int> *root, int x)
{
    // Write your code here.
    BinaryTreeNode<int> *temp = root;
    while (temp)
    {
        if (temp->data == x)
        {
            return true;
        }

        if (x > temp->data)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }

    return false;
}