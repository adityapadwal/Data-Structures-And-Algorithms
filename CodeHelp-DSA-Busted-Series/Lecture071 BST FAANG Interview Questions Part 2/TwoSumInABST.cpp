#include<iostream>
#include<vector>
using namespace std;
template < typename T >

// Following is the Binary Tree node structure
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};

// ********************************** MAIN CODE *****************************************
void storeInorder(BinaryTreeNode<int>* root, vector<int>&inorder)
{
    // using recursion
    // base case 
    if(root == NULL)
    {
        return;
    }
    
    storeInorder(root->left, inorder);
    inorder.push_back(root->data);
    storeInorder(root->right, inorder);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	// Algo 
    // 1. store inorder traversal of the BST 
    vector<int>inorder;
    storeInorder(root, inorder);
    // 2. Use 2 pointer approach for finding target 
    int size = inorder.size();
    int i = 0;
    int j = size-1;
    while(i < j)
    {
        int sum = inorder[i] + inorder[j];
        if(sum == target)
        {
            return true;
        }
        else if(sum > target)
        {
            j--;
        }
        else
        {
            // sum < target
            i++;
        }
    }
    return false;
}