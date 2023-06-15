#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(int index, int endIndex, vector<int>&slices, int n)
    {
        // base case 
        if(n == 0 || index > endIndex)
        {
            return 0;
        }

        int take = slices[index] + solve(index+2, endIndex, slices, n-1);
        int notTake = 0 + solve(index+1, endIndex, slices, n);

        int ans = max(take, notTake);
        return ans;
    }

    int solveMem(int index, int endIndex, vector<int>&slices, int n, vector<vector<int>>&dp)
    {
        // base case 
        if(n == 0 || index > endIndex)
        {
            return 0;
        }
        if(dp[index][n] != -1)
        {
            return dp[index][n];
        }

        int take = slices[index] + solveMem(index+2, endIndex, slices, n-1, dp);
        int notTake = 0 + solveMem(index+1, endIndex, slices, n, dp);

        dp[index][n] = max(take, notTake);
        return dp[index][n];
    }

    int maxSizeSlices(vector<int>& slices) {
        // Method 1: Recursion
        // int k = slices.size();
        // int case1 = solve(0, k-2, slices, k/3);
        // int case2 = solve(1, k-1, slices, k/3);
        // int finalAns = max(case1, case2);
        // return finalAns;

        // Method 2: Memoization 
        // int k = slices.size();
        // vector<vector<int>>dp1(k, vector<int>(k, -1));
        // vector<vector<int>>dp2(k, vector<int>(k, -1));
        // int case1 = solveMem(0, k-2, slices, k/3, dp1);
        // int case2 = solveMem(1, k-1, slices, k/3, dp2);
        // int finalAns = max(case1, case2);
        // return finalAns;
    }
};

// https://leetcode.com/problems/pizza-with-3n-slices/description/