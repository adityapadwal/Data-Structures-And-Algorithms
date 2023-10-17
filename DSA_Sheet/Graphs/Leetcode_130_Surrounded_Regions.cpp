#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void DFS(vector<vector<char>>& board, int i, int j, int n, int m)
    {
        if(i<0 || j<0 || i>=n || j>=m || board[i][j] != 'O')
        {
            return;
        }

        board[i][j] = '#';
        DFS(board, i-1, j, n, m);
        DFS(board, i+1, j, n, m);
        DFS(board, i, j-1, n, m);
        DFS(board, i, j+1, n, m);
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0)
        {
            return;
        }
        int m = board[0].size();

        // Moving over first and last col
        for(int i=0; i<n; i++)
        {
            // First column
            if(board[i][0] == 'O')
            {
                DFS(board, i, 0, n, m);
            }
            // Last column
            if(board[i][m-1] == 'O')
            {
                DFS(board, i, m-1, n, m);
            }
        }

        // Moving over first and last row
        for(int i=0; i<m; i++)
        {
            // First row
            if(board[0][i] == 'O')
            {
                DFS(board, 0, i, n, m);
            }
            // Last row
            if(board[n-1][i] == 'O')
            {
                DFS(board, n-1, i, n, m);
            }
        }

        // Traversing the board
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                if(board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
// https://leetcode.com/problems/surrounded-regions/description/