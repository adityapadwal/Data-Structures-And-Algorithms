//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void dfs(int node, unordered_map<int, bool>&visited, vector<int>&ans, vector<int> adj[])
    {
        ans.push_back(node);
        visited[node] = true;
        
        for(auto i: adj[node])
        {
            if(!visited[i])
            {
                dfs(i, visited, ans, adj);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // for the final Ans
        vector<int>ans;
        
        // for the visited array
        unordered_map<int, bool>visited;
        
        for(int i=0; i<V; i++)
        {
            if(visited[i] != true)
            {
                dfs(i, visited, ans, adj);
            }
        }
        
        return ans;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

// Remeber
// DFS of a graph can be found out using 2 ways
// 1. Using Recursion
// 2. Using Stack
// This problem demands solving using recursion. 
// Also prefer solving DFS using recursion and BFS using Queues