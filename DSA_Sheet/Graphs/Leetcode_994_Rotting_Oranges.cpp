#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // for the final answer
        int timer = 0;

        // finding dimensions of the given grid
        int n = grid.size(); // rows
        int m = grid[0].size(); // cols

        // Required data structures
        vector<vector<bool>> visited(n, vector<bool>(m));
        queue<pair<int, int>>q;

        // Adding rotten oranges in the queue
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push(make_pair(i, j));
                    visited[i][j] = true;
                }
            }
        }

        // Define 4 possible directions: up, down, left, right
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        // processing the queue
        while(!q.empty())
        {
            int size = q.size();
            bool changed = false;
            for(int i=0; i<size; i++)
            {
                pair<int, int> top = q.front();
                q.pop();
                int row = top.first;
                int col = top.second;

                for (int dir = 0; dir < 4; dir++) 
                {
                    int newRow = row + dx[dir];
                    int newCol = col + dy[dir];
                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !visited[newRow][newCol] && grid[newRow][newCol] == 1) 
                    {
                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol});
                        visited[newRow][newCol] = true;
                        changed = true;
                    }
                }
            }
            if(changed == true)
            {
                timer++;
            }
        }

        // Check if any fresh oranges are left in the grid
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return timer;
    }
};

// https://leetcode.com/problems/rotting-oranges/