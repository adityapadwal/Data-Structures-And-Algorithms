// NOT WORKING 

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // base case 
        if(n == 1)
        {
            return 0;
        }
        if(arr[0] == 0)
        {
            return -1;
        }
        
        // sort(arr, arr+n, greater<>());
        int size = n;
        int jumpCount = 0;
        int ans = 0;
        int i = 0;
        
        for(int i=0; i<n; i++)
        {
            if(arr[i] == 0)
            {
                size = i-1;
                break;
            }
        }
        
        while(ans < size)
        {
            if(arr[i] > 0)
            {
                ans += arr[i];
                jumpCount++;
                i = ans;
            }
            else
            {
                return 0;
            }
        }
        
        if(ans >= size)
        {
            // reached end of the array
            return jumpCount;
        }
        else
        {
            return -1;
        }
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1