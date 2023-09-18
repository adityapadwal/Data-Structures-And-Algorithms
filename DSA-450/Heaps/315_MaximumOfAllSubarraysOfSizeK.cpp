//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // vector for the finalAns
        vector<int>finalAns;
        
        // creating a max-heap
        priority_queue<pair<int, int>>maxHeap;
        
        // adding first k elements into the maxHeap
        for(int i=0; i<k; i++)
        {
            pair<int, int>p = make_pair(arr[i], i);
            maxHeap.push(p);
        }
        finalAns.push_back(maxHeap.top().first);
        
        // process for the remaining elements
        for(int i=k; i<n; i++)
        {
            pair<int, int>p = make_pair(arr[i], i);
            maxHeap.push(p);
            while(i-maxHeap.top().second >= k)
            {
                maxHeap.pop();
            }
            finalAns.push_back(maxHeap.top().first);
        }
        
        return finalAns;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1