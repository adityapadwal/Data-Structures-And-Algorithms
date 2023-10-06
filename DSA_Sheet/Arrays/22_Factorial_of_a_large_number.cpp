//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    void solve(vector<int>&fact, int n)
    {
        int carry = 0;
        for(int i=0; i<fact.size(); i++)
        {
            int data = fact[i] * n + carry;
            fact[i] = data % 10;
            carry = data / 10;
        }
        while(carry)
        {
            fact.push_back(carry%10);
            carry = carry/10;
        }
    }
    
    vector<int> factorial(int N){
        vector<int>result = {1};
        for(int i=2; i<=N; i++)
        {
            solve(result, i);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1