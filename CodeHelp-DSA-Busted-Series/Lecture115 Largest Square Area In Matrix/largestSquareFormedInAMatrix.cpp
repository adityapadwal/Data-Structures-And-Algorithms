//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// Method 1: Recursion(TLE)
class Solution{
private:
    int solve(vector<vector<int>>&mat, int i, int j, int &maxi)
    {
        // base case
        if(i >= mat.size() || j >= mat[0].size())
        {
            return 0;
        }
        
        int right = solve(mat, i, j+1, maxi);
        int diagonal = solve(mat, i+1, j+1, maxi);
        int down = solve(mat, i+1, j, maxi);
        
        if(mat[i][j] == 1)
        {
            int ans = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, ans);
            return ans;
        }
        else
        {
            return 0;
        }
    }
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi = 0; // for the final ans
        int i = 0; // rows 
        int j = 0; // cols
        
        solve(mat, i, j, maxi);
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends

// Method 2: Memoization
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int solve(vector<vector<int>>&mat, int i, int j, int &maxi, vector<vector<int>>&dp)
    {
        // base case
        if(i >= mat.size() || j >= mat[0].size())
        {
            return 0;
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        int right = solve(mat, i, j+1, maxi, dp);
        int diagonal = solve(mat, i+1, j+1, maxi, dp);
        int down = solve(mat, i+1, j, maxi, dp);
        
        if(mat[i][j] == 1)
        {
            dp[i][j] = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        }
        else
        {
            return dp[i][j] = 0;
        }
    }
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi = 0; // for the final ans
        int i = 0; // rows 
        int j = 0; // cols
        vector<vector<int>>dp(n, vector<int>(m+1, -1));
        
        solve(mat, i, j, maxi, dp);
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends

// Method 3: Tabulation
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int solve(vector<vector<int>>&mat, int &maxi)
    {
        int rows = mat.size();
        int cols = mat[0].size();
        
        vector<vector<int>>dp(rows+1, vector<int>(cols+1, 0));
        
        for(int i = rows-1; i>=0; i--)
        {
            for(int j = cols-1; j>=0; j--)
            {
                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];
                
                if(mat[i][j] == 1)
                {
                    dp[i][j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[0][0];
    }
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi = 0; // for the final ans
        
        solve(mat, maxi);
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends

// Space Optimization 
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int solve(vector<vector<int>>&mat, int &maxi)
    {
        int rows = mat.size();
        int cols = mat[0].size();
        
        vector<int>curr(cols+1, 0);
        vector<int>next(cols+1, 0);
        
        for(int i = rows-1; i>=0; i--)
        {
            for(int j = cols-1; j>=0; j--)
            {
                int right = curr[j+1];
                int diagonal = next[j+1];
                int down = next[j];
                
                if(mat[i][j] == 1)
                {
                    curr[j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, curr[j]);
                }
                else
                {
                    curr[j] = 0;
                }
            }
            next = curr;
        }
        return next[0];
    }
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi = 0; // for the final ans
        
        solve(mat, maxi);
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1