 
#include<iostream>
using namespace std;
class Node
{
    public:
    Node* prev;
    int data;
    Node* next;

    Node()
    {
       this->prev = NULL;
       this->next = NULL; 
    }
};

void createList(Node* &head, int n)
{
    cout<<"\n Enter head data: ";
    cin>>head->data;
    Node* temp = head;
    for(int i=1; i<n; i++)
    {
        temp->next = new Node();
        temp = temp->next;
        cout<<"\n Enter data: ";
        cin>>temp->data;
    }
}

void displayList(Node* &head)
{
    cout<<endl;
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<" => "<<temp->data;
        temp = temp->next;
    }
}

void insertFront(Node* &head)
{
    Node* temp = new Node();
    cout<<"\n Enter data: ";
    cin>>temp->data;
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertMiddle(Node* &head)
{
    int pos;
    Node* p = new Node();
    cout<<"\n Enter position: ";
    cin>>pos;
    cout<<"\n Enter data: ";
    cin>>p->data;
    Node* temp = head;
    for(int i=1; i<pos-1; i++)
    {
        temp = temp->next;
    }
    p->next = temp->next;
    p->next->prev = p;
    temp->next = p;
    temp->next->prev = p;
}

void insertRear(Node* &head)
{
    Node* p = new Node();
    cout<<"\n Enter data: ";
    cin>>p->data;
    Node* temp = head;
    while(temp->next!= NULL)
    {
        temp = temp->next;
    }
    temp->next = p;
    p->prev = temp;

}

void deleteFront(Node* &head)
{
    Node* temp = head;
    head = head->next;
    temp->next = NULL;
    head->prev = NULL;     
    delete temp;
}

void deleteMiddle(Node* &head)
{
    Node* temp = head;
    int pos;
    cout<<"\n Enter position: ";
    cin>>pos;
    for(int i=1; i<pos-1; i++)
    {
        temp = temp->next;
    }
    Node* p = temp->next;
    temp->next = p->next;
    p->next->prev = temp;
}

void deleteRear(Node* &head)
{
    Node* temp = head;
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *p = temp->next;
    p->prev = NULL;
    temp->next = NULL;
    delete p;
}

int main()
{
    int ch, n;
    Node* head = new Node();
    while(true)
    {
        cout<<"\n <===== MENU ======>";
        cout<<"\n 1. Create DLL";
        cout<<"\n 2. Display DLL";
        cout<<"\n 3. Insert at front";
        cout<<"\n 4. Insert at Middle";
        cout<<"\n 5. Insert at Rear";
        cout<<"\n 6. Delete Front";
        cout<<"\n 7. Delete Middle";
        cout<<"\n 8. delete Rear ";
        cout<<"\n 9. Exit";
        cout<<"\n Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: 
            {
                cout<<"\n Enter total data: ";
                cin>>n;
                createList(head, n);
                cout<<"\n List created successfully! ";
                break;
            }

            case 2:
            {
                cout<<endl;
                cout<<"\n Displaying DLL! ";
                displayList(head);
                break;
            }

            case 3:
            {
                insertFront(head);
                cout<<"\n Data added successfully!";
                break;
            }

            case 4:
            {
                insertMiddle(head);
                cout<<"\n Data added successfully! ";
                break;
            }

            case 5:
            {
                insertRear(head);
                cout<<"\n Data added successfully! ";
                break;
            }

            case 6:
            {
                deleteFront(head);
                cout<<"\n Data deleted successfully! ";
                break;
            }

            case 7:
            {
                deleteMiddle(head);
                cout<<"\n Data deleted Successfully! ";
                break;
            }

            case 8:
            {
                deleteRear(head);
                cout<<"\n Data deleted successfully! ";
                break;
            }

            case 9:
            {
                cout<<"\n Thank you! ";
                exit(0);
                break;
            }

            default:
            {
                cout<<"\n Wrong Choice! ";
                break;
            }
        }
    }
return 0;
}