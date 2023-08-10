//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        
        //Recursion solution...
        
        // if(x==0 || y==0)
        // {
        //     return 0;
        // }
        // if(s1[x-1]==s2[y-1])
        // {
        //     return 1+lcs(x-1,y-1,s1,s2);
        // }
        // else
        // {
        //     return max(lcs(x-1,y,s1,s2),lcs(x,y-1,s1,s2));
        // }
        
        // memo solution...
        
        // int memo[x+1][y+1];
        // memset(memo,-1,sizeof(memo));
        //  vector<vector<int>>memo(x+1,vector<int>(y+1,-1));
        // if(memo[x][y]!=-1)
        // return memo[x][y];
        // if(x==0 || y==0)
        // memo[x][y]=0;
        // else
        // {
        //     if(s1[x-1]==s2[y-1])
        //     memo[x][y]=1+lcs(x-1,y-1,s1,s2);
        //     else memo[x][y]=max(lcs(x-1,y,s1,s2),lcs(x,y-1,s1,s2));
        // }
        // return memo[x][y];
        
        //both gives TLE....
        
        //tabulation sol
        
      vector<vector<int>>dp(x+1,vector<int>(y+1,0));
        // int dp[x+1][y+1];
        // memset(dp,-1,sizeof(dp));
        for(int j=0;j<=y;j++)
        dp[0][j]=0;
        for(int i=0;i<=x;i++)
        dp[i][0]=0;
        
        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=y;j++)
            {
                if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else 
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
         return dp[x][y];
      
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1