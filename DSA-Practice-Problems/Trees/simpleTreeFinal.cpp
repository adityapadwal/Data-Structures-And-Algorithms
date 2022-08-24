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
        this->right = NULL;
        this->left = NULL;
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

    cout<<"\n Enter data to the left of "<<data<<" : ";
    root->left = buildTree(root->left);

    cout<<"\n Enter data to the right of "<<data<<" : ";
    root->right = buildTree(root->right);

    return root;
}

void levelorder(node* root)
{
    queue<node*>q;
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        cout<<" "<<temp->data;
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

void inorder(node* root)
{
    // base case 
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<" "<<root->data;
    inorder(root->right);
}

void preorder(node* root)
{
    // base case
    if(root == NULL)
    {
        return;
    }
    cout<<" "<<root->data;
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root)
{
    // base case 
    if(root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<" "<<root->data;
}

void buildFromLevelOrder(node* &root)
{
    queue<node*>q;
    cout<<"\n Enter data: ";
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        cout<<"\n Enter data to the left of "<<temp->data<<" : ";
        int leftData;
        cin>>leftData;

        if(leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout<<"\n Enter data to the right of "<<temp->data<<" : ";
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
    levelorder(root);

    cout<<"\n Inorder Traversal"<<endl;
    inorder(root);

    cout<<"\n Preorder Traversal"<<endl;
    preorder(root);

    cout<<"\n Postorder Traversal"<<endl;
    postorder(root);

    cout<<"\n Build From level order traversal";
    // 1 3 5 7 11 -1 -1 -1 -1 -1 -1 -1 
    buildFromLevelOrder(root);
    levelorder(root);
return 0;
}