#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        // This problem is an example of DP + Hashing

        // creating a dp array
        unordered_map<int, int>dp;

        int ans = 0;

        for(int i=0; i<arr.size(); i++)
        {
            int temp = arr[i] - difference;
            int tempAns = 0;

            // check in the unordered map
            if(dp.count(temp))
            {
                tempAns = dp[temp];
            }

            // current ans update karo
            dp[arr[i]] = 1 + tempAns;

        }

        for(int i=0; i<arr.size(); i++)
        {
            ans = max(ans, dp[arr[i]]);
        }

        return ans;
    }
};

// https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/