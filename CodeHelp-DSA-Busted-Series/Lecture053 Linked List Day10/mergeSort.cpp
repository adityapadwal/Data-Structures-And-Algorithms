#include<iostream>
using namespace std;
struct node {
    int data;
    struct node* next;
    node(int x) {
        data = x;
        next = NULL;
    }
};
node* findMiddle(node* head)
{
    node* fast = head->next;
    node* slow = head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node* merge(node* left, node* right)
{
    if(left == NULL)
    {
        return right;
    }
    
    if(right == NULL)
    {
        return left;
    }
    
    node* ans = new node(-1);
    node* temp = ans;
    //Merge two sorted LL
    while(left!=NULL && right!=NULL)
    {
        if(left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    
    while(left!=NULL)
    {
       temp->next = left;
       temp = left;
       left = left->next; 
    }
    
    while(right!=NULL)
    {
       temp->next = right;
       temp = right;
       right = right->next; 
    }
    ans =ans->next;
    return ans;
}
node* mergeSort(node *head) {
    //Base case
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    //Break linkedlist in 2 halves
    node* mid = findMiddle(head);
    node* left = head;
    node* right = mid->next;
    mid->next = NULL;
    
    //Recursive calls
    left = mergeSort(left);
    right = mergeSort(right);
    
    //merge both left and right halves
    node* result = merge(left, right);
    
    return result;
}

//why we prefer merge sort in LL and quicl sort in arrays

//https://www.codingninjas.com/codestudio/problems/mergesort-linked-list_630514?leftPanelTab=1