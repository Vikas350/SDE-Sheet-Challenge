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
            delete left;
        if (right)
            delete right;
    }
};

void inorder(BinaryTreeNode<int> *root, vector<int> &ino)
{
    if (!root)
        return;
    inorder(root->left, ino);
    ino.push_back(root->data);
    inorder(root->right, ino);
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    vector<int> ino;
    inorder(root, ino);
    int i = 0, j = ino.size() - 1;
    while (i < j)
    {
        if (ino[i] + ino[j] == k)
        {
            return true;
        }

        if (ino[i] + ino[j] < k)
        {
            i++;
        }
        else if (ino[i] + ino[j] > k)
        {
            j--;
        }
    }

    return false;
    // Write your code here
}