//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void createAdjList(unordered_map<int, list<pair<int, int>>>&adjList, vector<vector<int>>&edges)
    {
        for(int i=0; i<edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adjList[u].push_back(make_pair(v, w));
        }
    }
    
    void findTopo(int node, unordered_map<int, list<pair<int, int>>>&adjList, stack<int>&s, unordered_map<int, bool>&visited)
    {
        visited[node] = true;
        
        for(auto i: adjList[node])
        {
            if(!visited[i.first])
            {
                findTopo(i.first, adjList, s, visited);
            }
        }
        
        s.push(node);
    }
    
    void processAnswer(int src, stack<int>&s, vector<int>&dist, unordered_map<int, list<pair<int, int>>>&adjList)
    {
        dist[src]  = 0;
        
        while(!s.empty())
        {
            int top = s.top();
            s.pop();
            
            if(dist[top] != INT_MAX)
            {
                for(auto i: adjList[top])
                {
                    if(dist[top] + i.second < dist[i.first])
                    {
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
    }
    
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         
        // adjacency list
        unordered_map<int, list<pair<int, int>>>adjList;
        createAdjList(adjList, edges);
        
        // topological sorting using DFS
        stack<int>s;
        
        // visited data structure
        unordered_map<int, bool>visited;
        
        // distance data structure (for the final answer)
        vector<int>dist(N);
        for(int i=0; i<N; i++)
        {
            dist[i] = INT_MAX;
        }
        
        // topological sorting
        for(int i=0; i<N; i++)
        {
            if(!visited[i])
            {
                findTopo(i, adjList, s, visited);
            }
        }
        // topologically sorted array is present in the stack
        
        // further processing
        processAnswer(0, s, dist, adjList);
        
        for(int i=0; i<N; i++)
        {
            if(dist[i] == INT_MAX)
            {
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1