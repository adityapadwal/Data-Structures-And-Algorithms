#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int mini = prices[0];
        for(int i=1; i<prices.size(); i++)
        {
            int difference = prices[i]-mini;
            profit = max(profit, difference);
            mini = min(mini, prices[i]);
        }

        return profit;
    }
};

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/