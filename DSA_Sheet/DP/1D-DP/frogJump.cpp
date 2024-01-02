#include<bits/stdc++.h>
using namespace std;

int solve(int index, int n, vector<int>&heights)
{
    // base case
    if(index == n-1)
    {
        return 0; 
    }

    // One step jump
    int oneStep;
    if((index+1) < n)
    {
        oneStep = abs(heights[index] - heights[index+1]) + solve(index+1, n, heights);
    }
    else
    {
        oneStep = INT_MAX;
    }

    // Two step jump
    int twoStep;
    if((index+2) < n)
    {
        twoStep = abs(heights[index] - heights[index+2]) + solve(index+2, n, heights);
    }
    else
    {
        twoStep = INT_MAX;
    }

    return min(oneStep, twoStep);
}

int solveMem(int index, int n, vector<int>&heights, vector<int>&dp)
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

    // One step jump
    int oneStep;
    if((index+1) < n)
    {
        oneStep = abs(heights[index] - heights[index+1]) + solveMem(index+1, n, heights, dp);
    }
    else
    {
        oneStep = INT_MAX;
    }

    // Two step jump
    int twoStep;
    if((index+2) < n)
    {
        twoStep = abs(heights[index] - heights[index+2]) + solveMem(index+2, n, heights, dp);
    }
    else
    {
        twoStep = INT_MAX;
    }

    dp[index] = min(oneStep, twoStep);
    return dp[index];
}

int frogJump(int n, vector<int> &heights)
{
    int index = 0; // Pointer to keep a track of the stairs

    // Using recursion
    // int finalAns = solve(index, n, heights);
    // return finalAns;

    // Using Memoization
    vector<int>dp(n, -1);
    int finalAns = solveMem(index, n, heights, dp);
    return finalAns;
}

// https://www.codingninjas.com/studio/problems/frog-jump_3621012?leftPanelTabValue=SUBMISSION