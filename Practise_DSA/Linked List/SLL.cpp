#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

    Node()
    {
        next=NULL;
    }
};

void createList(Node* &head, int n)
{
    cout<<"\n Enter data(head): ";
    cin>>head->data;
    head->next = NULL;
    Node* temp = head;
    for(int i=1; i<n; i++)
    {
        temp->next = new Node();
        temp = temp->next;
        cout<<"\n Enter data: ";
        cin>>temp->data;
        temp->next = NULL;
    }
}

void displayList(Node* &head)
{
    cout<<endl;
    if(head->next==NULL)
    {
        cout<<"\n LL is empty! ";
    }
    else
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout<<" => "<<temp->data;
            temp = temp->next;
        }
    }
}

void insertFront(Node* &head)
{
    Node* temp = new Node();
    cout<<"\n Enter the data: ";
    cin>>temp->data;
    temp->next = head;
    head = temp;
}

void insertMiddle(Node* &head)
{
    Node* temp = head;
    int pos;
    cout<<"\n Enter position: ";
    cin>>pos;
    Node* p = new Node();
    cout<<"\n Enter data: ";
    cin>>p->data;
    for(int i=1; i<pos-1; i++)
    {
        temp = temp->next;
    }
    p->next = temp->next;
    temp->next = p;
}

void insertEnd(Node* &head)
{
    Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    Node* p = new Node();
    cout<<"\n Enter data: ";
    cin>>p->data;
    temp->next = p;
}

void deleteFirst(Node* &head)
{
    Node* p = head;
    head = head->next;
    p->next = NULL;
    delete p;
}

void deleteMiddle(Node* &head)
{
    int pos;
    Node* p = head;
    Node* q;
    cout<<"\n Enter the position: ";
    cin>>pos;
    for(int i=1; i<pos-1; i++)
    {
        p = p->next;
    }
    q = p->next;
    p->next = p->next->next;
    q->next = NULL;
    delete q;
}
void deleteLast(Node* &head)
{
    Node* p;
    Node* temp = head;
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    p = temp->next;
    temp->next = NULL;
    delete p;
}

bool searchRecord(Node* &head, int s)
{
    Node* temp = head;
    while(temp != NULL)
    {
        if(temp->data == s)
        {
            return true;
        }
        else
        {
            temp = temp->next;
        }
    }
    return false;
}

int main()
{
        int ch, n, s;
    Node* head = new Node();
    while(true)
    {
        cout<<"\n <==== MENU ====> ";
        cout<<"\n 1. Create List";
        cout<<"\n 2. Display List";
        cout<<"\n 3. Insert Front";
        cout<<"\n 4. Insert Middle";
        cout<<"\n 5. Insert End";
        cout<<"\n 6. Delete First";
        cout<<"\n 7. Delete Middle";
        cout<<"\n 8. Delete Last";
        cout<<"\n 9. Search Record";
        cout<<"\n 0. Exit";
        cout<<"\n Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 0:
            cout<<"\n Thank you! ";
            exit(0);
            break;

            case 1:
            cout<<"\n Enter total Number of Nodes: ";
            cin>>n;
            createList(head, n);
            cout<<"\n LL has been created";
            break;

            case 2:
            cout<<endl;
            cout<<"\n Displaying Linked List! ";
            displayList(head);
            cout<<endl;
            break;

            case 3:
            insertFront(head);
            cout<<"\n Number added successfully! ";
            break;

            case 4:
            insertMiddle(head);
            cout<<"\n Number added successfully!";
            break;

            case 5:
            insertEnd(head);
            cout<<"\n Number Added successfuly!";
            break;

            case 6:
            deleteFirst(head);
            cout<<"\n Number deleted successfully!";
            break;

            case 7:
            deleteMiddle(head);
            cout<<"\n Number deleted successfully!";
            break;

            case 8:
            deleteLast(head);
            cout<<"\n Number deleted successfully!";
            break;

            case 9:
            {
                cout<<"\n Enter the search record: ";
                cin>>s;
                bool ans = searchRecord(head, s);
                if(ans == true)
                {
                    cout<<"\n Record found successfully!";
                }
                else
                {
                    cout<<"\n Record not found";
                }
                break;
            }
            
            default:
            {
                cout<<"\n Wrong Choice ";
                break;
            }
        }
    }
    return 0;
}