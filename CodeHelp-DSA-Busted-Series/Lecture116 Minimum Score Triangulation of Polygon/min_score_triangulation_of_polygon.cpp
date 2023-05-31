#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>&v, int i, int j, int n)
    {
        // base case 
        if(i+1 == j)
        {
            return 0;
        }

        int ans = INT_MAX;
        for(int k=i+1; k<j; k++)
        {
            ans = min(ans, v[i]*v[j]*v[k] + solve(v, i, k, n) + solve(v, k, j, n));
        }
        return ans;
    }

    int solveMem(vector<int>&v, int i, int j, int n, vector<vector<int>>&dp)
    {
        // base case 
        if(i+1 == j)
        {
            return 0;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int ans = INT_MAX;
        for(int k=i+1; k<j; k++)
        {
            ans = min(ans, v[i]*v[j]*v[k] + solveMem(v, i, k, n, dp) + solveMem(v, k, j, n, dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    int solveTab(vector<int>&v)
    {
        int n = v.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));

        for(int i=n-1; i>=0; i--)
        {
            for(int j=i+2; j<n; j++)
            {
                int ans = INT_MAX;
                for(int k=i+1; k<j; k++)
                {
                    ans = min(ans, v[i]*v[j]*v[k] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n-1];
    }

    int minScoreTriangulation(vector<int>& values) {

        // Method 1: Recursion
        // int n = values.size();
        // int i = 0;
        // int j = n-1;
        // int finalAns = solve(values, i, j, n);
        // return finalAns;

        // Method 2: Memoization
        // int n = values.size();
        // int i = 0;
        // int j = n-1;
        // vector<vector<int>>dp(n, vector<int>(n, -1));
        // int finalAns = solveMem(values, i, j, n, dp);
        // return finalAns;

        // Method 3: Tabulation
        // int finalAns = solveTab(values);
        // return finalAns;
    }
};

// https://leetcode.com/problems/minimum-score-triangulation-of-polygon/