#include <bits/stdc++.h> 
#include<iostream>
#include<vector>
using namespace std;

// Method 1: Recursion (TLE)
int solve(vector<int>&weight, vector<int>&value, int i, int n, int maxWeight)
{
	// base case 
	if(i == n-1)
	{
		// array index last element par hai 
		// check for the knapsack weight condition
		if(weight[i] <= maxWeight)
		{
			return value[i];
		}
		else
		{
			return 0;
		}
	}

	// include call
	int include = 0;
	if(weight[i] <= maxWeight)
	{
		include = value[i] + solve(weight, value, i+1, n, maxWeight-weight[i]);
	}

	// exclude call
	int exclude = 0;
	exclude = 0 + solve(weight, value, i+1, n, maxWeight);

	int ans = max(exclude, include);
	return ans;
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	int i = 0;
	int ans = solve(weight, value, i, n, maxWeight);

	return ans;
}

// Method 2: Memoization 
#include <bits/stdc++.h> 

int solve(vector<int>&weight, vector<int>&value, int i, int n, int maxWeight, vector<vector<int>>&dp)
{
	// base case
	if(i == n-1)
	{
		// index i has reached the last pos
		// check for knapsack weight condition
		if(weight[i] <= maxWeight)
		{
			return value[i]; 
		}
		else
		{
			return 0;
		}
	}
	
	if(dp[i][maxWeight] != -1)
	{
		return dp[i][maxWeight];
	}

	int include = 0;
	if(weight[i] <= maxWeight)
	{
		include = value[i] + solve(weight, value, i+1, n, maxWeight-weight[i], dp);
	}

	int exclude = 0;
	exclude = 0 + solve(weight, value, i+1, n, maxWeight, dp);

	dp[i][maxWeight] = max(include, exclude);
	return dp[i][maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
  int i = 0;
  vector<vector<int>>dp(n, vector<int>(maxWeight+1, -1));
  int finalAns = solve(weight, value, i, n, maxWeight, dp);
  return finalAns;
}

// Method 3: Tabulation (Hard to understand)
#include <bits/stdc++.h> 

int solve(vector<int>&weight, vector<int>&value, int n, int maxWeight)
{
	// Step 1: Create a DP array
	vector<vector<int>>dp(n, vector<int>(maxWeight+1, 0));

	// Step 2: Analyze the base condition 
	for(int w = weight[0]; w <= maxWeight; w++)
	{
		if(weight[0] <= maxWeight)
		{
			dp[0][w] = value[0];
		}
		else
		{
			dp[0][w] = 0;
		}
	}

	// Take care of remaining recursive calls
	for(int i=1; i<n; i++)
	{
		for(int w=0; w<= maxWeight; w++)
		{
			int include = 0;
			if(weight[i] <= w)
			{
				include = value[i] + dp[i-1][w - weight[i]];
			}

			int exclude = 0 + dp[i-1][w];

			dp[i][w] = max(include, exclude);
		}
	}
	return dp[n-1][maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
  int finalAns = solve(weight, value, n, maxWeight);
  return finalAns;
}

// Method 4: Space Optimization
#include <bits/stdc++.h> 

int solve(vector<int>&weight, vector<int>&value, int n, int maxWeight)
{
	vector<int>prev(maxWeight+1, 0);
	vector<int>curr(maxWeight+1, 0);

	for(int w = weight[0]; w <= maxWeight; w++)
	{
		if(weight[0] <= maxWeight)
		{
			prev[w] = value[0];
		}
		else
		{
			prev[w] = 0;
		}
	}

	for(int i=1; i<n; i++)
	{
		for(int w=0; w<= maxWeight; w++)
		{
			int include = 0;
			if(weight[i] <= w)
			{
				include = value[i] + prev[w - weight[i]];
			}

			int exclude = 0 + prev[w];

			curr[w] = max(include, exclude);
		}
		prev = curr;
	}
	return prev[maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
  int finalAns = solve(weight, value, n, maxWeight);
  return finalAns;
}

/*
Notes
	1. Creting a dp array
		this dp array will have
		rows = n (4)
		columns = maxWeight+1 (5+1)
		vector<vector<int>>dp(n, vector<int>(maxWeight+1, -1));

	2. Revise tabulation and space optimization
*/

// https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1