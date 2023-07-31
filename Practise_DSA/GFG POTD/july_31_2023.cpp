//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // for storing the final ans
        vector<int>ans;
        
        // for bfs traversal
        queue<int>q;
        
        // visited elements will not be printed again
        unordered_map<int, bool>visited;
        
        //enter the root element
        q.push(0);
        
        while(!q.empty())
        {
            int i = q.front();
            q.pop();
            visited[i] = true;
            ans.push_back(i);
            
            for(auto adjNode: adj[i])
            {
                if(!visited[adjNode])
                {
                    q.push(adjNode);
                    visited[adjNode] = true;
                }
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
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1