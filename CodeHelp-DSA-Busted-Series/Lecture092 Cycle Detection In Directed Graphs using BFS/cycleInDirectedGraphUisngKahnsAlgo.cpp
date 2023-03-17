#include<queue>
#include<set>
#include<list>
#include<unordered_map>
#include<iostream>
using namespace std;

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {    
    unordered_map<int,list<int>>adj;
    
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first-1;
        int v=edges[i].second-1;
        adj[u].push_back(v);
    }
    //creating indegree array
    vector<int>indegree(n);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }
    //pushing all the elemntds with 0 indegere to q
    queue<int>q;
    for(int i=0;i<n;i++){        
           if(indegree[i]==0){               
                q.push(i);
           }                   
        
    }
    int cnt=0;                
    while(!q.empty()){
        //pushing the node with 0 indegree to ans
        int front=q.front();        
        q.pop();
        cnt++;
        //decreasin the indegree of neighbours
        for(auto neighbours:adj[front]){
            indegree[neighbours]--;
            //after decreaing if any of neighbours has 0 indegree push it to Queue
            if(indegree[neighbours]==0)             
                q.push(neighbours);        
        }
    }
     if(cnt==n)
     {
         // we have got a valid topological sort
         // So, the graph is acyclic 
         // return false as no cycles are present
        return false;   \
     }
    else
    {
        // we have got invalid topological sort
        // So, the graph is cyclic
        // return true as cycle is present
        return true;
    }     
}

// Rev
// https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0
