#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int row, int col, vector<vector<int>>&grid, int n)
    {
        if(row >= 0 && row < n && col >= 0 && col < n && grid[row][col] == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // Using Dijikstra's Algo
        
        // Get the grid size
        int n = grid.size();

        // Check if answer is impossible
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0)
        {
            return -1;
        }

        // priority queue (min-heap) (can also be done using set)
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        // dist array
        vector<vector<int>>dist(n, vector<int>(n, INT_MAX));

        dist[0][0] = 1;
        pq.push({0, 0, 1});

        vector<int>dx = {-1, -1, 0, 1, 1, 1, 0, -1};
        vector<int>dy = {0, 1, 1, 1, 0, -1, -1, -1};

        while(!pq.empty())
        {
            vector<int>top = pq.top();
            pq.pop();
            int row = top[0];
            int col = top[1];
            int oldDist = top[2];

            for(int i=0; i<8; i++)
            {
                int newRow = row + dx[i];
                int newCol = col + dy[i];

                if(isSafe(newRow, newCol, grid, n) && dist[newRow][newCol] > oldDist+1)
                {
                    dist[newRow][newCol] = oldDist + 1;
                    pq.push({newRow, newCol, dist[newRow][newCol]});
                }
            }
        }

        if(dist[n-1][n-1] == INT_MAX)
        {
            return -1;
        }
        else
        {
            return dist[n-1][n-1];
        }
    }
};

// https://leetcode.com/problems/shortest-path-in-binary-matrix/