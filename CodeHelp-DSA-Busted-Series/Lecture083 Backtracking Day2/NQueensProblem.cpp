#include <bits/stdc++.h> 
#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int x, int y, vector<vector<int>> visited, vector<vector<int>> &arr, int n)
{
    if((x >= 0) && (x < n) && (y >= 0) && (y < n) && (visited[x][y] == 0) && (arr[x][y] == 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(int x, int y, vector < vector < int >> & arr, int n, vector<string>&ans, vector < vector < int >> &visited, string &path)
{
//     base condition 
//     if we have reached the destination 
       if(x == n-1 && y == n-1)
       {
           ans.push_back(path);
           return;
       }
    
//     mark the visited location 
    visited[x][y] = 1;
    
//     We have 4 options 
//     Down, Up, Left and Right 
    
//     Down 
    int newx = x+1;
    int newy = y;
    if(isSafe(newx, newy, visited, arr, n))
    {
        path.push_back('D');
        solve(newx, newy, arr, n, ans, visited, path);
        path.pop_back();
    }
    
//     Up 
    newx = x-1; 
    newy = y;
    if(isSafe(newx, newy, visited, arr, n))
    {
        path.push_back('U');
        solve(newx, newy, arr, n, ans, visited, path);
        path.pop_back();
    }
    
//     Left 
    newx = x;
    newy = y-1;
    if(isSafe(newx, newy, visited, arr, n))
    {
        path.push_back('L');
        solve(newx, newy, arr, n, ans, visited, path);
        path.pop_back();
    }
    
//     Right 
    newx = x;
    newy = y+1;
    if(isSafe(newx, newy, visited, arr, n))
    {
        path.push_back('R');
        solve(newx, newy, arr, n, ans, visited, path);
        path.pop_back();
    }
    
    visited[x][y] = 0;
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
//     For the ans
    vector<string>ans;
    
//     Check for the base conditions
    if(arr[0][0] == 0 || arr[n-1][n-1] == 0)
    {
        return ans;
    }
    
//     Visited array 
    vector < vector < int >> visited = arr;
//     initializing the visited array with 0
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            visited[i][j] = 0;
        }
    }
    
//     srcx and srcy to 0
    int srcx = 0;
    int srcy = 0;
    
    string path = "";
    solve(srcx, srcy, arr, n, ans, visited, path);
    sort(ans.begin(), ans.end());
    return ans;
}