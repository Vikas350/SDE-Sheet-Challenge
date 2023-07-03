#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

void goLeft(TreeNode<int> *root, vector<int> &v)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    v.push_back(root->data);

    if (root->left != NULL)
        goLeft(root->left, v);
    else
        goLeft(root->right, v);
}

void leafNodes(TreeNode<int> *root, vector<int> &v)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        v.push_back(root->data);
        return;
    }

    leafNodes(root->left, v);
    leafNodes(root->right, v);
}

void goRight(TreeNode<int> *root, vector<int> &v)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    if (root->right != NULL)
        goRight(root->right, v);
    else
        goRight(root->left, v);

    v.push_back(root->data);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> v;

    if (root == NULL)
    {
        return v;
    }
    v.push_back(root->data);
    goLeft(root->left, v);
    leafNodes(root->left, v);
    leafNodes(root->right, v);
    goRight(root->right, v);

    return v;
}