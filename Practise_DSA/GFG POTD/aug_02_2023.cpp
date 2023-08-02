//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isPossible(int x, int y, int rows, int cols, vector<vector<int>>&arr)
    {
        if(x>=0 && x<rows && y>=0 && y<cols && arr[x][y] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    int solve(queue<pair<pair<int, int>, int>>&q, vector<vector<int>>&arr, int rows, int cols, int src, int dest)
    {
        q.push({{0, 0}, 0});
        
        while(!q.empty())
        {
            pair<pair<int, int>, int> element = q.front();
            q.pop();
            int x = element.first.first;
            int y = element.first.second;
            int res = element.second;
            
            if(x == src && y == dest)
            {
                return res;
            }
            
            // check right
            if(isPossible(x, y+1, rows, cols, arr))
            {
                q.push({{x, y+1}, res+1});
                arr[x][y+1] = 0; // visited
            }
            
            // check left
            if(isPossible(x, y-1, rows, cols, arr))
            {
                q.push({{x, y-1}, res+1});
                arr[x][y-1] = 0; // visited
            }
            
            // check up
            if(isPossible(x-1, y, rows, cols, arr))
            {
                q.push({{x-1, y}, res+1});
                arr[x-1][y] = 0; // visited
            }
            
            // check down
            if(isPossible(x+1, y, rows, cols, arr))
            {
                q.push({{x+1, y}, res+1});
                arr[x+1][y] = 0; // visited
            }
        }
        
        if(q.empty())
        {
            return -1;
        }
    }
    
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if(A[X][Y] == 0 || A[0][0] == 0)
        {
            return -1;
        }
        
        queue<pair<pair<int, int>, int>>q;
        
        int ans = solve(q, A, N, M, X, Y);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1