//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    // TLE TC=O(N*N)
    int getPairsCount(int arr[], int n, int k) {
        int ans = 0;
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(arr[i]+arr[j] == k)
                {
                    ans++;
                }
            }
        }
        return ans;
    }

    // Using hashmaps
    // TC = O(N) SC = O(N)
    int getPairsCount(int arr[], int n, int k) {
        // code here
        unordered_map<int,int> mp;
        
        int count = 0;
        for(int i = 0;i<n;i++) {
            if(mp[k-arr[i]])
            count+=mp[k-arr[i]];
            mp[arr[i]]++;
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends