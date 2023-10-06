#include <bits/stdc++.h>
using namespace std;

// Approach 1: Using hashmaps
// TC = O(N) SC = O(N)
void morethanNbyK(int arr[], int n, int k)
{
	int x = n / k;

	// unordered_map initialization
	unordered_map<int, int> freq;

	for (int i = 0; i < n; i++) {
		freq[arr[i]]++;
	}

	// Traversing the map
	for (auto i : freq) {

		// Checking if value of a key-value pair
		// is greater than x (where x=n/k)
		if (i.second > x) 
        {
			cout << i.first << endl;
		}
	}
}

// Approach 2: Using Moore's voting Algorithm
// TC = O(N*K) SC = O(1)


// Driver Code
int main()
{
	int arr[] = { 1, 1, 2, 2, 3, 5, 4, 2, 2, 3, 1, 1, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 4;

	morethanNbyK(arr, n, k);

	return 0;
}
