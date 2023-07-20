//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isPossible(vector<vector<int>>&arr, int n, int src, int dest, vector<vector<int>>visited)
    {
        if((src >= 0) && (src<n) && (dest >= 0) && (dest < n) && (visited[src][dest] == 0) && arr[src][dest] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    void solve(vector<vector<int>>&arr, int n, int src, int dest, vector<vector<int>>&visited, string &tempAns, vector<string>&finalAns)
    {
        if(src == n-1 && dest == n-1)
        {
            // we have reached the destination successfully
            finalAns.push_back(tempAns);
            return;
        }
        
        // marking the current position as visited
        visited[src][dest] = 1;
        
        // we have 4 options => down, up, left, right
        
        // dowm
        if(isPossible(arr, n, src+1, dest, visited))
        {
            tempAns.push_back('D');
            solve(arr, n, src+1, dest, visited, tempAns, finalAns);
            tempAns.pop_back();
        }
        
        // up
        if(isPossible(arr, n, src-1, dest, visited))
        {
            tempAns.push_back('U');
            solve(arr, n, src-1, dest, visited, tempAns, finalAns);
            tempAns.pop_back();
        }
        
        // left
        if(isPossible(arr, n, src, dest-1, visited))
        {
            tempAns.push_back('L');
            solve(arr, n, src, dest-1, visited, tempAns, finalAns);
            tempAns.pop_back();
        }
        
        // right
        if(isPossible(arr, n, src, dest+1, visited))
        {
            tempAns.push_back('R');
            solve(arr, n, src, dest+1, visited, tempAns, finalAns);
            tempAns.pop_back();
        }
        
        visited[src][dest] = 0;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // for the final answer
        vector<string>finalAns;
        
        if(m[0][0] == 0 || m[n-1][n-1] == 0)
        {
            return finalAns;
        }
        
        // initial values of source and destination are zero
        int src = 0;
        int dest = 0;
        
        // creating a visited array of size n*n and initializing it with zero
        vector<vector<int>>visited(n, vector<int>(n, 0));
        
        // for the temp ans;
        string tempAns = "";
        
        solve(m, n, src, dest, visited, tempAns, finalAns);
        
        sort(finalAns.begin(), finalAns.end());
        return finalAns;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1