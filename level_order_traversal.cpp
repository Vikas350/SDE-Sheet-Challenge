#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T val;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    vector<int> ans;

    if (root == NULL)
        return ans;

    while (!q.empty())
    {
        int sz = q.size();
        // vector<int> level;
        for (int i = 0; i < sz; i++)
        {
            BinaryTreeNode<int> *temp = q.front();
            q.pop();

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);

            ans.push_back(temp->val);
        }
    }

    return ans;
}