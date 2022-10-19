#include<limits.h>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    int row;
    int col;
    
    Node(int data, int r, int c)
    {
        this->data = data;
        row = r;
        col = c;
    }
};

class Compare
{
    public:
    bool operator()(Node*a, Node*b)
    {
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    int mini = INT_MAX;
    int maxi = INT_MIN;
    
//     Step 1: Creating a min heap
    priority_queue<Node*, vector<Node*>, Compare> minHeap;
    
//     Adding the starting element of each list into the minHeap and tracking mini/maxi value
    for(int i=0; i<k; i++)
    {
        int element = a[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new Node(element, i, 0));
    }
    
    int start = mini; 
    int end = maxi;
    
//     process ranges
    while(!minHeap.empty())
    {
//         fetch mini
        Node* temp = minHeap.top();
        minHeap.pop();
        
        mini = temp->data;
        
//         update the range or ans
        if((maxi - mini) < (end - start))
        {
            start = mini;
            end = maxi;
        }
        
//         check if the next element exists or not
        if(temp->col + 1 < n)
        {
            maxi = max(maxi, a[temp->row][temp->col + 1]);
            minHeap.push(new Node(a[temp->row][temp->col + 1], temp->row, temp->col + 1));
        }
        else
        {
//             next element does not exist
            break;
        }
    }
    
//     returning the difference as the final answer
    return (end - start + 1);
}