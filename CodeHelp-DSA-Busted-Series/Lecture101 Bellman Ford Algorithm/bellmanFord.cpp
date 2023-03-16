#include<iostream>
#include<vector>
#include <bits/stdc++.h> 
#include<limits.h>
using namespace std;

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // creating distance data structure
    vector<int>dist(n+1, 1e9);
    dist[src] = 0;

    // Step 1: Apply the distance reduction formula (n-1) times to all the edges of the graph 
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
        
            // distance reduction formula
            if((dist[u] != 1e9) && ((dist[u] + wt) < dist[v]))
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Step 2: Check for negative cycles in the graph
    bool flag = false;
    for(int j=0; j<m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        // distance reduction formula
        if ((dist[u] != 1e9) && ((dist[u] + wt) < dist[v]))
        {
            // negative cycle is present
            flag = true;
            break;
        }
    }

    if(flag == false)
    {
        // no negative cyce present
        return dist[dest];
    } 
    else {
      // negative cycle present
      return -1;
    }
}