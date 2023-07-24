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

bool isCircular(Node* head){
    //Base case
    if(head==NULL)
    {
        return true;
    }
    Node* temp = head->next;
    while(temp!=NULL && temp != head)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        return false;
    }

    if(temp == head)
    {
        return true;
    }
}