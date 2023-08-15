//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        int oneCount = 0;
        int zeroCount = 0;
        int ans = 0;
        
        for(int i=0; i<n; i++)
        {
            int digit = a[i];
            if(digit == 0)
            {
                zeroCount++;
            }
            else
            {
                // digit == 1
                oneCount++;
                zeroCount--;
            }
            ans = max(zeroCount, ans);
            if(zeroCount < 0)
            {
                zeroCount = 0;
            }
        }
        
        int finalAns = ans+oneCount;
        return finalAns;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/flip-bits0240/1