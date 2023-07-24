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

//another solution
Node* getMiddle(Node*head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    
    
    
    if(head->next->next == NULL)
    {
        return head->next;
    }
    Node* slow = head;
    Node* fast = head->next;
    
    while(fast!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}

int getLength(Node* head)
{
    int cnt = 0;
    while(head!=NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}
Node *findMiddle(Node *head) {
    int len = getLength(head);
    int ans = (len/2);
    Node* temp = head;
    int cnt = 0;
    while(cnt<ans)
    {
        temp = temp->next;
        cnt++;
    }
    return temp;
}

//https://www.codingninjas.com/codestudio/problems/middle-of-linked-list_973250?source=youtube&campaign=Lovebabbarcodestudio_24thJan&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio_24thJan&leftPanelTab=1