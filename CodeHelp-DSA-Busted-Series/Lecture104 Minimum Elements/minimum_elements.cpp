#include <bits/stdc++.h>
#include<iostream>
#include<limits>
#include<vector>
using namespace std;

// Approach 1: Using Recursion
int solve(vector<int>&num, int x)
{
    // base case 
    if(x == 0)
    {
        return 0;
    }
    if(x < 0)
    {
        return INT_MAX;
    }

    int mini = INT_MAX;
    for(int i=0; i<num.size(); i++)
    {
        int ans = solve(num, x-num[i]);
        if(ans != INT_MAX)
        {
            mini = min(mini, 1+ans);
        }
    }
    return mini;
}

int minimumElements(vector<int> &num, int x)
{
    int ans = solve(num, x);
    if(ans == INT_MAX)
    {
        // invalid ans
        return -1;
    }
    else
    {
        return ans;
    }
}

// Approach 2: Using Recursion + Memoization
int solve(vector<int>&num, int x, vector<int>&dp)
{
    // base case 
    if(x == 0)
    {
        return 0;
    }
    if(x < 0)
    {
        return INT_MAX;
    }
    if(dp[x] != -1)
    {
        return dp[x];
    }

    int mini = INT_MAX;
    for(int i=0; i<num.size(); i++)
    {
        int ans = solve(num, x-num[i], dp);
        if(ans != INT_MAX)
        {
            mini = min(mini, 1+ans);
        }
    }
    dp[x] = mini;
    return mini;
}

int minimumElements(vector<int> &num, int x)
{
    // creating a dp array for memoization
    vector<int>dp(x+1, -1);
    int ans = solve(num, x, dp);
    if(ans == INT_MAX)
    {
        // invalid ans
        return -1;
    }
    else
    {
        return ans;
    }
}

// Approach 3: Uisng Tabulation 
int solve(vector<int>&num, int x)
{
    vector<int>dp(x+1, INT_MAX);
    dp[0] = 0;

    for(int i=1; i<=x; i++)
    {
        // We are trying to solve for every amount figure from 1 to x
        for(int j=0; j<num.size(); j++)
        {
            if(i-num[j] >= 0 && dp[i-num[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], 1+dp[i-num[j]]);
            }
        }
    }

    if(dp[x] == INT_MAX)
    {
        return -1;
    }
    else
    {
        return dp[x];
    }
}

int minimumElements(vector<int> &num, int x)
{
    int ans = solve(num, x);
    return ans;
}

// https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091