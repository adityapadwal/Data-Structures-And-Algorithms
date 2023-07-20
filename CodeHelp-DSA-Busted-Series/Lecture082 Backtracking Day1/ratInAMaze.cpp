//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
    bool isSafe(int x, int y, vector<vector<int>> &m, int n, vector<vector<int>> visited)
    {
        if((x >= 0) && (x < n) && (y >= 0) && (y < n) && (visited[x][y] == 0) && (m[x][y] == 1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    void solve(vector<vector<int>> &m, int n, int x, int y, vector<string>&ans, vector<vector<int>>&visited, string path)
    {
        // base case 
        // if we reach to the destiation
        if(x == n-1 && y == n-1)
        {
            ans.push_back(path);
            return;
        }
        
        // now m[x][y] has been visited
        visited[x][y] = 1;
        
        // We have 4 cases now
        // Down, Up, Left and Right
        
        // Down
        int newx = x+1;
        int newy = y;
        if(isSafe(newx, newy, m, n, visited))
        {
            path.push_back('D');
            solve(m, n, newx, newy, ans, visited, path);
            path.pop_back();
        }
        
        // Up 
        newx = x-1;
        newy = y;
        if(isSafe(newx, newy, m, n, visited))
        {
            path.push_back('U');
            solve(m, n, newx, newy, ans, visited, path);
            path.pop_back();
        }
        
        // Left 
        newx = x;
        newy = y-1;
        if(isSafe(newx, newy, m, n, visited))
        {
            path.push_back('L');
            solve(m, n, newx, newy, ans, visited, path);
            path.pop_back();
        }
        
        // Right
        newx = x;
        newy = y+1;
        if(isSafe(newx, newy, m, n, visited))
        {
            path.push_back('R');
            solve(m, n, newx, newy, ans, visited, path);
            path.pop_back();
        }
        
        visited[x][y] = 0;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // for the ans
        vector<string>ans;
        
        // if start and end is 0 then return the ans
        if(m[0][0] == 0 || m[n-1][n-1] == 0)
        {
            return ans;
        }
        
        // Initialize srcx and srcy to 0
        int srcx = 0;
        int srcy = 0;
        
        // create a visited array and initialize it to zero
        vector<vector<int>> visited = m;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                visited[i][j] = 0;
            }
        }
        
        string path = "";
        solve(m, n, srcx, srcy, ans, visited, path);
        sort(ans.begin(), ans.end());
        return ans;
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