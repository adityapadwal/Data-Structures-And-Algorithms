#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

// ******** Using Simple Recursion (TLE) ********
class Solution {
private:
    int solve(vector<int>&cost, int n)
    {
        // base case
        if(n == 0)
        {
            return cost[0];
        }
        if(n == 1)
        {
            return cost[1];
        }

        int ans = cost[n] + min(solve(cost, n-1), solve(cost, n-2));
        return ans;    
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int ans = min(solve(cost, n-1), solve(cost, n-2));
        return ans;
    }
};

// *********** Using Top-Down Approach (R+M) ***********
class Solution {
private:
    int solve(vector<int>&cost, int n, vector<int>&dp)
    {
        // base case
        if(n == 0)
        {
            return cost[0];
        }
        if(n == 1)
        {
            return cost[1];
        }
        if(dp[n] != -1)
        {
            return dp[n];
        }

        dp[n] = cost[n] + min(solve(cost, n-1, dp), solve(cost, n-2, dp));
        return dp[n];    
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1, -1);
        int ans = min(solve(cost, n-1, dp), solve(cost, n-2, dp));
        return ans;
    }
};

// *********** Using Bottom-Up (Tabulation) ***********
class Solution {
private:
    int solve(vector<int>&cost, int n)
    {
        // Step 1: Create a dp array 
        vector<int>dp(n+1, -1);

        // Step 2: Analyse the base conditions
        dp[0] = cost[0];
        dp[1] = cost[1];

        // Step 3: Handle all the other conditions
        for(int i=2; i<n; i++)
        {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }

        return min(dp[n-1], dp[n-2]);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int ans = solve(cost, n);
        return ans;
    }
};

// *********** Using Space Optimization Approach ***********

class Solution {
private:
    int solve(vector<int>&cost, int n)
    {
        int prev2 = cost[0];
        int prev1 = cost[1];

        for(int i=2; i<n; i++)
        {
            int curr = cost[i] + min(prev1 , prev2);
        
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int ans = solve(cost, n);
        return ans;
    }
};

// https://leetcode.com/problems/min-cost-climbing-stairs/description/
// Revised
