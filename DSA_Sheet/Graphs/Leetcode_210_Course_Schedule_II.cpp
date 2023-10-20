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

    vector<int> bfsTraversal(int numCourses, unordered_map<int, list<int>>&adjList, vector<int>indegree, vector<int>&finalAns)
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
            finalAns.push_back(front);
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
            return finalAns;
        }
        else
        {
            return {};
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // for the final answer
        vector<int>finalAns;

        // adjacency list
        unordered_map<int, list<int>>adjList;
        createAdjList(prerequisites, adjList);

        // indegree array
        vector<int>indegree(numCourses);
        findIndegree(adjList, indegree);

        // bfs traversal using Kahn's algo
        finalAns = bfsTraversal(numCourses, adjList, indegree, finalAns);
        if(finalAns.size() == numCourses)
        {
            reverse(finalAns.begin(), finalAns.end());
        }
        return finalAns;
    }
};

// https://leetcode.com/problems/course-schedule-ii/