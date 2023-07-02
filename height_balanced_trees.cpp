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

int maxDepth(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int heightLeft = maxDepth(root->left);
    int heightRight = maxDepth(root->right);

    return max(heightLeft, heightRight) + 1;
}
bool isBalancedBT(BinaryTreeNode<int> *root)
{
    // Write your code here.
    if (root == NULL)
        return true;

    bool left = isBalancedBT(root->left);
    bool right = isBalancedBT(root->right);

    return left && right && abs(maxDepth(root->left) - maxDepth(root->right)) <= 1;
}