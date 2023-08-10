#include <bits/stdc++.h>
using namespace std;

// Following is the Binary Tree Node class structure:

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

void inorder_traversal(BinaryTreeNode<int> *root, int &cnt)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    inorder_traversal(root->left, cnt);
    if (root->left == NULL && root->right == NULL)
    {
        cnt++;
    }
    inorder_traversal(root->right, cnt);
}

int noOfLeafNodes(BinaryTreeNode<int> *root)
{
    // Algo
    // 1. Inorder traversal karlo
    // 2. if (root->left == NULL && root->right == NULL){cnt++}

    int count = 0;
    inorder_traversal(root, count);
    return count;
}

// https://www.codingninjas.com/codestudio/problems/count-leaf-nodes_893055?source=youtube&campaign=LoveBabbar_Codestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudio&leftPanelTab=1