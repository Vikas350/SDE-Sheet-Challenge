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
};

int height(TreeNode<int> *root, int &dia)
{
    if (root == NULL)
        return 0;

    int lh = height(root->left, dia);
    int rh = height(root->right, dia);

    dia = max(dia, lh + rh);

    return max(lh, rh) + 1;
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    // Write Your Code Here.
    int dia = 0;
    height(root, dia);
    return dia;
}
