//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool DFS(int node, bool color, vector<int>&colored, vector<int>adj[])
    {
        colored[node] = color;
        
        for(int neighbour: adj[node])
        {
            if(colored[neighbour] == -1)
            {
                bool miniAns = DFS(neighbour, !color, colored, adj);
                if(miniAns == false)
                {
                    return false;
                }
            }
            
            if(colored[neighbour] == color)
            {
                return false;
            }
        }
        return true;
    }
    
	bool isBipartite(int V, vector<int>adj[]){
	    // Using DFS
	    vector<int>colored(V, -1);
	    bool color = 1;
	   
	    for(int i=0; i<V; i++)
	    {
	        if(colored[i] == -1)
	        {
	            bool answer = DFS(i, color, colored, adj);
	            if(answer == false)
	            {
	                return false;
	            }
	        }
	    }
	    
	    return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/bipartite-graph/1