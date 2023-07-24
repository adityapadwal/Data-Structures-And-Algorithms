#include<iostream>
#include<map>
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

bool detectLoop(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }

    map<Node*, bool> visited;

    Node* temp = head;

    while(temp!=NULL)
    {   //Cycle is present
        if(visited[temp]==true)
        {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }

    return false;

}