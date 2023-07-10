#include<iostream>
using namespace std;
int firstOccur(int arr[], int size, int key)
{
    int start = 0;
    int end=size-1;
    int mid=start  + (end - start)/2;
    int ans=-1;

    while(start<=end)
    {
        if(arr[mid]==key)
        {
            ans = mid;
            end=mid-1;
        }
        if (key> arr[mid])
        {
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start  + (end - start)/2;

    }
    return ans;
}

int lastOccur(int arr[], int size, int key)
{
    int start = 0;
    int end=size-1;
    int mid=start  + (end - start)/2;
    int ans=-1;

    while(start<=end)
    {
        if(arr[mid]==key)
        {
            ans = mid;
            start = mid+1;
        }
        if (key> arr[mid])
        {
            end=mid-1;   
        }
        else{
            start=mid+1;
        }
        mid=start  + (end - start)/2;

    }
    return ans;
}
int main()
{
    //int even[6]={1,2,2,2,3,4};
    int odd[11]={1,2,3,3,3,3,3,3,3,3,5};

    // int a= firstOccur(even, 6, 2);
    // int b= lastOccur(even , 6, 2);
    // cout<<"\n First Occurance of 2 is at index: "<<a;
    // cout<<"\n Last Occurance of 2 is at index: "<<b;

    cout<<endl;

    int c= firstOccur(odd, 11, 3);
    int d= lastOccur(odd, 11, 3);
    cout<<"\n First Occurance of 3 is at index: "<<c;
    cout<<"\n Last Occurance of 3 is at index: "<<d;

return 0;
}