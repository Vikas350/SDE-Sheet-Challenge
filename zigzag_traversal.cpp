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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    vector<int> sol;

    if (root == NULL)
        return sol;
    int cnt = 0;

    while (!q.empty())
    {
        int sz = q.size();
        vector<int> ans;
        // vector<int> level;
        for (int i = 0; i < sz; i++)
        {
            BinaryTreeNode<int> *temp = q.front();
            q.pop();

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);

            ans.push_back(temp->data);
        }

        cnt++;

        if (cnt % 2 == 0)
            reverse(ans.begin(), ans.end());

        sol.insert(sol.end(), ans.begin(), ans.end());
    }

    return sol;
}
