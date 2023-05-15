//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

// Method 1: Recursion (TLE)
class Solution{
    private:
    int solve(int n)
    {
        // base case 
        if(n == 0)
        {
            return 0;
        }
        
        int ans = n;
        for(int i=1; i<n; i++)
        {
            if(i*i <= n)
            {
                ans = min(ans, 1+solve(n - i*i));
            }
        }
        return ans;
    }
	public:
	int MinSquares(int n)
	{
	    int finalAns = solve(n);
	    return finalAns;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends

//{ Driver Code Starts
//Initial Template for C++

// Method 2: Memoization 
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
    int solve(int n, vector<int>&dp)
    {
        // base case 
        if(n == 0)
        {
            return 0;
        }
        if(dp[n] != -1)
        {
            return dp[n];
        }
        
        int ans = n;
        for(int i=1; i<n; i++)
        {
            if(i*i <= n)
            {
                ans = min(ans, 1+solve((n - i*i), dp));
            }
        }
        dp[n] = ans;
        return dp[n];
    }
    
	public:
	int MinSquares(int n)
	{
	    vector<int>dp(n+1, -1);
	    int finalAns = solve(n, dp);
	    return finalAns;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends

// Method 3: Tabulation 
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
    int solve(int n)
    {
        vector<int>dp(n+1, INT_MAX);
        
        dp[0] = 0;
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(j*j <= n)
                {
                    if(i-(j*j) >= 0)
                    {
                        dp[i] = min(dp[i], 1 + dp[ i-(j*j) ]);
                    }
                }
            }
        }
        return dp[n];
    }
    
	public:
	int MinSquares(int n)
	{
	    int finalAns = solve(n);
	    return finalAns;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends