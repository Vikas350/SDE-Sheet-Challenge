#include <bits/stdc++.h>
using namespace std;

template <typename T = int>
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
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

bool getPath(TreeNode<int> *root, vector<int> &v, int x)
{
    // base case
    if (root == NULL)
    {
        return false;
    }
    // add the root value
    v.push_back(root->data);

    if (root->data == x)
    {
        return true;
    }

    bool lp = getPath(root->left, v, x);
    bool rp = getPath(root->right, v, x);

    if (lp || rp)
    {
        return true;
    }

    // if still not return means no x found in that path
    // so pop that node

    v.pop_back();

    return false;
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> v;
    getPath(root, v, x);
    return v;
}
