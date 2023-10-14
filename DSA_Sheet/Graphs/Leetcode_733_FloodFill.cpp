#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // Dimentions of the image
        int n = image.size();
        int m = image[0].size();
        
        // required data structures
        vector<vector<bool>>visited(n, vector<bool>(m));
        queue<pair<pair<int, int>, int>>q;
        vector<int>dx = {-1, 1, 0, 0};
        vector<int>dy = {0, 0, -1, 1};

        // initializations
        q.push({{sr, sc}, image[sr][sc]});
        visited[sr][sc] = true;
        image[sr][sc] = color;

        // Algo
        while(!q.empty())
        {
            pair<pair<int, int>, int>top = q.front();
            q.pop();
            int row = top.first.first;
            int col = top.first.second;
            int defColor = top.second;

            for(int dir=0; dir<4; dir++)
            {
                int newRow = row + dx[dir];
                int newCol = col + dy[dir];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && image[newRow][newCol] == defColor && !visited[newRow][newCol])
                {
                    q.push({{newRow, newCol}, image[newRow][newCol]});
                    visited[newRow][newCol] = true;
                    image[newRow][newCol] = color;
                }
            }
        }

        return image;
    }
};

// https://leetcode.com/problems/flood-fill/