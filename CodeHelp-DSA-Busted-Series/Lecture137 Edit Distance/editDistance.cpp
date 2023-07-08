#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<map>
using namespace std;

class Solution {
public:
    int solve(string &a, string &b, int i, int j)
    {
        // base case
        if(i == a.length())
        {
            // word a is shorter than word b 
            return b.length() - j;
        }
        if(j == b.length())
        {
            // word b is shorter than word a 
            return a.length() - i;
        }

        int ans = 0;
        if(a[i] == b[j])
        {
            return solve(a, b, i+1, j+1);
        }
        else 
        {
            // insert
            int insertAns = 1 + solve(a, b, i, j+1);

            // delete 
            int deleteAns = 1 + solve(a, b, i+1, j);

            // replace
            int replaceAns = 1 + solve(a, b, i+1, j+1);

            ans = min(insertAns, min(deleteAns, replaceAns));
        }
        return ans;
    }

    int solveMem(string &a, string &b, int i, int j, vector<vector<int>>&dp)
    {
        // base case
        if(i == a.length())
        {
            // word a is shorter than word b 
            return b.length() - j;
        }
        if(j == b.length())
        {
            // word b is shorter than word a 
            return a.length() - i;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int ans = 0;
        if(a[i] == b[j])
        {
            return solveMem(a, b, i+1, j+1, dp);
        }
        else 
        {
            // insert
            int insertAns = 1 + solveMem(a, b, i, j+1, dp);

            // delete 
            int deleteAns = 1 + solveMem(a, b, i+1, j, dp);

            // replace
            int replaceAns = 1 + solveMem(a, b, i+1, j+1, dp);

            ans = min(insertAns, min(deleteAns, replaceAns));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    int solveTab(string &a, string &b)
    {
        // creating the DP array
        vector<vector<int>>dp(a.length()+1, vector<int>(b.length()+1, 0));

        // analysing the base case
        for(int j=0; j<b.length(); j++)
        {
            dp[a.length()][j] = b.length() - j;
        }
        for(int i=0; i<a.length(); i++)
        {
            dp[i][b.length()] = a.length() - i;
        }

        for(int i=a.length()-1; i>=0; i--)
        {
            for(int j=b.length()-1; j>=0; j--)
            {
                int ans = 0;
                if(a[i] == b[j])
                {
                    ans = dp[i+1][j+1];
                }
                else 
                {
                    // insert
                    int insertAns = 1 + dp[i][j+1];

                    // delete 
                    int deleteAns = 1 + dp[i+1][j];

                    // replace
                    int replaceAns = 1 + dp[i+1][j+1];

                    ans = min(insertAns, min(deleteAns, replaceAns));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int solveSo(string &a, string &b)
    {
        // creating the DP array
        vector<int>curr(b.length()+1, 0);
        vector<int>next(b.length()+1, 0);

        // analysing the base case
        for(int j=0; j<b.length(); j++)
        {
            next[j] = b.length() - j;
        }
        // for(int i=0; i<a.length(); i++)
        // {
        //     dp[i][b.length()] = a.length() - i;
        // }

        for(int i=a.length()-1; i>=0; i--)
        {
            for(int j=b.length()-1; j>=0; j--)
            {
                // catch here-> from analysing the base case of Memoization
                curr[b.length()] = a.length() - i;

                int ans = 0;
                if(a[i] == b[j])
                {
                    ans = next[j+1];
                }
                else 
                {
                    // insert
                    int insertAns = 1 + curr[j+1];

                    // delete 
                    int deleteAns = 1 + next[j];

                    // replace
                    int replaceAns = 1 + next[j+1];

                    ans = min(insertAns, min(deleteAns, replaceAns));
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }

    int minDistance(string word1, string word2) {
        // Using recursion
        // int finalAns = solve(word1, word2, 0, 0);
        // return finalAns;

        // Using Memoization
        // vector<vector<int>>dp(word1.length(), vector<int>(word2.length(), -1));
        // int finalAns = solveMem(word1, word2, 0, 0, dp);
        // return finalAns;

        // Using Tabulation
        // int finalAns = solveTab(word1, word2);
        // return finalAns;

        // Using Space Optimization
        if(word1.length() == 0)
        {
            return word2.length();
        }
        if(word2.length() == 0)
        {
            return word1.length();
        }
        int finalAns = solveSo(word1, word2);
        return finalAns;
    }
};

// https://leetcode.com/problems/edit-distance/description/