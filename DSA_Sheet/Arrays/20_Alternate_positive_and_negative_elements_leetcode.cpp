#include<bits/stdc++.h>
using namespace std;

// Approach 1: TC = O(N) SC = O(1) Partially Accepted :(
class Solution {
public:
    void rightRotate(vector<int>&arr, int n, int outofplace, int cur)
    {
        char tmp = arr[cur];
        for (int i = cur; i > outofplace; i--)
            arr[i] = arr[i - 1];
        arr[outofplace] = tmp;
    }

    void rearrange(vector<int>&arr, int n)
    {
        // outOfPlace conditions
        // 1. positive element at odd index
        // 2. negative element at even index
        int outOfPlace = -1;
        for(int i=0; i<n; i++)
        {
            if(outOfPlace == -1)
            {
                // find the first element
                if((arr[i]<0 && i%2==0) || (arr[i]>=0 && i%2==1))
                {
                    outOfPlace = i;
                }
            }

            if(outOfPlace >= 0)
            {
                // find the second element 
                if(outOfPlace%2 == 1)
                {
                    // first element was a positive element with odd index. 
                    // Hence find the negative element with even index
                    if(arr[i]<0 && i%2==0)
                    {
                        rightRotate(arr, n, outOfPlace, i);
                        i = outOfPlace+1;
                        outOfPlace = -1;
                    }
                }
                else
                {
                    // first element was a negative element with even index. 
                    // Hence find the positive element with odd index
                    if(arr[i]>0 && i%2==1)
                    {
                        rightRotate(arr, n, outOfPlace, i);
                        i = outOfPlace+1;
                        outOfPlace = -1;
                    }
                }
            }
        }
    }
    vector<int> rearrangeArray(vector<int>& nums) {
        rearrange(nums, nums.size());
        return nums;
    }
};

// Approach 1: TC = O(N) SC = O(N)
class Solution {
public:
    vector<int> rearrange(vector<int>&nums, int n)
    {
        vector<int>ne;
        vector<int>po;
        vector<int>ans;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0){
                po.push_back(nums[i]);

            }
            else{
                ne.push_back(nums[i]);
            }
        }
        int k=0;
        int l=0;
        for(int i=0; i<nums.size(); i++){
            if(i%2==0){
                ans.push_back(po[k]);
                k++;
            }
            else{
                ans.push_back(ne[l]);
                l++;
            }
        }
        return ans;
    }
    vector<int> rearrangeArray(vector<int>& nums) {
        return rearrange(nums, nums.size());
    }
};

// https://leetcode.com/problems/rearrange-array-elements-by-sign/description/