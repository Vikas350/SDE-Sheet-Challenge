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

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

void inorder(TreeNode<int> *root, int k, priority_queue<int> &pq){
    if(!root) return ;
    inorder(root->left,k,pq);
    pq.push(root->data);
    if(pq.size() > k){
        pq.pop();
    }
    inorder(root->right,k,pq);
}
int kthSmallest(TreeNode<int> *root, int k)
{
    priority_queue<int> pq;
    inorder(root,k,pq);
    return pq.top();
	//	Write the code here.
}