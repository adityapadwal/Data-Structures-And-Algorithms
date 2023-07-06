#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int solve(int index, int operationNo, int k, vector<int>prices)
    {
        // base case 
        if(index == prices.size())
        {
            return 0;
        }
        if(operationNo == 2*k)
        {
            return 0;
        }

        int profit = 0;
        if(operationNo % 2 == 0)
        {
            // 2 choices => Buy & ignore/skip
            int buyKaro = -prices[index] + solve(index+1, operationNo+1, k, prices);
            int ignoreKaro = 0 + solve(index+1, operationNo, k, prices);
            profit = max(buyKaro, ignoreKaro);
        }
        else
        {
            // operationNo % 2 != 0
            // 2 choices => Sell & ignore/skip
            int sellKaro = prices[index] + solve(index+1, operationNo+1, k, prices);
            int ignoreKaro = 0 + solve(index+1, operationNo, k, prices);
            profit = max(sellKaro, ignoreKaro);
        }
        return profit;
    }

    int solveMem(int index, int operationNo, int k, vector<int>prices, vector<vector<int>>&dp)
    {
        // base case 
        if(index == prices.size())
        {
            return 0;
        }
        if(operationNo == 2*k)
        {
            return 0;
        }
        if(dp[index][operationNo] != -1)
        {
            return dp[index][operationNo];
        }

        int profit = 0;
        if(operationNo % 2 == 0)
        {
            // 2 choices => Buy & ignore/skip
            int buyKaro = -prices[index] + solveMem(index+1, operationNo+1, k, prices, dp);
            int ignoreKaro = 0 + solveMem(index+1, operationNo, k, prices, dp);
            profit = max(buyKaro, ignoreKaro);
        }
        else
        {
            // operationNo % 2 != 0
            // 2 choices => Sell & ignore/skip
            int sellKaro = prices[index] + solveMem(index+1, operationNo+1, k, prices, dp);
            int ignoreKaro = 0 + solveMem(index+1, operationNo, k, prices, dp);
            profit = max(sellKaro, ignoreKaro);
        }
        dp[index][operationNo] = profit;
        return dp[index][operationNo];
    }

    int solveTab(vector<int>prices, int k)
    {
        // creating a dp array
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2*k+1, 0));

        for(int index=n-1; index>=0; index--)
        {
            for(int operationNo=0; operationNo<2*k; operationNo++)
            {
                int profit = 0;
                if(operationNo % 2 == 0)
                {
                    // 2 choices => Buy & ignore/skip
                    int buyKaro = -prices[index] + dp[index+1][operationNo+1];
                    int ignoreKaro = 0 + dp[index+1][operationNo];
                    profit = max(buyKaro, ignoreKaro);
                }
                else
                {
                    // operationNo % 2 != 0
                    // 2 choices => Sell & ignore/skip
                    int sellKaro = prices[index] + dp[index+1][operationNo+1];
                    int ignoreKaro = 0 + dp[index+1][operationNo];
                    profit = max(sellKaro, ignoreKaro);
                }
                dp[index][operationNo] = profit;
            }
        }
        return dp[0][0];
    }

    int solveSo(vector<int>prices, int k)
    {
        // creating a dp array
        int n = prices.size();
        vector<int>curr(2*k+1, 0);
        vector<int>next(2*k+1, 0);

        for(int index=n-1; index>=0; index--)
        {
            for(int operationNo=0; operationNo<2*k; operationNo++)
            {
                int profit = 0;
                if(operationNo % 2 == 0)
                {
                    // 2 choices => Buy & ignore/skip
                    int buyKaro = -prices[index] + next[operationNo+1];
                    int ignoreKaro = 0 + next[operationNo];
                    profit = max(buyKaro, ignoreKaro);
                }
                else
                {
                    // operationNo % 2 != 0
                    // 2 choices => Sell & ignore/skip
                    int sellKaro = prices[index] + next[operationNo+1];
                    int ignoreKaro = 0 + next[operationNo];
                    profit = max(sellKaro, ignoreKaro);
                }
                curr[operationNo] = profit;
            }
            next = curr;
        }
        return curr[0];
    }

    int maxProfit(int k, vector<int>& prices) {
        // Using Recursion (TLE)
        // int finalAns = solve(0, 0, k, prices);
        // return finalAns;

        // Using Memoization (Accepted)
        // int n = prices.size();
        // vector<vector<int>>dp(n+1, vector<int>(2*k, -1));
        // int finalAns = solveMem(0, 0, k, prices, dp);
        // return finalAns;

        // Using Tabulation
        // int finalAns = solveTab(prices, k);
        // return finalAns;

        // Using Space Optimization (Accepted)
        int finalAns = solveSo(prices, k);
        return finalAns;
    }
};

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
// This problem is solved using 2D DP