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

vector<int> bottomView(BinaryTreeNode<int> *root)
{

    // Write your code here.
    map<int, int> topNodes;
    queue<pair<BinaryTreeNode<int> *, int>> q;
    q.push({root, 0});

    vector<int> ans;
    if (root == NULL)
        return ans;

    while (!q.empty())
    {
        pair<BinaryTreeNode<int> *, int> temp = q.front();
        q.pop();
        BinaryTreeNode<int> *frontNode = temp.first;
        int hd = temp.second;

        // if(topNodes.count(hd) == 0){
        //     topNodes[hd] = frontNode->val;
        // }
        topNodes[hd] = frontNode->data;

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
