#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

// Approach 1 - TC= O(n^2 lon n) SC= O(n^2)
int getKthLargest(vector<int> &arr, int k)
{
	vector<int> sumStore;
    
    for(int i=0; i<arr.size(); i++)
    {
        int sum = 0;
        for(int j=i; j<arr.size(); j++)
        {
            sum += arr[j];
            sumStore.push_back(sum);
        }
    }
    
    sort(sumStore.begin(), sumStore.end());
    
    return sumStore[sumStore.size() - k];
}

// Approach 2 - TC= O(n^2 log(k)) SC= O(log K)
#include<queue>
int getKthLargest(vector<int> &arr, int k)
{
// 	creating a min heap 
    priority_queue<int, vector<int>, greater<int>>pq;
    int n = arr.size();
    
    for(int i=0; i<n; i++)
    {
        int sum = 0;
        for(int j=i; j<n; j++)
        {
            sum += arr[j];
            if(pq.size() < k)
            {
                pq.push(sum);
            }
            else
            {
                if(sum > pq.top())
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();
}

// https://www.codingninjas.com/studio/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTab=0
// https://practice.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1