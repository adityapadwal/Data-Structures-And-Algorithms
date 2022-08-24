#include<iostream>
using namespace std;
int binSearch(int arr[], int key, int n)
{
    int start=0; 
    int end=n-1;
    int mid=start + ((start+end)/2);

    while(start<=end)
    {
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(key<arr[mid])
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
        mid=start + (start+end)/2;
    }
    return -1;
}
int main()
{
    int n;
    int key;
    cout<<"\n Enter size of the array: ";
    cin>>n;
int arr[n];
cout<<"\n Enter numbers in ascending order";
for(int i=0; i<n; i++)
{
    cout<<"\n Enter number: ";
    cin>>arr[i];
}
cout<<"\n Enter the key to be searched: ";
cin>>key;

int ans = binSearch(arr, key, n);
if(ans==-1)
{
	cout<<"\n Search unsuccessful :(";
}
else
{
	cout<<"\n Search successful";
}
return 0;
}
