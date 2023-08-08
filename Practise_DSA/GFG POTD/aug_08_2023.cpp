//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    // Brute force approach
    // TC = O(N*N)
    // TLE
    int countFractions(int n, int numerator[], int denominator[])
    {
        vector<double>division;
        
        for(int i=0; i<n; i++)
        {
            double first = double(numerator[i]);
            double second = double(denominator[i]);
            
            double ans = first/second;
            division.push_back(ans);
        }
        
        int count = 0;
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(division[i] + division[j] == 1)
                {
                    count++;
                }
            }
        }
        
        return count;
    }

    // Working approach
    // TC = O(N)
    // SC = O(N)
    int countFractions(int n, int numerator[], int denominator[])
    {
        map<pair<int, int>, int>mp;
        int count = 0;
        
        for(int i=0; i<n; i++)
        {
            int gcd = __gcd(numerator[i], denominator[i]);
            int x = numerator[i]/gcd;
            int y = denominator[i]/gcd;
            
            count = count + mp[{y-x, y}];
            
            mp[{x, y}]++;
        }
        
        return count;
    }
        
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends