//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    static bool cmp(pair<int, pair<int, int>>a, pair<int, pair<int, int>>b)
    {
        return a.second.first < b.second.first;
    }
    
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        int n = N;
        vector<int>ans; // for the final answer
        
        // creating a vector
        vector<pair<int,pair<int, int>>>v;
        
        // storing the values in the vector
        for(int i=0; i<n; i++)
        {
            v.push_back({S[i], {F[i], i}});
        }
        
        sort(v.begin(), v.end(), cmp);
        
        ans.push_back(v[0].second.second+1);
        int endAns = v[0].second.first;
        
        for(int i=1; i<n; i++)
        {
            if(v[i].first > endAns)
            {
                ans.push_back(v[i].second.second + 1);
                endAns= v[i].second.first;
            }
        }
        
        sort(ans.begin(), ans.end());
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
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1