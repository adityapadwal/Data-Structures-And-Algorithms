#include<bits/stdc++.h>
using namespace std;

// Partially Accepted TC = O(N*N)
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    if(n == 1)
    {
        arr[0] = -1;
        return arr;
    }
    
    for(int i=0; i<n-1; i++)
    {
        int temp;
        bool flag = false;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j] < arr[i])
            {
                temp = arr[j];
                flag = true;
                break;
            }
        }
        if(flag == false)
        {
            arr[i] = -1;
        }
        else{
            arr[i] = temp;
        }
    }

    arr[n-1] = -1;
    return arr;
}

// Accepted TC = O(N)
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    //Step1: Create a stack and add -1 to it 
    stack<int>s;
    s.push(-1);
    
    // Step2: Create a vector named ans
    vector<int>ans(n);
    
    //Step3: Traverse the for loop 
    for(int i=n-1; i>=0; i--)
    {
        int curr = arr[i];
        while(s.top() >= curr)
        {
            s.pop();
        }
        // now ans is stack ka top 
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

//https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1