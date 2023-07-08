#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<limits.h>
#include<map>
using namespace std;

class Solution {
public:
    bool solve(string &s, string &p, int i, int j)
    {
        // base case
        if(i<0 && j<0)
        {
            // string exhausted and pattern exhausted
            // hence pattern has matched, valid pattern
            return true;
        }
        if(i>=0 && j<0)
        {
            // string not exhausted but pattern exhausted
            // hence invalid pattern
            return false;
        }
        if(i<0 && j>=0)
        {
            for(int k=0; k<=j; k++)
            {
                if(p[k] != '*')
                {
                    return false;
                }
            }
            return true;
        }

        if(s[i] == p[j] || p[j] == '?')
        {
            return solve(s, p, i-1, j-1);
        }
        else if(p[j] == '*')
        {
            // here we get 2 cases
            // first, replace * by empty string
            bool case1 = solve(s, p, i, j-1);
            // second, replace * by any other string
            bool case2 = solve(s, p, i-1, j);
            return case1 || case2;
        }
        else
        {
            return false;
        }
    }

    bool solveMem(string &s, string &p, int i, int j, vector<vector<int>>&dp)
    {
        // base case
        if(i<0 && j<0)
        {
            // string exhausted and pattern exhausted
            // hence pattern has matched, valid pattern
            return true;
        }
        if(i>=0 && j<0)
        {
            // string not exhausted but pattern exhausted
            // hence invalid pattern
            return false;
        }
        if(i<0 && j>=0)
        {
            for(int k=0; k<=j; k++)
            {
                if(p[k] != '*')
                {
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if(s[i] == p[j] || p[j] == '?')
        {
            return dp[i][j] = solveMem(s, p, i-1, j-1, dp);
        }
        else if(p[j] == '*')
        {
            // here we get 2 cases
            // first, replace * by empty string
            bool case1 = solveMem(s, p, i, j-1, dp);
            // second, replace * by any other string
            bool case2 = solveMem(s, p, i-1, j, dp);
            return dp[i][j] = case1 || case2;
        }
        else
        {
            return false;
        }
    }

    bool isMatch(string s, string p) {
        // Using Recursion
        // bool finalAns = solve(s, p, s.length()-1, p.length()-1);
        // return finalAns;

        // Using Memoization
        vector<vector<int>>dp(s.length()+1, vector<int>(p.length()+1, -1));
        bool finalAns = solveMem(s, p, s.length()-1, p.length()-1, dp);
        return finalAns;
    }
};

// https://leetcode.com/problems/wildcard-matching/description/
// Convert memoization approach to 1 based indexing and solve for tabulation and Space Optimization