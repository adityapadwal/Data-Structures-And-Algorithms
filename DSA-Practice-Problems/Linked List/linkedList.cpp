#include<iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node* next;
}node;

class List
{
    public:
    int n;
    node* root;
    node* head;
    List()
    {
        root->data = NULL;
    }

    void createList()
    {
        cout<<"\n Enter total number of elements: ";
        cin>>n;
        for(int i=0; i<5; i++)
        {
            if(root->data == NULL)
            {
                cout<<"\n Enter value (in head): ";
                cin>>root->data;
                root->next = NULL;
            }
            else
            {
                head = root;
                while(head->next != NULL)
                {
                    head = head->next;
                }
                node* p = new node();
                cout<<"\n Enter the value: ";
                cin>>p->data;
                p->next = NULL;
                head->next = p;
            }
        }
    }

    void displayList()
    {
        node* temp = root;
        if(root == NULL)
        {
            cout<<"\n The List is Empty!";
        }
        else
        {
            while(temp->next != NULL)
            {
                cout<<" -> "<<temp->data;
                temp = temp->next;
            }
            cout<<" -> "<<temp->data;
        }
    }
};

int main()
{
    List l1;
    int ch;
    int n;
    cout<<"\n Program for Linked List";
    cout<<endl;

    while(true)
    {
        cout<<"\n <==== MENU ====>";
        cout<<"\n 1. Enter Elements";
        cout<<"\n 2. Display Elements";
        cout<<"\n 3. Exit";
        cout<<"\n Enter Your Choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1:
            l1.createList();
            break;

            case 2:
            l1.displayList();
            break;

            case 3:
            cout<<"\n Thank You! ";
            exit(0);
        }
    }
return 0;
}