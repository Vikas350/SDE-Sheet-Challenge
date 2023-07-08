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

class BSTiterator
{
public:
    vector<int> v;
    int i = 0;
    void inorder(TreeNode<int> *root)
    {
        if (!root)
            return;
        inorder(root->left);
        v.push_back(root->data);
        inorder(root->right);
    }

    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        inorder(root);
    }

    int next()
    {
        // write your code here
        return v[i++];
    }

    bool hasNext()
    {
        // write your code here
        if (i >= v.size())
            return false;
        return true;
    }
};

/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/