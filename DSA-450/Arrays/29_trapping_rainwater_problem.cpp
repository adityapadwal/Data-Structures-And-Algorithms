//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        long long ans = 0;
         // Create left and right arrays to store the maximum heights
        // to the left and right of each block respectively.
        int leftMax[n], rightMax[n];
        leftMax[0] = arr[0];
        rightMax[n - 1] = arr[n - 1];
    
        // Fill the leftMax array with maximum heights to the left of each block.
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], arr[i]);
        }
    
        // Fill the rightMax array with maximum heights to the right of each block.
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], arr[i]);
        }
    
        // Calculate trapped water for each block.
        for (int i = 0; i < n; i++) {
            ans += min(leftMax[i], rightMax[i]) - arr[i];
        }
    
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1