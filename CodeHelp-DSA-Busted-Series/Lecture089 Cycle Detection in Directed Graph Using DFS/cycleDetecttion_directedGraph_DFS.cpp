#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>

using namespace std;

void createAdjList(unordered_map<int, list<int>>&adjList, vector<pair<int, int>>&edges)
{
  for(int i=0; i<edges.size(); i++)
  {
    int u = edges[i].first;
    int v = edges[i].second;

    // directed graph, hence connect only from u to v and not from v to u
    adjList[u].push_back(v);
  }
}

bool detectCycleDfs(int node, unordered_map<int, list<int>>&adjList, unordered_map<int, bool>&visited, unordered_map<int, bool>&dfsVisited)
{
  visited[node] = true;
  dfsVisited[node] = true;
  
  for(auto i: adjList[node])
  {
    if(!visited[i])
    {
      bool cycleDetected = detectCycleDfs(i, adjList, visited, dfsVisited);
      if(cycleDetected == true)
      {
        return true;
      }
    }
    else if(visited[i] == true && dfsVisited[i] == true)
    {
      // cycle is present
      return true;
    }
    
  }
  dfsVisited[node] = false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // data structure for adjacency list 
  unordered_map<int, list<int>>adjList;

  createAdjList(adjList, edges);

  // visited data structure
  unordered_map<int, bool>visited;

  // dfsVisited data structure
  unordered_map<int, bool>dfsVisited;

  for(int i=1; i<=n; i++)
  {
    if(!visited[i])
    {
      bool ans = detectCycleDfs(i, adjList, visited, dfsVisited);
      if(ans == true)
      {
        return true;
      }
    }
  }
  return false;
}

// Rev
// https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar