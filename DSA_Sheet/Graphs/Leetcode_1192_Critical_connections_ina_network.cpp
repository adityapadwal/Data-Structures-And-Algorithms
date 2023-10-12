#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void createList(vector<vector<int>>&connections, unordered_map<int, list<int>>&adjList)
    {
        int size = connections.size();
        for(int i=0; i<size; i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void dfs(int node, int parent, unordered_map<int, list<int>>&adjList, int &timer, vector<int>&disc, vector<int>&low, vector<bool>&visited, vector<vector<int>>&result)
    {
        visited[node] = true;
        low[node] = timer;
        disc[node] = timer;
        timer++;

        for(auto neighbour: adjList[node])
        {
            if(neighbour == parent)
            {
                // ignore
                continue;
            }

            if(!visited[neighbour])
            {
                dfs(neighbour, node, adjList, timer, disc, low, visited, result);

                // Backtracking
                // 1. update low
                low[node] = min(low[node], low[neighbour]);
                // 2. check for the bridge
                if(low[neighbour] > disc[node])
                {
                    // bridge present
                    vector<int>bridge;
                    bridge.push_back(node);
                    bridge.push_back(neighbour);
                    result.push_back(bridge);
                }
            }

            if(visited[neighbour] == true && neighbour != parent)
            {
                // back edge present
                low[node] = min(low[node], disc[neighbour]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // creating the adjacency list
        unordered_map<int, list<int>>adjList;
        createList(connections, adjList);

        // required data structures
        int timer = 0;
        int parent = -1;
        vector<int>disc(n, -1);
        vector<int>low(n, -1);
        vector<bool>visited(n);

        // answer
        vector<vector<int>>result;

        // dfs traversal
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                dfs(i, parent, adjList, timer, disc, low, visited, result);
            }
        }

        return result;
    }
};