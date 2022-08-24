#include<iostream>
#include<map>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

    Node()
    {
        this->next == NULL;
    }
};

void createList(Node* &tail, int n)
{
    if(n==0)
    {
        cout<<"\n CLL not created :(";
        return;
    }
    else if(n==1)
    {
        Node* temp = tail;
        cout<<"\n Enter data: ";
        cin>>tail->data;
        tail->next = tail;
    }
    else if(n > 1)
    {
        Node* temp = tail;
        cout<<"\n Enter data: ";
        cin>>tail->data;
        for(int i=1; i<n; i++)
        {
            tail->next = new Node();
            tail = tail->next;
            cout<<"\n Enter data: ";
            cin>>tail->data;  
        }
        tail->next = temp;
    }
}

Node* floydDetectLoop(Node* head)
{
    if (head == NULL);
    return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow!=NULL && fast!=NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;

        if(slow == fast)
        {
            return slow;
        }
    }
    return NULL;
}

void displayList(Node* tail)
{
    Node* p = tail->next;
    cout<<endl<<" <-> ";
    do
    {
        cout<<p->data<<" <-> ";
        p = p->next;
    }while(p != tail->next);
}

void insertFront(Node* tail)
{
    Node* p = new Node();
    cout<<"\n Enter data: ";
    cin>>p->data;
    p->next = tail->next;
    tail->next = p;
}

void insertMiddle(Node* &tail)
{
    int pos;
    cout<<"\n Enter position: ";
    cin>>pos;
    Node* p = new Node();
    cout<<"\n Enter data: ";
    cin>>p->data;
    Node* temp = tail->next;
    for(int i=1; i<pos-1; i++)
    {
        temp = temp->next;
    }
    p->next = temp->next;
    temp->next = p;
}

Node* getStartingNode(Node* head)
{
    if(head == NULL)
    return NULL;

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

bool detectLoop(Node* &head)
{
    if(head==NULL)
    {
        return false;
    }
    map<Node*, bool> visited;

    Node* temp = head;
    while(temp!= NULL)
    {  
        if(visited[temp]==true)
        {
            // cycle is present
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

void insertRear(Node* &tail )
{
    Node* p = new Node();
    cout<<"\n Enter data: ";
    cin>>p->data;
    p->next = tail->next;
    tail->next = p;
    tail = p;
}

void deleteFront(Node* &tail)
{
    Node* temp = tail->next;
    tail->next = temp->next;
    temp->next = NULL;
    delete temp;
}

void deleteMiddle(Node* &tail)
{
    int pos;
    cout<<"\n Enter position: ";
    cin>>pos;
    Node* temp = tail->next;
    for(int i=1; i<pos-1; i++)
    {
        temp = temp->next;
    }
    Node *p = temp->next;
    temp->next = p->next;
    p->next = NULL;
    delete p;
}

void deleteRear(Node* &tail)
{
    Node* temp = tail->next;
    while(temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = tail->next;
    tail->next = NULL;
    delete tail;
    tail = temp;
}

int main()
{
    int ch, n, s;
    Node* tail = new Node();
    while(true)
    {
        cout<<endl;
        cout<<"\n<===== MENU (CLL)=====>";
        cout<<"\n 1. Create List ";
        cout<<"\n 2. Display List ";
        cout<<"\n 3. Insert Front ";
        cout<<"\n 4. Insert Middle ";
        cout<<"\n 5. Insert End ";
        cout<<"\n 6. Delete Front";
        cout<<"\n 7. Delete Middle";
        cout<<"\n 8. Delete Last";
        cout<<"\n 9. Detect Loop? ";
        cout<<"\n 0. Get Starting node?";
        cout<<"\n Enter your Choice: ";
        cin>>ch;
        switch(ch)
        {
            case 0:
            {
                Node* ans = getStartingNode(tail);
                if(ans != NULL)
                cout<<"\n Starting node of loop is: "<<ans->data;
                else
                cout<<"\n Loop not present! ";
                break;
            }

            case 1:
            {
                cout<<endl;
                cout<<"\n Enter total data: ";
                cin>>n;
                createList(tail, n);
                cout<<endl;
                if(n > 0)
                {
                    cout<<"\n All data added successfully!";
                }
                break;
            }

            case 2:
            {
                cout<<endl;
                cout<<"\n Displaying Linked List";
                displayList(tail);
                break;
            }

            case 3:
            {
                insertFront(tail);
                cout<<"|n Data added successfully! ";
                break;
            }

            case 4:
            {
                insertMiddle(tail);
                cout<<"\n Data added successfully! ";
                break;
            }

            case 5:
            {
                insertRear(tail);
                cout<<"\n Data added successfully! ";
                break;
            }

            case 6:
            {
                deleteFront(tail);
                cout<<"\n Data deleted successfully! ";
                break;
            }
            
            case 7:
            {
                deleteMiddle(tail);
                cout<<"\n Data deleted successfully! ";
                break;
            }

            case 8:
            {
                deleteRear(tail);
                cout<<"\n Data deleted successfully!";
                break;
            }
            
            case 9:
            {
                bool ans = detectLoop(tail);
                if(ans == true)
                {
                    cout<<"\n Cycle is Present! ";
                }
                else
                {
                    cout<<"\n Cycle is not present! ";
                }
                break;
            }

            default:
            {
                cout<<"\n WRONG CHOICE! ";
                exit(0);
            }
        }
    }
return 0;
}