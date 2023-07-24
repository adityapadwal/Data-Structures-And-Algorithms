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
        next = NULL;
    }
};

void createList(Node* &head, int n)
{
    cout<<"\n Enter data: ";
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
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<" => "<<temp->data;
        temp = temp->next;
    }
}

void insertFront(Node* &head)
{
    Node* p = new Node();
    cout<<"\n Enter Data: ";
    cin>>p->data;
    p->next = head;
    head = p;
}

// this function return true in case of a circular linked List
// slow - fast concept
bool floydDetectLoop(Node* head)   
{
    if (head == NULL);
    return false;

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
            return true;
        }
    }
    return false;
}

void insertMiddle(Node* &head)
{
    int pos; 
    Node* temp = head;
    Node* p = new Node();
    cout<<"\n Enter position: ";
    cin>>pos;
    cout<<"\n Enter data: ";
    cin>>p->data;
    p->next = NULL;
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
    Node* p = new Node();
    cout<<"\n Enter data: ";
    cin>>p->data;
    p->next = NULL;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = p;
}

void deleteFront(Node* &head)
{
    if(head == NULL)
    {
        return;
    }
    else
    {
        Node* p = head;
        head = head->next;
        p->next = NULL;
        delete p;
    }
}

void deleteMiddle(Node* &head)
{
    int pos; 
    Node* q;
    Node* temp = head;
    cout<<"\n Enter the position: ";
    cin>>pos;
    for(int i=1; i<pos-1; i++)
    {
        temp = temp->next;
    }
    q = temp->next;
    temp->next = q->next;  // temp->next = temp->next->next
    q->next = NULL;
    delete q;
}

void deleteLast(Node* head)
{
    Node* temp = head;
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node* p = temp->next;
    temp->next = NULL;
    delete p;
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
        cout<<endl;
        cout<<"\n<===== MENU =====>";
        cout<<"\n 1.Create List ";
        cout<<"\n 2. Display List ";
        cout<<"\n 3. Insert Front ";
        cout<<"\n 4. Insert Middle ";
        cout<<"\n 5. Insert End ";
        cout<<"\n 6. Delete Front";
        cout<<"\n 7. Delete Middle";
        cout<<"\n 8. Delete Last";
        cout<<"\n 9. Search Record";
        cout<<"\n 10. Floyd Detect Loop? ";
        cout<<"\n 0. Detect Loop?";
        cout<<"\n Enter your Choice: ";
        cin>>ch;
        switch(ch)
        {
            case 0:
            {
                bool ans = detectLoop(head);
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

            case 1:
            {
                cout<<endl;
                cout<<"\n Enter total data: ";
                cin>>n;
                createList(head, n);
                cout<<endl;
                cout<<"\n All data added successfully!";
                break;
            }

            case 2:
            {
                cout<<endl;
                cout<<"\n Displaying Linked List";
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
                insertEnd(head);
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
                deleteLast(head);
                cout<<"\n Data deleted successfully!";
                break;
            }

            case 9:
            {
                cout<<"\n Enter search data: ";
                cin>>s;
                bool ans = searchRecord(head, s);
                if(ans == true)
                {
                    cout<<"\n Record Found! ";
                }
                else
                {
                    cout<<"\n Record not found";
                }
                break;
            }

            case 10:
            {
                bool ans = floydDetectLoop(head);
                if(ans == true)
                cout<<"\n Loop is present! ";
                else
                cout<<"\n Loop not present! ";

                break;
            }
        }
    }
return 0;

}