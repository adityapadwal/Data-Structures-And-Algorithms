#include<iostream>
using namespace std;

bool binarySearch(int *arr, int s, int e,int key)
{
    //Base case
    if(s>e)
    {
        return false;
    }
    int mid = s+(e-s)/2;
    
    //Processing
    if(arr[mid] == key)
    {
        return true;
    }

    //Recursive relation
    else if(arr[mid]>key)
    {
        bool ans = binarySearch(arr,s,mid-1,key);
        return ans;
    }
    else{
        bool ans = binarySearch(arr,mid+1,e,key);
        return ans;
    }
}

int main()
{
    int arr[5];
    int key;
    cin>>key;
    for(int i = 0;i<5;i++)
    {
        cin>>arr[i];
    }
    int ans = binarySearch(arr, 0, 4, key);
    if(ans)
     cout<<ans<<endl;
    else
     cout<<"Not found"<<endl; 
}
//https://www.codingninjas.com/codestudio/problems/binary-search_972?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_11