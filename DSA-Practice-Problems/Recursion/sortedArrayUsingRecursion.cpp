#include<iostream>
using namespace std;

bool isSorted(int arr[], int n)
{
    if(n==0 || n==1)  //base case 
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
            isSorted(arr+1, n-1);
            // bool ans = isSorted(arr+1, n-1);
            // return ans;
        }
    }
    

}
int main()
{
    int arr[] = {2,3,4,5,6,7,8,9};
    int size =8;
    int ans = isSorted(arr, size);
    if(ans == true)
    {
        cout<<"\n The array of integers is Sorted! ";
    }
    else
    {
        cout<<"\n The array is not sorted! ";
    }
return 0;
}