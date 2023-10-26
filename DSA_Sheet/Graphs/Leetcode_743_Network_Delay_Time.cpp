#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void createAdjList(vector<vector<int>>&times, unordered_map<int, list<pair<int, int>>>&adjList)
    {
        int size = times.size();
        for(int i=0; i<size; i++)
        {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adjList[u].push_back({v, w});
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, list<pair<int, int>>>adjList;
        createAdjList(times, adjList);
        
        vector<int>dist(n+1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, k});

        while(!pq.empty())
        {
            pair<int, int>topPair = pq.top();
            pq.pop();

            int nodeDistance = topPair.first;
            int topNode = topPair.second;

            for(auto neighbour: adjList[topNode])
            {
                if(nodeDistance + neighbour.second < dist[neighbour.first])
                {
                    dist[neighbour.first] = nodeDistance + neighbour.second;
                    pq.push({dist[neighbour.first], neighbour.first});
                }
            }
        }

        int maxi = INT_MIN;
        for(int i=1; i<=n; i++)
        {
            if(dist[i] == INT_MAX)
            {
                return -1;
            }
            else
            {
                maxi = max(maxi, dist[i]);
            }
        }
        return maxi;
    }
};

// https://leetcode.com/problems/network-delay-time/