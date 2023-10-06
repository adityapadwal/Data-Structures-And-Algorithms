//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    long long currMul = 1;
	    long long maxMul = INT_MIN;
	    
	    for(int i=0; i<arr.size(); i++)
	    {
	        currMul = currMul * arr[i];
	        maxMul = max(currMul, maxMul);
	        
	        if(currMul == 0)
	        {
	            currMul = 1;
	        }
	    }
	    
	    currMul = 1;
	    for(int i=arr.size()-1; i>=0; i--)
	    {
	        currMul = currMul * arr[i];
	        maxMul = max(maxMul, currMul);
	        
	        if(currMul == 0)
	        {
	            currMul = 1;
	        }
	    }
	    
	    return maxMul;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1
// Use modified Kadane's Algorithm