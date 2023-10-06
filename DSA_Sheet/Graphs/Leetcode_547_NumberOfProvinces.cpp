#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void createAdjList(unordered_map<int, list<int>>&adjList, vector<vector<int>>& isConnected, int size)
    {
        for(int i=0; i<size; i++)
        {
            for(int j=0; j<size; j++)
            {
                if(isConnected[i][j] == 1)
                {
                    adjList[i].push_back(j);
                }
            }
        }
    }

    void dfs(int node, unordered_map<int, list<int>>&adjList, vector<bool>&visited)
    {
        visited[node] = true;
        for(auto neighbour: adjList[node])
        {
            if(!visited[neighbour])
            {
                dfs(neighbour, adjList, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        // for the final answer
        int finalAns = 0;

        // to get the number of vertices
        int size = isConnected.size();
        
        // creating adjcancy list 
        unordered_map<int, list<int>>adjList;
        createAdjList(adjList, isConnected, size);

        // visited data structure
        vector<bool>visited(size);

        // dfs traversal on all the conponents
        for(int i=0; i<size; i++)
        {
            if(!visited[i])
            {
                finalAns++;
                dfs(i, adjList, visited);
            }
        }

        // returning answer
        return finalAns;
    }
};