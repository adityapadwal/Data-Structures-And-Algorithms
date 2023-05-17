#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<queue>
using namespace std;

// Method 1: Recursion (TLE)
int solve(int n, vector<int>&days, vector<int>&cost, int index)
{
    // base case 
    if(index >= n)
    {
        return 0;
    }

    // 1-day pass
    int oneDayPass = cost[0] + solve(n, days, cost, index+1);
    
    // 7-day pass
    int i = 0;
    for(i=index; i<n && days[i] < days[index]+7; i++); // taking i to its correct position
    int sevenDayPass = cost[1] + solve(n, days, cost, i);

    // 30-day pass
    for(i=index; i<n && days[i] < days[index]+30; i++); // taking i to its correct position
    int thirtyDayPass = cost[2] + solve(n, days, cost, i);
    
    int ans = min(oneDayPass, min(sevenDayPass, thirtyDayPass));
    return ans;
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    int index = 0;
    int finalAns = solve(n, days, cost, index);
    return finalAns;
}

// Method 2: Memoization 
int solve(int n, vector<int>&days, vector<int>&cost, int index, vector<int>&dp)
{
    // base case 
    if(index >= n)
    {
        return 0;
    }
    if(dp[index] != -1)
    {
        return dp[index];
    }

    // 1-day pass
    int oneDayPass = cost[0] + solve(n, days, cost, index+1, dp);
    
    // 7-day pass
    int i;
    for(i=index; i<n && days[i] < days[index]+7; i++); // taking i to its correct position
    int sevenDayPass = cost[1] + solve(n, days, cost, i, dp);

    // 30-day pass
    for(i=index; i<n && days[i] < days[index]+30; i++); // taking i to its correct position
    int thirtyDayPass = cost[2] + solve(n, days, cost, i, dp);
    
    dp[index] = min(oneDayPass, min(sevenDayPass, thirtyDayPass));
    return dp[index];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    int index = 0;
    vector<int>dp(n+1, -1);
    int finalAns = solve(n, days, cost, index, dp);
    return finalAns;
}

// Method 3: Tabulation
int solve(int n, vector<int>&days, vector<int>&cost)
{
    vector<int>dp(n+1, INT_MAX);

    dp[n] = 0;

    for(int k=n-1; k>=0; k--)
    {
        // 1-day pass
        int oneDayPass = cost[0] + dp[k+1];
        
        // 7-day pass
        int i;
        for(i=k; i<n && days[i] < days[k]+7; i++); // taking i to its correct position
        int sevenDayPass = cost[1] + dp[i];

        // 30-day pass
        for(i=k; i<n && days[i] < days[k]+30; i++); // taking i to its correct position
        int thirtyDayPass = cost[2] + dp[i];
        
        dp[k] = min(oneDayPass, min(sevenDayPass, thirtyDayPass));
    }
    return dp[0];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    int finalAns = solve(n, days, cost);
    return finalAns;
}

// Method 4: Space Optimization
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    int ans = 0;
    
    queue<pair<int, int>>week;
    queue<pair<int, int>>month;
    
    for(int day:days)
    {
        // Step 1: Remove the expired days from the queue
        while(!month.empty() && month.front().first+30 <= day)
        {
            month.pop();
        }
        while(!week.empty() && week.front().first+7 <= day)
        {
            week.pop();
        }

        // Step 2: Push the cost of the current day
        week.push(make_pair(day, ans+cost[1]));
        month.push(make_pair(day, ans+cost[2]));

        // Step 3: update the answer
        ans = min(ans+cost[0], min(month.front().second, week.front().second));
    }
    return ans;
}

// https://www.codingninjas.com/codestudio/problems/minimum-coins_2180776?leftPanelTab=1