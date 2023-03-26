#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int>&arr, int n, int k, int mid)
{
	int painterCount = 1;
	int painterSum = 0;
	for(int i=0; i<n; i++)
	{
		if(painterSum + arr[i] <= mid)
		{
			painterSum+=arr[i];
		}
		else
		{
			painterCount ++;
			if(painterCount > k || arr[i]>mid)
			{
				return false;
			}
			painterSum = arr[i];
		}
	}
	return true;
}


int findLargestMinDistance(vector<int> &boards, int k)
{
	int n = boards.size();
    int s = 0;
	int sum = 0;
	for(int i=0; i<n; i++)
	{
		sum += boards[i];
	}
	int e = sum;
	int mid = s + (e-s)/2;
	int ans;
	while(s<=e)
	{
		if(isPossible(boards, n, k, mid))
		   {
			   ans = mid;
			   e = mid - 1;
		   }
		else
		   {
			   s = mid + 1;
		   }
		   mid = s + (e-s)/2;
   
	}
	return mid;
}	   	

// https://www.codingninjas.com/codestudio/problems/painter's-partition-problem_1089557?source=youtube&campaign=love_babbar_codestudio2