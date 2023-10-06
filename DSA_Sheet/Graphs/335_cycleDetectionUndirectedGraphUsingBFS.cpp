//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    void createAdjList(vector<int>adj[], unordered_map<int, set<int>>&adjList, int v)
    {
        for(int i=0; i<v; i++)
        {
            for(auto j: adj[i])
            {
                adjList[i].insert(j);
                adjList[j].insert(i);
            }
        }
    }
    
    bool detectCycle(int src, vector<int>adj[], unordered_map<int, bool>&visited, unordered_map<int, int>&parent)
    {
        visited[src] = true;
        parent[src] = -1;
        
        queue<int>q;
        q.push(src);
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            
            for(auto neighbour: adj[front])
            {
                
                if(visited[neighbour]==true && neighbour!=parent[front])
                {
                    // cycle present
                    return 1;
                }
                else if(!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = front;
                }
            }
        }
        return 0;
    }
    
    
    // Main function
    bool isCycle(int V, vector<int> adj[]) {
        // // adjacency list
        // unordered_map<int, set<int>>adjList;
        // createAdjList(adj, adjList, V);
        
        // visited data structure
        unordered_map<int, bool>visited;
        
        // parent data structure
        unordered_map<int, int>parent;
        
        // for disconnected graph
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                bool ans = detectCycle(i, adj, visited, parent);
                if(ans == true)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670?leftPanelTab=0