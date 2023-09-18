//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
int getPosition(int in[], int element, int n)
    {
        for(int i=0; i<n; i++)
        {
            if(in[i] == element)
            {
                return i;
            }
        }
        return -1;
    }
    
Node* solve(int in[], int post[], int &postorderIndex, int inorderStart, int inorderEnd, int n)
    {
        // using recursion
        // base case 
        if(postorderIndex <0 || inorderStart > inorderEnd)
        {
            return NULL;
        }
        
        int element = post[postorderIndex];
        postorderIndex--;
        Node* root = new Node(element);
        
        // now getting the position of element from inorder
        int position = getPosition(in, element, n);
        
        root->right = solve(in, post, postorderIndex, position+1, inorderEnd, n);
        root->left = solve(in, post, postorderIndex, inorderStart, position-1, n);
        
        return root;
    }
    
Node *buildTree(int in[], int post[], int n) {
    int postorderIndex = n-1;
    Node* ans = solve(in, post, postorderIndex, 0, n-1, n);
    return ans;
}

// https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1