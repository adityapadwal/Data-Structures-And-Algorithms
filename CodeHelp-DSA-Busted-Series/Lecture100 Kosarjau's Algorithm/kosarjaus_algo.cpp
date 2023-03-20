#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
using namespace std;

#include <bits/stdc++.h>
void dfs(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adjlist)
{
    visited[node] = true;
    for (auto nbr : adjlist[node])
    {
        if (!visited[nbr])
        {
            dfs(nbr, visited, s, adjlist);
        }
    }
    // topological logic
    s.push(node);
}

void transdfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjlist)
{
    visited[node] = true;
    for (auto nbr : adjlist[node])
    {
        if (!visited[nbr])
        {
            transdfs(nbr, visited, adjlist);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    // adj list
    unordered_map<int, list<int>> adjlist;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjlist[u].push_back(v);
    }
    // step 1: sort all node
    // topological sort
    stack<int> s;
    unordered_map<int, bool> visited;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, s, adjlist);
        }
    }

    // step 2:
    // create transpose
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
        for (auto nbr : adjlist[i])
        {
            transpose[nbr].push_back(i);
        }
    }
    // step 3:
    // call dfs using above ordering (transpose ordering)
    int count = 0;
    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        if (!visited[top])
        {
            count++;
            transdfs(top, visited, transpose);
        }
    }
    return count;
}

// *************************** My Code, not working******************************
// void topo_dfs(int node, unordered_map<int, list<int>>&adj, unordered_map<int, bool>&visited, stack<int>&st)
// {
// 	visited[node] = true;
// 	for(auto neighbour: adj[node])
// 	{
// 		if(!visited[neighbour])
// 		{
// 			topo_dfs(neighbour, adj, visited, st);
// 		}
// 	}
// 	st.push(node);
// }

// void dfs(int top, unordered_map<int, list<int>>&transpose, unordered_map<int, bool>&vis)
// {
// 	vis[top] = true;
// 	for(auto neighbour: transpose[top])
// 	{
// 		if(!vis[neighbour])
// 		{
// 			dfs(neighbour, transpose, vis);
// 		}
// 	}
// }

// // Main Function
// int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
// {
// 	// adjacency list
// 	unordered_map<int, list<int>>adj;
// 	for(int i=0; i<edges.size(); i++)
// 	{
// 		int u = edges[i][0];
// 		int v = edges[i][1];

// 		adj[u].push_back(v);
// 	}

// 	// ***Step 1: Topological sort***
// 	stack<int>st;
// 	unordered_map<int, bool>visited;
// 	for(int i=0; i<v; i++)
// 	{
// 		if(!visited[i])
// 		{
// 			topo_dfs(i, adj, visited, st);
// 		}
// 	}

// 	// ***Step 2: Transpose of the graph***
// 	unordered_map<int, list<int>>transpose;
// 	for(int i=0; i<v; i++)
// 	{
// 		for(auto neighbour: adj[i])
// 		{
// 			transpose[neighbour].push_back(i);
// 		}
// 	}

// 	// ***Step 3: DFS traversal of the graph***

// 	// for the final ans
// 	int result = 0;
// 	// new vis data structure
// 	unordered_map<int, bool>vis;
// 	// dfs traversal
// 	while(!st.empty())
// 	{
// 		int top = st.top();
// 		st.pop();
// 		if(!vis[top]);
// 		{
// 			result++;
// 			dfs(top, transpose, vis);
// 		}
// 	}

// 	// returning the final answer
// 	return result;
// }

// Rev
// https://www.codingninjas.com/codestudio/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151?leftPanelTab=0