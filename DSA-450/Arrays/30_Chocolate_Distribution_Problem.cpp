#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(), a.begin()+n);
        
        long long mini = INT_MAX;
        
        for(long long i=0; i<n; i++)
        {
            long long smaller = a[i];
            long long bigger;
            if(i+m-1 < n)
            {
                bigger = a[i+m-1];
            }
            else
            {
                break;
            }
            mini = min(mini, bigger-smaller);
        }
    
        return mini;
    }   
};

// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1