#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool cmp(vector<int>&a, vector<int>&b)
{
  return a[2] < b[2];
}

void makeSet(vector<int>&parent, vector<int>&rank, int n)
{
  for(int i=0; i<n; i++)
  {
    rank[i] = 0;
    parent[i] = i;
  }
}

int findParent(int node, vector<int>&parent)
{
    // base condition
  if(parent[node] == node)
  {
    return node;
  }
  // implementing path compression logic
  parent[node] = findParent(parent[node], parent);

  // without path compression
  // return findParent(parent[node], parent);
}

void unionSet(int u, int v, vector<int>&parent, vector<int>&rank)
{
//   u = findParent(u, parent);
//   v = findParent(v, parent);

  if(rank[u] < rank[v])
  {
    parent[u] = v;
  }

  else if(rank[v] < rank[u])
  {
    parent[v] = u;
  }
  else
  {
    // rank[u] == rank[v]
    parent[v] = u;
    rank[u]++;
  }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    // sorting the given edges
  sort(edges.begin(), edges.end(), cmp);

  // parent data structure
  vector<int>parent(n);
  // Rank data structure
  vector<int>rank(n);
  // initializations
  makeSet(parent, rank, n);

  // Kruskal's Algo
  int minWeight = 0;
  for(int i=0; i<edges.size(); i++)
  {
    int u = findParent(edges[i][0], parent);
    int v = findParent(edges[i][1], parent);
    int weight = edges[i][2];
    // if u and v lie in same components, ignore

    if(u != v)
    {
      // u and v lies in different  component
      minWeight += weight;
      unionSet(u, v, parent, rank);
    }
  }
  return minWeight;
}

// Rev
// https://www.codingninjas.com/codestudio/problems/minimum-spanning-tree_631769?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1