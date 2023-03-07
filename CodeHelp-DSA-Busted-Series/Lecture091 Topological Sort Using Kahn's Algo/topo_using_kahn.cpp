#include<iostream>
#include <unordered_map>
#include<list>
#include<queue>
#include<vector>
#include <bits/stdc++.h> 

using namespace std;

void createAdjList(vector<vector<int>> &edges, unordered_map<int, list<int>>&adjList)
{
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }
}

void findIndegree(vector<int>&indegree, unordered_map<int, list<int>>&adjList)
{
    for(auto i: adjList)
    {
        for(auto j: i.second)
        {
            indegree[j]++;
        }
    }
}

void bfsTraversal(unordered_map<int, list<int>>&adjList, vector<int>&indegree, queue<int>&q, vector<int>&finalAns, int v)
{
    for(int i=0; i<v; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        finalAns.push_back(node);

        for(auto neighbour: adjList[node])
        {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Adjacency List
    unordered_map<int, list<int>>adjList;
    // Creating Adj List
    createAdjList(edges, adjList);

    // vector for storing the indegree
    vector<int>indegree(v);
    // Finding indegree
    findIndegree(indegree, adjList);

    // vector for storing the final ans
    vector<int>finalAns;

    // queue for storing elements with indegree 0
    queue<int>q;

    // BFS traversal
    bfsTraversal(adjList, indegree, q, finalAns, v);

    return finalAns;
}

// https://www.codingninjas.com/codestudio/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar