#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int solve(int index, int buy, vector<int>prices, int limit)
    {
        // base case
        if(index == prices.size())
        {
            return 0;
        }
        if(limit == 0)
        {
            return 0;
        }

        int profit = 0;
        if(buy == 1)
        {
            // 2 choices => Buy & ignore/skip
            int buyKaro = -prices[index] + solve(index+1, 0, prices, limit);
            int ignoreKaro = 0 + solve(index+1, 1, prices, limit);
            profit = max(buyKaro, ignoreKaro);
        }
        else
        {
            // buy == 0
            // 2 choices => Sell & ignore/skip
            int sellKaro = prices[index] + solve(index+1, 1, prices, limit-1);
            int ignoreKaro = 0 + solve(index+1, 0, prices, limit);
            profit = max(sellKaro, ignoreKaro);
        }
        return profit;
    }

    int solveMem(int index, int buy, vector<int>prices, int limit, vector<vector<vector<int>>>dp)
    {
        // base case
        if(index == prices.size())
        {
            return 0;
        }
        if(dp[index][buy][limit] != -1)
        {
            return dp[index][buy][limit];
        }

        int profit = 0;
        if(buy == 1)
        {
            // 2 choices => Buy & ignore/skip
            int buyKaro = -prices[index] + solveMem(index+1, 0, prices, limit, dp);
            int ignoreKaro = 0 + solveMem(index+1, 1, prices, limit, dp);
            profit = max(buyKaro, ignoreKaro);
        }
        else
        {
            // buy == 0
            // 2 choices => Sell & ignore/skip
            int sellKaro = prices[index] + solveMem(index+1, 1, prices, limit-1, dp);
            int ignoreKaro = 0 + solveMem(index+1, 0, prices, limit, dp);
            profit = max(sellKaro, ignoreKaro);
        }
        dp[index][buy][limit] = profit;
        return dp[index][buy][limit];
    }

    int solveTab(vector<int>prices, int k)
    {
        // creating a dp array
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        for(int index=n-1; index>=0; index--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                for(int limit=1; limit<=k; limit++)
                {
                    int profit = 0;
                    if(buy == 1)
                    {
                        // 2 choices => Buy & ignore/skip
                        int buyKaro = -prices[index] + dp[index+1][0][limit];
                        int ignoreKaro = 0 + dp[index+1][1][limit];
                        profit = max(buyKaro, ignoreKaro);
                    }
                    else
                    {
                        // buy == 0
                        // 2 choices => Sell & ignore/skip
                        int sellKaro = prices[index] + dp[index+1][1][limit-1];
                        int ignoreKaro = 0 + dp[index+1][0][limit];
                        profit = max(sellKaro, ignoreKaro);
                    }
                    dp[index][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][k];
    }

    int solveSo(vector<int>prices, int k)
    {
        // creating a dp array
        int n = prices.size();
        vector<vector<int>>curr(2, vector<int>(k+1, 0));
        vector<vector<int>>next(2, vector<int>(k+1, 0));

        for(int index=n-1; index>=0; index--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                for(int limit=1; limit<=k; limit++)
                {
                    int profit = 0;
                    if(buy == 1)
                    {
                        // 2 choices => Buy & ignore/skip
                        int buyKaro = -prices[index] + next[0][limit];
                        int ignoreKaro = 0 + next[1][limit];
                        profit = max(buyKaro, ignoreKaro);
                    }
                    else
                    {
                        // buy == 0
                        // 2 choices => Sell & ignore/skip
                        int sellKaro = prices[index] + next[1][limit-1];
                        int ignoreKaro = 0 + next[0][limit];
                        profit = max(sellKaro, ignoreKaro);
                    }
                    curr[buy][limit] = profit;
                }
            }
            next = curr;
        }
        return curr[1][k];
    }

    int maxProfit(int k, vector<int>& prices) {
        // if buy=0 => not allowed to buy 
        // if buy=1 => allowed to buy

        // Using Recursion (TLE)
        // int finalAns = solve(0, 1, prices, k);
        // return finalAns;

        // Using Memoization (Memory Limit Exceeded)
        // int n = prices.size();
        // vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        // int finalAns = solveMem(0, 1, prices, k, dp);
        // return finalAns;

        // Using Tabulation (Accepted)
        // int finalAns = solveTab(prices, k);
        // return finalAns;

        // Using Space Optimization (Accepted)
        // int finalAns = solveSo(prices, k);
        // return finalAns;
    }
};

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
// This problem is solved using 3D DP
