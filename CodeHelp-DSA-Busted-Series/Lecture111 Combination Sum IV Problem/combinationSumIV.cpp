#include<iostream>
#include<vector>
using namespace std;
#include <bits/stdc++.h> 

// Method1: Recursion (TLE)
int solve(vector<int>&num, int tar)
{
    // base case 
    if(tar == 0)
    {
        return 1;
    }
    if(tar < 0)
    {
        return 0;
    }

    int ans = 0;
    for(int i=0; i<num.size(); i++)
    {
        ans += solve(num, tar-num[i]);
    }
    return ans;
}

int findWays(vector<int> &num, int tar)
{
    int finalAns = solve(num, tar);
    return finalAns;
}

// Method 2: Memoization
#include <bits/stdc++.h> 

int solve(vector<int>&num, int tar, vector<int>&dp)
{
    // base case 
    if(tar == 0)
    {
        return 1;
    }
    if(tar < 0)
    {
        return 0;
    }
    if(dp[tar] != -1)
    {
        return dp[tar];
    }

    int ans = 0;
    for(int i=0; i<num.size(); i++)
    {
        ans += solve(num, tar-num[i], dp);
    }
    dp[tar] = ans;
    return dp[tar];
}

int findWays(vector<int> &num, int tar)
{
    vector<int>dp(tar+1, -1);
    int finalAns = solve(num, tar, dp);
    return finalAns;
}

// Method 3: Tabulation
#include <bits/stdc++.h> 

int solve(vector<int>&num, int tar)
{
    // Step 1: Create a dp array
    vector<int>dp(tar+1, 0);

    // Step 2: Analyse the base condition
    dp[0] = 1;
    
    // Step 3: Take care of the remaining recursive calls
    
    // Traversing from 1 to tar
    for(int i=1; i<=tar; i++)
    {
        // Traversing on the num vector
        for(int j=0; j<num.size(); j++)
        {
            if(i-num[j] >= 0)
            {
                dp[i] += dp[i-num[j]];
            }
        }
    }
    return dp[tar];
}

int findWays(vector<int> &num, int tar)
{
    int finalAns = solve(num, tar);
    return finalAns;
}

// Space optimization is not possible
// because dp[i] depends on dp[i-num[j]]
// and dp[i-num[j]] is dificult to track down and store into variables
// Hence space optimization isn't possible

// https://www.codingninjas.com/codestudio/problems/number-of-ways_3755252?leftPanelTab=1