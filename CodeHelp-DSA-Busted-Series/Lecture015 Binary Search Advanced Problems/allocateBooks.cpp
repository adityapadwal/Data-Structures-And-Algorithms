#include <bits/stdc++.h> 
using namespace std;
bool isPossible(int n, int m, vector<int>time, long long mid)
{
	int days = 1;
	long long seconds = 0;
	for(int i=0; i<m; i++)
	{
		if(seconds + time[i] <= mid)
		{
			seconds += time[i];
		}
		else
		{
			days++;
			if(days > n || time[i] > mid)
			{
				return false;
			}
			seconds = time[i];
		}
	}
	return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long s = 0;
	long long sum = 0;
	for(int i=0; i<m; i++)
	{
		sum += time[i];
	}
	long long e = sum;
	long long ans = -1;
	long long mid = s+(e-s)/2;

	while(s<=e)
	{
		if(isPossible(n, m, time, mid))
		{
			ans = mid;
			e = mid-1;
		}
		else
		{
			s = mid + 1;
		}
		mid = s+(e-s)/2;
	}
	cout<<ans;
	return ans;
}

// https://www.codingninjas.com/codestudio/problems/ayush-and-ninja-test_1097574?source=youtube&campaign=love_babbar_codestudio2&leftPanelTab=0