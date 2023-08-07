//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
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

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1