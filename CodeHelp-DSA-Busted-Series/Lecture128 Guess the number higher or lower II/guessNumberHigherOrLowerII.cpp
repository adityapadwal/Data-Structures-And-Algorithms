#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Solution {
public:
    int solve(int start, int end)
    {
        // base case 
        if(start >= end)
        {
            return 0;
        }

        int maxi = INT_MAX;

        for(int i=start; i<=end; i++)
        {
            maxi = min(maxi, i+max(solve(start, i-1), solve(i+1, end)));
        }

        return maxi;
    }

    int solveMem(int start, int end, vector<vector<int>>&dp)
    {
        // base case 
        if(start >= end)
        {
            return 0;
        }
        if(dp[start][end] != -1)
        {
            return dp[start][end];
        }

        int maxi = INT_MAX;

        for(int i=start; i<=end; i++)
        {
            maxi = min(maxi, i+max(solveMem(start, i-1, dp), solveMem(i+1, end, dp)));
        }

        dp[start][end] = maxi;
        return dp[start][end];
    }

    int getMoneyAmount(int n) {
        // Using Recursion
        // int finalAns = solve(1, n);
        // return finalAns;

        // Using Memoization
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        int finalAns = solveMem(1, n, dp);
        return finalAns;
 
    }
};

// https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/
