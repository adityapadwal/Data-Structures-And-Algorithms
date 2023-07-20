#include <bits/stdc++.h> 
#include<iostream>
using namespace std;

bool isSafe(vector<vector<int>>&board, int row, int col, int val)
{
    for(int i=0; i<9; i++)
    {
        // check for row 
        if(board[row][i] == val)
        {
            return false;
        }
        
        // check for col 
        if(board[i][col] == val)
        {
            return false;
        }
        
        // check for the 3*3 matrix 
        if(board[3*(row/3)+i/3][3*(col/3)+i%3] == val)
        {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>>&board)
{
    for(int row=0; row<9; row++)
    {
        for(int col=0; col<9; col++)
        {
            // check for empty cell
            if(board[row][col] == 0)
            {
                for(int val=1; val<=9; val++)
                {
                    if(isSafe(board, row, col, val))
                    {
                        board[row][col] = val;
                        
                        // aage solution possible hai?
                        bool furtherSolutionPossible = solve(board);
                        if(furtherSolutionPossible)
                        {
                            return true;
                        }
                        else
                        {
                            //backtracking
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku);
}

// https://www.codingninjas.com/studio/problems/sudoku-solver_699919