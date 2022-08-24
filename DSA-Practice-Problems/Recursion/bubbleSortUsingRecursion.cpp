#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    //base case
    if(n==0 || n==1)
    {
        return ;
    }

    for(int i=0; i<n; i++)
    {
        if(arr[i] > arr[i+1])
        {
            swap(arr[i], arr[i+1]);
        }
    }

    bubbleSort(arr, n-1);
}

int main()
{
    int arr[10];
    int n;
    cout<<"\n Bubble Sort Using Recursion!!! ";
    cout<<"\n Enter total number of elements: ";
    cin>>n;
    cout<<"\n Enter the array of numbers";
    for(int i=0; i<n; i++)
    {
        cout<<"\n Enter number: ";
        cin>>arr[i];
    }

    bubbleSort(arr, n);

    cout<<"\n The sorted array is- ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<"  ";
    }

return 0;
}