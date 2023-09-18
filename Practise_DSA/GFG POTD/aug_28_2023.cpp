//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
    cout<<temp->data<<" ";
    temp=temp->next;
    }
}
Node* removeDuplicates(Node *root);
int main() {
	// your code goes here
	int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		Node *head = NULL;
        Node *temp = head;

		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
 // your code goes here
    if(head == NULL)
    {
        return NULL;
    }
    if(head->next == NULL)
    {
        return head;
    }
    
    Node* prev = head;
    Node* curr = head->next;
    
    while(curr != NULL)
    {
        if(prev->data == curr->data)
        {
            if(curr->next != NULL)
            {
                Node* temp = curr->next;
                prev->next = temp;
                curr->next = NULL;
                curr = temp;
            }
            else
            {
                prev->next = NULL;
                curr = NULL;
            }
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    
    return head;
}
// https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1