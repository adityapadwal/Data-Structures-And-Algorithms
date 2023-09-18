//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Step1: create a min heap
        priority_queue<long long, vector<long long>, greater<long long>>pq;
        
        // Step 2: Put all the array elements int the min heap
        for(long long i=0; i<n; i++)
        {
            pq.push(arr[i]);
        }
        
        long long finalAns = 0;
        while(pq.size() > 1)
        {
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            long long ans = first + second;
            finalAns += ans;
            pq.push(ans);
        }
        
        return finalAns;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1