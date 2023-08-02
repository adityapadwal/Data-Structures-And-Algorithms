// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	string FirstNonRepeating(string A)
	{
		// Step 1: create an unordered map(for keeping count), a queue and a string for returning the ans
		unordered_map<char, int> count;
		queue<int> q;
		string ans = "";

		// Step 2: Traverse the string and keep a count of the characters
		for (int i = 0; i < A.length(); i++)
		{
			char ch = A[i];

			// increase the count of the character
			count[ch]++;

			// Step 3: Push the characters into the queue
			q.push(ch);

			// Step 4: Solve for repeating/non repeating
			while (!q.empty())
			{
				if (count[q.front()] > 1)
				{
					// repeating character
					q.pop();
				}
				else
				{
					// non-repeating character
					ans.push_back(q.front());
					break;
				}
			}

			if (q.empty())
			{
				ans.push_back('#');
			}
		}
		return ans;
	}
};

// { Driver Code Starts.
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
} // } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1