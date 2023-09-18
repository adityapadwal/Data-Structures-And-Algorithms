//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    private:
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
    
    Node* solve(int in[], int pre[], int &preorderIndex, int inorderStart, int inorderEnd, int n)
    {
        // using recursion
        // base case 
        if(preorderIndex >= n || inorderStart > inorderEnd)
        {
            return NULL;
        }
        
        int element = pre[preorderIndex];
        preorderIndex++;
        Node* root = new Node(element);
        
        // now getting the position of element from inorder
        int position = getPosition(in, element, n);
        
        root->left = solve(in, pre, preorderIndex, inorderStart, position-1, n);
        root->right = solve(in, pre, preorderIndex, position+1, inorderEnd, n);
        
        return root;
    }
    
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        int preorderIndex = 0;
        Node* ans = solve(in, pre, preorderIndex, 0, n-1, n);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/construct-tree-1/1