#include<iostream>
using namespace std;
bool binarySearch(int arr[], int key, int n)
{
    int s = 0;
    int e = n-1;

    while(s <= e)
    {
        int mid = (s + (e-s)/2);
        if(arr[mid] == key)
        {
            return true;
        }
        else if(arr[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            // arr[mid] > key
            e = mid - 1;
        }
    }
    return false;
}
int main()
{
    int n;
    int searchKey;

    cout<<"\n Enter array size: ";
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++)
    {
        cout<<"\n Enter value: ";
        cin>>arr[i];
    }

    cout<<"\n Enter search key: ";
    cin>>searchKey;

    bool result = binarySearch(arr, searchKey, n);
    
    if(result == true)
    {
        cout<<"Search found!";
    }
    else 
    {
        cout<<"No search found";
    }

return 0;
}