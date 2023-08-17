//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    // Approach 1: TLE
    // TC = O(N*N) Hence TLE
    // long long int inversionCount(long long arr[], long long N)
    // {
    //     long long int count = 0;
    //     for(long long int i=0; i<N-1; i++)
    //     {
    //         for(long long int j=i+1; j<N; j++)
    //         {
    //             if(arr[i]>arr[j])
    //             {
    //                 // inversion
    //                 count++;
    //                 // swap(arr[i], arr[j]);
    //                 // break;
    //             }
    //         }
    //     }
    //     return count;
    // }
    
    // Approach 2: Using merge sort
    // TC = O(NlonN)
    void merge(long long arr[], long long left, long long mid, long long right, long long &count)
    {
        long long i = left;
        long long j = mid+1;
        long long k = left;
        long long temp[right];
        
        while(i<=mid && j<=right)
        {
            if(arr[i] <= arr[j])
            {
                temp[k] = arr[i];
                k++;
                i++;
            }
            else
            {
                count += mid-i+1;
                temp[k] = arr[j];
                j++;
                k++;
            }
        }
        while(i<=mid)
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        while(j<=right)
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
        
        for(int i=left; i<=right; i++)
        {
            arr[i] = temp[i];
        }
    }
    
    void mergeSort(long long arr[], long long left, long long right, long long &count)
    {
        // base case
        if(left >= right)
        {
            return;
        }
        
        long long mid = left+(right-left)/2;
        
        mergeSort(arr, left, mid, count);
        mergeSort(arr, mid+1, right, count);
        merge(arr, left, mid, right, count);
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        long long count = 0;
        mergeSort(arr, 0, N-1, count);
        return count;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1