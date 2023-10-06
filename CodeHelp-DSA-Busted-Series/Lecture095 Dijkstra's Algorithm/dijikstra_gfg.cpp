//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include<limits.h>
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    // void createAdjList(vector<vector<int>>* adj, unordered_map<int, list<pair<int, int>>>& adjList, int v)
    // {
    //     for(int i=0; i<v; i++)
    //     {
    //         int u = (*adj)[i][0];
    //         int v = (*adj)[i][1];
            
    //         adjList[i].push_back(make_pair(u, v));
    //         adjList[u].push_back(make_pair(i, v));
    //     }
    // }
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // adjacency list <node, dist>
        // unordered_map<int, list<pair<int, int>>>adjList(V);
        // createAdjList(adj, adjList, V);
        
        // creating the distance array
        vector<int>dist(V);
        for(int i=0; i<V; i++)
        {
            dist[i] = INT_MAX;
        }
        
        // creating the set data structure <dist, node>
        set<pair<int, int>>st;
        
        // initial steps
        dist[S] = 0;
        st.insert(make_pair(0, S));
        
        while(!st.empty())
        {
            auto top = *(st.begin());
            st.erase(st.begin());
            
            int nodeDist = top.first;
            int topNode = top.second;
            
            // traversing on all the neighbours of the node
            for(auto neighbour: adj[topNode])
            {
                if(nodeDist + neighbour[1] < dist[neighbour[0]])
                {
                    // updating the distance
                    dist[neighbour[0]] = nodeDist + neighbour[1];
                    
                    // inserting the updated distance in the set
                    st.insert(make_pair(dist[neighbour[0]], neighbour[0]));
                }
            }
        }
        
        // returning the final answer
        return dist;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}
// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1