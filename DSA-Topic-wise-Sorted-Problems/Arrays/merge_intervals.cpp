#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // base case 
        if(intervals.size() == 1)
        {
            return intervals;
        }

        vector<pair<int, int>>p;
        int n = intervals.size();

        for(int i=0; i<n; i++)
        {
            p.push_back(make_pair(intervals[i][0], intervals[i][1]));
        }

        sort(p.begin(), p.end());

        vector<vector<int>>finalAns; 
        int first = p[0].first;
        int second = p[0].second;

        for(int i=0; i<p.size()-1; i++)
        {
            vector<int>ans(2);
            if(p[i+1].first <= second)
            {
                second = max(second, p[i+1].second);
            }
            else
            {
                ans[0] = first;
                ans[1] = second;
                finalAns.push_back(ans);

                first = p[i+1].first;
                second = p[i+1].second;
            }
        }

        // put the last interval in the finalAns array
        finalAns.push_back({first, second});

        // return the final answer
        return finalAns;
    }
};

// https://leetcode.com/problems/merge-intervals/description/