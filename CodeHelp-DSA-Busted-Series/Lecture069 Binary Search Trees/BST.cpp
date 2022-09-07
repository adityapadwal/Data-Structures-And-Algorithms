#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void insertTree(Node* &root, int data)
{
    if(root == NULL)
    {
        root = new Node(data);
    }

    if(data > root->data)
    {
        insertTree(root->right, data);
    }

    if(data < root->data)
    {
        insertTree(root->left, data);
    }
}

void createTree(Node* &root)
{
    int data;
    cout<<"\n Enter the root data: ";
    cin>>data;

    while(data != -1)
    {
        insertTree(root, data);
        cin>>data;
    }
}

void levelOrderTraversal(Node* root) 
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) 
    {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) 
        { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) 
            { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else
        {
            cout << temp -> data << " ";
            if(temp ->left) 
            {
                q.push(temp ->left);
            }

            if(temp ->right) 
            {
                q.push(temp ->right);
            }
        }
    }
}

void inorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

void preorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}

int main()
{
    Node* root = NULL;
    createTree(root);

    cout<<endl;
    cout<<"\n Printing the level order traversal";
    cout<<endl;
    levelOrderTraversal(root);

    cout<<endl;
    cout<<"\n Printing the inorder traversal";
    cout<<endl;
    inorder(root);

    cout<<endl;
    cout<<"\n Printing the preorder traversal";
    cout<<endl;
    preorder(root);

    cout<<endl;
    cout<<"\n Printing the postorder traversal";
    cout<<endl;
    postorder(root);
    return 0;
}