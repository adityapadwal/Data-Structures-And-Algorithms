// Using Class
#include<iostream>
using namespace std;

class Nodes     //This is the node of the LL
{
    public:
    int data;
    Nodes* next;

    Nodes(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Nodes* &Head, int d)
{
    //create new node
    Nodes* temp = new Nodes(d);
    temp->next = Head;
    Head = temp;

}

void print(Nodes* Head)
{
    Nodes* temp;
    temp = Head;
    while(temp->next != NULL)
    {
        cout<<" => "<<temp->data;
        temp = temp->next;
    }
}

int main()
{
    Nodes* node1 = new Nodes(10);

    Nodes* head = node1;
    print(head);
    cout<<endl;

    insertAtHead(head, 12);
    print(head);
    cout<<endl;

    insertAtHead(head, 15);
    print(head);
return 0;
}


// // Using  Structure
// #include<iostream>
// using namespace std;
// typedef struct Node
// {
//     int data;
//     struct Node* next;
// }node;

// int main()
// {
// //node* nude; // If we just write like this then garbage value will be allocated to data and next.
// node* nude = new node();
// cout<<"\n nude->data : "<<nude->data;
// cout<<"\n nude->next : "<<nude->next; 
// return 0;
// }