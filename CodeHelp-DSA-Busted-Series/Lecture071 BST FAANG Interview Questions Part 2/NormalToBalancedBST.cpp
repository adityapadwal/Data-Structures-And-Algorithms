#include<iostream>
#include<vector>
using namespace std;

    template <typename T>
    class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

void inorder(TreeNode<int>* root, vector<int> &inorderval)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left, inorderval);
    inorderval.push_back(root->data);
    inorder(root->right, inorderval);
}

TreeNode<int>* inorderToBST(int s, int e, vector<int> inorderval)
{
    if(s > e)
    {
        return NULL;
    }
    int mid = (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(inorderval[mid]);
    root->left = inorderToBST(s, mid-1, inorderval);
    root->right = inorderToBST(mid+1, e, inorderval);
    return root;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> inorderval;
    inorder(root, inorderval);
    
    return inorderToBST(0, inorderval.size()-1, inorderval);
}
