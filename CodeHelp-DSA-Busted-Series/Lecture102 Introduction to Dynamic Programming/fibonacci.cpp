#include<bits/stdc++.h>
using namespace std;

// ************Method 1: Without using DP (Normal Recursive solution)**************
int fibo(int n)
{
    // base case 
    if(n==0 || n==1)
    {
        return n;
    }

    int tempAns = fibo(n-1) + fibo(n-2);
    return tempAns;
}

int main()
{
    int n;
    cin>>n;
    
    int ans = fibo(n);
    cout<< ans;
    
    return 0;
}

// **************Method 2: Using DP (Top Down Approach => Recursion + Memoization)**************
int fibo(int n, vector<int>&dp)
{
    // base case 
    if(n==0 || n==1)
    {
        return n;
    }

    if(dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = fibo(n-1, dp) + fibo(n-2, dp);
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    
    // creating an array for memoization 
    vector<int>dp(n+1, -1);
    
    int ans = fibo(n, dp);
    cout<< ans;
    
    return 0;
}

// **************Method 3: Using DP (Bottom-Up Approach=> Tabulation)*****************
int fibo(int n, vector<int>&dp)
{
    for(int i=2; i<=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }    
}

int main()
{
    int n;
    cin>>n;
      
    vector<int>dp(n+1, -1);
    
    dp[0] = 0;
    dp[1] = 1;
    
    fibo(n, dp);
    int ans = dp[n];
    cout<< ans;
    
    return 0;
}

// ********* Method 4: Using Space Optimization **********
int fib(int n)
{
    int prev1 = 1;
    int prev2 = 0;
    int curr;
    for(int i=2; i<=n; i++)
    {
        curr = prev1 + prev2;
        
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}

int main()
{
    int n;
    cin>>n;
    
    int ans = fib(n);
    cout<< ans;
}

// https://www.codingninjas.com/codestudio/problems/nth-fibonacci-number_74156?leftPanelTab=1
// Revised