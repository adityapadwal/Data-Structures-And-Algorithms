#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void createAdjList(vector<vector<int>>& prerequisites, unordered_map<int, list<int>>&adjList)
    {
        for(int i=0; i<prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adjList[u].push_back(v);
        }
    }

    void findIndegree(unordered_map<int, list<int>>&adjList, vector<int>&indegree)
    {
        for(auto i: adjList)
        {
            for(auto j: i.second)
            {
                indegree[j]++;
            }
        }
    }

    bool bfsTraversal(int numCourses, unordered_map<int, list<int>>&adjList, vector<int>indegree)
    {
        int count = 0;

        queue<int>q;
        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            count++;
            for(auto neighbour: adjList[front])
            {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }

        if(count == numCourses)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // adjacency list
        unordered_map<int, list<int>>adjList;
        createAdjList(prerequisites, adjList);

        // indegree array
        vector<int>indegree(numCourses);
        findIndegree(adjList, indegree);

        // bfs traversal using Kahn's algo
        bool finalAns = bfsTraversal(numCourses, adjList, indegree);
        return finalAns;
    }
};

// https://leetcode.com/problems/course-schedule/