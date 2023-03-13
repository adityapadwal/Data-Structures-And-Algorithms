#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

void dfs(int node, int parent, vector<int>&disc, vector<int>&low, int &timer, unordered_map<int, bool>&visited, unordered_map<int,list<int>>&adj, vector<vector<int>>&result)
{
    visited[node] = true;
    disc[node] = low[node] = timer;
    timer++;

    for(auto neighbour: adj[node])
    {
        if(neighbour == parent)
        {
            continue;
        }
        if(!visited[neighbour])
        {
            dfs(neighbour, node, disc, low, timer, visited, adj, result);
            
            // while going back 
            low[node] = min(low[node], low[neighbour]);
            // check if the edge is a bridge or not
            if(low[neighbour] > disc[node])
            {
                // the edge is a bridge
                vector<int>ans;
                ans.push_back(node);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
        }
        else
        {
            // visited[node] == true and node != parent
            // back edge condition
            // therefore update low
            low[node] = min(low[node], disc[neighbour]);
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // adjacency list 
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int>disc(v);
    vector<int>low(v);
    int parent = -1;
    unordered_map<int, bool>visited;
    vector<vector<int>>result;

    for(int i=0; i<v; i++)
    {
        disc[i] = -1;
        low[i] = -1;
        // visited[i] = false;
    }

    // dfs
    for(int i=0; i<v; i++)
    {
        if(!visited[i])
        {
            dfs(i, parent, disc, low, timer, visited, adj, result);
        }
    }

    return result;
}

// https://www.codingninjas.com/codestudio/problems/bridges-in-graph_893026?leftPanelTab=1