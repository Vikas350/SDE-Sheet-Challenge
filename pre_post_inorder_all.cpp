#include <bits/stdc++.h>
using namespace std;

template<typename T>

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

void preorder(BinaryTreeNode<int> *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    ans.push_back(root->data);

    preorder(root->left, ans);

    preorder(root->right, ans);
}
void postorder(BinaryTreeNode<int> *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    postorder(root->left, ans);

    postorder(root->right, ans);

    ans.push_back(root->data);
}
void inorder(BinaryTreeNode<int> *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here.
    vector<int> pre, post, ino;
    preorder(root, pre);
    postorder(root, post);
    inorder(root, ino);

    return {ino, pre, post};
}