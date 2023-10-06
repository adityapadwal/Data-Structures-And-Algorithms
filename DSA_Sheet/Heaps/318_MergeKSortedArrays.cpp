//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++

class Node {
    public:
    int data;
    int row;
    int col;
    
    Node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class Compare {
    public:
    bool operator()(Node* a, Node* b)
    {
        return a->data > b->data;
    }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        // for the finalAns
        vector<int>finalAns;
        
        // create a min heap
        priority_queue<Node*, vector<Node*>, Compare>minHeap;
        
        // insert all the first elements into the minHeap
        for(int i=0; i<K; i++)
        {
            int element = arr[i][0];
            Node* temp = new Node(element, i, 0);
            minHeap.push(temp);
        }
        
        // process remaining part
        while(!minHeap.empty())
        {
            Node* temp = minHeap.top();
            finalAns.push_back(temp->data);
            
            minHeap.pop();
            
            int i = temp->row;
            int j = temp->col;
            
            if(j+1 < arr[i].size())
            {
                Node* next = new Node(arr[i][j+1], i, j+1);
                minHeap.push(next);
            }
        }
        
        // return the answer array
        return finalAns;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}

// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1