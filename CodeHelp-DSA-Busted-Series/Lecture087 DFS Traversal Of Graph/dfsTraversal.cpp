#include<iostream>
#include <bits/stdc++.h> 
#include<unordered_map>
#include<vector>
#include<list>
#include<set>
#include<queue>

using namespace std;

void dfs(int node, unordered_map<int, set<int>>&adjList, unordered_map<int, bool>&visited, vector<int>&component)
{
    component.push_back(node);
    visited[node] = true;

    for(auto i: adjList[node])
    {
        if(!visited[i])
        {
            dfs(i, adjList, visited, component);
        }
    }
}

void findAdjList(unordered_map<int, set<int>>&adjList, vector<vector<int>> edges)
{
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // for adjacency list 
    unordered_map<int, set<int>>adjList;
    // for visited array
    unordered_map<int, bool>visited;
    // for the final answer
    vector<vector<int>>ans;

    // finding the adjacency list
    findAdjList(adjList, edges);

    // for all nodes, call dfs if not visited
    for(int i=0; i<V; i++)
    {
        if(!visited[i])
        {
            vector<int>component;
            dfs(i, adjList, visited, component);
            ans.push_back(component);
        }
    }
    return ans;
}

// https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar