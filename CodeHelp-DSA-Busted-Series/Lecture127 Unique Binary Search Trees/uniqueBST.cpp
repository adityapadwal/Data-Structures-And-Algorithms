#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(int n)
    {
        // base case
        if(n <= 1)
        {
            return 1;
        }

        int ans = 0;
        // i -> root node
        for(int i=1; i<=n; i++)
        {
            ans += solve(i-1) * solve(n-i);
        }
        return ans;
    }

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

        int ans = 0;
        // i -> root node
        for(int i=1; i<=n; i++)
        {
            ans += solveMem(i-1, dp) * solveMem(n-i, dp);
        }
        dp[n] = ans;
        return dp[n];
    }

    int solveTab(int n)
    {
        // creating the dp array
        vector<int>dp(n+1, 0);

        // analysing the base case of memoization
        dp[0] = 1;
        dp[1] = 1;

        // i-> number of nodes
        for(int i=2; i<=n; i++)
        {
            // j-> root node
            for(int j=1; j<=i; j++)
            {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }

    int numTrees(int n) {
        // Using Recursion 
        // int finalAns = solve(n);
        // return finalAns;

        // Using Memoization 
        // vector<int>dp(n+1, -1);
        // int finalAns = solveMem(n, dp);
        // return finalAns;

        // Using Tabulation 
        int finalAns = solveTab(n);
        return finalAns;
    }
};

// https://leetcode.com/problems/unique-binary-search-trees/submissions/986683452/