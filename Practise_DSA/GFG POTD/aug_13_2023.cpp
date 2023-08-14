//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int solve(int n)
    {
        if(n <= 1)
        {
            return n;
        }
        
        int ans = solve(n-1) + solve(n-2);
        return ans;
    }
    
    int solveMem(int n, vector<int>&dp)
    {
        if(n <= 1)
        {
            return n;
        }
        if(dp[n] != -1)
        {
            return dp[n];
        }
        
        dp[n] = solveMem(n-1, dp) + solveMem(n-2, dp) % 1000000007;
        return dp[n];
    }
    
    int solveTab(int n)
    {
        vector<int>dp(n+1, 0);
        
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i=2; i<=n; i++)
        {
            dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
        }
        
        return dp[n];
    }
    
    int solveSo(int n)
    {
        int prev2 = 0;
        int prev1 = 1;
        
        for(int i=2; i<=n; i++)
        {
            int curr = (prev2 + prev1) % 1000000007;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    
    int nthFibonacci(int n){
        // Using recursion
        // int finalAns = solve(n);
        // return finalAns % 1000000007;
        
        // Using Memoization
        // vector<int>dp(n+1, -1);
        // int finalAns = solveMem(n, dp);
        // return finalAns%1000000007;
        
        // Using Tabulation 
        // int finalAns = solveTab(n);
        // return finalAns;
        
        // Using Space Optimization
        int finalAns = solveSo(n);
        return finalAns;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/nth-fibonacci-number1335/1