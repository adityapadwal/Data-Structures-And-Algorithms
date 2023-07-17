#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

class Solution {
    void dfs(unordered_map<int, list<int>>&adj, vector<bool> &visited, int src)
    {
        visited[src] = true;
        for(auto i : adj[src])
        {
            if(!visited[i])
            {
                dfs(adj, visited, i);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& arr) {
        int len = arr.size();
        if(len<n-1)
        {
            // The given graph is not a MST
            return -1;
        }
        unordered_map<int, list<int>>adj(n);
        for(int i=0; i<len; i++)
        {
            int u = arr[i][0];
            int v = arr[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        int ans = 0;
        for(int i=0; i<n; i++)
        if(!visited[i])
        {
            dfs(adj, visited, i);
            ans++;
        }
        return ans - 1;
    }
};

// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/