#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int noDP(vector<int>prices)
    {
        int ans = 0;
        for(int i=0;i<prices.size()-1;i++)
        {
            if(prices[i]<prices[i+1])
              ans += prices[i+1]-prices[i];
        }
        return ans;
    }

    int solve(int index, int buy, vector<int>prices)
    {
        // base case
        if(index == prices.size())
        {
            return 0;
        }

        int profit = 0;
        if(buy == 1)
        {
            // 2 choices => Buy & ignore/skip
            int buyKaro = -prices[index] + solve(index+1, 0, prices);
            int ignoreKaro = 0 + solve(index+1, 1, prices);
            profit = max(buyKaro, ignoreKaro);
        }
        else
        {
            // buy == 0
            // 2 choices => Sell & ignore/skip
            int sellKaro = prices[index] + solve(index+1, 1, prices);
            int ignoreKaro = 0 + solve(index+1, 0, prices);
            profit = max(sellKaro, ignoreKaro);
        }
        return profit;
    }

    int solveMem(int index, int buy, vector<int>prices, vector<vector<int>>&dp)
    {
        // base case
        if(index == prices.size())
        {
            return 0;
        }
        if(dp[index][buy] != -1)
        {
            return dp[index][buy];
        }

        int profit = 0;
        if(buy == 1)
        {
            // 2 choices => Buy & ignore/skip
            int buyKaro = -prices[index] + solveMem(index+1, 0, prices, dp);
            int ignoreKaro = 0 + solveMem(index+1, 1, prices, dp);
            profit = max(buyKaro, ignoreKaro);
        }
        else
        {
            // buy == 0
            // 2 choices => Sell & ignore/skip
            int sellKaro = prices[index] + solveMem(index+1, 1, prices, dp);
            int ignoreKaro = 0 + solveMem(index+1, 0, prices, dp);
            profit = max(sellKaro, ignoreKaro);
        }
        return dp[index][buy] = profit;
    }

    int solveTab(vector<int>prices)
    {
        // creating a dp array
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2, 0));

        for(int index=n-1; index>=0; index--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                int profit = 0;
                if(buy == 1)
                {
                    // 2 choices => Buy & ignore/skip
                    int buyKaro = -prices[index] + dp[index+1][0];
                    int ignoreKaro = 0 + dp[index+1][1];
                    profit = max(buyKaro, ignoreKaro);
                }
                else
                {
                    // buy == 0
                    // 2 choices => Sell & ignore/skip
                    int sellKaro = prices[index] + dp[index+1][1];
                    int ignoreKaro = 0 + dp[index+1][0];
                    profit = max(sellKaro, ignoreKaro);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }

    int solveSo(vector<int>prices)
    {
        // creating a dp array
        int n = prices.size();
        vector<int>curr(2, 0);
        vector<int>next(2, 0);

        for(int index=n-1; index>=0; index--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                int profit = 0;
                if(buy == 1)
                {
                    // 2 choices => Buy & ignore/skip
                    int buyKaro = -prices[index] + next[0];
                    int ignoreKaro = 0 + next[1];
                    profit = max(buyKaro, ignoreKaro);
                }
                else
                {
                    // buy == 0
                    // 2 choices => Sell & ignore/skip
                    int sellKaro = prices[index] + next[1];
                    int ignoreKaro = 0 + next[0];
                    profit = max(sellKaro, ignoreKaro);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return curr[1];
    }

    int maxProfit(vector<int>& prices) {
        // if buy=0 => not allowed to buy 
        // if buy=1 => allowed to buy

        // Without using DP (Accepted)
        // int finalAns = noDP(prices);
        // return finalAns;

        // Using Recursion (TLE)
        // int finalAns = solve(0, 1, prices);
        // return finalAns;

        // Using Memoization (Memory Limit Exceeded)
        // int n = prices.size();
        // vector<vector<int>>dp(n, vector<int>(2, -1));
        // int finalAns = solveMem(0, 1, prices, dp);
        // return finalAns;

        // Using Tabulation (Accepted)
        // int finalAns = solveTab(prices);
        // return finalAns;

        // Using Space Optimization
        // int finalAns = solveSo(prices);
        // return finalAns;
    }
};

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/