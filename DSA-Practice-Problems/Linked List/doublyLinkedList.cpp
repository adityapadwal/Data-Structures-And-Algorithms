// Refer DLLFinal.cpp
#include<iostream>
using namespace std;
class Node
{
    public:
    Node* prev;
    int data;
    Node* next;
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node* &head)
{
    cout<<endl;
    Node* temp = head;
    while(temp!= NULL)
    {
        cout<<" => "<<temp->data;
        temp = temp->next;
    }
    
}

int getLength(Node* &head)
{
    int cnt = 0;
    Node* temp = head;
    while(temp!= NULL)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

void insertAtHead(Node* &head, int d)
{
    Node* temp = new Node(d);    //Step 1
    temp->next = head;          // Step 2
    head->prev = temp;          // Step 3
    head = temp;                // Step 4
}

void insertAtTail(Node* &head, int d)
{
    Node*  p = new Node(d);
    Node*temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = p;
    p->prev = temp;
} 

void insertAtPositon(Node* head, int position, int d)
{
    if(position ==1 )
    {
        insertAtHead(head, d);
    }
}
int main()
{
   Node* node1 = new Node(10);
   Node* head = node1;
//    Node* tail = node1;
   print(head);
   cout<<"\n Length of LL is: "<<getLength(head)<<endl;

   //inserting at head
   insertAtHead(head, 11);
   print(head);
   cout<<"\n Length of LL is: "<<getLength(head)<<endl;

   insertAtHead(head, 13);
   print(head);
   cout<<"\n Length of LL is: "<<getLength(head)<<endl;

   insertAtHead(head, 18);
   print(head);
   cout<<"\n Length of LL is: "<<getLength(head)<<endl;

    // inserting at Tail 
    insertAtTail(head, 5);
    print(head);
    cout<<"\n Length of LL is: "<<getLength(head)<<endl;

    insertAtTail(head, 3);
    print(head);
    cout<<"\n Length of LL is: "<<getLength(head)<<endl;

    // insertAtPosition()

return 0;
}