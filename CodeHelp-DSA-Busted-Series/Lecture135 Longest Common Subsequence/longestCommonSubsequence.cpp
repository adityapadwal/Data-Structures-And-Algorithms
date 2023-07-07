#include<iostream>
#include<vector>
#include<limits.h>
#include<map>
using namespace std;

class Solution {
public:
    int solve(string a, string b, int i, int j)
    {
        // base case
        if(i == a.length())
        {
            return 0;
        }
        if(j == b.length())
        {
            return 0;
        }

        int ans = 0;
        if(a[i] == b[j])
        {
            ans = 1 + solve(a, b, i+1, j+1);
        }
        else
        {
            // i++, j
            int case1 = solve(a, b, i+1, j);
            int case2 = solve(a, b, i, j+1);
            ans = max(case1, case2);
        }
        return ans;
    }

    int solveMem(string &a, string &b, int i, int j, vector<vector<int>>&dp)
    {
        // base case
        if(i == a.length())
        {
            return 0;
        }
        if(j == b.length())
        {
            return 0;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int ans = 0;
        if(a[i] == b[j])
        {
            ans = 1 + solveMem(a, b, i+1, j+1, dp);
        }
        else
        {
            int case1 = solveMem(a, b, i+1, j, dp);
            int case2 = solveMem(a, b, i, j+1, dp);
            ans = max(case1, case2);
        }
        return dp[i][j] = ans;
    }

    int solveTab(string a, string b)
    {
        int m = a.length();
        int n = b.length();

        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));

        for(int i=m-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                int ans = 0;
                if(a[i] == b[j])
                {
                    ans = 1 + dp[i+1][j+1];
                }
                else
                {
                    int case1 = dp[i+1][j];
                    int case2 = dp[i][j+1];
                    ans = max(case1, case2);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int solveSo(string a, string b)
    {
        int m = a.length();
        int n = b.length();

        vector<int>curr(n+1, 0);
        vector<int>next(n+1, 0);

        for(int i=m-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                int ans = 0;
                if(a[i] == b[j])
                {
                    ans = 1 + next[j+1];
                }
                else
                {
                    int case1 = next[j];
                    int case2 = curr[j+1];
                    ans = max(case1, case2);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return curr[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        // Using Recursion
        // int finalAns = solve(text1, text2, 0, 0);
        // return finalAns;

        // Using Memoization
        // vector<vector<int>>dp(text1.length(), vector<int>(text2.length(), -1));
        // int finalAns = solveMem(text1, text2, 0, 0, dp);
        // return finalAns;

        // Using Tabulation
        // int finalAns = solveTab(text1, text2);
        // return finalAns;

        // Using Space Optimization
        int finalAns = solveSo(text1, text2);
        return finalAns;
    }
};

// https://leetcode.com/problems/longest-common-subsequence/description/