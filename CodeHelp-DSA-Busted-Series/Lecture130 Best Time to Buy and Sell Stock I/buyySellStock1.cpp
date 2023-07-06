#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    // Method 1
    // TC = O(N)
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = 0;

        for(int i=1; i<prices.size(); i++)
        {
            int difference = prices[i] - mini;
            profit = max(profit, difference);
            mini = min(mini, prices[i]);
        }

        return profit;
    }

    // Method 2: TLE
    // TC = O(N*N)
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();

        for(int i=n-1; i>=1; i--)
        {
            int sell = prices[i];
            int buy = INT_MAX;
            for(int j=0; j<i; j++)
            {
                buy = min(buy, prices[j]);
            }

        int difference = sell - buy;
        profit = max(profit, difference);
        }
        return profit;
    }
};

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/