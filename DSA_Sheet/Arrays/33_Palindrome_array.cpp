//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

#include<vector>
class Solution {
public: 
    bool checkPalindrome(vector<int>&arr)
    {
        int s = 0;
        int e = arr.size()-1;
        while(s<e)
        {
            if(arr[s] == arr[e])
            {
                s++;
                e--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    
    bool isPalindrome(int n)
    {
        vector<int>temp;
        while(n!=0)
        {
            int digit = n%10;
            temp.push_back(digit);
            n = n/10;
        }
        return checkPalindrome(temp);
    }
    
    int PalinArray(int a[], int n)
    {
    	for(int i=0; i<n; i++)
    	{
    	    int num = a[i];
    	    bool tempAns = isPalindrome(num);
    	    if(tempAns == false)
    	    {
    	        return 0;
    	    }
    	}
    	return 1;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/palindromic-array-1587115620/1