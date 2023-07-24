#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL; 
    }

    ~Node()
    {
        int value = this->data;
        if(this->next!=NULL)
        {
            delete next;
            next = NULL;
        }
        cout<<"Memory is free for data and value is "<<value<<endl;
    }
};

//<----------------------------Approach1----------------------------------------->
#include<vector>

class Solution{
  public:
    
    bool checkPalindrome(vector<int> arr)
    {   int size = arr.size();
        int s = 0, e = size-1;
        while(s<=e)
        {
            if(arr[s] != arr[e])
            {
                return 0;
            }
            s++;
            e--;
        }
        return 1;
    }
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
       vector<int> arr;
       Node* temp = head;
       while(temp!=NULL)
       {
           arr.push_back(temp->data);
           temp = temp->next;
       }
       
       return checkPalindrome(arr);
    }
};

//<---------------------Approach2------------------------------->'
class Solution{
  public:
    
    Node* getMid(Node*head)
    {
        Node* slow = head;
        Node* fast = head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    Node* reverse(Node* temp)
    {
        Node* prev = NULL;
        Node* curr = temp;
        Node* next = NULL;
        while(curr!=NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
       if(head->next == NULL)
       {
           return true;
       }
       
       //step 1 Get middle of LL
       Node* middle = getMid(head);
       
       //step 2 reverse list after middle element
       Node* temp = middle->next;
       middle->next = reverse(temp);
       Node* head1 = head;
       Node* head2 = middle->next;
       while(head2!=NULL)
       {
          if(head1->data != head2->data)
          {
            return 0; 
          }
          head1 = head1->next;
          head2 = head2->next;
       }
       return true;
    }
};

//https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1