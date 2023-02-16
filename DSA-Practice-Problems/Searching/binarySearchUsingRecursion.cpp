#include<iostream>
using namespace std;

bool binarySearch(int arr[], int key, int s, int e)
{
    while(s <= e)
    {
        int mid = (s + (e-s)/2);
        if(arr[mid] == key)
        {
            return true;
        }
        else if(key < arr[mid])
        {
            binarySearch(arr, key, s, mid-1 );
        }
        else
        {
            binarySearch(arr, key, mid+1, e);
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

    bool result = binarySearch(arr, searchKey, 0, n-1);
    
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
