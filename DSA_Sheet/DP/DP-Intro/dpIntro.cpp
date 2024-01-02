#include<bits/stdc++.h>
using namespace std;

int solve(int n)
{
    // base case
    if(n <= 1)
    {
        return n;
    }

    int ans = solve(n-1) + solve(n-2);
    return ans;
}

int solveMem(int n, vector<int>&dp)
{
    // base case
    if(n <= 1)
    {
        return n;
    }
    if(dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = solveMem(n-1, dp) + solveMem(n-2, dp);
    return dp[n];
}

int solveTab(int n)
{
    // Creating the dp array
    vector<int>dp(n+1, -1);

    // Analyse the base case
    dp[0] = 0;
    dp[1] = 1;

    // Solve for remaining conditions
    for(int i=2; i<=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    // Return the answer
    return dp[n];
}

int solveSO(int n)
{
    int prev1 = 1;
    int prev2 = 0;

    for(int i=2; i<=n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {
    // Implementing Fibonacci Series

    int n;
    cout<<"\n Enter number: ";
    cin>> n;

    // cout<<"\n Using Recursion";
    // cout<<"\n";
    // int ans = solve(n);
    // cout<<"Answer using recursion is: "<<ans;

    // cout<<"\n Using Memoization";
    // vector<int>dp(n+1, -1);
    // cout<<"\n";
    // int ans = solveMem(n, dp);
    // cout<<"Answer using Memoization is: "<<ans;

    // cout<<"\n Using Tabulation";
    // cout<<"\n";
    // int ans = solveTab(n);
    // cout<<"Answer using Tabulation is: "<<ans;

    cout<<"\n Using Space Optimization";
    cout<<"\n";
    int ans = solveSO(n);
    cout<<"Answer using Space Optimization is: "<<ans;

    return 0;
}