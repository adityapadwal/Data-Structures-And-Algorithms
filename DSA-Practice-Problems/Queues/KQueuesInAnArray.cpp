#include<iostream>
using namespace std;

class kQueue{
    public:
        int n;
        int k;
        int* arr;
        int* front;
        int* rear;
        int* next;
        int freespot;

    kQueue(int n, int k)
    {
        // constructor initializations
        this->n = n;
        this->k = k;
        front = new int[k];
        rear = new int[k];
        next = new int[n];
        arr = new int[n];
        
        // initialize the freespot
        freespot = 0;

        // initialize the front and rear array 
        for(int i=0; i<k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        // initialize the next wala array 
        for(int i=0; i<n; i++)
        {
            next[i] = i+1;
        }
        //initailize the last index of the next array to -1
        next[n-1] = -1;
    }

    void enqueue(int data, int qn)   // push the element 'data' in the queue qn
    {
        // Step 1: Check for overflow 
        if(freespot==-1)
        {
            cout<<"\n Queue overflow!!! ";
            return;
        }
        else
        {
            // Step 2: Find the index where you want to insert  
            int index = freespot;

            // Step 3: Update the freespot 
            freespot = next[index];

            // Step 4: Check if the element to be inserted is the first element or not
            if(front[qn-1] == -1)
            {
                // element to be inserted is the first element 
                front[qn-1] = index;
            }
            else  
            {
                // element to be inserted is not the first element
                next[rear[qn-1]] = index;
            }

            // Step 5: insert the element
            next[index] = -1;    // update next
            rear[qn-1] = index;  // point rear to the index 
            arr[index] = data;   // element pushed
        }
    }

    int dequeue(int qn)
    {
        // Step 1: check for underflow
        if(front[qn-1] == -1)
        {
            cout<<"\n Queue underflow";
            return -1;
        }
        else
        {
            // Step 2: Find index (element to be popped)
            int index = front[qn-1];

            // Step 3: Make the element to be pooped -1
            // arr[index] = -1;

            // Stpe 4: Update front (front ko aage badhao)
            front[qn-1] = next[index];

            // Step 5: Manage freespots
            next[index] = freespot;
            freespot = index;

            // return the popped element
            return arr[index];
        }
    }

    void print()
    {
        cout<<"\n <====Displaying the queue====> ";
        cout<<"\n";
        for(int i=0; i<n; i++)
        {
            cout<<" -> "<<arr[i];
        }
    }
}; 
int main()
{
    kQueue q(6, 2);
    q.enqueue(5, 1);
    q.enqueue(10, 1);
    q.enqueue(15, 2);
    q.enqueue(20, 2);
    q.enqueue(25, 1);
    q.enqueue(30, 2);

    q.print();
    cout<<endl;

    cout<<"\n Dequeue form q1";
    cout<< " : " << q.dequeue(1);
    q.print();
    cout<<endl;

    cout<<"\n Dequeue form q2";
    cout<<" : " << q.dequeue(2);
    q.print();
    cout<<endl;

return 0;
}