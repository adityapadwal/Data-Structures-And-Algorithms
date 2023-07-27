#include<iostream>
using namespace std;

class Stack{
    public:
    class Node
    {
        public:
        int data;
        Node* next;
    };
    Node* top = new Node();

    void push(int element)
    {   
        if(top == NULL)
        {
            top->data = element;
            top->next = NULL;
        }
        else
        {
            Node* temp = new Node();
            temp->data = element;
            temp->next = top;
            top = temp;
        }
    }

    void pop()
    {
        Node* temp = new Node();
        int item;
        if(top == NULL)
        {
            cout<<"\n Stack is underflow! ";
            return;
        }
        else
        {
            temp = top;
            item = temp->data;
            top = top->next;
            delete temp;
            cout<<"\n Popped Item: "<<item;
        }
    }

    void displayList()
    {
        Node* temp;
        if(top != NULL)
        {
            temp = top;
            while(temp->next != NULL)
            {
                cout<<temp->data<<endl;
                temp = temp->next;
            }
        }
        else
        {
            cout<<"\n Stack is empty! ";
        }
    }
};

int main()
{
    Stack s;
    int ch;
    while(ch != 4)
    {
        cout<<"\n <==== MENU ====>";
        cout<<"\n 1. Push";
        cout<<"\n 2. Pop";
        cout<<"\n 3. Display";
        cout<<"\n 4. Exit ";
        cout<<"\n Emter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            int x;
            cout<<"\n Enter element: ";
            cin>>x;
            s.push(x);
            break;

            case 2:
            s.pop();
            break;
            
            case 3:
            s.displayList();
            break;

            case 4:
            exit(0);
            break;

            default:
            cout<<"\n Invalid Choice! ";
            break;
        }
    }
return 0;
}

// In stack using linked list, insertion and deletion both is done at the head of the linked list.