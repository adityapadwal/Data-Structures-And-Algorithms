#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

void createAdjList(unordered_map<int, list<int>>&adjList, vector<vector<int>> &edges, int m)
{
    for(int i=0; i<m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

bool isCyclicDFS(int node, int parent, unordered_map<int, bool>&visited, unordered_map<int, list<int>>&adjList)
{
    visited[node] = true;

    for(auto neighbour: adjList[node])
    {
        if(!visited[neighbour])
        {
            bool cycleDetected = isCyclicDFS(neighbour, node, visited, adjList);
            if(cycleDetected == true)
            {
                return true;
            }
        }
        else if(neighbour != parent)
        {
            // condition for cycle => visited[neighbour] == true && neighbour != parent 
            // cycle detected
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // creating an adjacency list 
    unordered_map<int, list<int>>adjList;
    createAdjList(adjList, edges, m);

    // creating a visited data structure
    unordered_map<int, bool>visited;

    // traversing all the nodes n, to handle disconnected components
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            bool ans = isCyclicDFS(i, -1, visited, adjList);
            if(ans == true)
            {
                return "Yes";
            }
        }
    }
    return "No";
}

// https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670?leftPanelTab=0