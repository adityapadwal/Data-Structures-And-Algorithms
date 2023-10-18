//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void DFS(int row, int col, vector<vector<int>>&grid, vector<vector<bool>>&visited, vector<pair<int, int>>&component, int firstRow, int firstCol, int n, int m)
    {
        visited[row][col] = true;
        component.push_back({row-firstRow, col-firstCol});
        
        // check in all four directions
        vector<int>dx = {-1, 0, 1, 0};
        vector<int>dy = {0, 1, 0, -1};
        
        for(int i=0; i<4; i++)
        {
            int newRow = row + dx[i];
            int newCol = col + dy[i];
            
            if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && !visited[newRow][newCol] && grid[newRow][newCol]==1)
            {
                DFS(newRow, newCol, grid, visited, component, firstRow, firstCol, n, m);
            }
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        // dimensions of grid
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        set< vector< pair<int, int> > >st;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!visited[i][j] && grid[i][j]==1)
                {
                    vector<pair<int, int>>component;
                    DFS(i, j, grid, visited, component, i, j, n, m);
                    st.insert(component);
                }
            }
        }
        
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1