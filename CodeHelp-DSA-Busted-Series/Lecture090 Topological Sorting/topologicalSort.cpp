#include <bits/stdc++.h> 
#include<unordered_map>
#include<stack>
#include<vector>
#include<list>

using namespace std;

void createAdjList(vector<vector<int>>edges, unordered_map<int, list<int>>&adjList)
{
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }
}

void topoDFS(int node, unordered_map<int, list<int>>&adjList, vector<bool>&visited, stack<int>&s)
{
    visited[node] = true;
    
    for(int neighbour: adjList[node])
    {
        if(!visited[neighbour])
        {
            topoDFS(neighbour, adjList, visited, s);
        }
    }

    s.push(node);
}

void finalAns(stack<int>&s, vector<int>&ans)
{
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>>adjList;
    createAdjList(edges, adjList);

    vector<bool>visited(v);

    stack<int>s;

    vector<int>ans;

    for(int i=0; i<v; i++)
    {
        if(!visited[i])
        {
            topoDFS(i, adjList, visited, s);
        }
    }

    finalAns(s, ans);
    return ans;
}

// https://www.codingninjas.com/codestudio/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar