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

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

void inorder(BinaryTreeNode<int> *root, int &pre, int &suc, int key)
{
    if (root == NULL)
        return;

    inorder(root->left, pre, suc, key);
    if (root->data < key)
        pre = root->data;
    if (root->data > key && suc == -1)
        suc = root->data;
    inorder(root->right, pre, suc, key);
}
pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *root, int key)
{
    // Write your code here.
    int pre = -1, suc = -1;
    inorder(root, pre, suc, key);
    return {pre, suc};
}
