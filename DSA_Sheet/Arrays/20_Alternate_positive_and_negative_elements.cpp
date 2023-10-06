/* C++ program to rearrange
positive and negative integers
in alternate fashion while keeping
the order of positive and negative numbers. */
#include <assert.h>
#include <iostream>
using namespace std;

// Utility function to right rotate all elements between
// [outofplace, cur]
void rightRotate(int arr[], int n, int outofplace, int cur)
{
	char tmp = arr[cur];
	for (int i = cur; i > outofplace; i--)
		arr[i] = arr[i - 1];
	arr[outofplace] = tmp;
}

void rearrange(int arr[], int n)
{
	int outOfPlace = -1;

    for(int i=0; i<n; i++)
    {
        if(outOfPlace == -1)
        {
            // find the first element
            if((arr[i]>=0 && i%2==0) || (arr[i]<0 && i%2==1))
            {
                outOfPlace = i;
            }
        }

        if(outOfPlace >= 0)
        {
            // find the second element 
            if(outOfPlace%2 == 1)
            {
                // first element was a negative element with odd index. 
                // Hence find the positive element with even index
                if(arr[i]>=0 && i%2==0)
                {
                    rightRotate(arr, n, outOfPlace, i);
                    i = outOfPlace;
                    outOfPlace = -1;
                }
            }
            else
            {
                // first element was a positive element with even index. 
                // Hence find the negative element with odd index
                if(arr[i]<0 && i%2==1)
                {
                    rightRotate(arr, n, outOfPlace, i);
                    i = outOfPlace;
                    outOfPlace = -1;
                }
            }
        }
    }
}

// A utility function to print an array 'arr[]' of size 'n'
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver code
int main()
{

	// int arr[] = {1, 2, 3, -4, -1, 4};
    int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
	int n = (sizeof(arr) / sizeof(arr[0]));

	cout << "Given array is \n";
	printArray(arr, n);

	rearrange(arr, n);

	cout << "Rearranged array is \n";
	printArray(arr, n);

	return 0;
}
