#include<iostream>
using namespace std;
int partition(int * arr, int s, int e)
{
    int pivot = arr[s];
    int cnt = 0;

    for(int i=s+1; i<=e; i++)
    {
        if(arr[i] <= pivot)
        {
            cnt++;
        }
    }

    int pivotIndex = cnt + s;
    swap(arr[s], arr[pivotIndex]);

    // sort right and left side of pivotIndex
    int i = s;
    int j = e;

    while((i<pivotIndex) && (j>pivotIndex))
    {
        while(arr[i] < arr[pivotIndex])
        {
            i++;
        }
        while(arr[j] > arr[pivotIndex])
        {
            j--;
        }
        if((i<pivotIndex) && (j>pivotIndex))
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotIndex;
}

void quickSort(int* arr, int s, int e)
{
    // base case
    if(s >= e)
    {
        return;
    }

    int p = partition(arr, s, e);

    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
}

int main()
{
    int n;
    cout<<"\n Enter count: ";
    cin>>n;

    int* arr = new int[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Enter number: ";
        cin>>arr[i];
    } 

    int s = 0;
    int e = n-1;
    quickSort(arr, s, e);

    cout<<"\n";
    cout<<"\n Displaying Sorted Elements";
    cout<<"\n";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" -> ";
    } 
return 0;
}