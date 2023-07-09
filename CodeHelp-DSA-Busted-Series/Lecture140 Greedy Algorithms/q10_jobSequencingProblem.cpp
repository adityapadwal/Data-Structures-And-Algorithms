//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool cmp(Job a, Job b)
    {
        return a.profit > b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // sort w.r.t profit in descending order
        sort(arr, arr+n, cmp);
        
        // creating a schedule array
        int maxi = INT_MIN;
        for(int i=0; i<n; i++)
        {
            maxi = max(maxi, arr[i].dead);
        }
        vector<int>schedule(maxi+1, -1); // maxi+1 because we have used 1-based indexing
        
        // for the answer
        int count = 0;
        int maxProfit = 0;
        
        // traversing the sorted array
        for(int i=0; i<n; i++)
        {
            int currJobId = arr[i].id;
            int currProfit = arr[i].profit;
            int currDeadline = arr[i].dead;
            
            for(int k=currDeadline; k>0; k--)
            {
                if(schedule[k] == -1)
                {
                    // we can do the job
                    count++;
                    maxProfit += currProfit;
                    schedule[k] = currJobId;
                    break;
                }
            }
        }
        
        //for returning the final answer 
        vector<int>finalAns;
        finalAns.push_back(count);
        finalAns.push_back(maxProfit);
        return finalAns;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}
// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1