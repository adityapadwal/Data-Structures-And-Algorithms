#include<iostream>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
private:
    TreeNode* minVal(TreeNode* root)
    {
        TreeNode* temp = root;
        while(temp -> left)
        {
            temp = temp -> left;
        }
        return temp;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // base case 
        if(root==NULL)
        {
            return NULL;
        }
        
        if(root->val == key)
        {
            // Case 1: leaf node 
            if(root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            
            // Case 2: 1 child 
            // a) delete left
            if(root->left!=NULL && root->right==NULL)
            {
                TreeNode* temp = root->left;
                // root = temp;
                // delete root->left;
                delete root;
                return temp;
            }
            // b) delete right
            if(root->right!=NULL && root->left==NULL)
            {
                TreeNode* temp = root->right;
                // root = temp;
                // delete root->right;
                delete root;
                return temp;
            }
            
            // Case 3: 2 children 
            if(root->left!=NULL && root->right!= NULL)
            {
                // replace root with inorder successor
                // Step 1: Find the minimum node from the left subtree
                int mini = minVal(root->right)->val;
                // Step 2: Replace root with mini
                root->val = mini;
                // Step 3: Delete mini
                root->right = deleteNode(root->right, mini);
                return root;
            }
        }
        
        else if(root->val < key)
        {
            root->right = deleteNode(root->right, key);
            return root;
        }
        
        else
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
         
        return NULL;
    }
};