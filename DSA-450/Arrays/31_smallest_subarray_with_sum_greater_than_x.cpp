//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    
    int smallestSubWithSum(int arr[], int n, int x)
    {
        // for the final answer
        int finalAns = INT_MAX;
        
        for(int i=0; i<n; i++)
        {
            int currSum = 0;
            int cnt = 0;
            for(int j=i; j<n; j++)
            {
                currSum +=arr[j];
                cnt++;
                if(currSum > x)
                {
                    finalAns = min(finalAns, cnt);
                    break;
                }
            }
        }
        
        if(finalAns == INT_MAX)
        {
            return 0;
        }
        else
        {
            return finalAns;
        }
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1