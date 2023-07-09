//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int solveMin(int candies[], int n, int k)
    {
        int buy = 0;
        int free = n-1;
        int ans = 0;
        while(buy <= free)
        {
            ans += candies[buy];
            
            buy++;
            free = free - k;
        }
        return ans;
    }
    
    int solveMax(int candies[], int n, int k)
    {
        int buy = n-1;
        int free = 0;
        int ans = 0;
        while(free <= buy)
        {
            ans += candies[buy];
            
            buy--;
            free = free + k;
        }
        return ans;
    }
    
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies, candies+N);
        
        int minAns = solveMin(candies, N, K);
        int maxAns = solveMax(candies, N, K);
        vector<int>finalAns;
        finalAns.push_back(minAns);
        finalAns.push_back(maxAns);
        return finalAns;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/shop-in-candy-store1145/1