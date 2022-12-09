#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

// Approach 1 TC=O(n) SC=O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> cnt(nums.size(),0);
        int ans;

        for(int i=0; i<nums.size(); i++)
        {
            cnt[nums[i]]++;
        }

        for(int i=0; i<nums.size(); i++)
        {
            if(cnt[i] > 1)
            {
                ans = i;
                return ans;
            }
        }
        return -1;
    }
};

//  Approach 2 TC=O(1) SC=O(1)
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//        for(int i=0; i<nums.size(); i++)
//        {
//            int index = abs(nums[i]);
//            if(nums[index] < 0)
//            {
//                return index;
//            }
//            nums[index] = - nums[index];
//        }
//        return -1;
//     }
// };


// Approach 3 TC=O(1) SC=O(1)
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//        int low = 1, high = nums.size() - 1, cnt;
        
//         while(low <=  high)
//         {
//             int mid = low + (high - low) / 2;
//             cnt = 0;
//             // cnt number less than equal to mid
//             for(int n : nums)
//             {
//                 if(n <= mid)
//                     ++cnt;
//             }
//             // binary search on left
//             if(cnt <= mid)
//                 low = mid + 1;
//             else
//             // binary search on right
//                 high = mid - 1;
            
//         }
//         return low;
//     }
// };

// https://leetcode.com/problems/find-the-duplicate-number/