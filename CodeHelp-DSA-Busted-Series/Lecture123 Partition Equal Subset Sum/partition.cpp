//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int index, int arr[], int n, int target)
    {
        // base case 
        if(index >= n)
        {
            return 0;
        }
        if(target < 0)
        {
            return 0;
        }
        if(target == 0)
        {
            return 1;
        }
        
        int include = solve(index+1, arr, n, target-arr[index]);
        int exclude = solve(index+1, arr, n, target-0);
        
        int ans = include or exclude;
        return ans;
    }
    
    int solveMem(int index, int arr[], int n, int target, vector<vector<int>>&dp)
    {
        // base case 
        if(index >= n)
        {
            return 0;
        }
        if(target < 0)
        {
            return 0;
        }
        if(target == 0)
        {
            return 1;
        }
        if(dp[index][target] != -1)
        {
            return dp[index][target];
        }
        
        int include = solveMem(index+1, arr, n, target-arr[index], dp);
        int exclude = solveMem(index+1, arr, n, target-0, dp);
        
        dp[index][target] = include or exclude;
        return dp[index][target];
    }
    
    int solveTab(int arr[], int n, int total)
    {
        // Step 1: Creating a DP array
        vector<vector<int>>dp(n+1, vector<int>(total+1, 0));
        
        // Step 2: Analyse the base case 
        for(int i=0; i<=n; i++)
        {
            dp[i][0] = 1;
        }
        
        // Step 3: Solve next steps
        for(int index=n-1; index>=0; index--)
        {
            for(int target=0; target<=total/2; target++)
            {
                int include = 0;
                if(target - arr[index] >=0)
                {
                    include = dp[index+1][target - arr[index]];
                }
                int exclude = dp[index+1][target-0];
                
                dp[index][target] = include or exclude;
            }
        }
        // Step 4: Return answer
        return dp[0][total/2];
    }
    
    int solveSo(int arr[], int n, int total)
    {
        vector<int>curr(total, 0);
        vector<int>next(total, 0);
        
        curr[0] = 1;
        next[0] = 1;
        
        for(int index=n-1; index>=0; index--)
        {
            for(int target=0; target<=total/2; target++)
            {
                int include = 0;
                if(target - arr[index] >=0)
                {
                    include = next[target - arr[index]];
                }
                int exclude = next[target-0];
                
                curr[target] = include or exclude;
            }
            next = curr;
        }
        
        // Step 4: Return answer
        return next[total/2];
    }
    
    int equalPartition(int N, int arr[])
    {
        // compute sum of all the array elements
        int total = 0;
        for(int i=0; i<N; i++)
        {
            total += arr[i];
        }
        
        // check if the total is odd 
        if(total % 2 != 0)
        {
            return 0;
        }
        
        // Now we know that out total is even. 
        // Hence processing further
        
        // Using Recursion
        // int finalAns = solve(0, arr, N, total/2);
        // return finalAns;
        
        // Using Memoization
        // vector<vector<int>>dp(N, vector<int>(total, -1));
        // int finalAns = solveMem(0, arr, N, total/2, dp);
        // return finalAns;
        
        // Using Tabulation 
        // int finalAns = solveTab(arr, N, total);
        // return finalAns;
        
        // Space Optimization
        int finalAns = solveSo(arr, N, total);
        return finalAns;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends

// https://www.youtube.com/watch?v=UGY7FMHt-M8&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=133&t=26s