#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // dimensions of mat
        int n = mat.size();
        int m = mat[0].size();

        // required data structures
        vector<vector<int>>dist(n, vector<int>(m, 0));
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>>q;

        // Traversing mat
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j] == 0)
                {
                    visited[i][j] = true;
                    q.push({{i, j}, 0});
                }
            }
        }

        vector<int>dx = {-1, 0, 1, 0};
        vector<int>dy = {0, 1, 0, -1};

        while(!q.empty())
        {
            pair<pair<int, int>, int>top = q.front();
            q.pop();
            
            int row = top.first.first;
            int col = top.first.second;
            int steps = top.second;

            dist[row][col] = steps;

            for(int i=0; i<4; i++)
            {
                int newRow = row + dx[i];
                int newCol = col + dy[i];

                if((newRow >= 0) && (newRow < n) && (newCol >= 0) && (newCol < m) && (!visited[newRow][newCol]))
                {
                    visited[newRow][newCol] = true;
                    q.push({{newRow, newCol}, steps+1});
                }
            }
        }
        
        return dist;
    }
};

// https://leetcode.com/problems/01-matrix/description/