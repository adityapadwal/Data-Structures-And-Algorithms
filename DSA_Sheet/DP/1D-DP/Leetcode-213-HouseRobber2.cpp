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

    int rob(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 0;
        }
        if(nums.size() == 1)
        {
            return nums[0];
        }
        
        vector<int>nums1;
        for(int i=0; i<nums.size()-1; i++)
        {
            nums1.push_back(nums[i]);
        }

        vector<int>nums2;
        for(int i=1; i<nums.size(); i++)
        {
            nums2.push_back(nums[i]);
        }

        int n = nums1.size();
        int index = 0; // pointer

        // Using recursion
        // int finalAns1 = solve(index, n, nums1);
        // int finalAns2 = solve(index, n, nums2);
        // return max(finalAns1, finalAns2);

        // Using Memoization
        vector<int>dp1(n, -1);
        vector<int>dp2(n, -1);
        int finalAns1 = solveMem(index, n, nums1, dp1);
        int finalAns2 = solveMem(index, n, nums2, dp2);
        return max(finalAns1, finalAns2);
    }
};

// https://leetcode.com/problems/house-robber-ii/description/