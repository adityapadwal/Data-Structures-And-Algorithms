#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solveMem(int n, vector<int>&dp)
    {
        // base case
        if(n <= 1)
        {
            return 1;
        }
        if(dp[n] != -1)
        {
            return dp[n];
        }

        // recursive calls
        dp[n]  = solveMem(n-1, dp) + solveMem(n-2, dp);
        return dp[n];
    }

    int solve(int n)
    {
        // base case
        if(n <= 1)
        {
            return 1;
        }

        // recursive calls
        int ans = solve(n-1) + solve(n-2);
        return ans;
    }

    int climbStairs(int n) {
        // Using recursion
        // int ans = solve(n);
        // return ans;
        // This gives TLE 

        // Using memoization
        vector<int>dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;
        int ans = solveMem(n, dp);
        return ans;
    }
};

// https://leetcode.com/problems/climbing-stairs/description/