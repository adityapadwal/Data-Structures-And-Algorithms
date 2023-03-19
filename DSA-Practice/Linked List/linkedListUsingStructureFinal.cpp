#include<iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node* next;
}node;

class List
{
    private:
    node* HEAD;
    node* p;
    int n;

    public:
    List()
    {
        HEAD = NULL;
    }

    void createList()
    {
        cout<<"\n Enter total numbers: ";
        cin>>n;
        HEAD = new node();
        cout<<"\n Enter head value: ";
        cin>>HEAD->data;
        HEAD->next = NULL;
        p = HEAD;

        for(int i=1; i<n; i++)
        {
            p->next = new node();
            p = p->next;
            cout<<"\n Enter value: ";
            cin>>p->data;
            p->next = NULL;
        }
    }

    void dipslayList()
    {
        if(HEAD==NULL)
        {
            cout<<"\n The LL is empty! ";
        }
        else
        {
            node* temp;
            temp = HEAD;
            while(temp->next != NULL)
            {
                cout<<" => "<<temp->data;
                temp = temp->next;
            }
            cout<<" => "<<temp->data;
        }
    }
};

int main()
{
    List l;
    // node* HEAD;
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
            l.createList();
            break;

            case 2:
            l.dipslayList();
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