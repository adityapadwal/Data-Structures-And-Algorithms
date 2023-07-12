#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Factorial
class Solution {
public:
    int nCr(int n,int j)
    {
       long long int res=1;
       for(int i=0;i<j;i++)
       {
           res=res*(n-i);
           res=res/(i+1);
       }
       return res;
   }

    vector<vector<int>> generate(int numRows) {
        // for the final answer
        vector<vector<int>>finalAns;
        vector<int>ans;

        for(int i=1; i<=numRows; i++)
        {
            ans.clear();
            for(int j=1; j<=i; j++)
            {
                int temp = nCr(i-1, j-1);
                ans.push_back(temp);
            }
            finalAns.push_back(ans);
        }
        return finalAns;
    }
};

// https://leetcode.com/problems/pascals-triangle/