#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void DFS(int i, int j, int n, int m, vector<vector<int>>&grid)
    {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=1)
        {
            return;
        }
        
        grid[i][j] = 2;

        DFS(i-1, j, n, m, grid);
        DFS(i+1, j, n, m, grid);
        DFS(i, j-1, n, m, grid);
        DFS(i, j+1, n, m, grid);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        // Dimensions of grid
        int n = grid.size(); // rows
        int m = grid[0].size(); // cols

        // Traversing the boundary
        // Traversing Cols
        for(int i=0; i<n; i++)
        {
            // traversing first col
            if(grid[i][0] == 1)
            {
                DFS(i, 0, n, m, grid);
            }
            // traversing last col
            if(grid[i][m-1] == 1)
            {
                DFS(i, m-1, n, m, grid);
            }
        }
        // Traversing rows
        for(int i=0; i<m; i++)
        {
            // traversing first row
            if(grid[0][i] == 1)
            {
                DFS(0, i, n, m, grid);
            }
            //traversing last row
            if(grid[n-1][i] == 1)
            {
                DFS(n-1, i, n, m, grid);
            }
        }

        // Traversing the array
        int ans = 0; 
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};

// https://leetcode.com/problems/number-of-enclaves/