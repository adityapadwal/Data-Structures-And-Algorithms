#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<limits.h>
#include<map>
using namespace std;

class Solution {
public:
    vector<int>findNext(vector<int>arr, int n)
    {
        vector<int>ans(n);
        stack<int>s;
        s.push(-1);

        for(int i=n-1; i>=0; i--)
        {
            int curr = arr[i];
            while(s.top()!=-1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int>findPrev(vector<int>arr, int n)
    {
        vector<int>ans(n);
        stack<int>s;
        s.push(-1);

        for(int i=0; i<n; i++)
        {
            int curr = arr[i];
            while(s.top()!=-1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        // Step 1: Finding the next smaller elements ka array
        vector<int>nextSmallerElements = findNext(heights, n);

        // Step 2:Finding the previuos smaller elements ka array
        vector<int>prevSmallerElements = findPrev(heights, n);

        // Step 3: Finding the ans
        int finalAns = INT_MIN;
        for(int i=0; i<n; i++)
        {
            if(nextSmallerElements[i] == -1) // imp remember
            {
                nextSmallerElements[i] = n;
            }

            int length = heights[i];

            // n-p-1
            int breadth = nextSmallerElements[i] - prevSmallerElements[i] - 1;

            int ans = length * breadth;

            finalAns = max(finalAns, ans);
        }

        return finalAns;
    }
};

// https://leetcode.com/problems/largest-rectangle-in-histogram/description/