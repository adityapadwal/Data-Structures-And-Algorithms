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
    
    int solveTab(int a[], int n)
    {
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        
        for(int curr=n-1; curr>=0; curr--)
        {
            for(int prev=curr-1; prev>=-1; prev--)
            {
                // include 
                int take = 0;
                if(prev == -1 || a[curr] > a[prev])
                {
                    take = 1 + dp[curr+1][curr+1];
                }
                
                // exclude
                // a[curr] < a[prev]
                int notTake = 0 + dp[curr+1][prev+1];
                
                dp[curr][prev+1] = max(take, notTake);
            }
        }
        return dp[0][0];
    }
    
    int solveSo(int a[], int n)
    {
        vector<int>currRow(n+1, 0);
        vector<int>nextRow(n+1, 0);
        
        for(int curr=n-1; curr>=0; curr--)
        {
            for(int prev=curr-1; prev>=-1; prev--)
            {
                // include 
                int take = 0;
                if(prev == -1 || a[curr] > a[prev])
                {
                    take = 1 + nextRow[curr+1];
                }
                
                // exclude
                // a[curr] < a[prev]
                int notTake = 0 + nextRow[prev+1];
                
                currRow[prev+1] = max(take, notTake);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }
    
    int solveOptimal(int n, int a[])
    {
        // base case 
        if(n == 0)
        {
            return 0;
        }
        
        vector<int>ans;
        
        // put the first element into the ans array
        ans.push_back(a[0]);
        
        for(int i=1; i<n; i++)
        {
            if(a[i] > ans.back())
            {
                ans.push_back(a[i]);
            }
            else
            {
                // arr[i] > ans.back()
                int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                ans[index] = a[i];
            }
        }
        return ans.size();
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
        // int curr = 0;
        // int prev = -1;
        // vector<vector<int>>dp(n, vector<int>(n+1, -1));
        // int finalAns = solveMem(a, n, curr, prev, dp);
        // return finalAns;
        
        // Method 3: Tabulation
        // int finalAns = solveTab(a, n);
        // return finalAns;
        
        // Method 4: Space Optimization
        // int finalAns = solveSo(a, n);
        // return finalAns;
        
        // Method 5: Optimal Code
        int finalAns = solveOptimal(n, a);
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

// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1