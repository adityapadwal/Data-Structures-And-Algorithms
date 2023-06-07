//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    int solve(int a[], int n, int curr, int prev)
    {
        // base case 
        if(curr == n)
        {
            return 0;
        }
        
        // include 
        int take = 0;
        if(prev == -1 || a[curr] > a[prev])
        {
            take = 1 + solve(a, n, curr+1, curr);
        }
        
        // exclude
        int notTake = 0;
        // a[curr] < a[prev]
        notTake = 0 + solve(a, n, curr+1, prev);
        
        int ans = max(take, notTake);
        return ans;
    }
    
    int solveMem(int a[], int n, int curr, int prev, vector<vector<int>>&dp)
    {
        // base case 
        if(curr == n)
        {
            return 0;
        }
        if(dp[curr][prev+1] != -1)
        {
            return dp[curr][prev+1];
        }
        
        // include 
        int take = 0;
        if(prev == -1 || a[curr] > a[prev])
        {
            take = 1 + solveMem(a, n, curr+1, curr, dp);
        }
        
        // exclude
        // a[curr] < a[prev]
        int notTake = 0 + solveMem(a, n, curr+1, prev, dp);
        
        dp[curr][prev+1] = max(take, notTake);
        return dp[curr][prev+1];
    }
    
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        // Method 1: Recursion
        // int curr = 0;
        // int prev = -1;
        // int finalAns = solve(a, n, curr, prev);
        // return finalAns;
        
        // Method 2: Memoization
        int curr = 0;
        int prev = -1;
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        int finalAns = solveMem(a, n, curr, prev, dp);
        return finalAns;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends