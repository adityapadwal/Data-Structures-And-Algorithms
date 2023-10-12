#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

void createList(vector<vector<int>>&edges, unordered_map<int, list<int>>&adj, int e)
{
    for(int i=0; i<e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int node, int parent, int &timer, unordered_map<int, list<int>>&adj, unordered_map<int, bool>&visited, vector<int>&disc, vector<int>&low, vector<vector<int>>&result)
{
    visited[node] = true;
    low[node] = disc[node] = timer;
    timer++;

    for(auto neighbour: adj[node])
    {
        if(parent == neighbour)
        {
            // ignore 
            continue;
        }

        if(!visited[neighbour])
        {
            // dfs call to the neighbour
            dfs(neighbour, node, timer, adj, visited, disc, low, result);

            // after returning, do the following two things, 
            // 1. update low of node, (Why? because the chlid might have a back edge which will lead to updating the cheild's low)
            low[node] = min(low[node], low[neighbour]);
            // 2. check for the bridge condition
            if(low[neighbour] > disc[node]) // imp
            {
                vector<int>ans;
                ans.push_back(node);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
        }
        else
        {
            // visited[neighbour] == true && neighbour != parent
            // back edge is present
            low[node] = min(low[node], disc[neighbour]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // adjacency list
    unordered_map<int, list<int>> adj;
    createList(edges, adj, e);

    // parent tracker
    int parent;
    // timer
    int timer;
    // discovery data structure
    vector<int> disc(v);
    // low (earliest possible time to reach the node) data structure
    vector<int> low(v);
    // visited data structure
    unordered_map<int, bool> visited(v);
    // for the final ans
    vector<vector<int>>result;

    // initializations
    timer = 0;
    parent = -1;
    for(int i=0; i<v; i++)
    {
        disc[i] = -1;
        low[i] = -1;
        visited[i] = false;
    }

    // dfs call 
    for(int i=0; i<v; i++)
    {
        if(!visited[i])
        {
            dfs(i, parent, timer, adj, visited, disc, low, result);
        }
    }

    // return final answer
    return result;
}

// Rev
// https://www.codingninjas.com/codestudio/problems/bridges-in-graph_893026?leftPanelTab=0
