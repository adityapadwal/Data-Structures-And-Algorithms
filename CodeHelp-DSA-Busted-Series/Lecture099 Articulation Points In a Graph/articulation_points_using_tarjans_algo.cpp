#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

int min(int a, int b)
{
    if(a > b) 
    {
        return a;
    }
    else 
    {
        return b;
    }
}

void dfs(int node, int parent, int &timer, unordered_map<int, list<int>>&adj, vector<int>&disc, vector<int>&low, unordered_map<int, bool>&visited, vector<int>&ap)
{
    visited[node] = true;
    disc[node] = low[node] = timer;
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
            dfs(neighbour, node, timer, adj, disc, low, visited, ap);

            // while coming back, update the low
            low[node] = min(low[node], low[neighbour]);

            // check for the articulation points
            if(low[neighbour] >= disc[node] && parent != -1)
            {
                // node is an articulation point
                ap[node] = 1;
            }
            child++;
        }
        else 
        {
            // visited[neighbour] == true && neighbour != parent
            // hence back edge is present
            low[node] = min(low[node], disc[neighbour]);
        }
    }
    // condition to check if the source node is an articulation point or not
    if(parent == -1 && child > 1)
    {
        ap[node] = 1;
    }
}

int main()
{
    // vertices and edges
    int v = 5;
    int e = 5;
    vector<pair<int, int>>edges;
    
    // adding edges
    for(int i=0; i<e; i++)
    {
        edges.push_back(make_pair(0, 3));
        edges.push_back(make_pair(3, 4));
        edges.push_back(make_pair(0, 4));
        edges.push_back(make_pair(0, 1));
        edges.push_back(make_pair(1, 2));        
    }

    // adjacency list 
    unordered_map<int, list<int>>adj;
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int parent;
    int timer;
    // discovery data structure
    vector<int>disc(v);
    // low (earliest possible time) data structure
    vector<int>low(v);
    // visited data structure
    unordered_map<int, bool>visited(v);
    // data structure to store articulation points
    vector<int>ap(v); 

    // initializations
    parent = -1;
    timer = 0;
    for(int i=0; i<v; i++)
    {
        disc[i] = -1;
        low[i] = -1;
        visited[i] = false;
        ap[i] = 0;
    }

    // dfs call
    for(int i=0; i<v; i++)
    {
        if(!visited[i])
        {
            dfs(i, parent, timer, adj, disc, low, visited, ap);
        }
    }
    
    // Printing all the articulation points
    cout<<"\n <=== Printing all the articulation points ===>"<<endl;
    for(int i=0; i<v; i++)
    {
        if(ap[i] != 0)
        {
            cout<<i<<" "<<endl;
        }
    }

return 0;
}