class Node {
    public:
    int data;
    int i;
    int j;
    
    Node(int data, int row, int col)
    {
        this->data = data;
        i = row;
        j = col;
    }
};

class Compare{
    public:
    bool operator() (Node* a, Node* b)
    {
        return a->data > b->data;
    }
};

#include <bits/stdc++.h> 
#include<vector>
#include<queue>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
//     creating a min heap
    priority_queue<Node*, vector<Node*>, Compare>minHeap;
    
//     Step 1: Insert all the first elements of all the arrays
    for(int i=0; i<k; i++)
    {
        Node* temp = new Node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }
    
//     Step 2:
    vector<int>ans;  //for thr final answer
    while(minHeap.size() > 0)
    {
        Node* temp = minHeap.top();
        
        ans.push_back(temp->data);
        minHeap.pop();
        
        int i = temp->i;
        int j = temp->j;
        
        if(j+1 < kArrays[i].size())
        {
            Node* next = new Node(kArrays[i][j+1], i, j+1);
            minHeap.push(next);
        }
    }
    return ans;
}
