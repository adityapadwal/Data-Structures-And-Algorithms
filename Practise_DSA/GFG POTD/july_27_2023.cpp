//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;
        
        if(left<n && arr[left]>arr[largest])
        {
            largest = left;
        }
        if(right<n && arr[right]>arr[largest])
        {
            largest = right;
        }
        
        if(largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        for(int i=n/2-1; i>=0; i--)
        {
            heapify(arr, n, i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        // Step 1: Build the max heap
        buildHeap(arr, n);
        
        // Step 2: Swap, delete and heapify
        for(int i=n-1; i>=0; i--)
        {
            // swapping the first(root) and last elements of the heap
            swap(arr[i], arr[0]);
            heapify(arr, i, 0); // after swapping heapifying the array. Here i is passed as n to heapify so that the last element is deleted.
        }
    }
};




//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/heap-sort/1