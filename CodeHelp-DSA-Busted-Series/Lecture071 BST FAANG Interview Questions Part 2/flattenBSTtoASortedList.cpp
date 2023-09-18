#include<iostream>
#include<vector>
using namespace std;

    template <typename T>
    class TreeNode {
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
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

void inorderTraversal(TreeNode<int>* root, vector<int>&inorder)
{
    // using recursion
    // base case 
    if(root == NULL)
    {
        return;
    }
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Algo 
    // 1. Store inorder traversal of the BST
    vector<int> inorder;
    inorderTraversal(root, inorder);
    // 2. Make left ptr NULL and point right ptr to next node 
    int n = inorder.size();
    TreeNode<int>* newRoot = new TreeNode<int>(inorder[0]);
    TreeNode<int>* curr = newRoot;
    
    for(int i=1; i<n; i++)
    {
        TreeNode<int>* temp = new TreeNode<int>(inorder[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    // 3. Make left and right ptrs of the last node as NULL
    curr->left = NULL;
    curr->right = NULL;
    return newRoot;
}

// https://www.codingninjas.com/studio/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTab=0