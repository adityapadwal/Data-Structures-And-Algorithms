// Final! (Use This one)
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
        this->next = NULL;
        this->prev = NULL;
    }
};

void createList(Node* &head, int n)
{
    cout<<"\n Enter data: ";
    cin>>head->data;
    Node* temp = head;
    for(int i=1; i<n; i++)
    {
        Node*p = new Node();
        cout<<"\n Enter data: ";
        cin>>p->data;
        p->next = NULL;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
        p->prev = temp;
    }
}

void displayList(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<" <=> "<<temp->data;
        temp = temp->next;
    }
}

void displayReverse(Node* head)
{
    Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    while(temp != NULL)
    {
        cout<<" <=> "<<temp->data;
        temp = temp->prev;
    }
}

void insertFront(Node* &head)
{
    Node* p = new Node();
    cout<<"\n Enter data: ";
    cin>>p->data;
    p->next = head;
    head->prev = p;
    head = p;
}

void insertMiddle(Node* &head)
{
    int pos;
    cout<<"\n Enter the position: ";
    cin>>pos;
    Node* p = new Node();
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
    while(temp->next != NULL)
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
    head->prev= NULL;
    delete temp;
}

void deleteMiddle(Node* &head)
{
    int pos;
    cout<<"\n Enter positon: ";
    cin>>pos;
    Node* temp = head;
    for(int i=1; i<pos-1; i++)
    {
        temp = temp->next;
    }
    Node* p = temp->next;
    temp->next = p->next;
    p->next->prev = temp;
    delete p;
}

void deleteRear(Node* &head)
{
    Node* temp = head;
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node* p = temp->next;
    temp->next = NULL;
    p->prev = NULL;
    delete p;
}

int main()
{
    Node* head = new Node();
    int ch, n;
    while(true)
    {
        cout<<"\n <===== MENU ====>";
        cout<<"\n 1. Create List";
        cout<<"\n 2. Display List";
        cout<<"\n 3. Insert Front";
        cout<<"\n 4. Insert Middle";
        cout<<"\n 5. Insert Rear";
        cout<<"\n 6. Delete Front";
        cout<<"\n 7. Delete Middle ";
        cout<<"\n 8. Delete Rear";
        cout<<"\n 9. Display Reverse";
        cout<<"\n Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                cout<<"\n Enter total number of records: ";
                cin>>n;
                createList(head, n);
                cout<<"\n The DLL is created successfully! ";
                break;
            }

            case 2:
            {
                cout<<endl;
                cout<<"\n Displaying the linked list";
                displayList(head);
                break;
            }

            case 3:
            {
                insertFront(head);
                cout<<"\n Data added successfully! ";
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
                cout<<"\n Data deleted successfully! ";
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
                cout<<"\n Displaying the reverse Linked List! ";
                displayReverse(head);
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