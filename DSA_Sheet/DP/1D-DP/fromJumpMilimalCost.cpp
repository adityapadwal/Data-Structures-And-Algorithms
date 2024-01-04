#include<bits/stdc++.h>
using namespace std;

int solve(int index, int n, int k, vector<int>&height)
{
    // base case
    if(index == n-1)
    {
        return 0;
    }

    vector<int>tempArr;
    for(int i=1; i<=k; i++)
    {
        int temp;
        if((index+i) < n)
        {
            temp = abs(height[index] - height[index+i]) + solve(index+i, n, k, height);
            tempArr.push_back(temp);
        }
        else
        {
            break;
        }
    }
    
    auto tempAns = min_element(tempArr.begin(), tempArr.end());
    return *tempAns;
}

int solveMem(int index, int n, int k, vector<int>&height, vector<int>&dp)
{
    // base case
    if(index == n-1)
    {
        return 0;
    }
    if(dp[index] != -1)
    {
        return dp[index];
    }

    vector<int>tempArr;
    for(int i=1; i<=k; i++)
    {
        int temp;
        if((index+i) < n)
        {
            temp = abs(height[index] - height[index+i]) + solveMem(index+i, n, k, height, dp);
            tempArr.push_back(temp);
        }
        else
        {
            break;
        }
    }
    
    auto tempAns = min_element(tempArr.begin(), tempArr.end());
    dp[index] = *tempAns;
    return dp[index];
}

int solveTab(int index, int n, int k, vector<int>&height)
{
    // Creating a dp array
    vector<int>dp(n, INT_MAX);

    // Analyse the base case
    dp[0] = 0;

    // Solving for the remaining cases
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= i + k && j < n; j++) {
            dp[j] = min(dp[j], dp[i] + abs(height[i] - height[j]));
        }
    }

    return dp[n - 1];
}

int minimizeCost(int n, int k, vector<int> &height){
    int index = 0; // pointer to keep a track

    // Using recursion
    // int finalAns = solve(index, n, k, height);
    // return finalAns;

    // Using Memoization (TD)
    // vector<int>dp(n, -1);
    // int finalAns = solveMem(index, n, k, height, dp);
    // return finalAns;

    // Using Tabulation (BU)
    int finalAns = solveTab(index, n, k, height);
    return finalAns;
}

// https://www.codingninjas.com/studio/problems/minimal-cost_8180930?leftPanelTabValue=PROBLEM