#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int row, int col, vector<vector<int>>& heights, int n, int m)
    {
        if(row>=0 && row<n && col>=0 && col<m)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));

        dist[0][0] = 0;
        pq.push({0, 0, 0});

        vector<int>dx = {-1, 0, 1, 0};
        vector<int>dy = {0, 1, 0, -1};

        while(!pq.empty())
        {
            vector<int>top = pq.top();
            pq.pop();
            int diff = top[0];
            int row = top[1];
            int col = top[2];

            if(row == n-1 && col == m-1)
            {
                return diff;
            }

            for(int i=0; i<4; i++)
            {
                int newRow = row + dx[i];
                int newCol = col + dy[i];

                if(isSafe(newRow, newCol, heights, n, m))
                {
                    int newDiff = max(diff, abs(heights[row][col] - heights[newRow][newCol]));
                    if(newDiff < dist[newRow][newCol])
                    {
                        dist[newRow][newCol] = newDiff;
                        pq.push({newDiff, newRow, newCol});
                    }
                }
            }
        }
        return 0;
    }
};

// https://leetcode.com/problems/path-with-minimum-effort/