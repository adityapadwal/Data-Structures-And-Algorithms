//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    void dfs(int node, vector<int>adj[], unordered_map<int, bool>&visited, vector<int>&ans)
    {
        ans.push_back(node);
        visited[node] = true;
        
        for(auto i: adj[node])
        {
            if(!visited[i])
            {
                dfs(i, adj, visited, ans);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // visited wala data structure
        unordered_map<int, bool>visited;
        // for the final answer
        vector<int>ans;
        
        // This is to be written if the given graph can be disconnected or connected, i.e, we need to traverse all the nodes/vertices
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                dfs(i, adj, visited, ans);
            }
        }

        // If it is a connected graph, then 
        dfs(0, adj, visited, ans);


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

// Rev
// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article