#include<bits/stdc++.h>
using namespace std;

void createAdjList(vector<vector<int>>edges, int m, unordered_map<int, set<int>>&adjList)
{
    for(int i=0; i<m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

bool dfs(int node, int parent, unordered_map<int, set<int>>&adjList, unordered_map<int, bool>&visited)
{
    visited[node] = true;

    for(auto neighbour: adjList[node])
    {
        if(visited[neighbour] == true && neighbour != parent)
        {
            // cycle present
            return true;
        }
        else if(!visited[neighbour])
        {
            bool findCycle = dfs(neighbour, node, adjList, visited);
            if(findCycle == true)
            {
                return true;
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // cycle detection using DFS

    // adjacency list
    unordered_map<int, set<int>>adjList;
    createAdjList(edges, m, adjList);

    // visited data structure
    unordered_map<int, bool>visited;

    // for handling disconnected components
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            bool ans = dfs(i, -1, adjList, visited);
            if(ans == true)
            {
                return "Yes";
            }
        }
    }
    return "No";
}

// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670?leftPanelTab=0