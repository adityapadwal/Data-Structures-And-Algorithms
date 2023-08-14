//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // brute force TC=O(N) SC=O(N)
        // map<int, int>mp;
        // vector<int>ans;
        
        // for(int i=0; i<nums.size(); i++)
        // {
        //     mp[nums[i]]++;
        // }
        
        // for(auto i: mp)
        // {
        //     if(i.second == 1)
        //     {
        //         ans.push_back(i.first);
        //     }
        // }
        // return ans;
        
        //Optimized TC=O(N) SC=O(1)
        int x = 0;
        for(int i=0; i<nums.size(); i++)
        {
            x = x^nums[i];
        }
        
        int temp = 1;
        while((temp & x) == 0)
        {
            temp = temp*2;
        }
        
        int num1 = 0;
        int num2 = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if((temp&nums[i]) == 0)
            {
                num1 = num1 ^ nums[i];
            }
            else
            {
                num2 = num2 ^ nums[i];
            }
        }
        
        vector<int>ans;
        ans.push_back(num1);
        ans.push_back(num2);
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1