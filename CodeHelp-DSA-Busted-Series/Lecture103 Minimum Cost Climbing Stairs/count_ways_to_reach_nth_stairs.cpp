#include <bits/stdc++.h> 
#include<iostream>
#include<vector>
using namespace std;
#define MOD 1000000007;

// ***** Solved using Top Down Approach (Recursion + Memoization)
int solve(int n, int i, vector<int>&dp)
{
    // base case
    if(i == n)
    {
        return 1;
    }

    if(i > n)
    {
        return 0;
    }
    
    if(dp[i] != -1)
    {
        return dp[i];
    }
    
    dp[i] = (solve(n, i+1, dp) + solve(n, i+2, dp)) % MOD;
    return dp[i];
}

int countDistinctWays(int nStairs) {
    int i = 0;
    vector<int>dp(nStairs+1, -1);
    int ans = solve(nStairs, i, dp);
    return ans;
}

// https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?leftPanelTab=0