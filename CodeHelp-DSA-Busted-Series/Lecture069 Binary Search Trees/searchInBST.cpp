// Search in BST (codeStudio)

/*
    Following is the Binary Tree node structure:

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
*/

// This is the code
/*
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Using recursion
    // base case 
    if(root==NULL)
    {
        return false;
    }
    
    if(root->data == x)
    {
        return true;
    }
    
    if(x < root->data)
    {
        return searchInBST(root->left, x);
    }
    
    if(x > root->data)
    {
        return searchInBST(root->right, x);
    }
}
*/