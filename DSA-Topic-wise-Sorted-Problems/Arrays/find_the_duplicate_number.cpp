#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 1;
        int high = n-1;
        int count = 0;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            count = 0;
            for(int i=0; i<n; i++)
            {
                if(nums[i] <= mid)
                {
                    count++;
                }
            }

            if(count <= mid)
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }

        return low;
    }
};

// https://leetcode.com/problems/find-the-duplicate-number/description/