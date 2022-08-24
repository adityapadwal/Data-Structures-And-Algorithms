// Quick sort Using Recursion 
// Done previously in Recursion Folder

#include<iostream>
using namespace std;

int partition(int* arr, int s, int e)
{
    int pivot = arr[s];
    int cnt =0;
    for(int i=s+1 ; i<=e; i++)
    {
        if(arr[i] <= pivot)
        {
            cnt++;
        }
    }

    // putting pivot into its right position!
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    // sorting the left and figt side of pivot!
    int i=s;
    int j=e;
    while(i<pivotIndex && j>pivotIndex)
    {
        while(arr[i] < arr[pivotIndex])
        {
            i++;
        }
        while(arr[j] > arr[pivotIndex])
        {
            j--;
        }
        if(i<pivotIndex && j>pivotIndex)
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

    // make partition
    int p = partition(arr, s, e);

    //left wala sambhal lo
    quickSort(arr, s, p-1);

    // right wala sambhal lo 
    quickSort(arr, p+1, e);
}

int main()
{
    int arr[]={9,8,7,6,5,4,3,2,1,0};
    int n = 10;
    quickSort(arr, 0, n-1);
    cout<<endl;
    cout<<endl;
    cout<<"\n Displaying The Sorted Array";
    for(int i=0; i<n; i++)
    {
        cout<<" -> "<<arr[i];
    }
return 0;
}