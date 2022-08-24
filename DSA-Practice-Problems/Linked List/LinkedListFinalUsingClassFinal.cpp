#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

void createList(Node* &head)
{
    int n;
    cout<<"\n How many nodes are to be entered: ";
    cin>>n; 

    head = new Node();
    cout<<"\n Enter head data: ";
    cin>>head->data;
    head->next = NULL;
    Node* temp = head;

    for(int i=1; i<n; i++)
    {
        temp->next = new Node();
        temp = temp->next;
        cout<<"\n Enter data: ";
        cin>> temp->data;
        temp->next = NULL;
    }
}

void displayList(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<" => "<<temp->data;
        temp = temp->next;
    }
}

int main()
{
    Node* head;
    int ch;
    while(true)
    {
        cout<<"\n <==== MENU ====> ";
        cout<<"\n 1. Create List";
        cout<<"\n 2. Display List";
        cout<<"\n 3. Exit";
        cout<<"\n Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            createList(head);
            break;

            case 2:
            displayList(head);
            break;

            case 3:
            cout<<"\n Thank you!";
            exit(0);

            default:
            cout<<"\n Wrong Choice ";
        }
    }
return 0;
}