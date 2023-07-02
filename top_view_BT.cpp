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

vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    map<int, int> topNodes;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});

    vector<int> ans;
    if (root == NULL)
        return ans;

    while (!q.empty())
    {
        pair<TreeNode<int> *, int> temp = q.front();
        q.pop();
        TreeNode<int> *frontNode = temp.first;
        int hd = temp.second;

        if (topNodes.count(hd) == 0)
        {
            topNodes[hd] = frontNode->val;
        }

        if (frontNode->left)
        {
            q.push({frontNode->left, hd - 1});
        }

        if (frontNode->right)
        {
            q.push({frontNode->right, hd + 1});
        }
    }

    for (auto i : topNodes)
    {
        ans.push_back(i.second);
    }

    return ans;
}