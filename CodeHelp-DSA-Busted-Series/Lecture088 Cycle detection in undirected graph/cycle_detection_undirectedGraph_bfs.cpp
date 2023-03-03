#include<iostream>
#include<vector>
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

bool isCyclicBFS(int src, unordered_map<int, bool>&visited, unordered_map<int, list<int>> adjList, unordered_map<int, int> &parent)
{
    parent[src] = -1;
    visited[src] = true;
    
    // creating a queue
    queue<int>q;

    q.push(src);
    
    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        for(auto neighbour: adjList[front])
        {
            // checking the condition if the cycle is present or not
            if(visited[neighbour] == true && neighbour != parent[front])
            {
                // cycle is present
                return true;
            }

            else if(!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
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
    
    // creating the parent data structure
    unordered_map<int, int>parent;

    // traversing all the nodes n, to handle disconnected components
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            bool ans = isCyclicBFS(i, visited, adjList, parent);
            if(ans == true)
            {
                return "Yes";
            }
        }
    }

    return "No";
}


// https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670?leftPanelTab=0