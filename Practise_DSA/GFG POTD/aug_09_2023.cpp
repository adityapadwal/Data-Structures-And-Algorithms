//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    // bool isPrime(int n)
    // {
    //     for(int i=2; i<n; i++)
    //     {
    //         if(n%i == 0)
    //         {
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    
    // long long int largestPrimeFactor(int N){
    //     // brute force approach
    //     // TC = O(N)
    //     // SC = O(N)
    //     int ans = INT_MIN;
    //     for(int i=2; i<=N; i++)
    //     {
    //         if((N%i == 0) && (isPrime(i)))
    //         {
    //             ans = max(ans, i);
    //         }
    //     }
        
    //     return ans;
    // }
    
    long long int largestPrimeFactor(int N){
        // Working Code 
        // TC = O(sqrt(N))
        // SC = O(1)
        long long int ans = 0;
        
        for(int i=2; i<=N; i++)
        {
            while(N%i == 0)
            {
                ans = max(ans, (long long int) i);
                N = N / i;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/largest-prime-factor2601/1