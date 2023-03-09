//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        // base case
        if(n == 1)
        {
            return 0;
        }
        
        sort(arr, arr+n);
        
        int ans = arr[n-1] - arr[0];
        
        int maxi;
        int mini;
        
        for(int i=1; i<n; i++)
        {
            maxi = max(arr[i-1]+k, arr[n-1]-k);
            mini = min(arr[0]+k, arr[i]-k);
            ans = min(ans, (maxi-mini));
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/minimize-the-heights-i/1