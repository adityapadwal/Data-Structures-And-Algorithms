//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int index, int arr[], int n, int target)
    {
        // base case
        if(index >= n)
        {
            return 0;
        }
        if(target < 0)
        {
            return 0;
        }
        if(target == 0)
        {
            return 1;
        }
        
        int include = solve(index+1, arr, n, target-arr[index]);
        int exclude = solve(index+1, arr, n, 0);
        
        int ans = include or exclude;
        return ans;
    }
    
    int equalPartition(int N, int arr[])
    {
        // Using recursion
        int total = 0;
        for(int i=0; i<N; i++)
        {
            total += arr[i];
        }
        if(total % 2 != 0)
        {
            return 0;
        }
        int target = total/2;
        int finalAns = solve(0, arr, N, target);
        return finalAns;
        
        // Using Memoization
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends

// https://www.youtube.com/watch?v=UGY7FMHt-M8&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=133&t=26s