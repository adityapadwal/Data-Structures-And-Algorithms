#include <bits/stdc++.h> 
    // Following is the Binary Search Tree node structure
    
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

int solve(TreeNode<int>* root, int &count, int k)
{
    if(root == NULL)
    {
        return -1;
    }

    int right = solve(root->right, count, k);
    if(right != -1)
    {
        return right;
    }

    count++;
    if(count == k)
    {
        return root->data;
    }
    return solve(root->left, count, k);
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    int count = 0;
    int finalAns = solve(root, count, k);
    return finalAns;
}
// https://www.codingninjas.com/studio/problems/k-th-largest-number_920438?leftPanelTab=0