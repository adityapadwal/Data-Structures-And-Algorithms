//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node, int parent, int &timer, vector<int>&disc, vector<int>&low, vector<bool>&visited, vector<int>&ap, vector<int>adj[])
    {
        visited[node] = true;
        low[node] = timer;
        disc[node] = timer;
        timer++;
        
        int child = 0;
        
        for(auto neighbour: adj[node])
        {
            if(neighbour == parent)
            {
                // ignore 
                continue;
            }
            else if(!visited[neighbour])
            {
                dfs(neighbour, node, timer, disc, low, visited, ap, adj);
                
                // Backtracking
                // 1. Update low
                  low[node] = min(low[node], low[neighbour]);
                // 2. Check for ap
                  if(low[neighbour] >= disc[node] && parent != -1)
                  {
                      ap[node] = 1;
                  }

                child++;
            }
            else
            {
                // visited[neighbour] == true && neighbour != parent
                // back edge is present
                // hence updating the low
                low[node] = min(low[node], disc[neighbour]);
            }
        }
        
        // checking if the source node is an ap
        if(parent == -1 && child > 1)
        {
            ap[node] = 1;
        }
    }
    
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        
        // required data structures
        int timer = 0;
        int parent = -1;
        vector<int>ap(V); // for storing the articulation points
        vector<int>disc(V); 
        vector<int>low(V);
        vector<bool>visited(V);
        
        // initializations
        for(int i=0; i<V; i++)
        {
            ap[i] = 0;
            low[i] = -1;
            disc[i] = -1;
            visited[i] = false;
        }
        
        // dfs traversal
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                dfs(i, parent, timer, disc, low, visited, ap, adj);
            }
        }
        
        // for the final answer
        vector<int>finalAns;
        for(int i=0; i<V; i++)
        {
            if(ap[i] == 1)
            {
                finalAns.push_back(i);
            }
        }
        
        if(finalAns.empty())
        {
            finalAns.push_back(-1);
            return finalAns;
        }
        else
        {
            return finalAns;
        }
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/articulation-point-1/1
// https://practice.geeksforgeeks.org/problems/articulation-point2616/1