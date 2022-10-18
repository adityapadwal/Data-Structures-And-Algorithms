#include<iostream>
#include<queue>
using namespace std;

class Heap {
    public:
    int arr[100];
    int size;

    // consrtructor
    Heap()
    {
       arr[0] = -1;
       size = 0; 
    }
    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        
        while(index > 1)
        {
            int parent = index/2;
            if(arr[parent] < arr[index])
            {
                // swap kardo 
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deleteFromHeap()
    {
        if(size == 0)
        {
            cout<<"\n Nothing to delete";
            return;
        }

        arr[1] = arr[size];
        size--;

        // Take root node to its correct position
        int i = 1;
        while(i < size)
        {
            int leftIndex = 2*i;
            int rightIndex = (2*i+1);
            
            if(leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        cout<<"\n Printing the Heap";
        cout<<endl;
        for(int i=1; i<=size; i++)
        {
            cout<<" "<<arr[i];
        }
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int size = n;
    while(size > 1)
    {
        // Ṣtep 1: Swap
        swap(arr[size], arr[1]);
        size--;

        // Step 3
        heapify(arr, size, 1);

    }
}
int main()
{
    Heap h;
    cout<<"\n Program for the Max Heap";
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.deleteFromHeap();
    h.print();

    // heap creation
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i=n/2; i>0; i--)
    {
        heapify(arr, n, i);
    }

    cout<<"\n Printing the heapified tree now!";
    cout<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<" "<<arr[i];
    }

    // heap sort
    heapSort(arr, n);

    cout<<"\n Printing the Heap Sort tree now!";
    cout<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<" "<<arr[i];
    }

    cout<<"\n Using priority queue here";
    // This is a max-heap
    priority_queue<int>pq; 
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout<<"\n Element at the top is: "<<pq.top()<<endl;
    cout<<"\n Size is: "<<pq.size();
    pq.pop();
    cout<<"\n Element at the top is: "<<pq.top()<<endl;
    cout<<"\n Size is: "<<pq.size();

    // This is a min heap
    priority_queue<int, vector<int>, greater<int> > minheap;
    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);
    cout<<"\n Element at the top is: "<<minheap.top()<<endl;
    cout<<"\n Size is: "<<minheap.size();
    minheap.pop();
    cout<<"\n Element at the top is: "<<minheap.top()<<endl;
    cout<<"\n Size is: "<<minheap .size();
    return 0;
}