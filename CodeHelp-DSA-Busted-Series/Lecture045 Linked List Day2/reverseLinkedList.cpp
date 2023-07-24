#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for data and value is " << value << endl;
    }
};

// Another Recursive solution
Node *reverse1(Node *head)
{
    // Base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *chotahead = reverse1(head->next);
    head->next->next = head;
    head->next = NULL;

    return chotahead;
}

// Using recursion (same as iterative solution, but implemented using recursion)
void reverse(Node *head, Node *curr, Node *prev)
{
    // Base case
    if (curr->next == NULL)
    {
        head = prev;
        return;
    }

    Node *forward = curr->next;
    reverse(head, forward, curr);
    curr->next = prev;
}

// using iteration
Node *reverseLinkedList(Node *head)
{
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *prev = NULL;
        Node *curr = head;
        while (curr->next != NULL)
        {
            Node *forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
}