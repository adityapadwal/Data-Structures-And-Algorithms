#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root)
{
    int data;
    cout<<"\n Enter data: ";
    cin>>data;
    root = new node(data);

    if(data == -1)
    {
        return NULL;
    }
    
    cout<<"\n Enter data to left of "<<data;
    root->left = buildTree(root->left);

    cout<<"\n Enter data to right of "<<data;
    root->right = buildTree(root->right);

    return root;
}

// Level order traversal or BFS traversal 
void levelOrderTraversal(node* root)
{
    queue<node*>q;
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        cout<<temp->data<<" ";

        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
        q.pop();
    }
}

void inorderTraversal(node* root)
{
    // base case 
    if(root == NULL)
    {
        return;
    }

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void preorderTraversal(node* root)
{
    // base case 
    if(root == NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(node* root)
{
    // base case 
    if(root == NULL)
    {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data <<" ";
}

void buildFromLevelOrder(node* &root)
{
    queue<node*> q;
    cout<<"\n Enter data for root"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        cout<<"\n Enter left node for "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout<<"\n Enter right node for "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}
int main()
{
    node* root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    cout<<"\n Level Order Traversal"<<endl;
    levelOrderTraversal(root);

    cout<<"\n Inorder Traversal"<<endl;
    inorderTraversal(root);

    cout<<"\n Preorder Traversal"<<endl;
    preorderTraversal(root);

    cout<<"\n Postorder Traversal"<<endl;
    postorderTraversal(root);

    cout<<"\n Build From level order traversal";
    // 1 3 5 7 11 -1 -1 -1 -1 -1 -1 -1 
    buildFromLevelOrder(root);
    levelOrderTraversal(root);

return 0;
}