//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
// 	void createAdjList(unordered_map<int, list<pair<int, int>>>&adjList, vector<vector<int>> adj[])
// 	{
// 	    for(int i=0; i<adj->size(); i++)
// 	    {
// 	        int u = (*adj)[i][0];
// 	        int v = (*adj)[i][1];
// 	        int w = (*adj)[i][2];
	        
// 	        adjList[u].push_back(make_pair(v, w));
// 	        adjList[v].push_back(make_pair(u, w));
// 	    }
// 	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // for the finalAns
        int finalAns = 0;
        
        // adjacency list
        unordered_map<int, list<pair<int, int>>>adjList;
        // createAdjList(adjList, adj);
        
        // key data structure
        vector<int>key(V);
        
        // mst data structure
        vector<bool>mst(V);
        
        // parent data structure
        // vector<int>parent(V);
        
        for(int i=0; i<V; i++)
        {
            key[i] = INT_MAX;
            mst[i] = false;
            // parent[i] = -1;
        }
        
        // initial initializations
        key[0] = 0;
        // parent[0] = -1;
        
        // Implementing Prim's ALgo
        for(int i=0; i<V; i++)
        {
            int mini = INT_MAX;
            int u;
            
            // Step 1: Finding the minimum element from the key data structure
            for(int v=0; v<V; v++)
            {
                if(mst[v] == false && key[v] < mini)
                {
                    u = v;
                    mini = key[v];
                }
            }
            
            // Step 2
            mst[u] = true;
            
            // Step 3: Process the adjList of u
            for(auto it: adj[u])
            {
                int v = it[0];
                int w = it[1];
                
                if(mst[v] == false && w < key[v])
                {
                    key[v] = w;
                    // parent[v] = u;
                }
            }
        }
        
        // final Ans
        for(int i=0; i<V; i++)
        {
            finalAns += key[i];
        }
        return finalAns;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1