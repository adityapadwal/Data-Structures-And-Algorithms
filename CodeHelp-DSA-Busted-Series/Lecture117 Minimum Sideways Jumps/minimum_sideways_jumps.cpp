#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>&obstacles, int pos, int currLane)
    {
        int n = obstacles.size()-1;

        // base case 
        if(pos == n)
        {
            // If the pos where I am standing is the final pos, then I need to take zero jumps
            return 0;
        }

        // aage rasta khali hai?
        if(obstacles[pos+1] != currLane)
        {
            return solve(obstacles, pos+1, currLane);
        }
        else
        {
            // obstacle hai aage 
            // hence we need to make sideways jump
            int ans = INT_MAX;
            for(int i=1; i<=3; i++)
            {
                if(currLane != i && obstacles[pos] != i)
                {
                    ans = min(ans, 1+solve(obstacles, pos, i));
                }
            }
            return ans;
        }
    }

    int solveMem(vector<int>&obstacles, int pos, int currLane, vector<vector<int>>&dp)
    {
        int n = obstacles.size()-1;

        // base case 
        if(pos == n)
        {
            // If the pos where I am standing is the final pos, then I need to take zero jumps
            return 0;
        }
        if(dp[currLane][pos] != -1)
        {
            return dp[currLane][pos];
        }

        // aage rasta khali hai?
        if(obstacles[pos+1] != currLane)
        {
            return solveMem(obstacles, pos+1, currLane, dp);
        }
        else
        {
            // obstacle hai aage 
            // hence we need to make sideways jump
            int ans = INT_MAX;
            for(int i=1; i<=3; i++)
            {
                if(currLane != i && obstacles[pos] != i)
                {
                    ans = min(ans, 1 + solveMem(obstacles, pos, i, dp) );
                }
            }
            dp[currLane][pos] = ans;
            return dp[currLane][pos];
        }
    }

    int minSideJumps(vector<int>& obstacles) {
        // Method 1: Recursion 
        // int pos = 0;
        // int currLane = 2;
        // int finalAns = solve(obstacles, pos, currLane);
        // return finalAns;

        // Method 2: Memoization 
        int pos = 0;
        int currLane = 2;
        int n = obstacles.size();
        vector<vector<int>>dp(4, vector<int>(n, -1));
        int finalAns = solveMem(obstacles, pos, currLane, dp);
        return finalAns;
    }
};