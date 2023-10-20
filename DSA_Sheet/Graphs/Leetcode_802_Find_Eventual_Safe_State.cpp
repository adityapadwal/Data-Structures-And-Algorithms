#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void createAdjList(vector<vector<int>>& graph, unordered_map<int, list<int>>&adjList)
    {
        // catch!!! -> create adjList with reversed directions
        for(int i=0; i<graph.size(); i++)
        {
            for(int j=0; j<graph[i].size(); j++)
            {
                adjList[graph[i][j]].push_back(i);
            }
        }
    }

    void findIndegree(unordered_map<int, list<int>>&adjList, vector<int>&indegree)
    {
        for(auto i: adjList)
        {
            for(auto j: i.second)
            {
                indegree[j]++;
            }
        }
    }

    vector<int> bfsTraversal(int v, unordered_map<int, list<int>>&adjList, vector<int>indegree, vector<int>&finalAns)
    {
        queue<int>q;
        for(int i=0; i<v; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            finalAns.push_back(front);
            for(auto neighbour: adjList[front])
            {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }

        return finalAns;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // for the final answer
        vector<int>finalAns;

        // vertices
        int v = graph.size();

        // adjacency list
        unordered_map<int, list<int>>adjList;
        createAdjList(graph, adjList);

        // indegree array
        vector<int>indegree(v);
        findIndegree(adjList, indegree);

        // bfs traversal using Kahn's algo
        finalAns = bfsTraversal(v, adjList, indegree, finalAns);
        sort(finalAns.begin(), finalAns.end());
        return finalAns;
    }
};

// https://leetcode.com/problems/find-eventual-safe-states/