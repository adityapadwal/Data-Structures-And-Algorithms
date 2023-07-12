#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int a;
        int b;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    for(int k=0; k<n; k++)
                    {
                        if(matrix[i][k] != 0)
                        {
                            matrix[i][k] = -9999;
                        }
                    }
                }
            }
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    for(int k=0; k<m; k++)
                    {
                        if(matrix[k][j] != 0)
                        {
                            matrix[k][j] = -9999;
                        }
                    }
                }
            }
        }

        // set all -9999 in matrix to zero
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] == -9999)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
}; 

// https://leetcode.com/problems/set-matrix-zeroes/