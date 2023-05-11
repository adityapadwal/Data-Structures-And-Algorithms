#include <bits/stdc++.h> 
#include<iostream>
#include<vector>
using namespace std;
#define MOD 1000000007

// Method 1: Recursion (TLE)
int add(int a, int b)
{
    return ((a%MOD) + (b%MOD))%MOD;
}

int mul(int a, int b)
{
    return ((a%MOD) * (b%MOD))%MOD;
}

int solve(int n, int k)
{
    // base case 
    if(n == 1)
    {
        return k;
    }
    if(n == 2)
    {
        int ans = add(k, mul(k, k-1));
        return ans;
    }

    int ans = add(mul(solve(n-2,k), k-1), mul(solve(n-1,k), k-1));
    return ans;
}

int numberOfWays(int n, int k) {
    return solve(n, k);
}

// Method 2: Memoization
#include <bits/stdc++.h> 
#define MOD 1000000007

int add(int a, int b)
{
    return ((a%MOD) + (b%MOD))%MOD;
}

int mul(int a, int b)
{
    return ((a%MOD) *1LL * (b%MOD))%MOD;
}

int solve(int n, int k, vector<int>&dp)
{
    // base case 
    if(n == 1)
    {
        return k;
    }
    if(n == 2)
    {
        int ans = add(k, mul(k, k-1));
        return ans;
    }
    if(dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = add(mul(solve(n-2,k,dp), k-1), mul(solve(n-1,k,dp), k-1));
    return dp[n];
}

int numberOfWays(int n, int k) {
    vector<int>dp(n+1, -1);
    return solve(n, k, dp);
}

// Method 3: Tabulation 
#include <bits/stdc++.h> 
#define MOD 1000000007

int add(int a, int b)
{
    return ((a%MOD) + (b%MOD))%MOD;
}

int mul(int a, int b)
{
    return ((a%MOD) *1LL * (b%MOD))%MOD;
}

int solve(int n, int k)
{
    vector<int>dp(n+1, -1);

    dp[1] = k;
    dp[2] = add(k, mul(k, k-1));

    for(int i=3; i<=n; i++)
    {
        dp[i] = add(mul(dp[i-2], k-1), mul(dp[i-1], k-1));
    }

    return dp[n];
}

int numberOfWays(int n, int k) {
    vector<int>dp(n+1, -1);
    return solve(n, k);
}

// Method 4: Space Optimization
#include <bits/stdc++.h> 
#define MOD 1000000007

int add(int a, int b)
{
    return ((a%MOD) + (b%MOD))%MOD;
}

int mul(int a, int b)
{
    return ((a%MOD) *1LL * (b%MOD))%MOD;
}

int solve(int n, int k)
{
    int prev2 = k;
    int prev1 = add(k, mul(k, k-1));

    for(int i=3; i<=n; i++)
    {
        int ans = add(mul(prev2, k-1), mul(prev1, k-1));

        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

int numberOfWays(int n, int k) {
    vector<int>dp(n+1, -1);
    return solve(n, k);
}

// https://www.codingninjas.com/codestudio/problems/ninja-and-the-fence_3210208?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1