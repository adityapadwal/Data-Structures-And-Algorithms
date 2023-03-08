#include<bits/stdc++.h>
#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

void createList(vector<pair<int,int>> edges, unordered_map<int, list<int>>&adjList)
{
	for(int i=0; i<edges.size(); i++)
	{
		int u = edges[i].first;
		int v = edges[i].second;

		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
}

void bfsTraversal(unordered_map<int, list<int>>&adjList, vector<bool>&visited, vector<int>&parent, queue<int>q, int src)
{
	q.push(src);
	visited[src] == true;
	parent[src] == -1;

	while(!q.empty())
	{
		int frontNode = q.front();
		q.pop();

		for(auto neighbour: adjList[frontNode])
		{
			if(visited[neighbour] == false)
			{
				visited[neighbour] = true;
				parent[neighbour] = frontNode;
				q.push(neighbour);
			}
		}
	}
}

void processParent(vector<int>&finalAns, vector<int>&parent, int src, int dest)
{
	int currentNode = dest;
	finalAns.push_back(dest);

	while(currentNode != src)
	{
		currentNode = parent[currentNode];
		finalAns.push_back(currentNode);
	}
}

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Adjacency List
	unordered_map<int, list<int>>adjList;
	createList(edges, adjList);

	// visited data structure
	vector<bool>visited(n+1);

	// parent data structure
	vector<int>parent(n+1);

	// queue data structure
	queue<int>q;

	// vector for the final answer
	vector<int>finalAns;

	// bfs traversal
	bfsTraversal(adjList, visited, parent, q, s);

	// process parent
	processParent(finalAns, parent, s, t);

	// returning the final answer
	reverse(finalAns.begin(), finalAns.end());
	return finalAns;

}

// https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar