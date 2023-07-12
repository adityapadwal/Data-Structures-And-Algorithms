#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // step 1: Sort the input array
        sort(nums.begin(), nums.end());
        set<vector<int>>s;
        vector<vector<int>> finalAns;

        for(int i=0; i<nums.size(); i++)
        {
            int j = i+1;
            int k = nums.size()-1;

            while(j < k)
            {
                if(nums[i]+nums[j]+nums[k] == 0)
                {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(nums[i]+nums[j]+nums[k] < 0)
                {
                    j++;
                }
                else 
                {
                    // nums[i]+nums[j]+nums[k] > 0
                    k--;
                }
            }
        }

        for(auto triplets: s)
        {
            finalAns.push_back(triplets);
        }

        return finalAns;
    }
};

// https://leetcode.com/problems/3sum/description/