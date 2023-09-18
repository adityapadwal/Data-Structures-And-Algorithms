//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    int countNodes(Node* root)
    {
        // base case
        if(root == NULL)
        {
            return 0;
        }
        
        int left = countNodes(root->left);
        int right = countNodes(root->right);
        
        return right+left+1;
    }
    
    bool isCBT(Node* root, int index, int cnt)
    {
        // base case
        if(root == NULL)
        {
            return true;
        }
        if(index >= cnt)
        {
            return false;
        }
        
        bool left = isCBT(root->left, 2*index+1, cnt);
        bool right = isCBT(root->right, 2*index+2, cnt);
        
        return left && right;
    }
    
    bool isMaxHeap(Node* root)
    {
        // base case
        if(root->left == NULL && root->right == NULL)
        {
            return true;
        }
        if(root->left != NULL && root->right == NULL)
        {
            return (root->data > root->left->data);
        }
        if(root->left == NULL && root->right != NULL)
        {
            return false;
        }
        
        bool left = isMaxHeap(root->left);
        bool right = isMaxHeap(root->right);
        
        if(left && right && ((root->left->data < root->data) && (root->right->data < root->data)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool isHeap(struct Node* tree) {
        // Algo
        // 1. Check if the tree is a CBT
        // 2. Check if the tree follows max heap property
        int index = 0;
        int nodes = countNodes(tree);

        if(isCBT(tree, index, nodes) && isMaxHeap(tree))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1