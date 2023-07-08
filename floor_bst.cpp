#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(TreeNode<int> *root, int key, int &ans)
{
    if (root == NULL)
        return;

    inorder(root->left, key, ans);
    if (root->val <= key)
        ans = root->val;
    inorder(root->right, key, ans);
}
int floorInBST(TreeNode<int> *root, int X)
{
    // Write your code here.
    int ans = -1;
    inorder(root, X, ans);
    return ans;
}