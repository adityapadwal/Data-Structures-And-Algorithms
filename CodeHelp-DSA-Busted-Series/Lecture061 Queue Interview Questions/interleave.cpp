//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        // Using Stack
        vector<int>ans;
        
        stack<int>s;
        
        int n = q.size();
        
        for(int i=0; i<n/2; i++)
        {
            int element = q.front();
            q.pop();
            s.push(element);
        }
        
        while(!s.empty())
        {
            int element = s.top();
            s.pop();
            q.push(element);
        }
        
        for(int i=0; i<n/2; i++)
        {
            int element = q.front();
            q.pop();
            q.push(element);
        }
        
        for(int i=0; i<n/2; i++)
        {
            int element = q.front();
            q.pop();
            s.push(element);
        }
        
        while(!s.empty() && !q.empty())
        {
            int elementOne = s.top();
            s.pop();
            ans.push_back(elementOne);
            
            int elementTwo = q.front();
            q.pop();
            ans.push_back(elementTwo);
        }
        
        return ans;
    }
    
    vector<int> rearrangeQueue(queue<int> &q){
        // Using queue
        vector<int>ans; // for the final ans
        queue<int>temp1;
        queue<int>temp2;
        
        int n = q.size();
        for(int i=0; i<n/2; i++)
        {
            int element = q.front();
            q.pop();
            temp1.push(element);
        }
        for(int i=0; i<n/2; i++)
        {
            int element = q.front();
            q.pop();
            temp2.push(element);
        }
        
        while(!temp1.empty() && !temp2.empty())
        {
            ans.push_back(temp1.front());
            ans.push_back(temp2.front());
            temp1.pop();
            temp2.pop();
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1?page=1&sortBy=latest