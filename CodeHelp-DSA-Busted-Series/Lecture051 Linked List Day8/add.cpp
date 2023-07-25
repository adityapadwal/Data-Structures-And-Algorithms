#include<iostream>
using namespace std;
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
class Solution
{
    public:
    Node* reverse(Node* head)
    {
        Node* prev = NULL;
        Node* curr = head;
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
    
    void insertAtTail(struct Node* &head, struct Node* &tail, int data)
    {
      Node* temp = new Node(data);
      if(head == NULL)
      {
          head = temp;
          tail = temp;
          return;
      }
      else{
          tail->next = temp;
          tail = temp;
      }
    }
    
       struct Node* add(struct Node* first, struct Node* second) {
        int carry = 0;
        
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        while(first != NULL || second != NULL || carry != 0) {
            
            int val1 = 0;
            if(first != NULL)
                val1 = first -> data;
                
            int val2 = 0;
            if(second !=NULL)
                val2 = second -> data;
            
            
            int sum = carry + val1 + val2;
            
            int digit = sum%10;
            
            //create node and add in answer Linked List
            insertAtTail(ansHead, ansTail, digit);
            
            carry = sum/10;
            if(first != NULL)
                first = first -> next;
            
            if(second != NULL)
                second = second -> next;
        }
        return ansHead;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        //Step 1 reverse input LL
        first = reverse(first);
        second = reverse(second);
        
        //step 2 add 2 LL
        Node* ans = add(first, second);
        
        //step 3 reverse ans list
        ans = reverse(ans);
        return ans;
    }
};

//https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1