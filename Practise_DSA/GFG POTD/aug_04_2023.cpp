//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void solveAgain(stack<int>&s, int element)
    {
        if(s.empty())
        {
            s.push(element);
            return;
        }
        
        int temp = s.top();
        s.pop();
        
        solveAgain(s, element);
        
        s.push(temp);
    }
    void solve(stack<int>&s)
    {
        // base case
        if(s.empty())
        {
            return;
        }
        
        int element = s.top();
        s.pop();
        
        solve(s);
        
        solveAgain(s, element);
    }
    
    void Reverse(stack<int> &St){
        if(St.empty())
        {
            return;
        }
        
        if(St.size() == 1)
        {
            return;
        }
        
        solve(St);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/reverse-a-stack/1