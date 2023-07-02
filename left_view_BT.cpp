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

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    queue<TreeNode<int> *> q;
    q.push(root);
    vector<int> ans;
    if (root == NULL)
        return ans;

    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            TreeNode<int> *temp = q.front();
            q.pop();

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);

            if (i == 0)
            {
                ans.push_back(temp->data);
            }
        }
    }

    return ans;
}