#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int index, int n, vector<int>&nums)
    {
        //base case
        if(index >= n)
        {
            return 0;
        }

        // recurive calls
        int take = nums[index] + solve(index+2, n, nums); // incrementing by 2
        int notTake = 0 + solve(index+1, n, nums); // incrementing by 1
        return max(take, notTake);
    }

    int solveMem(int index, int n, vector<int>&nums, vector<int>&dp)
    {
        //base case
        if(index >= n)
        {
            return 0;
        }
        if(dp[index] != -1)
        {
            return dp[index];
        }

        // recurive calls
        int take = nums[index] + solveMem(index+2, n, nums, dp); // incrementing by 2
        int notTake = 0 + solveMem(index+1, n, nums, dp); // incrementing by 1
        dp[index] = max(take, notTake);
        return dp[index];
    }

    int solveTab(int n, vector<int>&nums)
    {
        // Creating a dp array
        vector<int>dp(n, 0);

        // Analysing the base case
        dp[0] = nums[0];
        
        // Solve for remaining cases
        for(int i=1; i<n; i++)
        {
            int take = nums[i];
            if(i >= 2)
            {
                take += dp[i-2];
            }

            int notTake = dp[i-1];

            dp[i] = max(take, notTake);
        }

        return max(dp[n-1], dp[n-2]);
    }

    int solveSo(int n, vector<int>&nums)
    {
        int prev2 = 0;
        int prev1 = nums[0];

        for(int i=1; i<n; i++)
        {
            int take = nums[i];
            if(i>1)
            {
                take += prev2;
            }

            int notTake = 0 + prev1;

            int curr = max(take, notTake);

            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        int index = 0; // pointer

        // Using recursion
        // int finalAns = solve(index, n, nums);
        // return finalAns;

        // Using memoization
        // vector<int>dp(n, -1);
        // int finalAns = solveMem(index, n, nums, dp);
        // return finalAns;

        // Using tabulation (doesn't work)
        // int finalAns = solveTab(n, nums);
        // return finalAns;

        // Using Space Optimization
        int finalAns = solveSo(n, nums);
        return finalAns;
    }
};

// https://leetcode.com/problems/house-robber/description/
// This is same as maximum sum of non adjacent elements