#include <iostream>
#include <unordered_map>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    struct Node *arb;
    Node(int x)
    {
        data = x;
        next = NULL;
        arb = NULL;
    }
};
//<--------------------------------Approach1 TC=O(N) SC=O(N) ------------------------------------->

class Solution
{
public:
    void insertAtTail(Node *&head, Node *&tail, int data)
    {
        Node *temp = new Node(data);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }

        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    Node *copyList(Node *head)
    {
        // Write your code here
        Node *cloneHead = NULL;
        Node *cloneTail = NULL;

        // Step1 create a clone linkedlist
        Node *temp = head;
        while (temp != NULL)
        {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

        // step2 create a map
        unordered_map<Node *, Node *> oldToNewNode;
        Node *originalNode = head;
        Node *cloneNode = cloneHead;
        while (originalNode != NULL && cloneNode != NULL)
        {
            oldToNewNode[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        cloneNode = cloneHead;
        originalNode = head;
        while (originalNode != NULL)
        {
            cloneNode->arb = oldToNewNode[originalNode->arb];
            cloneNode = cloneNode->next;
            originalNode = originalNode->next;
        }

        return cloneHead;
    }
    //<------------------------------approach2 TC=O(N) SC=O(1) --------------------------------->
    Node *copyList1(Node *head)
    {
        // Write your code here
        Node *cloneHead = NULL;
        Node *cloneTail = NULL;

        // Step1 create a clone linkedlist
        Node *temp = head;
        while (temp != NULL)
        {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

        // step2 Clone node add between original list
        Node *originalNode = head;
        Node *cloneNode = cloneHead;
        while (originalNode != NULL && cloneNode != NULL)
        {
            Node *next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = next;

            next = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next;
        }
        // step3 random pointer copy
        temp = head;
        while (temp != NULL)
        {
            if (temp->next != NULL)
            {
                temp->next->arb = temp->arb
                                      ? temp->arb->next
                                      : temp->arb;
            }
            temp = temp->next->next;
        }

        // step4 revert changes done in step 2
        originalNode = head;
        cloneNode = cloneHead;
        while (originalNode != NULL && cloneNode != NULL)
        {
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;
            if (originalNode != NULL)
            {
                cloneNode->next = originalNode->next;
            }

            cloneNode = cloneNode->next;
        }

        return cloneHead;
    }
};
// https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1