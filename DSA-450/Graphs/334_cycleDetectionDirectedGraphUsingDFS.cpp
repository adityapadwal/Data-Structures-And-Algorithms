//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool detectCycleDfs(int node, vector<int> adj[], unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsVisited) {
    visited[node] = true;
    dfsVisited[node] = true;

    for (auto i : adj[node]) {
        if (!visited[i]) {
            bool cycleDetected = detectCycleDfs(i, adj, visited, dfsVisited);
            if (cycleDetected == true) {
                return true;
            }
        } else if (visited[i] == true && dfsVisited[i] == true) {
            // cycle is present
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}

// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[]) {
    // visited data structure
    vector<bool> visited(V, false);

    // dfsvisited data structure
    vector<bool> dfsVisited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            bool ans = detectCycleDfs(i, adj, visited, dfsVisited);
            if (ans == true) {
                return true;
            }
        }
    }
    return false;
}
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// https://www.codingninjas.com/studio/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0