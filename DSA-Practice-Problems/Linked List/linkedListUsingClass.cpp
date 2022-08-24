#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
int main()
{
    Node* node1 = new Node(10);
    cout<<"\n Printing node1->data:  ";
    cout<<node1->data;
    cout<<endl;
    cout<<"\n Printing node1->next:  ";
    cout<<node1->next;

return 0;
}