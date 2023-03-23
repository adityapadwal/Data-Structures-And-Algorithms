#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      
    // just to practice the modulus approach
      int n = nums.size();
      vector<int> temp(n);
      
      
      for(int i =0;i<n;i++) {
        
        temp[(i+k)%n] = nums[i];     // v. v. important formula
        
      }
      
      
      for(int i=0;i<nums.size();i++) 
      {
        nums[i] = temp[i];
      }
      
    }
};

// Rev
//https://leetcode.com/problems/rotate-array/