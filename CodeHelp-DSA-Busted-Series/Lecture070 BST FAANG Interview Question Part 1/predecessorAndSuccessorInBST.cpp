#include<iostream>
using namespace std;

    // Following is the Binary Tree node structure
    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Algo
    // 1. Find the key 
    BinaryTreeNode<int>* temp = root;
    int pred = -1;
    int succ = -1;
    while(temp->data != key)
    {
        if(temp->data > key)
        {
            succ = temp->data;
            // key lies in left subtree
            temp = temp->left;
        }
        else 
        {
            pred = temp->data;
            // key lies in right subtree 
            temp = temp->right;
        }
    }
    
    // 2. Find the predecessor and successor 
    BinaryTreeNode<int>* leftTree = temp->left;
    BinaryTreeNode<int>* rightTree = temp->right;
    
    while(leftTree != NULL)
    {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }
    
    while(rightTree != NULL)
    {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }
    
    pair<int, int>ans = make_pair(pred, succ);
    return ans;
}
