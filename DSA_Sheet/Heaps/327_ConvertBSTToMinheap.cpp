#include <iostream> 
#include<vector>
using namespace std;
    
    // Following is the Binary Tree node structure:

	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};


// *************************** MAIN CODE **********************************
void solve(BinaryTreeNode*root, int &index, vector<int>&ans)
{
    if(root==NULL)
    {
        return;
    }
    root->data = ans[index];
    index++;
    solve(root->left,index,ans);
    solve(root->right,index,ans);
    
}
void inorder(BinaryTreeNode*root,vector<int>&ans){
    if(root==NULL)
        return;
    
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
    
}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
    vector<int>ans;
    inorder(root,ans);
    int index=0;
    solve(root,index,ans);
    return root;
}
// ************************* MAIN CODE ENDS **********************************

// https://www.codingninjas.com/studio/problems/convert-bst-to-min-heap_920498?leftPanelTab=1
// https://www.geeksforgeeks.org/convert-bst-min-heap/