//{ Driver Code Starts
// #include<bits/stdc++.h>
#include<iostream>
#include<unordered_map>
#include<set>
#include<list>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        unordered_map<int, list<pair<int, int>>>adjList;
        for(int i=0; i<adj.size(); i++)
        {
            int u = vec[i][0];
            int v = vec[i][1];
            int weight = vec[i][2];
    
            adj[u].push_back(make_pair(v, weight));
            adj[v].push_back(make_pair(u, weight));
        }
        
        // dist data structure
        vector<int>dist(V);
        for(int i=0; i<V; i++)
        {
            dist[i] = INT_MAX;
        }
    
        // set data structure
        set<pair<int, int>>st;
    
        // initializations
        dist[source] = 0;
        st.insert(make_pair(0, source));
    
        while(! st.empty())
        {
            // fetch top of the set
            auto top = *(st.begin());
            int nodeDistance = top.first;
            int topNode = top.second;
    
            // now, remove the top record
            st.erase(st.begin());
    
            // traverse on neighbours of node
            for(auto neighbour: adj[topNode])
            {
                if(nodeDistance + neighbour.second < dist[neighbour.first])
                {
                    // finding if a record is not already present in the set
                    auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                    // if record found, then erase it
                    if(record != st.end())
                    {
                        // record found
                        st.erase(record);
                    }
                    
                    // update the distance
                    dist[neighbour.first] = nodeDistance +  neighbour.second;
                    
                    // push record in the set
                    st.insert(make_pair(dist[neighbour.first], neighbour.first));
                }
            }
        }
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