#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>&nums1, vector<int>&nums2, int index, bool swapped)
    {
        // base case 
        if(index >= nums1.size())
        {
            return 0;
        }

        // for the final answer
        int ans = INT_MAX;

        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        // catch!
        if(swapped)
        {
            swap(prev1, prev2);
        }

        // no swap
        if(nums1[index]>prev1 && nums2[index]>prev2)
        {
            ans = solve(nums1, nums2, index+1, 0);
        }

        // swap
        if(nums1[index]>prev2 && nums2[index]>prev1)
        {
            ans = min(ans, 1+solve(nums1, nums2, index+1, 1));
        }

        return ans;
    }

    int solveMem(vector<int>&nums1, vector<int>&nums2, int index, bool swapped, vector<vector<int>>&dp)
    {
        // base case 
        if(index >= nums1.size())
        {
            return 0;
        }
        if(dp[index][swapped] != -1)
        {
            return dp[index][swapped];
        }

        // for the final answer
        int ans = INT_MAX;

        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        // catch!
        if(swapped)
        {
            swap(prev1, prev2);
        }

        // no swap
        if(nums1[index]>prev1 && nums2[index]>prev2)
        {
            ans = solveMem(nums1, nums2, index+1, 0, dp);
        }

        // swap
        if(nums1[index]>prev2 && nums2[index]>prev1)
        {
            ans = min(ans, 1+solveMem(nums1, nums2, index+1, 1, dp));
        }

        dp[index][swapped] = ans;
        return dp[index][swapped];
    }

    int solveTab(vector<int>&nums1, vector<int>&nums2, bool swapped)
    {
        int n = nums1.size();
        // create a dp array
        vector<vector<int>>dp(n+1, vector<int>(2, 0));

        for(int index=n-1; index>=1; index--)
        {
            for(int swapped=1; swapped>=0; swapped--)
            {
                // for the final answer
                int ans = INT_MAX;

                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                // catch!
                if(swapped)
                {
                    swap(prev1, prev2);
                }

                // no swap
                if(nums1[index]>prev1 && nums2[index]>prev2)
                {
                    ans = dp[index+1][0];
                }

                // swap
                if(nums1[index]>prev2 && nums2[index]>prev1)
                {
                    ans = min(ans, 1 + dp[index+1][1]);
                }

                dp[index][swapped] = ans;
            }
        }
        return dp[1][0];
    }

    int solveSo(vector<int>&nums1, vector<int>&nums2, bool swapped)
    {
        int n = nums1.size();
        int noswap = 0;
        int swap = 0;
        int currnoswap = 0;
        int currswap = 0;

        for(int index=n-1; index>=1; index--)
        {
            for(int swapped=1; swapped>=0; swapped--)
            {
                // for the final answer
                int ans = INT_MAX;

                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                // catch!
                if(swapped)
                {
                    // swapping prev2 and prev1
                    int temp = prev2;
                    prev2 = prev1;
                    prev1 = temp;
                }

                // no swap
                if(nums1[index]>prev1 && nums2[index]>prev2)
                {
                    ans = noswap;
                }

                // swap
                if(nums1[index]>prev2 && nums2[index]>prev1)
                {
                    ans = min(ans, 1 + swap);
                }

                if(swapped)
                {
                    currswap = ans;
                }
                else
                {
                    currnoswap = ans;
                }
            }
            swap = currswap;
            noswap = currnoswap;
        }
        return min(swap, noswap);
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // Insert -1 in the beginning of both the arrays
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        // Using Recursion
        // bool swapped = 0;
        // int finalAns = solve(nums1, nums2, 1, swapped);
        // return finalAns;

        // Using Memoization
        // bool swapped = 0;
        // int n = nums1.size();
        // vector<vector<int>>dp(n, vector<int>(2, -1));
        // int finalAns = solveMem(nums1, nums2, 1, swapped, dp);
        // return finalAns;

        // Using Tabulation
        // bool swapped = 0;
        // int finalAns = solveTab(nums1, nums2, swapped);
        // return finalAns;

        // Using Space Optimization
        // bool swapped = 0;
        // int finalAns = solveSo(nums1, nums2, swapped);
        // return finalAns;

    }
};

// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/
// Revise for Space Optimization 