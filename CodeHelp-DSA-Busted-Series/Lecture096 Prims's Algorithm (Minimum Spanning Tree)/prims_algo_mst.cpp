#include <bits/stdc++.h>
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Adjacency List
    unordered_map<int, list<pair<int, int>>>adj;
    for(int i=0; i<g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int weight = g[i].second;

        adj[u].push_back(make_pair(v, weight));
        adj[v].push_back(make_pair(u, weight));
    }

    // key data structure 
    vector<int>key(n+1);

    // mst data structure
    vector<bool>mst(n+1);

    // parent data structure
    vector<int>parent(n+1);

    // initializations
    for(int i=0; i<=n; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    // Applying Prim's Algo
    key[1] = 0;
    parent[1] = -1;

    for(int i=0; i<n; i++)
    {
        // Step 1: Finding minimum element from the key data structure (finding u)
        int mini = INT_MAX;
        int u;

        for(int v=1; v<=n; v++)
        {
            if(mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        // Step 2: Make mst[u] = true
        mst[u] = true;

        // Step 3: Process in adjacency list
        for(auto it: adj[u])
        {
            int v = it.first;
            int w = it.second;

            if(mst[v] == false && w < key[v])
            {
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    // for the final answer 
    vector<pair<pair<int, int>, int>>result;
    for(int i=2; i<=n; i++)
    {
        result.push_back({{parent[i], i}, key[i]});
    }
    return result;
}

// Rev
// https://www.codingninjas.com/codestudio/problems/prim-s-mst_1095633?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1