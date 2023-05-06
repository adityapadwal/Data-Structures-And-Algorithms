#include <bits/stdc++.h> 
#include<iostream>
#include<vector>
using namespace std;

// using normal recursion
int solve(vector<int>&nums, int i, int n)
{
    // base case 
    if(i > n)
    {
        return 0;
    }
    if(n == 0)
    {
        return nums[0];
    }

    int include = solve(nums, i+2, n) + nums[i];
    int exclude = solve(nums, i+1, n) + 0;

    return max(include, exclude);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int i = 0;
    int ans = solve(nums, i, n);
    return ans;
}

// Using Memoization 
#include <bits/stdc++.h> 

// using normal recursion
int solve(vector<int>&nums, int i, int n, vector<int>&dp)
{
    // base case 
    if(i > n)
    {
        return 0;
    }
    if(n == 0)
    {
        return nums[0];
    }
    if(dp[i] != INT_MIN)
    {
        return dp[i];
    }

    int include = solve(nums, i+2, n, dp) + nums[i];
    int exclude = solve(nums, i+1, n, dp) + 0;

    dp[i] = max(include, exclude);
    return dp[i];
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int i = 0;
    vector<int>dp(n+1, INT_MIN);
    int ans = solve(nums, i, n-1, dp);
    return ans;
}

// Using Tabulation 
#include <bits/stdc++.h> 

// using normal recursion
int solve(vector<int>&nums)
{
    // Step 1: Creation of the dp array and other required variables
    int n = nums.size();
    vector<int>dp(n+1, INT_MIN);

    // Step 2: Convert base case of the memoization
    dp[0] = nums[0];

    // /Step 3: 
    for(int i=1; i<n; i++)
    {
        int include = dp[i-2] + nums[i];
        int exclude = dp[i-1] + 0;

        dp[i] = max(include, exclude);
    }
    return dp[n-1];
}

int maximumNonAdjacentSum(vector<int> &nums){
    int ans = solve(nums);
    return ans;
}

// using space optimization
#include <bits/stdc++.h> 

// using normal recursion
int solve(vector<int>&nums)
{
    int prev2 = 0;
    int prev1 = nums[0];

    for(int i=1; i<nums.size(); i++)
    {
        int include = prev2 + nums[i];
        int exclude = prev1 + 0;
        int ans = max(include, exclude);

        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums){
    int ans = solve(nums);
    return ans;
}

// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=1
// Revised