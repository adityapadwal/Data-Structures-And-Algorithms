//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void solve(string S, int i, vector<string>&finalAns)
    {
        // base case
        if(i >= S.length())
        {
            finalAns.push_back(S);
            return;
        }
        
        for(int j=i; j<S.length(); j++)
        {
            swap(S[i], S[j]);
            solve(S, i+1, finalAns);
            swap(S[i], S[j]);
        }
    }
    
    vector<string> permutation(string S)
    {
        int n = S.length();
        int i = 0;
        vector<string>finalAns;
        solve(S, 0, finalAns);
        
        sort(finalAns.begin(), finalAns.end());
        return finalAns;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string-1587115620/1