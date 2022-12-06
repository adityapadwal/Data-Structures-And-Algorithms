//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        // creating auxArr
        int auxArr[n];
        
        int front = 0;
        int back = n-1;
        
        for(int i=0, j=n-1; i<n, j>=0; i++, j--)
        {
            if(arr[i] >= 0)
            {
                auxArr[front] = arr[i];
                front++;
            }
            if(arr[j] < 0)
            {
                auxArr[back] = arr[j];
                back--;
            }
        }
        
        for(int i=0; i<n; i++)
        {
            arr[i] = auxArr[i];
        }
    }
};

//{ Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}

// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/move-all-negative-elements-to-end1813/1