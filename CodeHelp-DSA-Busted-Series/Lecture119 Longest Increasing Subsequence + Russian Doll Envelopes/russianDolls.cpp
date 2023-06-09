#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();

        // base case
        if(n == 0)
        {
            return 0;
        }

        // sorting the envelopes 2D array such that
        // first element is in the ascending order
        // if the fist element of two rows is same, 
        // then sorting it in the descending order
        // of the second element
        sort(envelopes.begin(), envelopes.end(), [](const auto& a, const auto& b) 
        {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        }
        );

        // consider on the height. No need to consider the width.
        // Perform Longest Increasing Subsequence (LIS) on this array.
        // Use the Optimized approach TC = O(n log n)
        // LIS + Binary Search 
        vector<int> a;
        for(int i=0; i<n; i++)
        {
            a.push_back(envelopes[i][1]);
        }

        vector<int>ans;
        // put the first element into the ans array
        ans.push_back(a[0]);

        for(int i=1; i<n; i++)
        {
            if(a[i] > ans.back())
            {
                ans.push_back(a[i]);
            }
            else
            {
                // arr[i] > ans.back()
                int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                ans[index] = a[i];
            }
        }
        return ans.size();
    }
};

// https://leetcode.com/problems/russian-doll-envelopes/description/