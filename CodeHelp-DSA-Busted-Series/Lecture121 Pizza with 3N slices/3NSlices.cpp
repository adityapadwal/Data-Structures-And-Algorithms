#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(vector<int>&slices, int start, int end, int n)
    {
        if(n <= 0 || start > end)
        {
            return 0;
        }

        int take = slices[start] + solve(slices, start+2, end, n-1);
        int notTake = 0 + solve(slices, start+1, end, n);

        int ans = max(take, notTake);
        return ans;
    }

    int solveMem(vector<int>&slices, int start, int end, int n, vector<vector<int>>&dp)
    {
        if(n <= 0 || start > end)
        {
            return 0;
        }
        if(dp[start][n] != -1)
        {
            return dp[start][n];
        }

        int take = slices[start] + solveMem(slices, start+2, end, n-1, dp);
        int notTake = 0 + solveMem(slices, start+1, end, n, dp);

        int ans = max(take, notTake);
        dp[start][n] = ans;
        return dp[start][n];
    }

    int solveTab(vector<int>&slices)
    {
        int k = slices.size();
        // create a DP array
        vector<vector<int>>dp1(k+2, vector<int>(k+2, 0));
        vector<vector<int>>dp2(k+2, vector<int>(k+2, 0));

        for(int index = k-2; index >= 0; index--)
        {
            for(int n=1; n<= k/3; n++)
            {
                int take = slices[index] + dp1[index+2][n-1];
                int notTake = 0 + dp1[index+1][n];

                dp1[index][n] = max(take, notTake);
            }
        }
        int case1 = dp1[0][k/3];

        for(int index = k-1; index >= 1; index--)
        {
            for(int n=1; n<= k/3; n++)
            {
                int take = slices[index] + dp2[index+2][n-1];
                int notTake = 0 + dp2[index+1][n];

                dp2[index][n] = max(take, notTake);
            }
        }
        int case2 = dp2[1][k/3];

        return max(case1, case2);
    }

    int solveSo(vector<int>&slices)
    {
        int k = slices.size();
        // create a DP array
        vector<int>prev1(k+2, 0);
        vector<int>curr1(k+2, 0);
        vector<int>next1(k+2, 0);

        vector<int>prev2(k+2, 0);
        vector<int>curr2(k+2, 0);
        vector<int>next2(k+2, 0);

        for(int index = k-2; index >= 0; index--)
        {
            for(int n=1; n<= k/3; n++)
            {
                int take = slices[index] + next1[n-1];
                int notTake = 0 + curr1[n];

                prev1[n] = max(take, notTake);
            }
            next1 = curr1;
            curr1 = prev1;
        }
        int case1 = curr1[k/3];

        for(int index = k-1; index >= 1; index--)
        {
            for(int n=1; n<= k/3; n++)
            {
                int take = slices[index] + next2[n-1];
                int notTake = 0 + curr2[n];

                prev2[n] = max(take, notTake);
            }
            next2 = curr2;
            curr2 = prev2;
        }
        int case2 = curr2[k/3];

        return max(case1, case2);
    }

    int maxSizeSlices(vector<int>& slices) {
        // Recursive Solution
        // int k = slices.size();
        // int case1 = solve(slices, 0, k-2, k/3);
        // int case2 = solve(slices, 1, k-1, k/3);
        // int finalAns = max(case1, case2);
        // return finalAns;

        // Memoization Solution
        // int k = slices.size();

        // vector<vector<int>>dp1(k, vector<int>((k/3 + 1), -1));
        // int case1 = solveMem(slices, 0, k-2, k/3, dp1);

        // vector<vector<int>>dp2(k, vector<int>((k/3 + 1), -1));
        // int case2 = solveMem(slices, 1, k-1, k/3, dp2);
        
        // int finalAns = max(case1, case2);
        // return finalAns;

        // We can take the size of the dp array as k*k
        // But I have optimized it to k*(k/3+1)

        // Tabulation Solution
        // int finalAns = solveTab(slices);
        // return finalAns;

        // Space Optimization
        int finalAns = solveSo(slices);
        return finalAns;
    }
};

// https://www.youtube.com/watch?v=XY297u8qRDI&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=131