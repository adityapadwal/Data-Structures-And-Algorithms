#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
            for(auto x: graph[i])
            {
                adj[i].push_back(x);
            }
        }

        vector<int>color(n, -1);
        for(int i=0; i<n; i++)
        {
            if(color[i] == -1)
            {
                queue<pair<int, int>>q;

                q.push({i, 0});
                color[0] = 0;

                while(!q.empty())
                {
                    int node = q.front().first;
                    int nodeColor = q.front().second;
                    q.pop();

                    for(auto neighbour: adj[node])
                    {
                        if(color[neighbour] == -1)
                        {
                            color[neighbour] = !nodeColor;
                            q.push({neighbour, color[neighbour]});
                        }

                        else if(color[neighbour] == nodeColor)
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

// https://leetcode.com/problems/is-graph-bipartite/