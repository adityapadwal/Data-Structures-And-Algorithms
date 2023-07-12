#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>ans;
        int first = 0;
        int second = 0;
        for(int i=0; i<n-1; i++)
        {
            first = nums[i];
            for(int j=i+1; j<n; j++)
            {
                second = nums[j];
                if(first + second == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};

// https://leetcode.com/problems/two-sum/submissions/992731615/