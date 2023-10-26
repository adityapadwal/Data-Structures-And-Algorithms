#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void createAdjList(unordered_map<int, list<pair<int, int>>>&adjList, vector<vector<int>>&flights)
    {
        int size = flights.size();
        for(int i=0; i<size; i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];

            adjList[u].push_back({v, w});
        }
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, list<pair<int, int>>>adjList;
        createAdjList(adjList, flights);

        vector<int>dist(n, INT_MAX);

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({0, 0, src});

        while(!pq.empty())
        {
            vector<int>topVector = pq.top();
            pq.pop();

            int stops = topVector[0];
            int nodeDistance = topVector[1];
            int topNode = topVector[2];

            if(stops >= k+1)
            {
                continue;
            }

            for(auto neighbour: adjList[topNode])
            {
                if(nodeDistance + neighbour.second < dist[neighbour.first])
                {
                    dist[neighbour.first] = nodeDistance + neighbour.second;
                    pq.push({stops+1, dist[neighbour.first], neighbour.first});
                }
            }
        }

        if(dist[dst] == INT_MAX)
        {
            return -1;
        }
        else
        {
            return dist[dst];
        }
    }
};

// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/