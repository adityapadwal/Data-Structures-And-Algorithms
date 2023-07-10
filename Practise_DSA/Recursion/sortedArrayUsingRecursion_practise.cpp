#include<iostream>
using namespace std;
bool isSorted(int arr[], int n)
{
    // base case
    if(n==0 || n==1)
    {
        return true;
    }
    else
    {
        if(arr[0] > arr[1])
        {
            return false;
        }
        else
        {
            bool ans = isSorted(arr+1 , n-1);  // recursive relations
            return ans;
        }
    }
}
int main()
{
int arr[] = {1,2,3,4,6,5,7,8,9};
int n = 9;
bool ans = isSorted(arr, n);
if(ans == true)
{
    cout<<"\n The array is sorted! ";
}
else
{
    cout<<"\n The array is not sorted:( ";
}
return 0;
}