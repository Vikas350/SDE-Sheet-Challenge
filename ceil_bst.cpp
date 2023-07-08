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

// void inorder(BinaryTreeNode<int> *root, int key, int &ans){
//     if(root == NULL) return ;

//     inorder(root->left,key,ans);
//     if(root->data >= key && ans == -1) ans = root->data;
//     inorder(root->right,key,ans);

// }
int findCeil(BinaryTreeNode<int> *node, int x)
{
    // Write your code here.
    int ans = -1;
    while (node)
    {
        if (node->data == x)
        {
            return node->data;
        }

        if (x > node->data)
        {
            node = node->right;
        }
        else
        {
            ans = node->data;
            node = node->left;
        }
    }

    return ans;
}